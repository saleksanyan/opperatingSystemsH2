#include <stdio.h>

int main() {
    int num = 10;
    int* ptr = &num;

    printf("Address of num using &num: %p\n", (void*)&num);
    printf("Address of num using the pointer ptr: %p\n", (void*)ptr);

    *ptr = 20;

    printf("New value of num after modification through pointer: %d\n", num);

    return 0;
}
