/**
 * @file main.cpp
 * @brief Итоговое задание по дисциплине
 *        «Алгоритмы и структуры данных».
 *
 * Реализация алгоритма нечёткого поиска
 * дублирующихся товарных предложений
 * с использованием коэффициента Жаккара.
 *
 * Язык: C++23
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <sstream>
#include <string>
#include <unordered_map>
#include <format>

#include "include/io/io.h"
#include "include/utils/utils.h"

/**
 * @brief Точка входа в программу.
 *
 * Выполняет:
 * - чтение входных файлов;
 * - сравнение новых товаров с каталогом;
 * - поиск дубликатов по коэффициенту Жаккара;
 * - сохранение результата в JSON-файл.
 *
 * @return Код завершения программы.
 */
int main(int argc, char **argv) {
    using namespace analyzer::io;
    using namespace analyzer::utils;

    auto catalog = read_items("catalog.txt");
    auto new_items = read_items("new_items.txt");

    const std::string out_file("duplicates.json");
    std::ofstream out(out_file);
    if (!out.is_open()) {
        std::cerr << std::format("Failed to open file '{}'", out_file);
        exit(EXIT_FAILURE);
    }
    out << "{\n";

    bool first_item = true;

    for (const auto &[new_id, new_tokens]: new_items) {
        if (!first_item) out << ",\n";
        first_item = false;

        out << "  \"" << new_id << "\": [";

        bool first_match = true;

        for (const auto &[cat_id, cat_tokens]: catalog) {
            double score = jaccard(new_tokens, cat_tokens);
            if (score >= analyzer::SIMILARITY_THRESHOLD) {
                if (!first_match) out << ",";
                first_match = false;

                out << "\n    { \"catalog_id\": \"" << cat_id
                        << "\", \"similarity_score\": "
                        << std::fixed << std::setprecision(2) << score << " }";
            }
        }

        if (!first_match) out << "\n  ";
        out << "]";
    }

    out << "\n}\n";
    std::cout << "Success!\n";
    return 0;
}
