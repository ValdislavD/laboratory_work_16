#include <stdio.h>
#include <stdbool.h>
#include "tasks/string_.h"

#define MAX_STRING_SIZE 100
#define MAX_WORDS 100
#define MAX_WORD_LENGTH 50
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Функция для сортировки букв в слове
void sortWord(char *word) {
    int length = string_length(word);
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (word[i] > word[j]) {
                // Обмен символов для сортировки по возрастанию
                char temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
        }
    }
}

// Структура для хранения слова и его отсортированной версии
typedef struct {
    char original[MAX_WORD_LENGTH];
    char sorted[MAX_WORD_LENGTH];
} WordData;

// Функция для определения наличия пары слов-анаграмм
bool hasAnagramPair(const char *s) {
    char buffer[MAX_STRING_SIZE + 1];
    WordData words[MAX_WORDS];
    int wordCount = 0;

    // Копирование строки в буфер
    copy(s, s + string_length(s), buffer);

    // Находим все слова в буфере
    char *start = buffer;
    while (*start != '\0') {
        // Находим начало слова
        start = findNonSpace(start);
        if (*start == '\0') {
            break; // Если достигнут конец строки, выходим из цикла
        }

        // Находим конец слова
        char *end = findSpace(start);

        // Копируем текущее слово в структуру слова
        copy(start, end, words[wordCount].original);
        words[wordCount].original[end - start] = '\0'; // Добавляем нуль-терминатор

        // Сохраняем отсортированную версию слова
        copy(words[wordCount].original, words[wordCount].original + string_length(words[wordCount].original), words[wordCount].sorted);
        sortWord(words[wordCount].sorted);

        // Увеличиваем счетчик слов
        wordCount++;

        // Перемещаем указатель на начало следующего слова
        start = findNonSpace(end);
    }

    // Проверяем каждую пару слов на анаграммы
    for (int i = 0; i < wordCount - 1; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            // Сравниваем отсортированные слова
            if (my_strcmp(words[i].sorted, words[j].sorted) == 0) {
                return true; // Найдена пара анаграмм
            }
        }
    }

    return false; // Пара анаграмм не найдена
}

// Функция для проверки строк
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

// Тестовая функция для проверки hasAnagramPair
void testHasAnagramPair() {
    const char *testString1 = "stirng this is a test string with some anagram words like hits his";
    const char *testString2 = "hello world this is a test string with some anagram words like hits his";
    const char *testString3 = "listen to silent and watch the god and dog";
    const char *testString4 = "apple banana orange peach strawberry";
    
    // Ожидаемые результаты
    const char *expected1 = "The string contains a pair of anagram words.\n";
    const char *expected2 = "The string does not contain a pair of anagram words.\n";

    // Получаем фактические результаты
    bool result1 = hasAnagramPair(testString1);
    bool result2 = hasAnagramPair(testString2);
    bool result3 = hasAnagramPair(testString3);
    bool result4 = hasAnagramPair(testString4);

    // Проверяем результаты
    if (result1) {
        ASSERT_STRING(expected1, "The string contains a pair of anagram words.\n");
    } else {
        ASSERT_STRING(expected2, "The string does not contain a pair of anagram words.\n");
    }

    if (!result2) {
        ASSERT_STRING(expected2, "The string does not contain a pair of anagram words.\n");
    } else {
        ASSERT_STRING(expected1, "The string contains a pair of anagram words.\n");
    }
    if (result3) {
        ASSERT_STRING(expected1, "The string contains a pair of anagram words.\n");
    } else {
        ASSERT_STRING(expected2, "The string does not contain a pair of anagram words.\n");
    }

    if (result4) {
        ASSERT_STRING(expected1, "The string contains a pair of anagram words.\n");
    } else {
        ASSERT_STRING(expected2, "The string does not contain a pair of anagram words.\n");
    }
}

int main() {
    testHasAnagramPair();
    return 0;
}