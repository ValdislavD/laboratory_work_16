#include <stdio.h>
#include "tasks/string_.h"

// Максимальное количество слов в строке
#define MAX_WORDS_IN_STRING 100

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

char _stringBuffer[MAX_STRING_SIZE + 1];

// Структура для хранения слова
typedef struct {
    char *begin;
    char *end;
} WordDescriptor;

// Функция для извлечения следующего слова из строки
// Возвращает 1, если слово найдено, и 0 в противном случае
int getWord(char **beginSearch, WordDescriptor *word) {
    char *ptr = *beginSearch;

    // Пропускаем пробелы, если они есть
    while (*ptr == ' ') {
        ptr++;
    }

    if (*ptr == '\0') {
        return 0; // Достигнут конец строки
    }

    // Начало текущего слова
    word->begin = ptr;

    // Поиск конца слова (до пробела или конца строки)
    while (*ptr != ' ' && *ptr != '\0') {
        ptr++;
    }

    // Конец текущего слова
    word->end = ptr;

    // Перемещаем указатель начала поиска к следующему символу после слова
    *beginSearch = ptr;

    return 1; // Слово найдено
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

#include "tasks/string_.h"

// Функция для проверки, является ли символ разделителем
int isDelimiter(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',' || ch == '.');
}

// Функция для копирования слова из source в dest
void copyWord(const char *sourceStart, const char *sourceEnd, char *dest) {
    while (sourceStart < sourceEnd) {
        *dest++ = *sourceStart++;
    }
}

// Функция для чередования слов из двух строк s1 и s2
void alternateWords(const char *s1, const char *s2, char *result) {
    const char *ptr1 = s1;
    const char *ptr2 = s2;
    char *outputPtr = result;

    // Проходим по строкам s1 и s2, чередуя слова
    while (*ptr1 != '\0' || *ptr2 != '\0') {
        // Пропускаем пробелы и другие разделители в s1
        while (isDelimiter(*ptr1) && *ptr1 != '\0') {
            ptr1++;
        }

        // Пропускаем пробелы и другие разделители в s2
        while (isDelimiter(*ptr2) && *ptr2 != '\0') {
            ptr2++;
        }

        // Если есть слово в s1, копируем его в result
        if (*ptr1 != '\0') {
            const char *start = ptr1;
            while (!isDelimiter(*ptr1) && *ptr1 != '\0') {
                ptr1++;
            }
            copyWord(start, ptr1, outputPtr);
            outputPtr += (ptr1 - start);
            *outputPtr++ = ' '; // Добавляем пробел между словами
        }

        // Если есть слово в s2, копируем его в result
        if (*ptr2 != '\0') {
            const char *start = ptr2;
            while (!isDelimiter(*ptr2) && *ptr2 != '\0') {
                ptr2++;
            }
            copyWord(start, ptr2, outputPtr);
            outputPtr += (ptr2 - start);
            *outputPtr++ = ' '; // Добавляем пробел между словами
        }
    }

    // Устанавливаем завершающий нуль-символ в конце результата
    if (outputPtr > result) {
        *(outputPtr - 1) = '\0';
    }
}

// Функция для проверки строки на соответствие ожидаемому результату
void testAlternateWords() {
    const char *s1 = "Hello world";
    const char *s2 = "Good morning";
    char result[100];

    alternateWords(s1, s2, result);

    // Ожидаемый результат: "Hello Good world morning "
    ASSERT_STRING("Hello Good world morning", result);

    // Тест на одно слово в первой строке
    const char *s3 = "Hello";
    const char *s4 = "Good morning";
    char result2[100];

    alternateWords(s3, s4, result2);
    // Ожидаемый результат: "Hello Good morning "
    ASSERT_STRING("Hello Good morning", result2);

    // Тест на одно слово во второй строке
    const char *s5 = "Hello world";
    const char *s6 = "Good";
    char result3[100];

    alternateWords(s5, s6, result3);
    // Ожидаемый результат: "Hello Good world "
    ASSERT_STRING("Hello Good world", result3);

    // Тест на пустую первую строку
    const char *s7 = "";
    const char *s8 = "Good morning";
    char result4[100];

    alternateWords(s7, s8, result4);
    // Ожидаемый результат: "Good morning "
    ASSERT_STRING("Good morning", result4);

    // Тест на пустую вторую строку
    const char *s9 = "Hello world";
    const char *s10 = "";
    char result5[100];

    alternateWords(s9, s10, result5);
    // Ожидаемый результат: "Hello world "
    ASSERT_STRING("Hello world", result5);
}

int main() {
    testAlternateWords();

    return 0;
}
