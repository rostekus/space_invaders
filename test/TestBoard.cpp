#include <boost/test/unit_test.hpp>

#include "gameboard.hpp"
#include "config.hpp"

BOOST_AUTO_TEST_SUITE(TestBoard)

BOOST_AUTO_TEST_CASE(testBoardDim)
{
    Board b();
    // BOOST_CHECK_EQUAL(b.getWidth(), DEFAULT_BOARD_WIDTH - 1);
    // BOOST_CHECK_EQUAL(b.getHeight(), DEFAULT_BOARD_HEIGHT - 1);
}

BOOST_AUTO_TEST_SUITE_END()
