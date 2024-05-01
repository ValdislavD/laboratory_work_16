/*#include <stdio.h>
#include "tasks/string_.h"

void removeAdjacentEqualLetters(char *s) {
    if (s == NULL || *s == '\0') {
        return; // Ничего не делаем для пустой строки или нулевого указателя
    }

    char *writePtr = s; // Указатель для записи уникальных символов

    // Перебираем строку
    while (*s != '\0') {
        *writePtr = *s; // Записываем текущий символ

        // Пропускаем все последующие одинаковые символы
        while (*(s + 1) != '\0' && *(s + 1) == *s) {
            s++;
        }

        // Переходим к следующему символу для записи
        s++;
        writePtr++;
    }

    // Устанавливаем завершающий нуль-терминатор после окончания новой строки
    *writePtr = '\0';
}

// Функция для определения слов в строке
int isWord(char *start, char *end) {
    while (start < end) {
        if (*start == ' ') {
            return 0; // Найден пробел, это не слово
        }
        start++;
    }
    return 1; // Нет пробелов, это слово
}

// Функция для удаления лишних пробелов между словами в предложении
void removeExtraSpaces(char *s) {
    if (s == NULL || *s == '\0') {
        return; // Ничего не делаем для пустой строки или нулевого указателя
    }

    char *writePtr = s; // Указатель для записи очищенной строки
    char *wordStart = s, *wordEnd = s;

    // Пропускаем начальные пробелы
    while (*wordStart == ' ') {
        wordStart++;
    }

    // Перебираем строку
    while (*wordStart != '\0') {
        wordEnd = wordStart;

        // Находим конец текущего слова
        while (*wordEnd != '\0' && *wordEnd != ' ') {
            wordEnd++;
        }

        // Проверяем, является ли найденная последовательность словом
        if (isWord(wordStart, wordEnd)) {
            // Копируем слово в новую строку
            while (wordStart < wordEnd) {
                *writePtr = *wordStart;
                writePtr++;
                wordStart++;
            }

            // Если это не последнее слово, добавляем один пробел
            if (*wordStart != '\0') {
                *writePtr = ' ';
                writePtr++;
            }
        }

        // Переходим к следующему слову
        wordStart = wordEnd;

        // Пропускаем пробелы между словами
        while (*wordStart == ' ') {
            wordStart++;
        }
    }

    // Удаляем завершающие пробелы
    if (writePtr > s && *(writePtr - 1) == ' ') {
        *(writePtr - 1) = '\0'; // Устанавливаем нуль-терминатор вместо последнего пробела
    } else {
        *writePtr = '\0'; // Устанавливаем нуль-терминатор
    }
}

// Функция для сравнения строк и вывода результата теста в stderr
void assertString(const char *expected, const char *actual) {
    if (my_strcmp(expected, actual) == 0) {
        fprintf(stderr, "OK\n");
    } else {
        fprintf(stderr, "Expected: \"%s\", Got: \"%s\"\n", expected, actual);
    }
}

// Тестирование функции removeAdjacentEqualLetters
void test_removeAdjacentEqualLetters() {
    char str1[] = "hello";
    removeAdjacentEqualLetters(str1);
    assertString("helo", str1);

    char str2[] = "aaabbbcccdddeee";
    removeAdjacentEqualLetters(str2);
    assertString("abcde", str2);

    char str3[] = "aabbcc";
    removeAdjacentEqualLetters(str3);
    assertString("abc", str3);

    char str4[] = "xyz";
    removeAdjacentEqualLetters(str4);
    assertString("xyz", str4);

    char str5[] = "";
    removeAdjacentEqualLetters(str5);
    assertString("", str5);

    char str6[] = "aaaa";
    removeAdjacentEqualLetters(str6);
    assertString("a", str6);

    char str7[] = "aabbaabb";
    removeAdjacentEqualLetters(str7);
    assertString("abab", str7);
}

// Тестирование функции removeExtraSpaces
void test_removeExtraSpaces() {
    char str1[] = "Hello     world";
    removeExtraSpaces(str1);
    assertString("Hello world", str1);

    char str2[] = "   This  is   a     test   string   ";
    removeExtraSpaces(str2);
    assertString("This is a test string", str2);

    char str3[] = "  One space  ";
    removeExtraSpaces(str3);
    assertString("One space", str3); // Только один пробел между словами

    char str4[] = "NoSpaces";
    removeExtraSpaces(str4);
    assertString("NoSpaces", str4); // Без пробелов, строка остается неизменной
}

int main() {
    test_removeAdjacentEqualLetters();
    test_removeExtraSpaces();
    return 0;
}
*/