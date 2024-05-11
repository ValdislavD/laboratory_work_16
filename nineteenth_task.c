/*#include <stdio.h>
#include "tasks/string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,
                  const char *fileName, const char *funcName,
                  int line) {
    if (my_strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

int containsAllLetters(const char *str, const char *word) {
    const char *wordPtr = word;

    // Итерируемся по каждой букве в слове
    while (*wordPtr != '\0') {
        const char *strPtr = str;
        int found = 0;

        // Ищем текущую букву слова в строке
        while (*strPtr != '\0') {
            if (*strPtr == *wordPtr) {
                found = 1;
                break;
            }
            strPtr++;
        }

        // Если текущая буква слова не найдена в строке
        if (!found) {
            return 0;
        }

        // Переходим к следующей букве слова
        wordPtr++;
    }

    // Все буквы слова найдены в строке
    return 1;
}

void testContainsAllLetters() {
    const char *str = "hello world";
    const char *word1 = "dlrow";
    const char *word2 = "hello";
    const char *word3 = "world";
    const char *word4 = "dlwos";

    ASSERT_STRING("OK", containsAllLetters(str, word1) ? "OK" : "Not OK");
    ASSERT_STRING("OK", containsAllLetters(str, word2) ? "OK" : "Not OK");
    ASSERT_STRING("OK", containsAllLetters(str, word3) ? "OK" : "Not OK");
    ASSERT_STRING("Not OK", containsAllLetters(str, word4) ? "OK" : "Not OK");
}

int main() {
    testContainsAllLetters();
    return 0;
}*/