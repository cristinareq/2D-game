#include "game.h"
#include <iostream>
#include <random>

Ghost::Ghost(float x, float y, const sf::Texture &texture) : x(x), y(y)
{
    sprite.setTexture(texture);
    float originalWidth = sprite.getLocalBounds().width;
    float originalHeight = sprite.getLocalBounds().height;
    float desiredSize = 40.0f;
    sprite.setScale(desiredSize / originalWidth, desiredSize / originalHeight); // Scale the sprite
    sprite.setPosition(x, y);
}

void Ghost::draw(sf::RenderWindow &window)
{
    window.draw(sprite);
}
class Wall
{
public:
    float x, y, width, height;

    static std::vector<Wall> createWalls()
    {
        std::vector<Wall> walls;
        walls.push_back({200.0f, 100.0f, 20.0f, 202.0f});
        walls.push_back({400.0f, 300.0f, 300.0f, 22.0f});
        walls.push_back({131.0f, 600.0f, 300.0f, 22.0f});
        walls.push_back({600.0f, 500.0f, 20.0f, 202.0f});
        walls.push_back({750.0f, 140.0f, 100.0f, 22.0f});
        walls.push_back({130.0f, 500.0f, 20.0f, 102.0f});
        return walls;
    }
};

std::vector<Wall> walls = Wall::createWalls();

const float Game::SCENE_WIDTH = 998.0f;
const float Game::SCENE_HEIGHT = 800.0f;
const float Game::PLAYER_START_X = 500.0f;
const float Game::PLAYER_START_Y = 400.0f;
const float Game::RADIUS = 20.0f;

Game::Game() : rng(rd()), distX(0.0f, SCENE_WIDTH), distY(0.0f, SCENE_HEIGHT)
{
    initWindow();
    initBackground();
    initPlayer();
    initGhostTexture();
    initGhosts(); // Make sure this is called after initGhostTexture

    player.setPosition(PLAYER_START_X, PLAYER_START_Y);

    rightPressed = false;

    leftPressed = false;
    upPressed = false;
    downPressed = false;
}

int Game::initGhostTexture()
{
    if (!ghostTexture.loadFromFile("resources/ghost.png"))
    {
        return 1; // Error loading texture
    }
    return 0; // Successfully loaded
}
int Game::initWindow()
{
    window.create(sf::VideoMode(SCENE_WIDTH, SCENE_HEIGHT), "Updated 2D Game");
    window.setFramerateLimit(120);
    return 0;
}

int Game::initBackground()
{
    if (!backgroundTexture.loadFromFile("resources/background3.png"))
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

void Game::initGhosts()
{
    for (int i = 0; i < 6; ++i)
    {
        float x, y;
        do
        {
            x = distX(rng);
            y = distY(rng);
        } while (!isValidPosition(x, y)); // Updated to a new method
        ghosts.emplace_back(x, y, ghostTexture);
    }
}

void Game::update()
{
    float speed = 3.0f;

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

    for (auto it = ghosts.begin(); it != ghosts.end();)
    {
        if (player.getGlobalBounds().intersects(it->sprite.getGlobalBounds()))
        {
            it = ghosts.erase(it);
            spawnNewGhost();
        }
        else
        {
            ++it;
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

    for (auto &ghost : ghosts)
    {
        ghost.draw(window); // Check if this method is called
    }

    window.draw(player);
    window.display();
}

void Game::spawnNewGhost()
{
    float x, y;
    do
    {
        x = distX(rng);
        y = distY(rng);
    } while (!isValidPosition(x, y));
    ghosts.emplace_back(x, y, ghostTexture);
}

bool Game::isValidPosition(float x, float y)
{
    float ghostSize = 40.0f; // Size of the ghosts

    // Check if the position is within the game window
    if (x < 0 || x + ghostSize > SCENE_WIDTH || y < 0 || y + ghostSize > SCENE_HEIGHT)
    {
        return false;
    }

    sf::FloatRect newGhostBounds(x, y, ghostSize, ghostSize);

    // Check for intersection with walls
    for (const auto &wall : walls)
    {
        sf::FloatRect wallBounds(wall.x, wall.y, wall.width, wall.height);
        if (newGhostBounds.intersects(wallBounds))
        {
            return false;
        }
    }

    // Check for intersection with existing ghosts
    for (const auto &ghost : ghosts)
    {
        if (newGhostBounds.intersects(ghost.sprite.getGlobalBounds()))
        {
            return false;
        }
    }

    return true; // Position is valid if all checks are passed
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