#include "gpx/trk.h"

#include <cstring>
#include <stdexcept>

#include "rapidxml.hpp"

namespace gpx {
Trk::Trk(rapidxml::xml_node<> *node) {
    // error case
    if (node == nullptr) {
        throw std::invalid_argument("Arguments is null.");
    }

    // not match node name
    if (std::strcmp(node->name(), "trk")) {
        throw std::invalid_argument("Node name must be 'trk'");
    }

    for (rapidxml::xml_node<> *child_node = node->first_node(); child_node;
         child_node = child_node->next_sibling()) {
        /* TODO
         * Need to check child name is trkseg or not. */
    }
}
}  // namespace gpx
