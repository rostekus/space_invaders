#include <boost/test/unit_test.hpp>

#include "enemy.hpp"
#include "config.hpp"

BOOST_AUTO_TEST_SUITE(TestEnemy)

BOOST_AUTO_TEST_CASE(testEnemyTakeDemage)
{
    Enemy e;
    e.takeDamage(10);
    BOOST_CHECK_EQUAL(90, DEF_HEALTH - 10);
}

BOOST_AUTO_TEST_SUITE_END()
