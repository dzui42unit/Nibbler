//
// Created by Serhii Protsenko on 04.09.2018.
//

#include "SfmlWrapper.h"
#include "../../Snake/Snake.h"

SfmlWrapper::SfmlWrapper(int w, int h) {
    w *= 2;
    h *= 2;

    /*
     *  Init Windows
     */

    win.create(sf::VideoMode(w * 32 + (SIDE_MENU_WIDTH * 2), h * 32), "Nibbler");
    if (!win.isOpen()) {
        std::cout << "Error: can't open SFML window" << std::endl;
        exit(1);
    }

//    sf::Vector2u size = win.getSize();
//    std::cout << size.x << std::endl;
//    std::cout << size.y << std::endl;

    /*
     *  create background
     */

    sf::Image     image_backgroud;
    if (!image_backgroud.loadFromFile("libs/sfml/sfml_background2.jpg")) {
        std::cout << "Error: can't load image for background" << std::endl;
        exit(0);
    }
    sf::IntRect  rect_background(0, 0, (w * 32), (h * 32));
    if (!texture_background.loadFromImage(image_backgroud, rect_background)) {
        std::cout << "Error: can't create texture from background image" << std::endl;
        exit(0);
    }

    sf::Image   all;
    if (!all.loadFromFile("libs/sfml/All64.png")) {
        std::cout << "Error: can't load image" << std::endl;
        exit(0);
    }


    sf::IntRect  rect_border(64, 128, 64, 64);
    if (!texture_border.loadFromImage(all, rect_border)) {
        std::cout << "Error: can't create texture from border image" << std::endl;
        exit(0);
    }
    if (!texture_border_block.loadFromImage(all, sf::IntRect(0, 128, 64, 64))) {
        std::cout << "Error: can't create texture from border image" << std::endl;
        exit(0);
    }

    sprite.setTexture(texture_background);

    sf::IntRect  rect_food(64, 192, 64, 64);
    if (!texture_food.loadFromImage(all, rect_food)) {
        std::cout << "Error: can't create texture from food image" << std::endl;
        exit(0);
    }
    sprite_food.setTexture(texture_food);

    sf::IntRect  rect_super_food(192, 128, 64, 64);
    if (!texture_super_food.loadFromImage(all, rect_super_food)) {
        std::cout << "Error: can't create texture from super_food image" << std::endl;
        exit(0);
    }
    sprite_super_food.setTexture(texture_super_food);

    if (!texture_snake_head_up.loadFromImage(all, sf::IntRect(0, 256, 64, 64)) ||
        !texture_snake_head_down.loadFromImage(all, sf::IntRect(192, 256, 64, 64)) ||
        !texture_snake_head_left.loadFromImage(all, sf::IntRect(128, 256, 64, 64)) ||
        !texture_snake_head_right.loadFromImage(all, sf::IntRect(64, 256, 64, 64)))  {
        std::cout << "Error: can't create texture from snake image" << std::endl;
        exit(0);
    }

    sf::IntRect     rect_snake_body(0, 64, 64, 64);
    if (!texture_snake_body.loadFromImage(all, rect_snake_body)) {
        std::cout << "Error: can't create texture from snake_body image" << std::endl;
        exit(0);
    }

    if (!texture_game_over.loadFromFile("libs/sfml/game_over.png")) {
        std::cout << "Error: can't create texture from game_over image" << std::endl;
        exit(0);
    }

    sf::Vector2u size = texture_game_over.getSize();

    sprite_game_over.scale(((w * 32) / static_cast<float>(size.x)), ((h * 32) / static_cast<float>(size.y)));
    sprite_game_over.setTexture(texture_game_over);

    /*
     * working with text
     */

    if (!font.loadFromFile("libs/sfml/10.ttf")) {
        std::cout << "Error: can't load ttf file";
        exit (0);
    }
}

