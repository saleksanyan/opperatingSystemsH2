#include <stdio.h>

int main(){
    int num = 100;
    int *ptr = &num;
    int **dblPtr = &ptr;

    printf("Using pointer: %d\n", *ptr);

    printf("Using double pointer: %d\n", **dblPtr);

    return 0;
}
