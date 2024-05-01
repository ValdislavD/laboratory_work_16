#include "tasks/string_.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <windows.h>

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
char _stringBuffer[MAX_STRING_SIZE + 1]; // Определение глобальной переменной

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

// Функция для перемещения букв в начало слова и цифр в конец слова
void transformWord(char *word) {
    char letters[MAX_STRING_SIZE]; // Буфер для букв
    char digits[MAX_STRING_SIZE];  // Буфер для цифр
    int letterIdx = 0;
    int digitIdx = 0;

    // Разделяем буквы и цифры в слове
    char *ptr = word;
    while (*ptr != '\0') {
        if (isalpha(*ptr)) {
            letters[letterIdx++] = *ptr;
        } else if (isdigit(*ptr)) {
            digits[digitIdx++] = *ptr;
        }
        ptr++;
    }
    letters[letterIdx] = '\0'; // Завершаем строку буквами
    digits[digitIdx] = '\0';   // Завершаем строку цифрами

    // Собираем слово обратно: сначала буквы, потом цифры
    ptr = word;
    char *letterPtr = letters;
    while (*letterPtr != '\0') {
        *ptr++ = *letterPtr++;
    }
    char *digitPtr = digits;
    while (*digitPtr != '\0') {
        *ptr++ = *digitPtr++;
    }
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

void assertString(const char *expected, char *got, const char *fileName, const char *funcName, int line) {
    if (my_strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Тесты для функции transformWord
void testTransformWord() {
    char word1[] = "123hello";
    transformWord(word1);
    assertString("hello123", word1, __FILE__, __func__, __LINE__);

    char word2[] = "4wo5rld6";
    transformWord(word2);
    assertString("world456", word2, __FILE__, __func__, __LINE__);

    char word3[] = "12345";
    transformWord(word3);
    assertString("12345", word3, __FILE__, __func__, __LINE__); // Ничего не должно измениться
}


bool getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    // Пропускаем пробельные символы в начале слова
    while (rbegin < rend && isspace(*rbegin)) {
        ++rbegin;
    }

    char *endOfWord = rend - 1;

    // Пропускаем пробельные символы в конце слова
    while (endOfWord >= rbegin && isspace(*endOfWord)) {
        --endOfWord;
    }

    // Устанавливаем указатели на начало и конец слова
    word->begin = rbegin;
    word->end = endOfWord + 1;

    // Перемещаемся с начала к концу слова, сохраняя порядок букв
    char *writePtr = rbegin;
    for (char *ptr = rbegin; ptr <= endOfWord; ++ptr) {
        if (isalpha(*ptr)) {
            *writePtr++ = *ptr;
        }
    }
    *writePtr = '\0'; // Добавляем завершающий нуль-символ

    return true; // Всегда возвращаем true, так как всегда находим слово
}

void testGetWordReverse() {
    // Тест 1: Пустая строка
    char inputString1[] = "";
    WordDescriptor wordDesc1;
    getWordReverse(inputString1, inputString1 + strlen(inputString1), &wordDesc1);
    ASSERT_STRING("", wordDesc1.begin);

    // Тест 2: Строка с пробелами и цифрами
    char inputString2[] = "dlr3e 4l1iw4";
    WordDescriptor wordDesc2;
    getWordReverse(inputString2, inputString2 + strlen(inputString2), &wordDesc2);
    ASSERT_STRING("dlreliw", wordDesc2.begin);

    // Тест для строки "    dg123    "
    char inputString[] = "    dg123    ";
    WordDescriptor wordDesc;
    getWordReverse(inputString, inputString + strlen(inputString), &wordDesc);
    ASSERT_STRING("dg", wordDesc.begin);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    testTransformWord();
    testGetWordReverse();
    return 0;
}