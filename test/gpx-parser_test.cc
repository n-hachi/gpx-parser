#include <sstream>

#include "gpx/gpx.h"
#include "gtest/gtest.h"

/*
 * Tests for Gpx class constructor with minimam string.
 */
TEST(GpxTest, GpxMinimumTest) {
    std::istringstream ss(
        u8R"##(
<gpx
 version="1.1"
 creator="n-hachi">
</gpx>
)##");
    gpx::Gpx gpx(ss);
    EXPECT_EQ(gpx.version(), "1.1");
    EXPECT_EQ(gpx.creator(), "n-hachi");
}
