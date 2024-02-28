#include "dynarray.h"
// #include "dynarray.c"
#include <stdio.h>

// is there any way to not declaring below?
struct dynarray {
  size_t capacity;
  size_t element_size;
  double growth_factor;
  int *items_ptr;
  int length;
};

int test_remove(struct dynarray *array){
    printf("\n ----- test_remove started ----- \n");

    int removed_value;
    int result = dynarray_remove(array, 1, &removed_value);

    if (result != ERR_OK){
      printf("result should be ERR_OK :%d\n", result);
      return 1;
    } else {
      printf("Passed the ERR_OK test\n");
    }

    if (removed_value != 815){
      printf("Removed_value should be 815:%d\n", removed_value);
      return 1;
    } else {
      printf("Passed removed value test\n");
    }

    if (array->length != 1){
      printf("The length should be 1:%d\n", array->length);
      return 1;
    } else {
      printf("Passed the length test");
    }

    int result2 = dynarray_remove(array, 1, &removed_value);

    if (result2 != ERR_BOUNDS){
      printf("result2 should be ERROR_BOUNDS:%d\n", result2);
      return 1;
    } else {
      printf("Passed ERROR_BOUNDS test:%d\n", result2);
    }

    printf("----- All of the tests passed :D ----- \n\n");
    return 0;

}


int test_append_string(struct dynarray *array){
  char *name = "taesu";
  dynarray_append(array, &name);
  
  // if (array->items_ptr[0] != name){
  //   printf("Name 'taesu' should be appended:%c",array->items_ptr[0]);
  //   return 1;
  // } else {
  //   printf("Passed the string append test");
  // }
  

  return 0;
  
} 




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


    int result = test_remove(array);

    dynarray_destroy(array);


    struct dynarray *str_array = dynarray_create(1,4,2);


    // test_append_string(str_array);



    printf("Test finished\n");

   
    return 0;
};
