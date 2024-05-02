#include <stdio.h>
#include "tasks/string_.h"

// Макрос для проверки и вывода результатов с использованием assertInt
#define ASSERT_INT(expected, got) assertInt(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Функция для проверки, является ли слово палиндромом
int isPalindrome(const char *begin, const char *end) {
    while (begin < end) {
        if (*begin != *end) {
            return 0; // Не палиндром
        }
        begin++;
        end--;
    }
    return 1; // Палиндром
}

// Функция для подсчета количества слов-палиндромов в строке
int countPalindromeWords(const char *sentence) {
    int count = 0;
    const char *current = sentence;

    // Перебираем строку посимвольно
    while (*current != '\0') {
        // Пропускаем разделители (запятые)
        while (*current == ',') {
            current++;
        }

        // Начало очередного слова
        const char *start = current;

        // Ищем конец текущего слова (до запятой или конца строки)
        while (*current != ',' && *current != '\0') {
            current++;
        }

        // Конец очередного слова
        const char *end = current - 1;

        // Проверяем, является ли слово палиндромом
        if (start <= end && isPalindrome(start, end)) {
            count++;
        }
    }

    return count;
}

// Функция для сравнения целых чисел
void assertInt(int expected, int got, const char *fileName, const char *funcName, int line) {
    if (expected != got) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: %d\n", expected);
        fprintf(stderr, "Got: %d\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Тестовая функция для функции countPalindromeWords с использованием ASSERT_INT
void testCountPalindromeWords() {
    // Тест на пустую строку
    const char *input1 = "";
    ASSERT_INT(0, countPalindromeWords(input1)); // Ожидаем 0 палиндромов

    // Тест на строку с одним палиндромом
    const char *input2 = "level";
    ASSERT_INT(1, countPalindromeWords(input2)); // Ожидаем 1 палиндром

    // Тест на строку без палиндромов
    const char *input4 = "hello, world, civic";
    ASSERT_INT(0, countPalindromeWords(input4)); // Ожидаем 0 палиндромов

    // Тест на строку с пустыми словами
    const char *input5 = ",,";
    ASSERT_INT(0, countPalindromeWords(input5)); // Ожидаем 0 палиндромов

    // Тест на строку с одним символом (палиндромом)
    const char *input6 = "a, b, c, d, e";
    ASSERT_INT(1, countPalindromeWords(input6)); // Ожидаем 1 палиндром
}

int main() {
    testCountPalindromeWords();
    return 0;
}