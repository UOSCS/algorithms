#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000001

typedef struct
{
    int heap[SIZE];
    int heap_size;
} Heap;

Heap *create(Heap **h)
{
    *h = malloc(sizeof(Heap));
}

void init(Heap *h)
{
    h->heap_size = 0;
}

void insert_min_heap(Heap *h, int n)
{
    int i;

    for(i = ++(h->heap_size); i != 1 && (n < h->heap[i / 2]); i /= 2)
        h->heap[i] = h->heap[i / 2];
    h->heap[i] = n;
}

int delete_min_heap(Heap *h)
{
    int tmp = h->heap[1], parent = 1, key = (h->heap[h->heap_size--]);

    for(int child = 2; child <= h->heap_size; parent = child, child *= 2)
    {
        if(h->heap[child] > h->heap[child + 1])
            child++;

        if(h->heap[child] < key)
            h->heap[parent] = h->heap[child];
        else
            break;
    }
    h->heap[parent] = key;

    return tmp;
}

int main(void)
{
    Heap *h;
    int N, *arr;

    create(&h);
    init(h);

    scanf("%d", &N);

    arr = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++)
    {
        scanf("%d", arr + i);
        insert_min_heap(h, arr[i]);
    }

    for(int i = 0; i < N; i++)
        printf("%d\n", delete_min_heap(h));

    return 0;
}