#pragma once
#include <SFML/Graphics.hpp>

enum class Direction
{
    None,
    Left,
    Right,
    Up,
    Down
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
};
