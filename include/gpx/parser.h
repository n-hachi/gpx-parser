#pragma once

#include <istream>
#include <memory>

#include "gpx/gpx.h"

namespace gpx {
std::unique_ptr<Gpx> Parse(std::istream *is);
}  // namespace gpx
