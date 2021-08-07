#pragma once

#include <string>

namespace gpx {
class Gpx {
   public:
    Gpx();

   private:
    /* attributes */
    std::string version_;
    std::string creator_;
};
}  // namespace gpx
