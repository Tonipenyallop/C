#include "dynarray.h"
// #include "dynarray.c"
#include <stdio.h>


struct dynarray {
  size_t capacity;
  size_t element_size;
  double growth_factor;
  int *items_ptr;
  int length;
};

int main(){
    printf("main is called\n");
    
    struct dynarray *array = dynarray_create(5,4,2);
    
    if(array == NULL){
        return 1;
    }


    int input = 10;
    int *ptr = &input;


    dynarray_append(array,ptr);
    
    printf("should be 10:%d\n", array->items_ptr[0]);
    // printf("array->items_ptr[0]:%d\n", array->items_ptr[0]);
    dynarray_destroy(array);

    printf("Test finished\n");
   
    return 0;
}