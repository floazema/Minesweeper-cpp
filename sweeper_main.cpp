/*
** EPITECH PROJECT, 2022
** cpp
** File description:
** sweeper
*/

#include "sweeper.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>

Game::sweeper::sweeper()
{
    texture_bomb.loadFromFile("assets/bomb.png");
    Bomb.setTexture(texture_bomb);
    texture_flag.loadFromFile("assets/flag.png");
    flag.setTexture(texture_flag);
    texture_box.loadFromFile("assets/box.png");
    box.setTexture(texture_box);
}

void event_manage(Game::sweeper *ji, sf::Vector2i pos, int *bomb)
{
    sf::Event event;
    while (ji->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            ji->window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && pos.y >= 100 && pos.y <= 16 * 50 + 100 && pos.x >= 0 && pos.x <= 16 * 50) {
            if (bomb[((16 * (pos.y / 25)) + (pos.x / 25) - 32)] == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left)) == 1) {
                bomb[((16 * (pos.y / 25)) + (pos.x / 25) - 32)] = 2;
            }
        }
    }
}

void place_box(Game::sweeper *ji, int *bomb)
{
    for (int x = 0, y = 100, i = 0, count = -32; y != 16 * 50 + 100;) {
        if (i % 2 == 0) {
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                ji->window.draw(ji->box);
            }
            count++;
            x += 25;
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                ji->window.draw(ji->box);
            }
            x += 25;
            count++;
        } else if (i % 2 == 1) {
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                ji->window.draw(ji->box);
            }
            x += 25;
            count++;
            ji->box.setPosition(x, y);
            if (bomb[count] != 2) {
                ji->window.draw(ji->box);
            }
            x += 25;
            count++;
        }
        if (x >= 16 * 50) {
            y += 25;
            x = 0;
            i += 1;
        }
    }
}

int main(int ac, char **av)
{
    Game::sweeper ji;
    ji.window.create(sf::VideoMode(800, 800), "démineur");
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
    while (ji.window.isOpen())
    {
        ji.window.clear(sf::Color(158, 158, 158));
        sf::Vector2i pos = sf::Mouse::getPosition(ji.window);
        place_box(&ji, bomb);
        if (pos.y >= 100 && pos.y <= 16 * 50 + 100 && pos.x >= 0 && pos.x <= 16 * 50) {
            if (bomb[((16 * (pos.y / 25)) + (pos.x / 25) - 32)] == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left)) == 1) {
                ji.Bomb.setPosition((pos.x / 25) * 25, (pos.y / 25) * 25);
                ji.window.draw(ji.Bomb);
            }
        }
        event_manage(&ji, pos, bomb);
        ji.window.display();
    }
    return 0;
}