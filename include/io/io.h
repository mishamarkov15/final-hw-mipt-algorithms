#pragma once

#include <unordered_map>
#include <unordered_set>
#include <string>

#include "../analyzer.h"

namespace analyzer::io {
    /**
     * @brief Считывает список товаров из файла и преобразует их в токены.
     *
     * Ожидается формат строки:
     * ID<SPACE>Название товара
     *
     * При включённой предобработке выполняется
     * нормализация текстовых данных.
     *
     * @param filename Имя входного файла.
     * @return Отображение: ID товара → множество токенов.
     */
    std::unordered_map<std::string, TokenSet>
    read_items(const std::string &filename);
} // analyzer::io
