#include "game.hpp"
#include "enemy.hpp"
#include "config.hpp"

Game::Game()
{
    board = new Board();
    player = new Player(floor(board->getWidth() / 2), board->getHeight() - 1);
    round = 0;
    midSpace = floor(board->getWidth() / 2);
    numRows = 2;
    numCols = 4;
}
Game::~Game()
{
    delete this->board;
    delete this->player;
}

void Game::addPlayerToBoard()
{
    this->board->addObject(this->player);
}
void Game::populateBoardwithEnemy()
{
    for (int i = 0; i < this->numRows; i++)
    {
        for (int j = 0; j < this->numCols; j++)
        {
            Enemy *enemy = new Enemy(this->midSpace - (this->numCols / 2) + j, i + 1);
            this->board->addObject(new Enemy(this->midSpace - (this->numCols / 2) + j, i + 1));
        }
    }
}

void Game::runGame()
{
    while (true)
    {
        // Check if game is over
        if (this->checkGameOver())
        {
            break;
        }
        // Next round
        if (this->board->getObjects(ENEMY_REP).size() == 0)
        {
            this->nextRound();
        }
        // Player loses life when aliens hit bottom
        this->checkAlienHitPlayer();
        // Update board
        this->board->update();
        // Move player
        this->movePlayer();
    }
}

bool Game::checkGameOver()
{
    if (this->player->getLives() <= 0)
    {
        this->isGameOver = true;
        return true;
    }
    return false;
}

void Game::movePlayer()
{
    int c = this->board->getInput();
    switch (c)
    {
    case RIGHT_KEY:
        if (this->player->getPosX() < this->board->getWidth() - 1)
        {
            this->player->moveRight();
        }
        break;
    case LEFT_KEY:
        if (this->player->getPosX() > 1)
        {
            this->player->moveLeft();
        }
        break;
    case UP_KEY:
        Missile *p = new Missile(true, this->player->getPosX(), this->player->getPosY() - 1);
        this->board->addObject(new Missile(true, this->player->getPosX(), this->player->getPosY() - 1));
        break;
    }
}

void Game::nextRound()
{

    this->round++;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            Enemy *enemy = new Enemy(this->midSpace - (this->numCols / 2) + j, i + 1, this->round);
            board->addObject(new Enemy(this->midSpace - (this->numCols / 2) + j, i + 1, this->round));
        }
    }
}

void Game::checkAlienHitPlayer()
{
    auto aliens = this->board->getObjects(ENEMY_REP);
    for (auto &enemy : aliens)
    {
        if (enemy->getPosY() > this->player->getPosY())
        {
            this->player->loseLife();
        }
    }
}
Board *Game::getBoard()
{
    return this->board;
}
Player *Game::getPlayer()
{
    return this->player;
}