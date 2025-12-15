#pragma once

#include <unordered_set>
#include <string>

namespace analyzer {
    using TokenSet = std::unordered_set<std::string>;

    static constexpr double SIMILARITY_THRESHOLD = 0.8;
    static constexpr bool USE_PREPROCESSING = true;
} // analyzer
