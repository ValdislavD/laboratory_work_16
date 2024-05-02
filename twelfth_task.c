#include <stdio.h>

#define MAX_N_WORDS_IN_STRING 100
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Тип данных для описания слова
typedef struct {
    const char *start; // указатель на начало слова в исходной строке
    size_t length;     // длина слова
} WordDescriptor;

// Тип данных для мешка слов
typedef struct {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

// Функция для сравнения строк без использования string.h
int strcmp_(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        ++s1;
        ++s2;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

// Функция для проверки равенства строк и вывода сообщения в случае несоответствия
void assertString(const char *expected, const char *got, const char *fileName, const char *funcName, int line) {
    if (strcmp_(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Функция для преобразования WordDescriptor в строку char*
void wordDescriptorToString(WordDescriptor word, char *destination) {
    for (size_t i = 0; i < word.length; ++i) {
        *destination++ = word.start[i];
    }
    *destination = '\0';
}

// Собственная реализация strncmp для сравнения не более n символов
int strncmp_(const char *s1, const char *s2, size_t n) {
    while (n > 0) {
        if (*s1 != *s2) {
            return (*(unsigned char *)s1 - *(unsigned char *)s2);
        }
        if (*s1 == '\0') {
            return 0;
        }
        s1++;
        s2++;
        n--;
    }
    return 0;
}

// Функция для определения последнего слова из первой строки, которое есть во второй строке
WordDescriptor lastWordInFirstStringInSecondString(const char *s1, const char *s2) {
    WordDescriptor lastWord = {NULL, 0};
    const char *start = NULL;
    size_t length = 0;

    // Проходим по первой строке (s1) и ищем слова, сравнивая их с второй строкой (s2)
    while (*s1 != '\0') {
        // Пропускаем начальные пробелы
        while (*s1 == ' ') {
            ++s1;
        }

        if (*s1 == '\0') {
            break;
        }

        start = s1; // Начало слова
        length = 0;

        // Находим длину текущего слова
        while (*s1 != ' ' && *s1 != '\0') {
            ++s1;
            ++length;
        }

        // Формируем описание слова
        WordDescriptor currentWord = {start, length};

        // Проверяем, есть ли это слово во второй строке (s2)
        const char *pos = s2;
        while (*pos != '\0') {
            // Ищем совпадение слова
            const char *wordStart = pos;
            while (*pos != ' ' && *pos != '\0') {
                ++pos;
            }
            size_t wordLength = pos - wordStart;
            if (wordLength == length && strncmp_(wordStart, start, length) == 0) {
                // Найдено совпадение, обновляем последнее найденное слово
                lastWord = currentWord;
                break;
            }
            if (*pos == ' ') {
                ++pos;
            }
        }
    }

    return lastWord;
}

// Функция для запуска тестов
void runTests() {
    const char *s1 = "This is a test string";
    const char *s2 = "Here is a simple test";

    // Тест 1: Последнее слово из s1, которое есть в s2
    WordDescriptor word1 = lastWordInFirstStringInSecondString(s1, s2);

    // Преобразуем найденное слово в строку
    char string1[100];
    wordDescriptorToString(word1, string1);

    // Проверяем результат
    ASSERT_STRING("test", string1);

    // Тест 2: Поиск последнего слова из "simple test" в "This is a simple test string"
    const char *s3 = "This is a simple test string";
    WordDescriptor word2 = lastWordInFirstStringInSecondString(s2, s3);

    // Преобразуем найденное слово в строку
    char string2[100];
    wordDescriptorToString(word2, string2);

    // Проверяем результат
    ASSERT_STRING("test", string2);

    // Тест 3: Поиск последнего слова из s1, которое есть в пустой строке s2
    const char *s4 = "";
    WordDescriptor word3 = lastWordInFirstStringInSecondString(s1, s4);

    // Преобразуем найденное слово в строку
    char string3[100];
    wordDescriptorToString(word3, string3);

    // Проверяем результат (ожидаем, что слово не найдено)
    ASSERT_STRING("", string3);
}

int main() {
    // Запускаем тесты
    runTests();

    return 0;
}