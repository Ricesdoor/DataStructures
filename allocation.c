#include <stdio.h>
#include <stdlib.h>

// memory allocation method - malloc
// ptr = (cast-type*) malloc(byte-size)
// example:

int main() {

    int* ptr; //this pointer will hold the base address of the block created
    int n, i;

    printf("-----MALLOC-----\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Entered number of elements: %d\n", n);

    ptr = (int*)malloc(n * sizeof(int)); //memory allocated dynamically

    //checking if the memory was successfully allocated
    if(ptr == NULL) {
        printf("Memory not allocated. \n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated using malloc.\n");
    
        //getting the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        //print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i <n; i++) {
            printf("%d, ", ptr[i]);
        }
    }
}   

// contiguous allocation - calloc
// ptr = (cast-type*)calloc(n, element-size);
// similar to malloc, but initializes each block with '0' and has 2 arguments
// representing the number of elements and the size of each element, respectively

//free() method
//free(ptr);
//used to dinamically de-allocate memory.

int main2() {

    int *ptr, *ptr1;
    int n, i;

    n = 5;
    printf("\n---CALLOC/FREE---");
    printf("\nEnter the number of elements: %d\n", n);

    ptr = (int*)malloc(n * sizeof(int));

    ptr1 = (int*)calloc(n, sizeof(int));

    if (ptr == NULL || ptr1 == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
        printf("Memory successfully allocated using malloc.\n");

        free(ptr);
        printf("Malloc memory successfully freed.\n");

        printf("Memory successfully allocated using calloc.\n");

        free(ptr1);
        printf("Calloc memory successfully freed.\n");
    }
    return 0;
}