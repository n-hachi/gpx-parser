#pragma once

#include <istream>
#include <string>

#include "rapidxml.hpp"

namespace gpx {
class Gpx {
   public:
    Gpx(rapidxml::xml_node<> *node);

    /* getter */
    std::string version() const { return version_; }
    std::string creator() const { return creator_; }

   private:
    /* attributes */
    std::string version_;
    std::string creator_;
};
}  // namespace gpx
