#include <stdio.h>
#include <stdlib.h>

int *union_array(int *a, int sz_a, int *b, int sz_b)
{
    int current_a = 0, current_b = 0;

    int *res = (int *)malloc(sizeof(int) * (sz_a + sz_b));
    while (current_a != sz_a && current_b != sz_b)
    {
        if (a[current_a] < b[current_b])
        {
            res[current_a + current_b] = a[current_a];
            current_a++;
        }
        else
        {
            res[current_a + current_b] = b[current_b];
            current_b++;
        }
    }

    while(current_a != sz_a)
    {
        res[current_a + current_b] = a[current_a];
        ++current_a;
    }

    while(current_b != sz_b)
    {
        res[current_a + current_b] = b[current_b];
        ++current_b;
    }

    return res;
}

int same_res(int *x, int sz)
{
    int elem = x[0];
    for(int i = 1; i < sz; ++i)
    {
        if (elem != x[i])
        {
            return 0;
        }
    }
    return 1;
}

int *quik_sort(int *array, int sz)
{
    if (sz <= 1)
    {
        return array;
    }
    int r = rand() % sz;
    int pivot = array[r];
    int left_size = 0;
    int right_size = 0;

    for (int i = 0; i < sz; ++i)
    {
        if (array[i] < pivot)
        {
            ++left_size;
        }
        else
        {
            ++right_size;
        }
    }

    if (left_size == 0)
    {
        if (same_res(array, right_size))
        {
            return array;
        }
    }

    if (right_size == 0)
    {
        if (same_res(array, left_size))
        {
            return array;
        }
    }

    int *left_array = (int *)malloc(sizeof(int) * left_size);
    int *right_array = (int *)malloc(sizeof(int) * right_size);

    int current_left = 0, current_right = 0;
    for (int i = 0; i < sz; ++i)
    {
        if (array[i] < pivot)
        {
            left_array[current_left++] = array[i];
        }
        else
        {
            right_array[current_right++] = array[i];
        }
    }

    left_array = quik_sort(left_array, left_size);
    right_array = quik_sort(right_array, right_size);

    int *res = union_array(left_array, left_size, right_array, right_size);
    return res;
}

void print_array(int *arr, int sz)
{
    for(int i = 0; i < sz; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    srand(NULL);
    int sz1 = 6;
    int *array1 = malloc(sizeof(int) * sz1); // {10, 2, 5, 4, 3, 2};
    array1[0] = 10;
    array1[1] = 2;
    array1[2] = 5;
    array1[3] = 4;
    array1[4] = 3;
    array1[5] = 2;

    int sz2 = 5;
    int *array2 = malloc(sizeof(int) * sz2); // {4, 4, 4, 4, 4};
    array2[0] = 4;
    array2[1] = 4;
    array2[2] = 4;
    array2[3] = 4;
    array2[4] = 4;

    print_array(array1, sz1);
    array1 = quik_sort(array1, sz1);
    print_array(array1, sz1);

    printf("\n");

    print_array(array2, sz2);
    array2 = quik_sort(array2, sz2);
    print_array(array2, sz2);

}