#ifndef sorting_h
#define sorting_h

void merge_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));
void quick_sort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void *));


#endif