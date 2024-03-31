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
    while (rbegin != rend && (*rbegin == ' ' || *rbegin == '\0'))
        rbegin--;
    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin != rend && *rbegin != ' ')
        rbegin--;
    return rbegin;
}