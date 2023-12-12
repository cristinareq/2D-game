#include "game.h"
#include <gtest/gtest.h>
#include <SFML/Graphics.hpp>

class GameTest : public ::testing::Test
{
protected:
    Game game;

    void SetUp() override
    {
        game.initWindow();
        game.initBackground();
        game.initPlayer();
        game.initGhostTexture();
        game.initGhosts();
    }
};

TEST_F(GameTest, GameComponentsInitialization)
{
    game.initWindow();
    EXPECT_NE(&game.window, nullptr); // Directly accessing the public member 'window'

    game.initBackground();
    EXPECT_TRUE(game.background.getTexture() != nullptr); // Directly accessing the public member 'background'
}

TEST_F(GameTest, PlayerInitialPosition)
{
    game.initPlayer();
    EXPECT_FLOAT_EQ(game.player.getPosition().x, Game::PLAYER_START_X); // Directly accessing the public member 'player'
    EXPECT_FLOAT_EQ(game.player.getPosition().y, Game::PLAYER_START_Y);
}

class GhostTest : public ::testing::Test
{
protected:
    sf::Texture texture;
    Ghost ghost{0, 0, texture};

    void SetUp() override
    {
    }
};

TEST_F(GhostTest, GhostInitialization)
{
    EXPECT_FLOAT_EQ(ghost.x, 0);
    EXPECT_FLOAT_EQ(ghost.y, 0);
    // Check if sprite is set correctly
    EXPECT_TRUE(ghost.sprite.getTexture() == &texture);
}

TEST_F(GameTest, GhostMovementLogic)
{
    sf::Time elapsedTime = sf::seconds(1.0f);
    std::vector<sf::FloatRect> walls;
    std::mt19937 rng;
    float maxX = Game::SCENE_WIDTH;
    float maxY = Game::SCENE_HEIGHT;
    for (auto &ghost : game.ghosts)
    {
        sf::Vector2f oldPos = ghost.sprite.getPosition();
        ghost.updateghost(maxX, maxY, walls, rng, elapsedTime);
        sf::Vector2f newPos = ghost.sprite.getPosition();
        // Check if the ghost has moved
        EXPECT_FALSE(oldPos == newPos);
    }
}
// Test for Pac-Man wall collision
TEST_F(GameTest, PacmanWallCollision)
{
    game.initPlayer();

    // Assuming player starts in a position where it can move without collision
    game.player.setPosition(Game::PLAYER_START_X, Game::PLAYER_START_Y);

    // Simulate movement towards a wall
    // Assuming there is a method to move the player and check for collisions
    game.processInput(); // Simulate input for movement
    game.update();       // Update game state, including collision checks

    // Check if wall collision is detected and handled
    EXPECT_EQ(game.wallCollisions, 1); // Assuming wallCollisions is incremented on collision
}

// Test for Pac-Man ghost collision
TEST_F(GameTest, PacmanGhostCollision)
{
    game.initPlayer();
    game.initGhosts();

    // Place Pac-Man in a position to collide with a ghost
    game.player.setPosition(game.ghosts[0].sprite.getPosition().x, game.ghosts[0].sprite.getPosition().y);

    int initialGhostsEaten = game.ghostsEaten;

    // Update game to process collision
    game.update(); // This should include collision checking

    // Check if ghost collision is detected and handled
    EXPECT_EQ(game.ghostsEaten, initialGhostsEaten + 1); // Assuming ghostsEaten is incremented on eating a ghost
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}