/*#include <stdio.h>
#include "tasks/string_.h"

// Макрос для проверки и вывода результатов с использованием assertString
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)


// Структура для представления диапазона слова
typedef struct {
    char *begin;
    char *end;
} WordDescriptor;

// Функция для копирования слова из source в dest
void copyWord(const char *sourceStart, const char *sourceEnd, char *dest) {
    while (sourceStart < sourceEnd) {
        *dest++ = *sourceStart++;
    }
}

char *findSubstring(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack;  // Если needle пустая строка, вернуть haystack
    }

    while (*haystack != '\0') {
        const char *h = haystack;
        const char *n = needle;

        // Начинаем сравнивать символы в haystack и needle
        while (*n != '\0' && *h == *n) {
            h++;
            n++;
        }

        // Если достигли конца needle, значит нашли вхождение
        if (*n == '\0') {
            return (char *)haystack;
        }

        haystack++;  // Переходим к следующему символу в haystack
    }

    return NULL;  // Вхождение не найдено
}

void assertString(const char *expected, char *got,

                  char const *fileName, char const *funcName,
                  int line) {
    if (my_strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

void replace(char *source, char *w1, char *w2) {
    size_t w1Size = string_length(w1);
    size_t w2Size = string_length(w2);

    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char _stringBuffer[1000]; // Буфер для временного хранения строки (можно выбрать достаточный размер)

    char *readPtr, *recPtr;
    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        // Копируем исходную строку в буфер
        copyWord(source, source + string_length(source), _stringBuffer);
        readPtr = _stringBuffer;
        recPtr = source;
    }

    // Заменяем все вхождения слова w1 на слово w2
    while ((recPtr = findSubstring(recPtr, w1)) != NULL) {
        // Копируем слово w2 в исходную строку на место слова w1
        copyWord(word2.begin, word2.end, readPtr);

        // Перемещаем указатели
        recPtr += w1Size;
        readPtr += w2Size;
    }

    // Записываем завершающий нуль-символ в конец модифицированной строки
    *readPtr = '\0';

    // Если использовался буфер, копируем результат из буфера в исходную строку
    if (w1Size < w2Size) {
        copyWord(_stringBuffer, _stringBuffer + string_length(_stringBuffer), source);
    }
}

// Функция для тестирования функции replace
void run_replace_tests() {
    // Тест на замену одного вхождения
    {
        char source[] = "hello world";
        char w1[] = "world";
        char w2[] = "planet";
        replace(source, w1, w2);
        ASSERT_STRING("hello planet", source);
    }

    // Тест на замену множества вхождений
    {
        char source[] = "apple banana apple orange apple";
        char w1[] = "apple";
        char w2[] = "fruit";
        replace(source, w1, w2);
        ASSERT_STRING("fruit banana fruit orange fruit", source);
    }

    // Тест на замену, где w2 длиннее w1
    {
        char source[] = "The quick brown fox jumps over the lazy dog";
        char w1[] = "fox";
        char w2[] = "beautiful and graceful fox";
        replace(source, w1, w2);
        ASSERT_STRING("The quick brown beautiful and graceful fox jumps over the lazy dog", source);
    }

    // Тест на замену, где w1 и w2 имеют одинаковую длину
    {
        char source[] = "programming is fun";
        char w1[] = "is";
        char w2[] = "can be";
        replace(source, w1, w2);
        ASSERT_STRING("programming can be fun", source);
    }
}

int main() {
    // Выполняем все тесты
    run_replace_tests();

    return 0;
}
*/