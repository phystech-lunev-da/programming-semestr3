
#include <stddef.h>

template <typename T>
void array_copy(T * const ds_begin, T * const src_begin, T * const src_end)
{
    size_t size = src_end - src_begin;
    T* const ds_end = ds_begin + size;

    T* ds_iter = ds_begin;
    T* src_iter = src_begin;

    while(ds_iter != ds_end && src_iter != src_end)
    {
        *ds_iter++ = *src_iter++;
    }
}

template void array_copy<int>(int * const ds_begin, int * const src_begin, int * const src_end);

#include <cassert>

int main() {
	int arr_src[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr_dst[10];
    array_copy(arr_dst, arr_src, arr_src + 10);
    for (unsigned idx = 0; idx != 10; ++idx)
  	    assert(arr_src[idx] == arr_dst[idx]);
	return 0;
}