/*#include <stdio.h>
#include "tasks/string_.h"
#include <ctype.h> // Для использования функции isdigit
#include <windows.h>

// Макрос для упрощения использования функции assertString
#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)
#define MAX_STRING_SIZE 100

void replaceDigitsWithSpaces(char *s) {
    if (s == NULL) {
        return; // Защита от нулевого указателя
    }

    int length = string_length(s);
    if (length == 0) {
        return; // Ничего не делаем для пустой строки
    }

    char buffer[MAX_STRING_SIZE]; // Временный буфер для измененной строки
    int bufferIndex = 0;

    // Перебираем каждый символ исходной строки
    for (int i = 0; i < length; ++i) {
        if (isdigit(s[i])) { // Если текущий символ - цифра
            int digit = s[i] - '0'; // Получаем целочисленное значение цифры

            // Заполняем буфер соответствующим количеством пробелов
            for (int j = 0; j < digit; ++j) {
                if (bufferIndex < MAX_STRING_SIZE - 1) {
                    buffer[bufferIndex++] = ' ';
                } else {
                    break; // Предотвращаем переполнение буфера
                }
            }
        } else {
            // Просто копируем текущий символ, если это не цифра
            if (bufferIndex < MAX_STRING_SIZE - 1) {
                buffer[bufferIndex++] = s[i];
            } else {
                break; // Предотвращаем переполнение буфера
            }
        }
    }

    // Добавляем завершающий нуль-символ, чтобы получить корректную строку
    buffer[bufferIndex] = '\0';

    // Копируем измененную строку обратно в исходный массив
    strcpy(s, buffer);
}

// Функция для сравнения ожидаемой строки с фактической и вывода сообщения об ошибке при несоответствии
void assertString(const char *expected, const char *got, const char *fileName, const char *funcName, int line) {
    if (my_strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Тесты для функции replaceDigitsWithSpaces
void testReplaceDigitsWithSpaces() {
    char s1[MAX_STRING_SIZE] = "abc123def";
    replaceDigitsWithSpaces(s1);
    ASSERT_STRING("abc      def", s1);

    char s2[MAX_STRING_SIZE] = "1a2b3c4d5";
    replaceDigitsWithSpaces(s2);
    ASSERT_STRING(" a  b   c    d     ", s2);

    char s3[MAX_STRING_SIZE] = "no_digits_here";
    replaceDigitsWithSpaces(s3);
    ASSERT_STRING("no_digits_here", s3);

    char s4[MAX_STRING_SIZE] = "12345678901234567890";
    replaceDigitsWithSpaces(s4);
    ASSERT_STRING("                                                                                          ", s4);

    char s5[MAX_STRING_SIZE] = "";
    replaceDigitsWithSpaces(s5);
    ASSERT_STRING("", s5);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    // Вызываем тесты для функции replaceDigitsWithSpaces
    testReplaceDigitsWithSpaces();
    return 0;
}*/