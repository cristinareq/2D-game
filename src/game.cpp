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

    // Declare the step variable outside of the switch statement
    float step = 5.0f; // Adjust the step size as needed

    // Create flags to track whether a key is currently pressed
    static bool rightPressed = false;
    static bool leftPressed = false;
    static bool upPressed = false;
    static bool downPressed = false;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            // Check if the corresponding key is already pressed
            if (event.key.code == sf::Keyboard::Right && !rightPressed)
            {
                player.move(step, 0.0f); // Move right
            }
            else if (event.key.code == sf::Keyboard::Left && !leftPressed)
            {
                player.move(-step, 0.0f); // Move left
            }
            else if (event.key.code == sf::Keyboard::Up && !upPressed)
            {
                player.move(0.0f, -step); // Move up
            }
            else if (event.key.code == sf::Keyboard::Down && !downPressed)
            {
                player.move(0.0f, step); // Move down
            }
            break;
        case sf::Event::KeyReleased:
            // Reset the corresponding key flag when released
            if (event.key.code == sf::Keyboard::Right)
                rightPressed = false;
            else if (event.key.code == sf::Keyboard::Left)
                leftPressed = false;
            else if (event.key.code == sf::Keyboard::Up)
                upPressed = false;
            else if (event.key.code == sf::Keyboard::Down)
                downPressed = false;
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