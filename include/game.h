#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include <chrono>

enum class Direction
{
    None,
    Left,
    Right,
    Up,
    Down
};

class Bomb
{
public:
    float x, y;
    sf::Sprite sprite;

    Bomb(float x, float y, const sf::Texture &texture);

    void draw(sf::RenderWindow &window);

private:
    std::vector<Bomb> bombs;
    sf::Texture bombTexture;
    sf::Clock bombSpawnClock;
    static const sf::Time BombSpawnInterval;
};

class Ghost
{
public:
    float x, y;
    sf::Sprite sprite;

    Ghost(float x, float y, const sf::Texture &texture);

    void draw(sf::RenderWindow &window);
    void updateghost(float maxX, float maxY, const std::vector<sf::FloatRect> &walls, std::mt19937 &rng, sf::Time elapsedTime);

private:
    sf::Time moveTimer; // Timer to control movement interval
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

    std::vector<Bomb> bombs;
    sf::Texture bombTexture;
    sf::Clock bombSpawnClock;

    sf::Sprite endGameBackground;
    sf::Texture endGameBackgroundTexture;
    bool gameEnded = false;

    std::random_device rd;
    std::mt19937 rng;
    std::uniform_real_distribution<float> distX, distY;

    sf::Clock gameClock;
    sf::Text timerText;
    sf::Font font;

    sf::Time lastUpdateTime;
    static const sf::Time UpdateInterval;
    static const std::string FONT_PATH;

    int ghostsEaten;
    int wallCollisions;
    bool isColliding;

    static const float SCENE_WIDTH;
    static const float SCENE_HEIGHT;
    static const float PLAYER_START_X;
    static const float PLAYER_START_Y;
    static const float RADIUS;

    static const sf::Time BombSpawnInterval; // Only declaration

    bool rightPressed;
    bool leftPressed;
    bool upPressed;
    bool downPressed;

    bool leftBlocked;
    bool rightBlocked;
    bool upBlocked;
    bool downBlocked;

    bool touchingLeftBorder = false;
    bool touchingRightBorder = false;
    bool touchingTopBorder = false;
    bool touchingBottomBorder = false;

    Direction lastDirection;

    int initWindow();
    int initBackground();
    int initPlayer();
    void processInput();
    void update();
    void render();
    void initGhosts();
    void initBombs();
    void initTimer();
    void updateTimer();
    void spawnNewGhost();
    void spawnNewBomb();
    int initGhostTexture();
    int initBombTexture();
    bool isValidPosition(float x, float y);
    void resetMovementFlags();
    void endGame();
};
