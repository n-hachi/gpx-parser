#include "gpx/parser.h"

#include <memory>
#include <sstream>
#include <vector>

#include "rapidxml.hpp"

namespace gpx {

std::unique_ptr<Gpx> Parse(std::istream *is) {
    /* Create xml_node */
    std::istreambuf_iterator<char> it{*is};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');
    rapidxml::xml_document<> doc;
    doc.parse<0>(&buf[0]);
    rapidxml::xml_node<> *node = doc.first_node();

    /* Create Gps instance */
    gpx::Gpx gpx(node);
    return std::make_unique<Gpx>(gpx);
}

}  // namespace gpx
