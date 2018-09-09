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

    win.create(sf::VideoMode(w * 32 + (SIDE_MENU_WIDTH * 2), h * 32), "Nibbler SFML", sf::Style::Titlebar | sf::Style::Close);
    if (!win.isOpen()) {
        std::cout << "Error: can't open SFML window" << std::endl;
        exit(1);
    }

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

    /*
     *  prepare game over/ game_over screen
     */

    sf::Vector2u size = texture_game_over.getSize();

    sprite_game_over.scale((((w * 32) + (SIDE_MENU_WIDTH * 2)) / static_cast<float>(size.x)), ((h * 32) / static_cast<float>(size.y)));
    sprite_game_over.setTexture(texture_game_over);

    /*
     * working with text
     */

    if (!font.loadFromFile("libs/sfml/10.ttf")) {
        std::cout << "Error: can't load ttf file";
        exit (0);
    }

    text_score.setFont(font);
    text_score.setStyle(sf::Text::Bold);
    text_score.setCharacterSize(60);
    text_score.setPosition(w * 32 + 30, 30);
    text_score.setFillColor(sf::Color::Yellow);

    text_time_left.setFont(font);
    text_time_left.setStyle(sf::Text::Bold);
    text_time_left.setCharacterSize(60);
    text_time_left.setPosition(w * 32 + 30, 120);
    text_time_left.setFillColor(sf::Color::Yellow);

    text_best_score.setFont(font);
    text_best_score.setStyle(sf::Text::Bold);
    text_best_score.setCharacterSize(60);
    text_best_score.setPosition(w * 32 + 30, 210);
    text_best_score.setFillColor(sf::Color::Yellow);
    text_best_score.setString("BEST SCORES:");

    text_score_element.setFont(font);
    text_score_element.setStyle(sf::Text::Bold);
    text_score_element.setCharacterSize(60);
    text_score_element.setFillColor(sf::Color::Yellow);
}

SfmlWrapper::~SfmlWrapper() {
//    win.clear();
    win.close();
//    system("leaks Nibbler -q");
}

SfmlWrapper::SfmlWrapper(const SfmlWrapper &sfml)
        : event(sfml.event),
          texture_background(sfml.texture_background),
          texture_border(sfml.texture_border),
          texture_border_block(sfml.texture_border_block),
          texture_food(sfml.texture_food),
          texture_super_food(sfml.texture_super_food),
          texture_snake_head_up(sfml.texture_snake_head_up),
          texture_snake_head_down(sfml.texture_snake_head_down),
          texture_snake_head_left(sfml.texture_snake_head_left),
          texture_snake_head_right(sfml.texture_snake_head_right),
          texture_snake_body(sfml.texture_snake_body),
          texture_game_over(sfml.texture_game_over),
          sprite(sfml.sprite),
          sprite_border(sfml.sprite_border),
          sprite_food(sfml.sprite_food),
          sprite_super_food(sfml.sprite_super_food),
          sprite_snake(sfml.sprite_snake),
          sprite_game_over(sfml.sprite_game_over),
          font(sfml.font),
          text_score(sfml.text_score),
          text_time_left(sfml.text_time_left),
          text_best_score(sfml.text_best_score),
          text_score_element(sfml.text_score_element)
{

}

SfmlWrapper& SfmlWrapper::operator=(const SfmlWrapper &sfml) {
    event = sfml.event;
    texture_background = sfml.texture_background;
    texture_border = sfml.texture_border;
    texture_border_block = sfml.texture_border_block;
    texture_food = sfml.texture_food;
    texture_super_food = sfml.texture_super_food;
    texture_snake_head_up = sfml.texture_snake_head_up;
    texture_snake_head_down = sfml.texture_snake_head_down;
    texture_snake_head_left = sfml.texture_snake_head_left;
    texture_snake_head_right = sfml.texture_snake_head_right;
    texture_snake_body = sfml.texture_snake_body;
    texture_game_over = sfml.texture_game_over;
    sprite = sfml.sprite;
    sprite_border = sfml.sprite_border;
    sprite_food = sfml.sprite_food;
    sprite_super_food = sfml.sprite_super_food;
    sprite_snake = sfml.sprite_snake;
    sprite_game_over = sfml.sprite_game_over;
    font = sfml.font;
    text_score = sfml.text_score;
    text_time_left = sfml.text_time_left;
    text_best_score = sfml.text_best_score;
    text_score_element = sfml.text_score_element;
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

    text_score.setString("Score: " + std::to_string(score));
    win.draw(text_score);
    text_time_left.setString("Time left: " + std::to_string(time_left));
    win.draw(text_time_left);
    win.draw(text_best_score);

    for (size_t i = 0, k = 300; i < score_data.size(); i++) {
        text_score_element.setPosition(w * 2 + 30, k);
        text_score_element.setString(std::to_string(i + 1) + ": " + std::to_string(score_data[i]));
        k += 70;
        win.draw(text_score_element);
    }
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
