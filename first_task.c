/*#include <stdio.h>
#include "tasks/string_.h"
#include <ctype.h>
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define TEST_CHAR(end, expected) checkCharTest(end, expected)

// Обновленная функция для поиска последнего символа в строке, не являющегося пробелом или нулевым символом
char *getEndOfString(char *s) {
    char *end = s;

    // Перемещаем указатель end до конца строки
    while (*end != '\0') {
        end++;
    }

    // Возвращаем последний непробельный символ перед нулевым символом
    while (end > s && isspace(*(end - 1))) {
        end--;
    }

    // Если строка состоит только из пробельных символов, вернем указатель на первый пробельный символ
    if (end == s) {
        while (*s != '\0' && isspace(*s)) {
            s++;
        }
        end = s;
    }

    return end;
}

// Функция для удаления непробельных символов из строки, копирования и установки нуль-терминатора
void removeNonLetters(char *s) {
    // Находим конец строки с учётом условий пробельных символов
    char *endSource = getEndOfString(s);

    // Копируем только буквенные символы из исходной строки в ту же строку
    char *destination = copyIf(s, endSource, s, isgraph);

    // Устанавливаем нуль-терминатор в конце результирующей строки
    *destination = '\0';
}

void assertString(const char *expected, char *got, char const *fileName, char const *funcName, int line) {
    if (my_strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

// Функция для проверки символа в тесте и вывода результата в поток ошибок
void checkCharTest(char *end, char expected) {
    if (*end == expected || (*end == '\0' && expected == '\0') || (isspace(*end) && isspace(expected))) {
        fprintf(stderr, "checkCharTest - OK\n");
    } else {
        fprintf(stderr, "Expected: '%c'\n Got: '%c'\n", expected, *end);
    }
}

// Тестирование функции getEndOfString
void test_getEndOfString() {
    char s1[] = "Hello World   ";
    char *end1 = getEndOfString(s1);
    TEST_CHAR(end1 - 1, 'd'); // Ожидаем символ 'd'

    char s2[] = "This is a test string";
    char *end2 = getEndOfString(s2);
    TEST_CHAR(end2 - 1, 'g'); // Ожидаем символ 'g'

    char s3[] = "   ";
    char *end3 = getEndOfString(s3);
    TEST_CHAR(end3, '\0'); // Ожидаем '\0' (конец строки) или пробельный символ
}

// Тестирование функции removeNonLetters
void test_removeNonLetters() {
    char s1[] = "Hello World   ";
    removeNonLetters(s1);
    ASSERT_STRING("HelloWorld", s1);

    char s2[] = "This is a test string";
    removeNonLetters(s2);
    ASSERT_STRING("Thisisateststring", s2);

    char s3[] = "12345";
    removeNonLetters(s3);
    ASSERT_STRING("12345", s3);

    char s4[] = " !@#$%^&*() ";
    removeNonLetters(s4);
    ASSERT_STRING("!@#$%^&*()", s4);
}

int main() {
    test_getEndOfString();
    test_removeNonLetters();
    return 0;
}
*/