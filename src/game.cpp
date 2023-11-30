#include "game.h"
#include <iostream>

class Wall
{
public:
    float x, y, width, height;

    static std::vector<Wall> createWalls()
    {
        std::vector<Wall> walls;

        Wall wall1;
        wall1.x = 200.0f;
        wall1.y = 100.0f;
        wall1.width = 20.0f;
        wall1.height = 200.0f;

        Wall wall2;
        wall2.x = 400.0f;
        wall2.y = 300.0f;
        wall2.width = 300.0f;
        wall2.height = 20.0f;

        walls.push_back(wall1);
        walls.push_back(wall2);

        return walls;
    }
};

std::vector<Wall> walls = Wall::createWalls();

const float Game::SCENE_WIDTH = 1000.0f;
const float Game::SCENE_HEIGHT = 800.0f;
const float Game::PLAYER_START_X = 500.0f;
const float Game::PLAYER_START_Y = 400.0f;
const float Game::RADIUS = 40.0f;

Game::Game() : lastDirection(Direction::None), leftBlocked(false), rightBlocked(false), upBlocked(false), downBlocked(false)
{
    initWindow();
    initBackground();
    initPlayer();

    player.setPosition(PLAYER_START_X, PLAYER_START_Y);

    rightPressed = false;
    leftPressed = false;
    upPressed = false;
    downPressed = false;
}

int Game::initWindow()
{
    window.create(sf::VideoMode(SCENE_WIDTH, SCENE_HEIGHT), "Updated 2D Game");
    window.setFramerateLimit(120);
    return 0;
}

int Game::initBackground()
{
    if (!backgroundTexture.loadFromFile("resources/background2.png"))
    {
        return 1;
    }
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT));
    return 0;
}

int Game::initPlayer()
{
    player.setRadius(RADIUS);
    player.setOrigin(RADIUS, RADIUS);
    if (!playerTexture.loadFromFile("resources/pacman.png"))
    {
        return 1;
    }
    player.setTexture(&playerTexture);
    return 0;
}

void Game::update()
{
    float speed = 1.0f;

    bool leftWallCollision = false;
    bool rightWallCollision = false;
    bool upWallCollision = false;
    bool downWallCollision = false;

    sf::FloatRect playerBounds = player.getGlobalBounds();

    for (const auto &wall : walls)
    {
        sf::FloatRect wallBounds(wall.x, wall.y, wall.width, wall.height);

        if (playerBounds.intersects(wallBounds))
        {
            if (player.getPosition().x < wall.x)
            {
                rightWallCollision = true;
            }
            else if (player.getPosition().x > wall.x + wall.width)
            {
                leftWallCollision = true;
            }

            if (player.getPosition().y < wall.y)
            {
                downWallCollision = true;
            }
            else if (player.getPosition().y > wall.y + wall.height)
            {
                upWallCollision = true;
            }
        }
    }

    if (!leftWallCollision && leftPressed)
    {
        if (player.getPosition().x - speed - RADIUS >= 0)
        {
            player.move(-speed, 0.0f);
        }
    }

    if (!rightWallCollision && rightPressed)
    {
        if (player.getPosition().x + speed + RADIUS <= SCENE_WIDTH)
        {
            player.move(speed, 0.0f);
        }
    }

    if (!upWallCollision && upPressed)
    {
        if (player.getPosition().y - speed - RADIUS >= 0)
        {
            player.move(0.0f, -speed);
        }
    }

    if (!downWallCollision && downPressed)
    {
        if (player.getPosition().y + speed + RADIUS <= SCENE_HEIGHT)
        {
            player.move(0.0f, speed);
        }
    }
}

void Game::processInput()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Left)
            {
                if (!leftBlocked)
                {
                    leftPressed = true;
                    lastDirection = Direction::Left;
                    rightPressed = false;
                    upPressed = false;
                    downPressed = false;
                    rightBlocked = false;
                    upBlocked = false;
                    downBlocked = false;
                }
            }
            else if (event.key.code == sf::Keyboard::Right)
            {
                if (!rightBlocked)
                {
                    rightPressed = true;
                    lastDirection = Direction::Right;
                    leftPressed = false;
                    upPressed = false;
                    downPressed = false;
                    leftBlocked = false;
                    upBlocked = false;
                    downBlocked = false;
                }
            }
            else if (event.key.code == sf::Keyboard::Up)
            {
                if (!upBlocked)
                {
                    upPressed = true;
                    lastDirection = Direction::Up;
                    leftPressed = false;
                    rightPressed = false;
                    downPressed = false;
                    leftBlocked = false;
                    rightBlocked = false;
                    downBlocked = false;
                }
            }
            else if (event.key.code == sf::Keyboard::Down)
            {
                if (!downBlocked)
                {
                    downPressed = true;
                    lastDirection = Direction::Down;
                    leftPressed = false;
                    rightPressed = false;
                    upPressed = false;
                    leftBlocked = false;
                    rightBlocked = false;
                    upBlocked = false;
                }
            }
            break;
        default:
            break;
        }
    }
}

void Game::render()
{
    window.clear(sf::Color::White);
    window.draw(background);
    window.draw(player);
    window.display();
}

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
