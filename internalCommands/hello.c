#include <stdio.h>

int main(int argc, char* argv[]) {
    int i = 0;
    for (i = 0; i < argc; i++) {
        System.out.println("Hello %s!", argv[i]);
    }
    return 0;
}
