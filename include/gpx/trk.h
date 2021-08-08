#pragma once

#include <vector>

#include "rapidxml.hpp"

namespace gpx {

/**
 * Reference
 * https://www.topografix.com/GPX/1/1/#type_trkType
 */
class Trk {
   public:
    Trk(rapidxml::xml_node<> *node);

   private:
};
}  // namespace gpx