SfmlWrapper::~SfmlWrapper() {
    win.clear();
    win.close();
//    system("leaks Nibbler -q");
}

SfmlWrapper::SfmlWrapper(const SfmlWrapper &sfml) {
    //TODO Add info
}
SfmlWrapper& SfmlWrapper::operator=(const SfmlWrapper &sfml) {
    //TODO Add info
    return *this;
}

void SfmlWrapper::RenderMap(const std::vector <std::vector<int>> &game_map) {
    win.draw(sprite);

    for (size_t i = 0; i < game_map.size(); i++)
    {
        for (size_t j = 0; j < game_map[i].size(); j++)
        {
            sprite_border.setPosition(j * 64, i * 64);
            if (game_map[i][j] == 1) {
                sprite_border.setTexture(texture_border);
                win.draw(sprite_border);
            } else if (game_map[i][j] != 0) {
                sprite_border.setTexture(texture_border_block);
                win.draw(sprite_border);
            }
        }
    }
}

void SfmlWrapper::ClearImage() {
    win.clear();
}
void SfmlWrapper::RenderImage() {
    win.display();
}
void SfmlWrapper::RenderFood(int x, int y, bool isBonusFruit) {

    if (isBonusFruit) {
        sprite_super_food.setPosition(y * 64, x * 64);
        win.draw(sprite_super_food);
    } else {
        sprite_food.setPosition(y * 64, x * 64);
        win.draw(sprite_food);
    }
}

int SfmlWrapper::HandleInput() {

    while (win.isOpen() && win.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            return (0);
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
                return (0);
            if (event.key.code == sf::Keyboard::Left)
                return (Directions::LEFT);
            if (event.key.code == sf::Keyboard::Right)
                return (Directions::RIGHT);
            if (event.key.code == sf::Keyboard::Up)
                return (Directions::UP);
            if (event.key.code == sf::Keyboard::Down)
                return (Directions::DOWN);
            if (event.key.code == sf::Keyboard::Space)
                return (Directions::PAUSE);
            if (event.key.code == sf::Keyboard::Numpad1)
                return (Directions::SDL_LIB);
            if (event.key.code == sf::Keyboard::Numpad2)
                return (Directions::SFML_LIB);
            if (event.key.code == sf::Keyboard::Numpad3)
                return (Directions::OPENGL_LIB);
        }
    }
    return (Directions::NOTHING_PRESSED);
}

void SfmlWrapper::RenderSnake(const std::vector <std::pair<int, int>> &snake_parts, int dir) {

    sf::IntRect r(0, 0, 64, 64);

    for (size_t i = 1; i < snake_parts.size(); i++)
    {
        sprite_snake.setTexture(texture_snake_body);
        sprite_snake.setPosition(snake_parts[i].second * 64, snake_parts[i].first * 64);
        win.draw(sprite_snake);
    }

    r.left = snake_parts[0].second * r.width;
    r.top = snake_parts[0].first * r.height;

    switch (dir) {
        case 1: {
            sprite_snake.setTexture(texture_snake_head_up);
            break;
        }
        case 2: {
            sprite_snake.setTexture(texture_snake_head_down);
            break;

        }
        case 3: {
            sprite_snake.setTexture(texture_snake_head_left);
            break;

        }
        case 4: {
            sprite_snake.setTexture(texture_snake_head_right);
            break;

        }
        default: {
            break;
        }
    }
    sprite_snake.setPosition(r.left, r.top);
    win.draw(sprite_snake);
}

void SfmlWrapper::RenderSideMenu(int w, int h, size_t score, float time_left, std::vector<int> score_data) {

}

void SfmlWrapper::RenderGameOverScreen() {
    win.draw(sprite_game_over);
}


extern "C" SfmlWrapper      *createWrapper(int w, int h)
{
    return (new SfmlWrapper(w, h));
}
extern "C" void             deleteWrapper(SfmlWrapper *lib)
{
    delete lib;
}