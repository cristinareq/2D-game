/*
 * File: game.cpp
 * Author: Alessandra Gorla
 * Date: November 21, 2023
 * Description: Game class to deal with initialization and controller of 2D my game application.
 */
#include "game.h"
#include <iostream>

const float Game::SCENE_WIDTH = 800.0f;
const float Game::SCENE_HEIGHT = 600.0f;
const float Game::PLAYER_START_X = 400.0f;
const float Game::PLAYER_START_Y = 300.0f;
const float Game::RADIUS = 40.0f;

Game::Game()
{
    initWindow();
    initBackground();
    initPlayer();

    // Set movement flags to false initially
    rightPressed = false;
    leftPressed = false;
    upPressed = false;
    downPressed = false;
}

/**
 * Window initializer.
 */
int Game::initWindow()
{
    window.create(sf::VideoMode(SCENE_WIDTH, SCENE_HEIGHT), "My 2D game");
    window.setFramerateLimit(120);
    return 0;
}
/**
 * Background initializer.
 */
int Game::initBackground()
{
    if (!backgroundTexture.loadFromFile("resources/background.png"))
    {
        return 1;
    }
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT));
    return 0;
}

/**
 * Player (e.g. PacMan) initializer
 * @return 0 if successfully initialized, 1 otherwise
 */
int Game::initPlayer()
{
    player.setRadius(RADIUS);
    player.setOrigin(RADIUS, RADIUS);
    player.setPosition(PLAYER_START_X, PLAYER_START_Y);
    if (!playerTexture.loadFromFile("resources/pacman.png"))
    {
        return 1;
    }
    player.setTexture(&playerTexture);
    return 0;
}

/**
 * Dealing with events on window.
 */

void Game::processInput()
{
    sf::Event event;

    float step = 5.0f; // Step size for movement

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Right)
            {
                if (player.getPosition().x + step + RADIUS <= SCENE_WIDTH)
                    player.move(step, 0.0f); // Move right
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                if (player.getPosition().x - step - RADIUS >= 0)
                    player.move(-step, 0.0f); // Move left
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                if (player.getPosition().y - step - RADIUS >= 0)
                    player.move(0.0f, -step); // Move up
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                if (player.getPosition().y + step + RADIUS <= SCENE_HEIGHT)
                    player.move(0.0f, step); // Move down
            }
            break;
        default:
            break;
        }
    }
}

/**
 * Function to update the position of the player
 */
void Game::update()
{
    float speed = 5.0f; // Adjust movement speed if needed

    if (moveRight)
        printf("right key pressed\n");
    if (moveLeft)
        player.move(-speed, 0.0f); // Move left
    if (moveUp)
        player.move(0.0f, -speed); // Move up
    if (moveDown)
        player.move(0.0f, speed); // Move down
}

/**
 * Render elements in the window
 */
void Game::render()
{
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    window.display();
}
/**
 * Main function to deal with events, update the player and render the updated scene on the window.
 */
int Game::run()
{
    while (window.isOpen())
    {
        processInput();
        update();
        render();
    }
    return 0;
}