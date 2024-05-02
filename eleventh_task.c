/*#include <stdio.h>
#include <ctype.h>
#include "tasks/string_.h"

// Макрос для использования assertString с информацией о месте вызова
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define MAX_WORD_SIZE 50

char _stringBuffer[MAX_STRING_SIZE + 1];

typedef enum {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

void printWordBeforeFirstWordWithA(char *s) {
    char *start = s;
    char *wordStart = NULL;
    char *wordEnd = NULL;
    WordBeforeFirstWordWithAReturnCode result = EMPTY_STRING;

    // Обход строки для поиска первого слова, содержащего букву 'a'
    while (*start) {
        start = findNonSpace(start);
        if (*start) { // Проверяем, не конец ли строки
            char *word = start;
            // Определение конца текущего слова
            while (*start && !isspace(*start)) {
                if (tolower(*start) == 'a') {
                    // Найдено первое слово, содержащее 'a'
                    result = WORD_FOUND;
                    break;
                }
                start++;
            }
            if (result == WORD_FOUND) {
                // Копируем слово, содержащее 'a'
                wordStart = word;
                wordEnd = start;
                break;
            }
        }
    }

    if (result == WORD_FOUND && wordStart && wordEnd) {
        // Обход назад для поиска слова перед словом, содержащим 'a'
        start = s;
        while (start < wordStart) {
            char *prev = start;
            start = findNonSpace(start);
            if (start >= wordStart) {
                break;
            }
            wordStart = prev;
        }

        if (wordStart < wordEnd) {
            // Вывод слова перед словом, содержащим 'a'
            while (wordStart < wordEnd) {
                putchar(*wordStart);
                wordStart++;
            }
            putchar('\n');
            return;
        }
    }

    // Вывод сообщения в зависимости от результата
    switch (result) {
        case EMPTY_STRING:
            printf("No words in the string.\n");
            break;
        case NOT_FOUND_A_WORD_WITH_A:
            printf("No words containing 'a' found.\n");
            break;
        case FIRST_WORD_WITH_A:
            printf("The first word in the string contains 'a', no word before it.\n");
            break;
        default:
            printf("Unexpected error.\n");
            break;
    }
}

// Функция assertString для сравнения строк и вывода информации об ошибке
void assertString(const char *expected, char *got,
                  const char *fileName, const char *funcName, int line) {
    if (my_strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Тесты для функции printWordBeforeFirstWordWithA
void test_printWordBeforeFirstWordWithA() {
    char s1[] = ""; // Пустая строка
    printWordBeforeFirstWordWithA(s1); // Ожидаем вывода "No words in the string."
    ASSERT_STRING("No words in the string.", _stringBuffer);

    char s2[] = "ABC"; // Строка без слов
    printWordBeforeFirstWordWithA(s2); // Ожидаем вывода "No words in the string."
    ASSERT_STRING("No words in the string.", _stringBuffer);

    char s3[] = "BC A"; // Строка с одним словом перед словом с 'a'
    printWordBeforeFirstWordWithA(s3); // Ожидаем вывода "BC"
    ASSERT_STRING("BC", _stringBuffer);

    char s4[] = "B Q WE YR OW IUWR"; // Строка без слов с 'a'
    printWordBeforeFirstWordWithA(s4); // Ожидаем вывода "No words containing 'a' found."
    ASSERT_STRING("No words containing 'a' found.", _stringBuffer);

    char s5[] = "The quick brown fox jumps over a lazy dog"; // Строка с словом перед словом с 'a'
    printWordBeforeFirstWordWithA(s5); // Ожидаем вывода "jumps"
    ASSERT_STRING("jumps", _stringBuffer);
}

// Тестирование всех случаев
void testAll() {
    test_printWordBeforeFirstWordWithA();
}

// Входная точка программы
int main() {
    testAll(); // Запуск всех тестов
    return 0;
}
*/