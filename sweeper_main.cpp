/*
** EPITECH PROJECT, 2022
** cpp
** File description:
** sweeper
*/

#include "sweeper.hpp"
#include <SFML/Graphics.hpp>
#include <time.h>
#include <stdlib.h>
#include <string>

Game::sweeper::sweeper()
{
    texture_bomb.loadFromFile("assets/bomb.png");
    Bomb.setTexture(texture_bomb);
    texture_flag.loadFromFile("assets/flag.png");
    flag.setTexture(texture_flag);
    texture_box.loadFromFile("assets/box.png");
    box.setTexture(texture_box);
    nbr_f.loadFromFile("assets/arial.ttf");
    nbr_t.setFont(nbr_f);
    nbr_t.setFont(nbr_f);
    nbr_t.setCharacterSize(25);
    //sf::Color color = {0, 0, 255};
    //nbr_t.setColor(color);
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
            if (bomb[((32 * (pos.y / 25)) + (pos.x / 25) - 128)] == 0 && sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left)) == 1) {
                bomb[((32 * (pos.y / 25)) + (pos.x / 25) - 128)] = 2;
                std::cout << ((32 * (pos.y / 25)) + (pos.x / 25) - 128) << "\n";
            }
        }
    }
}

void do_0(int *bomb, int y, int x)
{
    if (bomb[((32 * (y / 25)) + (x / 25) - 129)] != 3 ||
    bomb[((32 * (y / 25)) + (x / 25) - 127)] != 3 ||
    bomb[((32 * (y / 25)) + (x / 25) - 160)] != 3 ||
    bomb[((32 * (y / 25)) + (x / 25) - 161)] != 3 ||
    bomb[((32 * (y / 25)) + (x / 25) - 159)] != 3 ||
    bomb[((32 * (y / 25)) + (x / 25) - 96)] != 3 ||
    bomb[((32 * (y / 25)) + (x / 25) - 95)] != 3 ||
    bomb[((32 * (y / 25)) + (x / 25) - 97)] != 3 && 
    bomb[((32 * (y / 25)) + (x / 25) - 128)] == 3) {
        bomb[((32 * (y / 25)) + (x / 25) - 128)] = 2;
        bomb[((32 * (y / 25)) + (x / 25) - 129)] = 3;
        bomb[((32 * (y / 25)) + (x / 25) - 127)] = 3;
        bomb[((32 * (y / 25)) + (x / 25) - 160)] = 3;
        bomb[((32 * (y / 25)) + (x / 25) - 161)] = 3;
        bomb[((32 * (y / 25)) + (x / 25) - 159)] = 3;
        bomb[((32 * (y / 25)) + (x / 25) - 96)] =  3;
        bomb[((32 * (y / 25)) + (x / 25) - 95)] =  3;
        bomb[((32 * (y / 25)) + (x / 25) - 97)] =  3;
        do_0(bomb, y, x);
    }
    return;
}

void place_box(Game::sweeper *ji, int *bomb)
{
    for (int x = 0, y = 100, i = 0, count = 0, nbr_bomb = 0; y != 16 * 50 + 100;) {
        if (i % 2 == 0) {
            ji->box.setPosition(x, y);
            if (bomb[count] < 2) {
                ji->window.draw(ji->box);
            } else {
                if (bomb[((32 * (y / 25)) + (x / 25) - 129)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 127)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 160)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 161)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 159)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 96)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 95)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 97)] == 1)
                    nbr_bomb += 1;
                if (nbr_bomb == 0) {
                    do_0(bomb, y, x);
                } else {
                    ji->nbr_t.setString(std::to_string(nbr_bomb));
                    ji->nbr_t.setPosition(x + 5, y - 3);
                    ji->window.draw(ji->nbr_t);
                    nbr_bomb = 0;
                }
            }
            count++;
            x += 25;
            ji->box.setPosition(x, y);
            if (bomb[count] < 2) {
                ji->window.draw(ji->box);
            } else {
                if (bomb[((32 * (y / 25)) + (x / 25) - 129)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 127)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 160)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 161)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 159)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 96)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 95)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 97)] == 1)
                    nbr_bomb += 1;
                if (nbr_bomb == 0) {
                    do_0(bomb, y, x);
                } else {
                    ji->nbr_t.setString(std::to_string(nbr_bomb));
                    ji->nbr_t.setPosition(x + 5, y - 3);
                    ji->window.draw(ji->nbr_t);
                    nbr_bomb = 0;
                }
            }
            count++;
            x += 25;
        } else if (i % 2 == 1) {
            ji->box.setPosition(x, y);
            if (bomb[count] < 2) {
                ji->window.draw(ji->box);
            } else {
                if (bomb[((32 * (y / 25)) + (x / 25) - 129)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 127)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 160)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 161)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 159)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 96)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 95)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 97)] == 1)
                    nbr_bomb += 1;
                if (nbr_bomb == 0) {
                    do_0(bomb, y, x);
                } else {
                    ji->nbr_t.setString(std::to_string(nbr_bomb));
                    ji->nbr_t.setPosition(x + 5, y - 3);
                    ji->window.draw(ji->nbr_t);
                    nbr_bomb = 0;
                }
            }
            count++;
            x += 25;
            ji->box.setPosition(x, y);
            if (bomb[count] < 2) {
                ji->window.draw(ji->box);
            } else {
                if (bomb[((32 * (y / 25)) + (x / 25) - 129)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 127)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 160)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 161)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 159)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 96)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 95)] == 1)
                    nbr_bomb += 1;
                if (bomb[((32 * (y / 25)) + (x / 25) - 97)] == 1)
                    nbr_bomb += 1;
                if (nbr_bomb == 0) {
                    do_0(bomb, y, x);
                } else {
                    ji->nbr_t.setString(std::to_string(nbr_bomb));
                    ji->nbr_t.setPosition(x + 5, y - 3);
                    ji->window.draw(ji->nbr_t);
                    nbr_bomb = 0;
                }
            }
            count++;
            x += 25;
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
            if (bomb[((32 * (pos.y / 25)) + (pos.x / 25) - 128)] == 1 && sf::Mouse::isButtonPressed(sf::Mouse::Button(sf::Mouse::Left)) == 1) {
                ji.Bomb.setPosition((pos.x / 25) * 25, (pos.y / 25) * 25);
                ji.window.draw(ji.Bomb);
            }
        }
        event_manage(&ji, pos, bomb);
        ji.window.display();
    }
    return 0;
}