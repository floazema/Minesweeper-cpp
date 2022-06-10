/*
** EPITECH PROJECT, 2022
** cpp
** File description:
** Epaint_Main
*/

#ifndef EPAINT_MAIN_HPP_
#define EPAINT_MAIN_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game {
    class Epaint_Main {
        public:
            Epaint_Main();
            ~Epaint_Main() = default;
            sf::Sprite Bomb;
            sf::Texture texture_bomb;
            sf::Sprite flag;
            sf::Texture texture_flag;
            sf::Sprite box;
            sf::Texture texture_box;
        protected:
        private:
    };
}

#endif /* !EPAINT_MAIN_HPP_ */
