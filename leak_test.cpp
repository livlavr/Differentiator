#include <stdio.h>
#include <stdlib.h>

int main() {
    int* pointer = NULL;
    for(size_t i = 0; i < 10; i++)
        pointer = (int*)calloc(5, sizeof(int));
    pointer = NULL;
}
