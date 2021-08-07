#include "gpx/gpx.h"

#include <string.h>

#include <iostream>
#include <string>
#include <vector>

#include "rapidxml.hpp"

namespace gpx {

Gpx::Gpx(rapidxml::xml_node<> *node) {
    bool is_version = false;
    bool is_creator = false;
    for (rapidxml::xml_attribute<> *attr = node->first_attribute(); attr;
         attr = attr->next_attribute()) {
        if (strcmp(attr->name(), "version") == 0) {
            is_version = true;
            version_ = attr->value();
        }
        if (strcmp(attr->name(), "creator") == 0) {
            is_creator = true;
            creator_ = attr->value();
        }
    }
}

}  // namespace gpx
