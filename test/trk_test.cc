#include "gpx/trk.h"

#include <sstream>
#include <stdexcept>

#include "gtest/gtest.h"

/*
 * Tests for Trk class constructor with minimam string.
 */
TEST(TrkTest, TrkMinimumTest) {
    // Sample input
    std::istringstream ss(
        u8R"##(
<trk>
</trk>
)##");

    /* Create xml_node */
    std::istreambuf_iterator<char> it{ss};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);
    rapidxml::xml_node<> *node = doc.first_node();

    // Create trk
    EXPECT_NO_THROW((gpx::Trk(node)));
}

/*
 * Tests for Trk class constructor with unproper string.
 */
TEST(TrkTest, TrkUnproperArgumentTest) {
    // Sample input
    std::istringstream ss(
        u8R"##(
<unproper_tag>
</unproper_tag>
)##");

    /* Create xml_node */
    std::istreambuf_iterator<char> it{ss};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);
    rapidxml::xml_node<> *node = doc.first_node();

    // Create trk
    EXPECT_THROW((gpx::Trk(node)), std::invalid_argument);
}
