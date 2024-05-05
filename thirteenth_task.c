/*#include <stdio.h>
#include <stdbool.h>
#include "tasks/string_.h"

#define MAX_WORDS 100

// Макрос для удобства проверки строк
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Функция для сравнения двух слов
bool areEqualWords(const char *word1, const char *word2) {
    while (*word1 != '\0' && *word2 != '\0') {
        if (*word1 != *word2) {
            return false;
        }
        word1++;
        word2++;
    }
    return *word1 == '\0' && *word2 == '\0';
}

// Функция для определения наличия повторяющихся слов в строке
bool hasDuplicateWords(const char *s) {
    char words[MAX_WORDS][MAX_STRING_SIZE]; // Массив для хранения слов
    int wordCount = 0;

    const char *start = s;

    while (*start != '\0') {
        // Находим начало текущего слова (пропускаем пробелы)
        start = findNonSpace((char *)start);
        if (*start == '\0') {
            break; // Если достигнут конец строки, выходим из цикла
        }

        // Находим конец текущего слова (первый пробел или конец строки)
        const char *end = findSpace((char *)start);
        if (end == start) {
            break; // Если конец текущего слова совпадает с началом, выходим из цикла
        }

        // Копируем текущее слово в буфер и вычисляем его длину
        size_t length = end - start;
        copy(start, end, words[wordCount]);
        words[wordCount][length] = '\0'; // Добавляем завершающий нуль-символ

        // Проверяем, содержится ли это слово уже в массиве
        bool foundDuplicate = false;
        for (int i = 0; i < wordCount; i++) {
            if (areEqualWords(words[i], words[wordCount])) {
                foundDuplicate = true;
                break;
            }
        }

        if (foundDuplicate) {
            return true; // Найдено повторение слова
        }

        // Добавляем слово в массив, если есть место
        if (wordCount < MAX_WORDS) {
            wordCount++;
        }

        // Переходим к началу следующего слова
        start = end + 1; // Пропускаем пробелы после текущего слова
    }

    return false; // Одинаковых слов не найдено
}


// Функция для сравнения строк и вывода сообщения в случае несоответствия
void assertString(const char *expected, char *got, const char *fileName, const char *funcName, int line) {
    if (my_strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Функция для тестирования hasDuplicateWords
void runTests() {
    // Тест 1: Проверка строки без повторяющихся слов
    const char *s1 = "this is a test string without duplicates";
    bool result1 = hasDuplicateWords(s1);
    ASSERT_STRING("The string does not contain duplicate words.", result1 ? "The string contains duplicate words." : "The string does not contain duplicate words.");

    // Тест 2: Проверка строки с повторяющимися словами
    const char *s2 = "this is a test string with duplicate words test is";
    bool result2 = hasDuplicateWords(s2);
    ASSERT_STRING("The string contains duplicate words.", result2 ? "The string contains duplicate words." : "The string does not contain duplicate words.");

    // Тест 3: Проверка пустой строки
    const char *s3 = "";
    bool result3 = hasDuplicateWords(s3);
    ASSERT_STRING("The string does not contain duplicate words.", result3 ? "The string contains duplicate words." : "The string does not contain duplicate words.");

    // Тест 4: Проверка строки с одним словом
    const char *s4 = "onlyone";
    bool result4 = hasDuplicateWords(s4);
    ASSERT_STRING("The string does not contain duplicate words.", result4 ? "The string contains duplicate words." : "The string does not contain duplicate words.");

    // Тест 5: Проверка строки с множественными пробелами
    const char *s5 = "   multiple      spaces       between     words   ";
    bool result5 = hasDuplicateWords(s5);
    ASSERT_STRING("The string does not contain duplicate words.", result5 ? "The string contains duplicate words." : "The string does not contain duplicate words.");
}

int main() {
    runTests();
    return 0;
}
*/