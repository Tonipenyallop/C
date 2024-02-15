#include "dynarray.h"

struct dynarray {
  size_t capacity;
  size_t element_size;
  double growth_factor;
  int *items_ptr;
  int length;
};

struct dynarray *dynarray_create(size_t capacity, size_t element_size, double growth_factor){
  printf("dynarray_create was called\n");
  struct dynarray *d = malloc(sizeof(struct dynarray));
  printf("%lu\n",sizeof(struct dynarray));

  if (d == NULL){
    return NULL;
  }


  d->items_ptr = (int*) malloc(capacity * element_size);

  if (d->items_ptr == NULL){
    free(d);
    return NULL; 
  }
  d->capacity = capacity;
  d->element_size = element_size;
  d->growth_factor = growth_factor;
  d->length = 0;
  return d;
}


void dynarray_destroy(struct dynarray *array){
    free(array);
    printf("dynarray destroyed\n");
}




int dynarray_append(struct dynarray *array, void *p_in){
    printf("dynarray_append was called\n");
    if (array == NULL || p_in == NULL){
        return ERR_NULL;
    }

    printf("append was called\n");
    printf("array length:%d\n",array->length);
    

    // if capacity available
    if (array->length < array->capacity ){
        array->items_ptr[array->length] = 10;
        array->length += 1;
        return ERR_OK;
    }

    // else {
    //     array->capacity *= array->growth_factor;

    //     array = realloc(array,array->capacity * array->element_size);
    //     if (array == NULL){
    //         return ERR_NO_ALLOC;
    //     }

    //     array->length += 1;
    //     return ERR_OK;
    // }
    


    return ERR_OK;

}

