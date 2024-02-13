#pragma once

/**
 * Note to implementer:
 * You probably want to use these functions from the C standard library.
 * malloc() / calloc()
 * free();
 * realloc()
 * memcpy()
 */

/* Error definitions. */

enum dynarray_error_t {
  ERR_OK = 0,       /** No error. */
  ERR_NULL = 1,     /** Error: an argument provided was null. */
  ERR_BADARG = 2,   /** Error: a non-pointer argument provided was invalid. */
  ERR_NO_ALLOC = 3, /** Error: a memory allocation failed internally. */
  ERR_BOUNDS = 4    /** Error: attempted to access an index of this array that does not exist. */
};

/**
 * Create a dynamic array, with the provided initial capacity and growth factor.
 *
 * @param size_t element_size the sizeof any given element
 * @param size_t capacity     the initial size of this array; this many elements
 *                            can be added without needing to grow the array
 * @param double growth_factor - how much bigger to grow the array when you attempt to add a new 
 *
 * @return a pointer to the created array or NULL if it failed to allocate
 **/
struct dynarray_t *dynarray_create(size_t capacity, size_t element_size, double growth_factor);

/**
 * Delete a dynarray. Does nothing if array is NULL
 */
void dynarray_destroy(struct dynarray_t *array);

/**
 * Adds an element to the end of this array.
 *
 * @param array the dynarray
 * @param p_in a pointer to the element to add
 *
 * Returns ERR_OK (0) on success
 * Returns ERR_NULL if array or p_in is NULL
 * Returns ERR_NO_ALLOC if append required a reallocation that failed
 */
int dynarray_append(struct dynarray_t *, void *p_in);

/**
 * Returns the number of elements stored in the dynarray.
 *
 * @returns 0 if array is NULL
 */
size_t dynarray_size(struct dynarray_t *);

/**
 * Returns the number of elements that *could* be stored in this dynarray
 * without triggering a reallocation.
 *
 * Returns the capacity of the dynarray, or 0 if the array is NULL
 */
size_t dynarray_capacity(struct dynarray_t *array);

/**
 * Stores a copy of the element in the location pointed at by 
 *
 * Returns ERR_OK (0) on success
 * Returns ERR_NULL if array or p_out is NULL
 * Returns ERR_BOUNDS if the provided index is not between 0 and size() - 1
 */
int dynarray_get(struct dynarray_t *array, size_t index, void *p_out);

/**
 * Sets the element at index 0 to the value pointed at by p_in.
 *
 * Returns ERR_OK (0) on success
 * Returns ERR_NULL if array or p_in is NULL
 * Returns ERR_BOUNDS if the provided index is not between 0 and size() - 1
 */
int dynarray_set(struct dynarray_t *array, size_t index, void *p_in);

/**
 * Removes the element at the provided index. Elements after this index are
 * shifted down by one. Copies the removed element to p_in, if it is provided.
 *
 * @param array the dynarray
 * @param index the index of the element to remove
 * @param p_in if not NULL, the removed element will be stored here
 *
 * Returns ERR_OK (0) on success
 * Returns ERR_NULL if array is null
 * Returns ERR_BOUNDS if the provided index is not between 0 and size() - 1
 */
int dynarray_remove(struct dynarray_t *, size_t index, void *p_out);
