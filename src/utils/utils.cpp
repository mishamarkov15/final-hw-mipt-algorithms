#include "../../include/utils/utils.h"

#include <sstream>
#include <ranges>
#include <algorithm>
#include <cctype>
#include <iostream>

namespace analyzer::utils {
    std::string to_lower(std::string s) {
        std::ranges::transform(s, s.begin(),
                               [](unsigned char c) { return std::tolower(c); });
        return s;
    }

    std::string normalize(std::string s) {
        s = to_lower(s);

        for (char &c: s) {
            if (!std::isalnum(static_cast<unsigned char>(c)))
                c = ' ';
        }

        std::stringstream ss(s);
        std::string word, result;
        while (ss >> word) {
            result += word + ' ';
        }
        return result;
    }

    TokenSet tokenize(const std::string &s) {
        std::stringstream ss(s);
        return {
            std::istream_iterator<std::string>(ss),
            std::istream_iterator<std::string>()
        };
    }

    double jaccard(const TokenSet &a, const TokenSet &b) {
        size_t intersection = 0;
        for (const auto &token: a)
            intersection += b.contains(token);

        size_t uni = a.size() + b.size() - intersection;
        return uni == 0 ? 0.0 : static_cast<double>(intersection) / uni;
    }
} // analyzer::utils