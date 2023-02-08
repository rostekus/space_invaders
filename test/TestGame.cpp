#include <boost/test/unit_test.hpp>

#include "game.hpp"
#include "enemy.hpp"
#include "config.hpp"

BOOST_AUTO_TEST_SUITE(TestGame)

BOOST_AUTO_TEST_CASE(testEnemyHitPlayer)
{
    Game *game = new Game();
    game->addPlayerToBoard();
    int posXEnemy = game->getPlayer()->getposX();
    int posYEnemy = game->getPlayer()->getposY() + 1;
    game->getBoard()->addObject(new Enemy(posXEnemy, posYEnemy));
    game->checkAlienHitPlayer();
    BOOST_CHECK_EQUAL(DEF_LIVES - 1, game->getPlayer()->getLives());
}

BOOST_AUTO_TEST_CASE(testBreakLoopWhenGameOver)
{
    Game *game = new Game();
    game->addPlayerToBoard();
    for (int i = 0; i <= DEF_LIVES; i++)
    {
        game->getPlayer()->loseLife();
    }
    game->runGame();
    BOOST_CHECK_EQUAL(game->checkGameOver(), true);
}

BOOST_AUTO_TEST_SUITE_END()
