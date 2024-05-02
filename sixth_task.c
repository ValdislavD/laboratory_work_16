#include <stdio.h>
#include "tasks/string_.h"

// Макрос для проверки и вывода результатов с использованием assertInt
#define ASSERT_INT(expected, got) assertInt(expected, got, __FILE__, __FUNCTION__, __LINE__)

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

typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после последнего символа
} WordDescriptor;

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    char *ptr1 = w1.begin;
    char *ptr2 = w2.begin;

    // Проверяем каждый символ слова до конца диапазона
    while (ptr1 != w1.end && ptr2 != w2.end) {
        if (*ptr1 != *ptr2) {
            return 0; // Символы не совпадают, слова не равны
        }
        ptr1++;
        ptr2++;
    }

    // Убеждаемся, что оба слова закончились одновременно
    if (ptr1 == w1.end && ptr2 == w2.end) {
        return 1; // Слова равны
    } else {
        return 0; // Длины слов не совпадают, слова не равны
    }
}

// Функция для проверки упорядоченности слов в предложении
int areWordsLexicographicallyOrdered(const char *sentence) {
    WordDescriptor currentWord;
    WordDescriptor previousWord;
    int isFirstWord = 1; // Флаг для определения первого слова
    char *ptr = sentence;

    // Проходим по предложению
    while (*ptr != '\0') {
        // Пропускаем пробелы и определяем начало следующего слова
        char *wordBegin = findNonSpace(ptr);
        if (*wordBegin == '\0') {
            break; // Достигнут конец предложения
        }

        // Определяем конец текущего слова
        char *wordEnd = findSpace(wordBegin);

        // Устанавливаем диапазон текущего слова
        currentWord.begin = wordBegin;
        currentWord.end = wordEnd;

        if (!isFirstWord) {
            // Если не первое слово, сравниваем текущее слово с предыдущим
            if (!areWordsEqual(previousWord, currentWord)) {
                // Сравниваем символы двух слов посимвольно
                char *ptr1 = previousWord.begin;
                char *ptr2 = currentWord.begin;

                while (ptr1 != previousWord.end && ptr2 != currentWord.end) {
                    if (*ptr1 < *ptr2) {
                        break; // Первое слово меньше в лексикографическом порядке
                    } else if (*ptr1 > *ptr2) {
                        return 0; // Первое слово больше в лексикографическом порядке (неупорядочено)
                    }
                    ptr1++;
                    ptr2++;
                }

                // Если одно слово является префиксом другого
                if (ptr1 == previousWord.end && ptr2 != currentWord.end) {
                    return 1; // Слова упорядочены (префиксное отношение)
                } else if (ptr1 != previousWord.end && ptr2 == currentWord.end) {
                    return 0; // Первое слово больше в лексикографическом порядке (неупорядочено)
                }
            }
        }

        // Устанавливаем предыдущее слово как текущее для следующей итерации
        previousWord = currentWord;
        isFirstWord = 0; // Сбрасываем флаг первого слова

        // Переходим к следующему слову
        ptr = wordEnd;
    }

    return 1; // Все слова упорядочены
}

// Тестовая функция для проверки упорядоченности слов в предложении
void testAreWordsLexicographicallyOrdered() {
    // Тест на упорядоченные слова
    const char *sentence1 = "apple banana cherry";
    ASSERT_INT(1, areWordsLexicographicallyOrdered(sentence1));

    // Тест на неупорядоченные слова (обратный порядок)
    const char *sentence2 = "zebra lion elephant";
    ASSERT_INT(0, areWordsLexicographicallyOrdered(sentence2));

    // Тест на неупорядоченные слова (смешанный порядок)
    const char *sentence3 = "orange apple banana";
    ASSERT_INT(0, areWordsLexicographicallyOrdered(sentence3));

    // Тест на одно слово (упорядоченное)
    const char *sentence4 = "hello";
    ASSERT_INT(1, areWordsLexicographicallyOrdered(sentence4));

    // Тест на пустую строку (считаем, что пустая строка упорядочена)
    const char *sentence5 = "";
    ASSERT_INT(1, areWordsLexicographicallyOrdered(sentence5));

    // Тест на строку с одним словом и пробелами
    const char *sentence6 = "  world  ";
    ASSERT_INT(1, areWordsLexicographicallyOrdered(sentence6));
}

int main() {
    // Запуск тестов
    testAreWordsLexicographicallyOrdered();

    return 0;
}
