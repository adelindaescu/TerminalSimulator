#include <stdio.h>

int main(int argc, char* argv[]) {
    int i = 0;
    if (argc == 1) {
        printf("Hello there!\n");
        fflush(stdout);
    }

    for (i = 1; i < argc; i++) {
        printf("Hello %s!\n", argv[i]);
        fflush(stdout);
    }
    return 0;
}
