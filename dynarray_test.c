#include "dynarray.h"
// #include "dynarray.c"
#include <stdio.h>



int main(){
    printf("main is called\n");
    
    struct dynarray *array = dynarray_create(1,4,2);
    
    int input = 521;

    int out;

    dynarray_append(array,&input);

    dynarray_get(array, 0, &out);

    if (out != input) {
      printf("the value should be 521: %d\n",out);
    }else {
      printf("passed Append test\n");
    }
    
    int get_result = dynarray_get(array, 1, &out);

    if (get_result != ERR_BOUNDS){
      printf("ERR_BOUNDS error should be thrown\n");
    }else {
      printf("Passed ERR_BOUNDS test\n");
    }

    int value = 77;

    dynarray_set(array, 0, &value);

    dynarray_get(array, 0, &out);


    if (out != 77) {
      printf("out should be 77:%d\n",out);
    }else {
      printf("passed set test\n");
    }



    int new_val = 815;
    dynarray_append(array,&new_val);
    size_t capacity = dynarray_capacity(array);

    if (capacity != 2){
      printf("capacity should be 2:%zu\n",capacity);
    } else {
      printf("Passed capacity test after appending element\n");
    }


    int expected_new_val;
    dynarray_get(array, 1,&expected_new_val);

    if (expected_new_val != new_val){
      printf("expected_new_val should be 815: %d\n",expected_new_val);
    }else {
      printf("passed get 1st index value\n");
    }


    int removed_value;
    dynarray_remove(array,1, &removed_value);

    if (removed_value != 815){
      printf("removed_value should be 815:%d\n", removed_value);
    }else {
      printf("Remove test1 passed\n");
    }

    // printf("should be 10:%d\n", array->items_ptr[0]);
    // printf("array->items_ptr[0]:%d\n", array->items_ptr[0]);
    dynarray_destroy(array);

    printf("Test finished\n");

   
    return 0;
}