#include "../../include/io/io.h"

#include <fstream>
#include <iostream>
#include <format>

#include "../../include/utils/utils.h"

namespace analyzer::io {
    std::unordered_map<std::string, TokenSet>
    read_items(const std::string &filename) {
        using namespace analyzer::utils;

        std::ifstream in(filename);
        if (!in.is_open()) {
            std::cerr << std::format("Failed to open file '{}'\n", filename);
            exit(EXIT_FAILURE);
        }
        std::unordered_map<std::string, TokenSet> items;

        for (std::string line; std::getline(in, line);) {
            auto pos = line.find(' ');
            if (pos == std::string::npos) continue;

            std::string id = line.substr(0, pos);
            std::string name = line.substr(pos + 1);

            if (USE_PREPROCESSING) {
                name = normalize(name);
            }

            items[id] = tokenize(name);
        }

        in.close();
        return items;
    }
} // analyzer::io
