/*
** EPITECH PROJECT, 2022
** cpp
** File description:
** Epaint_Main
*/

#include "Epaint_Main.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>

Game::Epaint_Main::Epaint_Main()
{
    texture_bomb.loadFromFile("assets/bomb.png");
    Bomb.setTexture(texture_bomb);
    texture_flag.loadFromFile("assets/flag.png");
    flag.setTexture(texture_flag);
    texture_box.loadFromFile("assets/box.png");
    box.setTexture(texture_box);
}

void event_manage(sf::RenderWindow window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void place_box(Game::Epaint_Main *ji, int *bomb, sf::RenderWindow window)
{
    for (int x = 0, y = 100, i = 0, count = 0; y != 16 * 50 + 100; count++) {
        if (i % 2 == 0) {
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                window.draw(ji->box);
            }
            x += 25;
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                window.draw(ji->box);
            }
            x += 25;
        } else if (i % 2 == 1) {
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                window.draw(ji->box);
            }
            x += 25;
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                window.draw(ji->box);
            }
            x += 25;
        }
        if (x == 16 * 50) {
            count++;
            y += 25;
            x = 0;
            i += 1;
        }
    }
}

int main(int ac, char **av)
{
    Game::Epaint_Main ji;
    sf::RenderWindow window(sf::VideoMode(16 * 50, 16 * 50 + 100), "Demineur");
    sf::RectangleShape Menu;
    int bomb[1024];
    srand (time(NULL));

    for (int i = 0, alea = -1; i != 1024; i++) {
        alea = rand() % 100;
        if (atoi(av[1]) >= alea) {
            bomb[i] = 1;
        } else {
            bomb[i] = 0;
        }
    }
    while (window.isOpen())
    {
        window.clear(sf::Color(158, 158, 158));
        sf::Vector2i pos = sf::Mouse::getPosition(window);
        place_box(&ji, bomb, window);
        if (pos.y >= 100 && pos.y <= 16 * 50 + 100 && pos.x >= 0 && pos.x <= 16 * 50) {
            if (bomb[((16 * (pos.y / 25)) + (pos.x / 25) - 32)] == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left)) == 1) {
                ji.Bomb.setPosition((pos.x / 25) * 25, (pos.y / 25) * 25);
                window.draw(ji.Bomb);
            }
        }
        if (pos.y >= 100 && pos.y <= 16 * 50 + 100 && pos.x >= 0 && pos.x <= 16 * 50) {
            if (bomb[((16 * (pos.y / 25)) + (pos.x / 25) - 32)] == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left)) == 1) {
                bomb[((16 * (pos.y / 25)) + (pos.x / 25) - 32)] = 2;
            }
        }
        event_manage();
        window.display();
    return 0;
    }
}