#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "../analyzer.h"

namespace analyzer::io {
    std::unordered_map<std::string, TokenSet>
    read_items(const std::string &filename);
} // analyzer::io
