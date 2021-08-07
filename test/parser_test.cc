#include "gpx/parser.h"

#include <memory>
#include <sstream>

#include "gpx/gpx.h"
#include "gtest/gtest.h"

/*
 * Tests for Gpx class constructor with minimam string.
 */
TEST(ParserTest, ParserSimplestTest) {
    // Sample input
    std::istringstream ss(
        u8R"##(
<gpx
 version="1.1"
 creator="n-hachi">
</gpx>
)##");

    // Create gpx
    std::unique_ptr<gpx::Gpx> gpx = gpx::Parse(&ss);

    EXPECT_EQ(gpx->version(), "1.1");
    EXPECT_EQ(gpx->creator(), "n-hachi");
}
