#include "string_.h"
#include <ctype.h>

size_t string_length(const char *begin) {
    const char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find(char *begin, const char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char* findNonSpace(char *begin) {
    while (*begin != '\0' && isspace(*begin))
        begin++;
    return begin;
}

char* findSpace(char *begin) {
    while (*begin != ' ' && *begin != '\0')
        begin++;
    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend) {
        if (!isspace(*rbegin))
            return rbegin;
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && *rbegin != ' ')
        rbegin--;
    return rbegin;
}

int my_strcmp(const char *lhs, const char *rhs) {
    while (*lhs && *rhs && *lhs == *rhs) {
        lhs++;
        rhs++;
    }
    return *lhs - *rhs;
}

char* copy(const char *beginSource, const char *endSource, char *beginDestination) {
    // Вычисляем длину фрагмента для копирования
    size_t length = 0;
    const char *temp = beginSource;
    while (temp != endSource) {
        ++length;
        ++temp;
    }

    // Копируем фрагмент
    temp = beginSource;
    char *dest = beginDestination;
    while (length--) {
        *dest++ = *temp++;
    }

    // Возвращаем указатель на следующий свободный фрагмент памяти в destination
    return dest;
}

char* copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    while (beginSource != endSource) {
        if (f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}