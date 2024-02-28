#include <string.h>
#include <stdio.h>
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
    if (array == NULL || p_in == NULL){
        return ERR_NULL;
    }

    
    if (array->length >= array->capacity ){
        // reallocate memory
        double new_capacity = array->capacity * array->growth_factor;
        int *realloc_ptr = realloc(array->items_ptr, new_capacity * sizeof(array->element_size));
        
        if (realloc_ptr == NULL){
          dynarray_destroy(array);
          return ERR_NO_ALLOC;
        }
        *array->items_ptr = *realloc_ptr;
        array->capacity = new_capacity;
    }

    memcpy(&(array->items_ptr[array->length]), p_in, array->element_size + 1);
    
    array->length += 1;
    return ERR_OK;
    
}

size_t dynarray_size(struct dynarray *array){
 if (array == NULL){
    return ERR_NULL;
  }
  return array->length; 
}

size_t dynarray_capacity(struct dynarray *array){
  if (array == NULL){
    return ERR_NULL;
  }
  return array->capacity;
}

int dynarray_get(struct dynarray *array, size_t index, void *p_out){

  if (array == NULL || p_out == NULL) {
    return ERR_NULL;
  }
  
  if (index > array->length - 1){
    return ERR_BOUNDS;
  }


  *((int *) p_out) = array->items_ptr[index];


  return ERR_OK;  
}

int dynarray_set(struct dynarray *array, size_t index, void *p_in){
  if (array == NULL || p_in == NULL){
    return ERR_NULL;
  }

  if (index > array->length - 1){
    return ERR_BOUNDS;
  }

  array->items_ptr[index] = *(int*) p_in;

  return ERR_OK;

}

int dynarray_remove(struct dynarray *array, size_t index, void *p_out){
  if (array == NULL || p_out == NULL){
    return ERR_NULL;
  }

  if (index >= array->length){
    return ERR_BOUNDS;
  }

  *(int*)p_out = array->items_ptr[index];

  // 1. Create a same size array
  int *tmp_ptr = malloc(array->capacity * array->element_size);

  if (tmp_ptr == NULL){
    return ERR_NO_ALLOC;
  }

  // 2. Copy till ith element
  for (int i = 0; i < index; i++){
    tmp_ptr[i] = array->items_ptr[i];
  }

  // 3. Update length
  array->length -= 1;

  // 4. Copy from ith till ith element
  for (int i = index; i < array->length; i++){
    tmp_ptr[i] = array->items_ptr[i];
  }

  // 5. Clean the memory
  free(array->items_ptr);

  // 6. Reassign item_ptr
  array->items_ptr = tmp_ptr;
  
  return ERR_OK;


}