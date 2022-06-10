/*
** EPITECH PROJECT, 2022
** cpp
** File description:
** sweeper
*/

#ifndef sweeper_HPP_
#define sweeper_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game {
    class sweeper {
        public:
            sweeper();
            ~sweeper() = default;
            sf::Sprite Bomb;
            sf::Texture texture_bomb;
            sf::Sprite flag;
            sf::Texture texture_flag;
            sf::Sprite box;
            sf::Texture texture_box;
            sf::RenderWindow window;
        protected:
        private:
    };
}

#endif /* !sweeper_HPP_ */
