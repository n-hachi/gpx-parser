#pragma once

#include <istream>
#include <string>

namespace gpx {
class Gpx {
   public:
    Gpx(std::istream *is);

    /* getter */
    std::string version() const { return version_; }
    std::string creator() const { return creator_; }

   private:
    /* attributes */
    std::string version_;
    std::string creator_;
};
}  // namespace gpx
