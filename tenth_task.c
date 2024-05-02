#include <stdio.h>
#include "tasks/string_.h"

#define ASSERT_STRING(expected, got) assertString(expected, got, __FILE__, __FUNCTION__, __LINE__)

// функция для определения пробельных символов
int isSpace(char ch) {
    return (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r');
}

void reverseRange(char *begin, char *end) {
    // Переворачиваем слово, заданное диапазоном [begin, end)
    while (begin < end) {
        char temp = *begin;
        *begin = *end;
        *end = temp;
        begin++;
        end--;
    }
}

void reverseWordsInPlace(char *sentence) {
    char *current = sentence;
    char *wordBegin = NULL;

    // Перебираем строку посимвольно
    while (*current != '\0') {
        // Если текущий символ - буква, это начало нового слова
        if (!isSpace(*current)) {
            if (wordBegin == NULL) {
                wordBegin = current;
            }
        } else {
            // Если текущий символ - пробел или знак пунктуации и мы находимся внутри слова
            if (wordBegin != NULL) {
                reverseRange(wordBegin, current - 1); // Переворачиваем слово
                wordBegin = NULL; // Сбрасываем указатель начала слова
            }
        }
        current++;
    }

    // Последнее слово в строке нужно перевернуть от wordBegin до конца строки
    if (wordBegin != NULL) {
        reverseRange(wordBegin, current - 1);
    }

    // Теперь нужно перевернуть всю строку, чтобы слова были в правильном порядке
    reverseRange(sentence, current - 1);
}

// Функция для вывода сообщения об ошибке или успешном выполнении теста
void assertString(const char *expected, char *got, const char *fileName, const char *funcName, int line) {
    if (my_strcmp(expected, got)) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else {
        fprintf(stderr, "%s - OK\n", funcName);
    }
}

// Тестовая функция для проверки работы функции reverseWordsInPlace
void testReverseWordsInPlace() {
    // Тест на пустую строку
    char s1[] = "";
    reverseWordsInPlace(s1);
    ASSERT_STRING("", s1);

    // Тест на строку с одним словом
    char s2[] = "Hello";
    reverseWordsInPlace(s2);
    ASSERT_STRING("Hello", s2);

    // Тест на строку с несколькими словами и знаками препинания
    char s3[] = "Hello world! Good morning.";
    reverseWordsInPlace(s3);
    ASSERT_STRING("morning. Good world! Hello", s3);

    // Добавьте другие тесты здесь

    // Тест на строку с особыми случаями (например, много пробелов, знаков препинания и т. д.)
    char s4[] = "   How     are you?    ";
    reverseWordsInPlace(s4);
    ASSERT_STRING("    you? are     How   ", s4);
}

int main() {
    // Запуск теста
    testReverseWordsInPlace();
    return 0;
}