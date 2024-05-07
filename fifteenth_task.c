/*#include <stdio.h>
#include <stdbool.h>
#include "tasks/string_.h"

#define MAX_STRING_SIZE 100
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Функция для поиска слов в строке, отличных от последнего слова
void getStringWithoutLastWord(const char *s, char *result) {
    int i = 0;
    int lastWordStart = 0;
    int lastWordEnd = 0;
    int previousChar = ' ';

    // Находим начало и конец последнего слова в строке
    while (s[i] != '\0') {
        if (s[i] != ' ' && previousChar == ' ') {
            lastWordStart = i;
        }
        if (s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0')) {
            lastWordEnd = i;
        }
        previousChar = s[i];
        i++;
    }

    // Убираем пробел перед последним словом, если он есть
    if (lastWordEnd > lastWordStart && s[lastWordEnd] == ' ') {
        lastWordEnd--; // Игнорируем пробел перед последним словом
    }

    // Формируем новую строку без последнего слова
    int j = 0;
    i = 0;
    bool skipSpace = false;
    while (s[i] != '\0') {
        if (i >= lastWordStart && i <= lastWordEnd) {
            skipSpace = true;
            i++;
            continue; // Пропускаем последнее слово
        }

        if (s[i] == ' ' && skipSpace) {
            i++;
            continue; // Пропускаем лишний пробел перед последним словом
        }

        result[j++] = s[i++];
        skipSpace = false;
    }

    // Удаляем лишний пробел в конце результирующей строки, если он есть
    if (j > 0 && result[j - 1] == ' ') {
        result[j - 1] = '\0'; // Устанавливаем нулевой символ вместо пробела
    } else {
        result[j] = '\0'; // Завершаем строку-результат
    }
}

// Функция для сравнения строк с использованием assertString
void assertString(const char *expected, const char *got, const char *fileName, const char *funcName, int line) {
    if (my_strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Тестовая функция для проверки getStringWithoutLastWord
void testGetStringWithoutLastWord() {
    const char *s1 = "this is a test string with some words";
    char result1[MAX_STRING_SIZE + 1];
    getStringWithoutLastWord(s1, result1);
    ASSERT_STRING("this is a test string with some", result1);

    const char *s2 = "one";
    char result2[MAX_STRING_SIZE + 1];
    getStringWithoutLastWord(s2, result2);
    ASSERT_STRING("", result2);

    const char *s3 = "hello world";
    char result3[MAX_STRING_SIZE + 1];
    getStringWithoutLastWord(s3, result3);
    ASSERT_STRING("hello", result3);

    const char *s4 = "singleword";
    char result4[MAX_STRING_SIZE + 1];
    getStringWithoutLastWord(s4, result4);
    ASSERT_STRING("", result4);
}

int main() {
    testGetStringWithoutLastWord();
    return 0;
}
*/