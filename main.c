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

void test_findSpace() {
    char str[] = "Hello World";
    char *p = str;
    while (*p != '\0') p++;
    char *space = findSpace(str);
    assert(*space == ' ');

    char str2[] = "HelloWorld";
    char *p2 = str2;
    while (*p2 != '\0') p2++;
    char *space2 = findSpace(str2);
    assert(space2 == p2);
}

void test_findNonSpaceReverse() {
    char s[] = "   Hello World!    ";
    char *nonSpace = findNonSpaceReverse(s + string_length(s) - 10, s);
    assert(*nonSpace == 'W');

    char s2[] = "   \t\t";
    nonSpace = findNonSpaceReverse(s2 + string_length(s2) + 1, s2);
    assert(*nonSpace == '\0');
}

void test_findSpaceReverse() {
    char str[] = "Hello World ";
    char *p = &str[10];
    char *space = findSpaceReverse(p, str);
    assert(*space == ' ');

    char str2[] = "HelloWorld";
    char *p2 = &str2[9];
    char *space2 = findSpaceReverse(p2, str2);
    assert(space2 == str2);
}

int main() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    printf("All tests passed successfully!\n");
    return 0;
}
