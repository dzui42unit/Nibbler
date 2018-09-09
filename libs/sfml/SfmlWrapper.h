//
// Created by Serhii Protsenko on 04.09.2018.
//

#ifndef NIBBLER_SFMLWRAPPER_H
#define NIBBLER_SFMLWRAPPER_H

#endif //NIBBLER_SFMLWRAPPER_H

#include "../../InterfaceLibrary/InterfaceLibrary.h"
#include <Graphics.hpp>
#include <Graphics/Image.hpp>
#include <Window/VideoMode.hpp>
#include <Graphics/Sprite.hpp>
#include "iostream"


class   SfmlWrapper : public InterfaceLibrary
{
public:
    SfmlWrapper() = delete;
    SfmlWrapper(int w, int h);
    ~SfmlWrapper();
    SfmlWrapper(const SfmlWrapper &sfml);
    SfmlWrapper &operator=(const SfmlWrapper &sfml);

    void 			RenderMap(const std::vector<std::vector<int>> &game_map) final;
    void			ClearImage(void) final;
    void			RenderImage(void) final;
    void 			RenderFood(int x, int y, bool isBonusFruit) final;
    int 			HandleInput(void) final;
    void 			RenderSnake(const std::vector<std::pair<int, int>> &snake_parts, int dir) final ;
    void			RenderSideMenu(int w, int h, size_t score, float time_left, std::vector<int> score_data) final ;
    void			RenderGameOverScreen(void) final;

    sf::RenderWindow    win;
    sf::Event           event;

    sf::Texture         texture_background;
    sf::Texture         texture_border;
    sf::Texture         texture_border_block;
    sf::Texture         texture_food;
    sf::Texture         texture_super_food;
    sf::Texture         texture_snake_head_up;
    sf::Texture         texture_snake_head_down;
    sf::Texture         texture_snake_head_left;
    sf::Texture         texture_snake_head_right;
    sf::Texture         texture_snake_body;
    sf::Texture         texture_game_over;
    sf::Sprite          sprite;
    sf::Sprite          sprite_border;
    sf::Sprite          sprite_food;
    sf::Sprite          sprite_super_food;
    sf::Sprite          sprite_snake;
    sf::Sprite          sprite_game_over;

    sf::Font            font;


};