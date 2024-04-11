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
    char str[] = " Hello World\0";
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

void test_my_strcmp() {
    const char *str1 = "hello";
    const char *str2 = "world";
    const char *str3 = "hello";
    const char *str4 = "hell";

    // Тестируем случай, когда lhs располагается перед rhs
    assert(my_strcmp(str1, str2) < 0);

    // Тестируем случай, когда lhs равно rhs
    assert(my_strcmp(str1, str3) == 0);

    // Тестируем случай, когда lhs располагается после rhs
    assert(my_strcmp(str2, str1) > 0);

    // Тестируем случай, когда lhs длиннее rhs
    assert(my_strcmp(str1, str4) > 0);
}

void test_copy() {
    char source[] = "Hello, world!";
    char destination[20] = {0}; // Инициализируем массив нулями

    // Копируем фрагмент из source в destination
    char* nextFree = copy(source, source + 5, destination);

    // Проверяем, что скопировано правильно
    assert(nextFree == destination + 5); // Указатель на следующий свободный фрагмент

}

int isDigit(int ch) {
    return (ch >= '0' && ch <= '9');
}

void test_copyIf() {
    char source[] = "Hello12345World";
    char destination[20] = {0}; // Инициализируем массив нулями

    // Копируем только цифры из source в destination
    char* nextFree = copyIf(source, source + 15, destination, isDigit);

    // Проверяем, что скопировано правильно
    assert(nextFree == destination + 5); // Указатель на следующий свободный фрагмент
}

// Функция-предикат для копирования только букв
int isAlpha(int ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

void test_copyIfReverse() {
    char source[] = "Hello12345World";
    char destination[20] = {0}; // Инициализируем массив нулями

    // Копируем только буквы из source в destination в обратном порядке
    char* result = copyIfReverse(source + 14, source - 1, destination, isAlpha);

    // Проверяем, что скопировано правильно
    assert(result == destination + 9); // Указатель на следующий свободный для записи фрагмент в памяти
    assert(my_strcmp(destination, "dlroWolleH") == 0); // Проверка скопированной строки

}


int main() {
    test_strlen();
    test_find();
    test_findNonSpace();
    test_findSpace();
    test_findNonSpaceReverse();
    test_findSpaceReverse();
    test_my_strcmp();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
    printf("All tests passed successfully!\n");
    return 0;
}
