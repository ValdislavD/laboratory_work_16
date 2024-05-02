#include "tasks/string_.h"

// Макрос для проверки и вывода результатов с использованием assertInt
#define ASSERT_INT(expected, got) assertInt(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define MAX_N_WORDS_IN_STRING 100

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

typedef struct {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

// Глобальные переменные для хранения BagOfWords
BagOfWords _bag;
BagOfWords _bag2;

void getBagOfWords(BagOfWords *bag, char *s) {
    bag->size = 0;
    char *ptr = s;

    // Проходим по строке s
    while (*ptr != '\0') {
        // Пропускаем пробелы и определяем начало слова
        char *wordBegin = findNonSpace(ptr);
        if (*wordBegin == '\0') {
            break; // Достигнут конец строки
        }

        // Определяем конец текущего слова
        char *wordEnd = findSpace(wordBegin);

        // Добавляем слово в BagOfWords
        bag->words[bag->size].begin = wordBegin;
        bag->words[bag->size].end = wordEnd;
        bag->size++;

        // Переходим к следующему слову
        ptr = wordEnd;
    }
}

void printWordsReversed(BagOfWords *bag) {
    // Выводим слова в обратном порядке
    for (int i = bag->size - 1; i >= 0; i--) {
        WordDescriptor *word = &bag->words[i];
        char *ptr = word->begin;

        // Выводим слово посимвольно до его конца
        while (ptr != word->end) {
            printf("%c", *ptr);
            ptr++;
        }

        printf("\n"); // Переходим на новую строку после каждого слова
    }
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

int my_strncmp(const char *str1, const char *str2, size_t n) {
    // Пройдемся по первым n символам или до конца строк, если одна из них закончится
    for (size_t i = 0; i < n; i++) {
        // Достигли конца обеих строк
        if (str1[i] == '\0' && str2[i] == '\0') {
            return 0; // Строки идентичны до данной длины n
        }

        // Достигли конца str1 (но str2 продолжает)
        if (str1[i] == '\0') {
            return -1; // str1 меньше str2
        }

        // Достигли конца str2 (но str1 продолжает)
        if (str2[i] == '\0') {
            return 1; // str1 больше str2
        }

        // Сравниваем символы
        if (str1[i] != str2[i]) {
            return (str1[i] < str2[i]) ? -1 : 1;
        }
    }

    return 0; // Строки идентичны до данной длины n
}

// Тестовая функция для функции getBagOfWords
void testGetBagOfWords() {
    // Тест на пустую строку
    char s1[] = "";
    BagOfWords bag1;
    getBagOfWords(&bag1, s1);
    ASSERT_INT(0, bag1.size);

    // Тест на строку с одним словом
    char s2[] = "Hello";
    BagOfWords bag2;
    getBagOfWords(&bag2, s2);
    ASSERT_INT(1, bag2.size);
    ASSERT_INT(0, my_strcmp(bag2.words[0].begin, "Hello"));

    // Тест на строку с несколькими словами
    char s3[] = "This is a test string";
    BagOfWords bag3;
    getBagOfWords(&bag3, s3);
    ASSERT_INT(5, bag3.size);

    // Проверяем начала слов
    ASSERT_INT(0, my_strncmp(bag3.words[0].begin, "This", bag3.words[0].end - bag3.words[0].begin));
    ASSERT_INT(0, my_strncmp(bag3.words[1].begin, "is", bag3.words[1].end - bag3.words[1].begin));
    ASSERT_INT(0, my_strncmp(bag3.words[2].begin, "a", bag3.words[2].end - bag3.words[2].begin));
    ASSERT_INT(0, my_strncmp(bag3.words[3].begin, "test", bag3.words[3].end - bag3.words[3].begin));
    ASSERT_INT(0, my_strncmp(bag3.words[4].begin, "string", bag3.words[4].end - bag3.words[4].begin));
}

int main() {
    // Запуск тестов
    testGetBagOfWords();

    return 0;
}