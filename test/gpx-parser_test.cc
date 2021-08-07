#include <sstream>

#include "gpx/gpx.h"
#include "gtest/gtest.h"

/*
 * Tests for Gpx class constructor with minimam string.
 */
TEST(GpxTest, GpxMinimumTest) {
    // Sample input
    std::istringstream ss(
        u8R"##(
<gpx
 version="1.1"
 creator="n-hachi">
</gpx>
)##");

    /* Create xml_node */
    std::istreambuf_iterator<char> it{ss};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);
    rapidxml::xml_node<> *node = doc.first_node();

    // Create gpx
    gpx::Gpx gpx(node);

    EXPECT_EQ(gpx.version(), "1.1");
    EXPECT_EQ(gpx.creator(), "n-hachi");
}
