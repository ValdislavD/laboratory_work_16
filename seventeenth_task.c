/*#include <stdio.h>
#include "tasks/string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Функция для проверки строки с помощью assertString
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

// Функция определяет, является ли слово палиндромом
int isPalindrome(char *begin, char *end) {
    char *left = begin;
    char *right = end - 1;

    while (left < right) {
        if (*left != *right) {
            return 0;  // Не палиндром
        }
        left++;
        right--;
    }
    return 1;  // Палиндром
}

// Функция удаляет слова-палиндромы из строки
void removePalindromes(char *str) {
    char *curr = findNonSpace(str);  // Найти первый символ
    char *end = curr;
    int isFirstWord = 1;  // Флаг для определения первого слова

    while (*end != '\0') {
        if (*end == ' ' || *end == '\t') {
            if (curr != end) {  // Есть слово между curr и end
                if (!isPalindrome(curr, end)) {  // Проверяем, не палиндром ли это слово
                    if (!isFirstWord) {
                        *str++ = ' ';  // Добавляем пробел перед словом (кроме первого слова)
                    }
                    copy(curr, end, str);  // Копируем слово обратно в строку
                    str += (end - curr);  // Сдвигаем указатель str
                    isFirstWord = 0;  // Сбрасываем флаг первого слова
                }
            }
            curr = findNonSpace(end);  // Найти следующий символ
        }
        end++;
    }

    // Обрабатываем последнее слово, если оно не палиндром
    if (curr != end && !isPalindrome(curr, end)) {
        if (!isFirstWord) {
            *str++ = ' ';  // Добавляем пробел перед словом (кроме первого слова)
        }
        copy(curr, end, str);  // Копируем последнее слово обратно в строку
        str += (end - curr);  // Сдвигаем указатель str
    }

    *str = '\0';  // Завершаем строку
}

// Функция для тестирования удаления палиндромов из строки
void testRemovePalindromes() {
    // Тест 1: Удаляем палиндромы из строки с несколькими словами
    {
        char str[] = "abc deed level xyz radar";  // Исходная строка
        char expected[] = "abc xyz";  // Ожидаемый результат после удаления палиндромов

        // Вызываем функцию, которую мы тестируем
        removePalindromes(str);

        // Проверяем результат с ожидаемым значением
        ASSERT_STRING(expected, str);
    }

    // Тест 2: Удаляем палиндромы из строки, где все слова являются палиндромами
    {
        char str[] = "deed deed deed deed";  // Исходная строка (все слова - палиндромы)
        char expected[] = "";  // Ожидаемый результат после удаления палиндромов

        // Вызываем функцию, которую мы тестируем
        removePalindromes(str);

        // Проверяем результат с ожидаемым значением
        ASSERT_STRING(expected, str);
    }

    // Тест 3: Удаляем палиндромы из строки, где нет палиндромов
    {
        char str[] = "hello world example";  // Исходная строка (нет палиндромов)
        char expected[] = "hello world example";  // Ожидаемый результат - строка остается неизменной

        // Вызываем функцию, которую мы тестируем
        removePalindromes(str);

        // Проверяем результат с ожидаемым значением
        ASSERT_STRING(expected, str);
    }
}

int main() {
    // Запускаем тестовую функцию
    testRemovePalindromes();

    return 0;
}
*/