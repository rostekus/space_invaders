#include <boost/test/unit_test.hpp>

#include "missile.hpp"
#include "config.hpp"

BOOST_AUTO_TEST_SUITE(TestMissle)

BOOST_AUTO_TEST_CASE(testMissleInit)
{
    Missile m(true);
    BOOST_CHECK_EQUAL(m.getFriendly(), true);
}
BOOST_AUTO_TEST_CASE(testMissleSecodInit)
{
    Missile m(false, 1, 1);
    BOOST_CHECK_EQUAL(m.getFriendly(), false);
}
BOOST_AUTO_TEST_SUITE_END()
