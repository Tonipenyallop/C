#include "dynarray.h"
// #include "dynarray.c"
#include <stdio.h>



int main(){
    printf("main is called\n");
    
    struct dynarray *array = dynarray_create(5,4,2);
    
    if(array == NULL){
        return 1;
    }


    int input = 10;

    int out;

    int value = 77;

    dynarray_append(array,&input);

    dynarray_get(array, 0, &out);

    if (out == input) {
      printf("the value is 10\n");
    }
    
    int get_result = dynarray_get(array, 1, &out);

    if (get_result == ERR_BOUNDS){
      printf("ERR_BOUNDS ERROR\n");
    }

    printf("output:%d\n", out);

    dynarray_set(array,0, &value);

    dynarray_get(array, 0, &out);


    if (out == 77) {
      printf("CONGRATS OUT IS 77\n");
    }



    
    
    // printf("should be 10:%d\n", array->items_ptr[0]);
    // printf("array->items_ptr[0]:%d\n", array->items_ptr[0]);
    dynarray_destroy(array);

    printf("Test finished\n");



  // int x = 6;
  // float f = 3.0f;
  // float value = f / x;
  // printf("value:%f\n", value);
  //   int ivalue = ((int) f) / x;
  // printf("value:%d\n", ivalue);

   
    return 0;
}