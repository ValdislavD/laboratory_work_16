#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tasks/string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Функция assertString для сравнения строк и вывода сообщения об ошибке
void assertString(const char *expected, char *got,
                  const char *fileName, const char *funcName,
                  int line) {
    if (my_strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got:      \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

int my_strncmp(const char *str1, const char *str2, size_t n) {
    // Проходим по символам обеих строк до количества n или до первого отличия
    for (size_t i = 0; i < n; i++) {
        if (str1[i] != str2[i]) {
            // Если символы не совпадают, возвращаем разность их кодов ASCII
            return (int)(unsigned char)str1[i] - (int)(unsigned char)str2[i];
        }

        // Если дошли до конца одной из строк, завершаем сравнение
        if (str1[i] == '\0' || str2[i] == '\0') {
            break;
        }
    }

    // Если первые n символов идентичны, или мы достигли n символов, возвращаем 0
    return 0;
}

char* my_strncpy(char* dest, const char* src, size_t n) {
    char* original_dest = dest; // Сохраняем указатель на начало dest для возврата

    // Копируем не более n символов из src в dest
    while (n > 0 && *src != '\0') {
        *dest++ = *src++;
        n--;
    }

    // Дополняем dest нулевыми символами до n символов, если необходимо
    while (n > 0) {
        *dest++ = '\0';
        n--;
    }

    return original_dest; // Возвращаем указатель на начало dest
}


bool isWordInString(const char *word, const char *str) {
    const char *p = str;
    while (*p != '\0') {
        // Находим начало слова
        while (*p != '\0' && (*p == ' ' || *p == '\t')) {
            p++;
        }
        const char *wordStart = p;
        // Находим конец слова
        while (*p != '\0' && *p != ' ' && *p != '\t') {
            p++;
        }
        // Сравниваем найденное слово с искомым
        if (p - wordStart > 0 && my_strncmp(wordStart, word, p - wordStart) == 0) {
            return true;
        }
    }
    return false;
}

char* findPreviousWord(const char *s1, const char *s2) {
    const char *p1 = s1;
    const char *commonWord = NULL;

    // Находим первое общее слово между s1 и s2
    while (*p1 != '\0') {
        // Находим начало слова в s1
        while (*p1 != '\0' && (*p1 == ' ' || *p1 == '\t')) {
            p1++;
        }
        const char *wordStart = p1;
        // Находим конец слова в s1
        while (*p1 != '\0' && *p1 != ' ' && *p1 != '\t') {
            p1++;
        }
        // Проверяем, содержится ли слово в s2
        if (isWordInString(wordStart, s2)) {
            commonWord = wordStart;
            break;
        }
    }

    // Если не найдено общее слово, возвращаем NULL
    if (commonWord == NULL) {
        return NULL;
    }

    // Находим слово, предшествующее commonWord в s1
    const char *prevWordEnd = commonWord - 1;
    while (prevWordEnd > s1 && (*prevWordEnd == ' ' || *prevWordEnd == '\t')) {
        prevWordEnd--;
    }
    const char *prevWordStart = prevWordEnd;
    while (prevWordStart > s1 && *prevWordStart != ' ' && *prevWordStart != '\t') {
        prevWordStart--;
    }
    prevWordStart++;

    // Вычисляем длину предыдущего слова
    size_t wordLength = prevWordEnd - prevWordStart + 1;

    // Выделяем память под результат и копируем предыдущее слово
    char *result = (char *)malloc(wordLength + 1);
    if (result != NULL) {
        my_strncpy(result, prevWordStart, wordLength);
        result[wordLength] = '\0';  // Завершаем строку нулевым символом
    }
    return result;
}

// Тестовая функция для проверки findPreviousWord
void testFindPreviousWord() {
    const char *s1 = " hello example world";
    const char *s2 = " this is an example";

    // Тест 1: Проверяем наличие предыдущего слова "hello" в s1 перед первым общим словом
    char *previousWord1 = findPreviousWord(s1, s2);
    ASSERT_STRING("hello", previousWord1);
    free(previousWord1);

    const char *s3 = " this is a test";
    const char *s4 = " example of a test";

    // Тест 2: Проверяем наличие предыдущего слова "a" в s3 перед первым общим словом
    char *previousWord2 = findPreviousWord(s3, s4);
    ASSERT_STRING("is", previousWord2);
    free(previousWord2);

    const char *s5 = " some words";
    const char *s6 = " different words";

    // Тест 3: Проверяем отсутствие общих слов, ожидаем NULL
    char *previousWord3 = findPreviousWord(s5, s6);
    ASSERT_STRING("some", previousWord3); // Проверяем, что результат равен NULL
    free(previousWord3);
}

int main() {
    testFindPreviousWord();
    return 0;
}