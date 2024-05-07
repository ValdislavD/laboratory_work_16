/*#include <stdio.h>
#include "tasks/string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// Функция для проверки строк и вывода сообщения об ошибке
void assertString(const char *expected, char *got, const char *fileName, const char *funcName, int line) {
    if (my_strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}


// Определение пользовательской функции для проверки буквенно-цифровых символов
int my_isalnum(int ch) {
    return (ch >= '0' && ch <= '9') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= 'A' && ch <= 'Z');
}

// Функция для подсчета количества слов в строке
int countWords(const char *str) {
    int count = 0;
    const char *p = str;

    // Пропускаем начальные пробелы
    while (*p != '\0' && (*p == ' ' || *p == '\t')) {
        p++;
    }

    while (*p != '\0') {
        count++;
        p = findSpace(p);
        p = findNonSpace(p);
    }

    return count;
}

// Функция для поиска последнего слова в строке
void findLastWord(const char *str, char **start, char **end) {
    const char *p = str + string_length(str) - 1;

    // Идем к началу последнего слова
    while (p >= str && !my_isalnum(*p)) {
        p--;
    }

    // Идем к концу последнего слова
    while (p >= str && my_isalnum(*p)) {
        p--;
    }

    *start = (char *)(p + 1);
    *end = (char *)(str + string_length(str) - 1);
}

// Функция для добавления последнего слова из src в конец dest
void appendLastWord(char *dest, const char *src) {
    char *lastWordStart = NULL;
    char *lastWordEnd = NULL;

    findLastWord(src, &lastWordStart, &lastWordEnd);

    // Копируем последнее слово в конец строки dest
    dest += string_length(dest); // перемещаем указатель в конец строки dest
    *dest++ = ' '; // добавляем пробел перед словом, если это не первое слово
    copy(lastWordStart, lastWordEnd + 1, dest); // копируем слово
}

// Функция для запуска всех тестов
void runAllTests() {
    // Тест 1: Добавление слова из строки в конец пустой строки
    char dest1[MAX_STRING_SIZE + 1] = "";
    char src1[MAX_STRING_SIZE + 1] = "hello world";
    appendLastWord(dest1, src1);
    ASSERT_STRING(" world", dest1);

    // Тест 2: Добавление слова из строки в конец непустой строки
    char dest2[MAX_STRING_SIZE + 1] = "this is a";
    char src2[MAX_STRING_SIZE + 1] = "test sentence";
    appendLastWord(dest2, src2);
    ASSERT_STRING("this is a sentence", dest2);

    // Тест 3: Добавление слова из пустой строки в конец непустой строки
    char dest3[MAX_STRING_SIZE + 1] = "hello";
    char src3[MAX_STRING_SIZE + 1] = "";
    appendLastWord(dest3, src3);
    ASSERT_STRING("hello ", dest3);
}

int main() {
    runAllTests();
    return 0;
}*/