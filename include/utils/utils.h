#pragma once

#include <string>

#include "../analyzer.h"

namespace analyzer::utils {

    std::string to_lower(std::string s);

    std::string normalize(std::string s);

    TokenSet tokenize(const std::string &s);

    double jaccard(const TokenSet &a, const TokenSet &b);

} // analyzer::utils