#include <boost/test/unit_test.hpp>

#include "player.hpp"
#include "config.hpp"

BOOST_AUTO_TEST_SUITE(TestPlayer)

BOOST_AUTO_TEST_CASE(testPlayerLivesNumber)
{
    Player p;
    BOOST_CHECK_EQUAL(p.getLives(), DEF_LIVES);
}

BOOST_AUTO_TEST_CASE(testPlayerMoveRight)
{
    Player p(0, 0);
    p.moveRight();
    BOOST_CHECK_EQUAL(p.getposX(), 1);
    BOOST_CHECK_EQUAL(p.getposY(), 0);
    p.moveRight();
    BOOST_CHECK_EQUAL(p.getposX(), 2);
    BOOST_CHECK_EQUAL(p.getposY(), 0);
}
BOOST_AUTO_TEST_CASE(testPlayerMoveLeft)
{
    Player p(10, 0);
    p.moveLeft();
    BOOST_CHECK_EQUAL(p.getposX(), 9);
    BOOST_CHECK_EQUAL(p.getposY(), 0);
    p.moveLeft();
    BOOST_CHECK_EQUAL(p.getposX(), 8);
    BOOST_CHECK_EQUAL(p.getposY(), 0);
}

BOOST_AUTO_TEST_CASE(testPlayerShoot)
{
    Player p(10, 10);
    Missile m = p.shoot();
    BOOST_CHECK_EQUAL(m.getFriendly(), true);
    BOOST_CHECK_EQUAL(m.getPosX(), 10);
    BOOST_CHECK_EQUAL(m.getPosY(), 11);
}

BOOST_AUTO_TEST_SUITE_END()
