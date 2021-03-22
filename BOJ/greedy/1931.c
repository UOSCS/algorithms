#include <stdio.h>
#include <stdlib.h>

#define SIZE 100001

typedef struct
{
    int start;
    int end;
} Discussion;
typedef struct
{
    Discussion heap[SIZE];
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

void insert_min_heap(Heap *h, Discussion discussion)
{
    int i;

    for(i = ++(h->heap_size); (i != 1 && (discussion.end < h->heap[i / 2].end)) || (discussion.end == h->heap[i / 2].end && discussion.start < h->heap[i / 2].start); i /= 2)
        h->heap[i] = h->heap[i / 2];
    h->heap[i] = discussion;
}

Discussion delete_min_heap(Heap *h)
{
    int parent = 1;
    Discussion tmp = h->heap[1], key = h->heap[h->heap_size--];

    for(int child = 2; child <= h->heap_size; parent = child, child *= 2)
    {
        if(h->heap[child].end > h->heap[child + 1].end || (h->heap[child].end == h->heap[child + 1].end && h->heap[child].start > h->heap[child + 1].start))
            child++;

        if((h->heap[child].end < key.end) || (h->heap[child].end == key.end && h->heap[child].start < key.start))
            h->heap[parent] = h->heap[child];
        else
            break;
    }
    h->heap[parent] = key;

    return tmp;
}

int main(void)
{
    int N, count = 0;
    Heap *h;

    create(&h);
    init(h);

    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        Discussion discussion;
        scanf("%d %d", &discussion.start, &discussion.end);
        insert_min_heap(h, discussion);
    }

    for(int prev_end_time = 0, i = 0; i < N; i++)
    {
        Discussion discussion;
        if((discussion = delete_min_heap(h)).start >= prev_end_time)
        {
            prev_end_time = discussion.end;
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}