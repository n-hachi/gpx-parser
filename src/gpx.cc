#include "gpx/gpx.h"

#include <iostream>
#include <string>
#include <vector>

#include "rapidxml.hpp"

namespace gpx {

Gpx::Gpx(std::istream *is) {
    std::istreambuf_iterator<char> it{*is};
    std::vector<char> buf(it, std::istreambuf_iterator<char>());
    buf.push_back('\0');
}

}  // namespace gpx
