#include <stdio.h>
#include <assert.h>
#include "tasks/string_.h"

void test_strlen() {
    const char *s1 = "Hello";
    assert(string_length(s1) == 5);

    const char *s2 = "";
    assert(string_length(s2) == 0);

    const char *s3 = "12345";
    assert(string_length(s3) == 5);

    const char *s4 = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
    assert(string_length(s4) == 56);

    const char *s5 = "1234567890";
    assert(string_length(s5) == 10);
}

void test_find() {
    char str[] = "Hello, world!";
    char *begin = str;
    char *end = str + 12; // Указывает на символ '!'

    // Поиск символа 'H'
    assert(find(begin, end, 'H') == begin);

    // Поиск символа 'o'
    assert(find(begin, end, 'o') == begin + 4);

    // Поиск символа '!'
    assert(find(begin, end, '!') == end);

    // Поиск символа 'X' (не существует в строке)
    assert(find(begin, end, 'X') == end);
}

void test_findNonSpace() {
    char str1[] = "  Hello,  world!  ";
    char *begin = str1;

    // Первый символ, отличный от пробелов
    assert(*findNonSpace(begin) == 'H');

    char str2[] = "     ";
    begin = str2;

    // В строке только пробелы, поэтому должен вернуть '\0'
    assert(*findNonSpace(begin) == '\0');
}

int main() {
    test_strlen();
    test_find();
    test_findNonSpace();
    printf("All tests passed successfully!\n");
    return 0;
}
