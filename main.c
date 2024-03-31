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

int main() {
    test_strlen();
    printf("All tests passed successfully!\n");
    return 0;
}
