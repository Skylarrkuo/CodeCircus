#include <stdio.h>

union hh {
    char ch[6];
    float a;
    float b;
};

struct xx {
    double w;
    union hh u;
    float v[5];
};

int main() {
    struct xx vh;
    printf("Size of struct xx: %lu bytes\n", sizeof(vh));
    return 0;
}
