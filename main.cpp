#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <locale>
#include <codecvt>

//Логика 
std::wstring process_string(const std::wstring &input) {
    std::wstring lowercase_input = input;

    // Стерение капитализации
    std::transform(input.begin(), input.end(), lowercase_input.begin(), ::towlower);

    // Хэш сэт для отслеживания чистоты букв
    std::unordered_map<wchar_t, int> char_count;
    for (wchar_t c : lowercase_input) {
        char_count[c]++;
    }

    // вывод 
    std::wstring output;
    for (size_t i = 0; i < input.size(); ++i) {
        if (char_count[lowercase_input[i]] == 1) {
            output.push_back(L'(');
        } else {
            output.push_back(L')');
        }
    }

    return output;
}

int main() {

    // Конфигурация кириллицы в стадартном выводе 
    std::ios::sync_with_stdio(false);
    std::wcin.imbue(std::locale("en_US.UTF-8"));
    std::wcout.imbue(std::locale("en_US.UTF-8"));

    std::wstring input;
    std::getline(std::wcin, input);

    std::wstring output = process_string(input);

    std::wcout << output << std::endl;

    return 0;
}
