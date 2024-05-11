#include <stdio.h>
#include <assert.h>
#include "tasks/string_.h"

typedef enum {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(char *s, char *word) {
    if (string_length(s) == 0) {
        printf("Empty string\n");
        return EMPTY_STRING;
    }

    char *start = s;
    char *end = s;
    char *prevWordStart = NULL;
    char *prevWordEnd = NULL;
    int foundWordWithA = 0;

    while (*end != '\0') {
        // Отладочный вывод
        printf("start: %s, end: %s, prevWordStart: %s, prevWordEnd: %s\n", start, end, prevWordStart, prevWordEnd);

        start = findNonSpace(start);
        end = findSpace(start);

        // Проверяем, нашли ли мы слово
        if (start == end)
            break;

        // Проверяем, содержит ли это слово 'a' (с учетом регистра)
        char *aFound = find(start, end, 'a');
        if (aFound != NULL && (prevWordStart == NULL || aFound < prevWordStart)) {
            // Нашли слово с буквой 'a', которое является первым в строке
            prevWordStart = start;
            prevWordEnd = end;
            foundWordWithA = 1;
        }

        // Переходим к следующему слову
        start = findSpace(end);
        end = start;
    }

    if (foundWordWithA) {
        if (prevWordStart != NULL) {
            // Копируем предыдущее слово в массив 'word'
            copy(prevWordStart, prevWordEnd, word);
            word[prevWordEnd - prevWordStart] = '\0';
            printf("Word extracted: %s\n", word);
            return WORD_FOUND;
        } else {
            printf("No word before the first word with 'a'\n");
            return FIRST_WORD_WITH_A;
        }
    }

    printf("No word with 'a' found in the string\n");
    return NOT_FOUND_A_WORD_WITH_A;
}

void test_getWordBeforeFirstWordWithA() {
    char word[MAX_STRING_SIZE + 1];

    char s1[] = "";
    WordBeforeFirstWordWithAReturnCode result_s1 = getWordBeforeFirstWordWithA(s1, word);
    printf("Result for s1: %d\n", result_s1);
    assert(result_s1 == EMPTY_STRING);

    char s3[] = "BC A";
    WordBeforeFirstWordWithAReturnCode result_s3 = getWordBeforeFirstWordWithA(s3, word);
    printf("Result for s3: %d\n", result_s3);
    assert(result_s3 == WORD_FOUND);
    assert(my_strcmp(word, "BC") == 0);

}

int main() {
    test_getWordBeforeFirstWordWithA();
    return 0;
}
