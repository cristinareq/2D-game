#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

enum class Direction
{
    None,
    Left,
    Right,
    Up,
    Down
};

class Ghost
{
public:
    float x, y;
    sf::Sprite sprite;

    Ghost(float x, float y, const sf::Texture &texture);

    void draw(sf::RenderWindow &window);
};

class Game
{
public:
    Game();
    int run();

private:
    sf::RenderWindow window;
    sf::Sprite background;
    sf::Texture backgroundTexture;
    sf::Texture playerTexture;
    sf::CircleShape player;
    sf::Texture ghostTexture;
    std::vector<Ghost> ghosts;

    std::random_device rd;
    std::mt19937 rng;
    std::uniform_real_distribution<float> distX, distY;

    static const float SCENE_WIDTH;
    static const float SCENE_HEIGHT;
    static const float PLAYER_START_X;
    static const float PLAYER_START_Y;
    static const float RADIUS;

    bool rightPressed;
    bool leftPressed;
    bool upPressed;
    bool downPressed;

    bool leftBlocked;
    bool rightBlocked;
    bool upBlocked;
    bool downBlocked;

    Direction lastDirection;

    int initWindow();
    int initBackground();
    int initPlayer();
    void processInput();
    void update();
    void render();
    void initGhosts();
    void spawnNewGhost();
    int initGhostTexture();
    bool isValidPosition(float x, float y);
};
