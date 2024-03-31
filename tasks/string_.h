#ifndef UNTITLED20_STRING__H
#define UNTITLED20_STRING__H

#include <stdio.h>

size_t string_length(const char *s); //возвращает количество символов в строке

char* find(char *begin, const char *end, int ch); //возвращает указатель на первый элемент с кодом ch

char* findNonSpace(char *begin); //возвращает указатель на первый символ

char* findSpace(char *begin); //возвращает указатель на первый пробельный символ

char* findNonSpaceReverse(char *rbegin, const char *rend); //возвращает указатель на первый справа символ, отличный от пробельных

char* findSpaceReverse(char *rbegin, const char *rend); //возвращает указатель на первый пробельный символ справа, расположенный на ленте памяти

int my_strcmp(const char *lhs, const char *rhs); //сравнивает две строки

char* copy(const char *beginSource, const char *endSource, char *beginDestination); //записывает по адресу beginDestination фрагмент памяти

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)); //записывает по адресу beginDestination элементы из фрагмента памяти начиная с beginSource заканчивая endSource, удовлетворяющие функции-предикату f.

char* copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int));

#endif //UNTITLED20_STRING__H
