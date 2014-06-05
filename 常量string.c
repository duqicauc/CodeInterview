#include <stdio.h>

char *
getstr1() {
    char a[] = "hello world";
    return a;
}

char *
getstr2() {
    char *a = "hello world";
    return a;
}

int
main(int argc, char *argv[]) {
    printf("%s\n", getstr1());

    printf("%s\n", getstr2());
    return 0;
}
