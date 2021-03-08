#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 20001

typedef struct
{
    char *heap[SIZE];
    int heap_size;
} Heap;

void create(Heap **h)
{
    *h = malloc(sizeof(Heap));
}

void init(Heap *h)
{
    h->heap_size = 0;
}

void insert_min_heap(Heap *h, char *word)
{
    int i;

    for(i = ++(h->heap_size); i != 1 && (strlen(word) <= strlen(h->heap[i / 2])); i /= 2)
        if(strlen(word) == strlen(h->heap[i / 2]))
        {
            if(strcmp(word, h->heap[i / 2]) == -1)
                h->heap[i] = h->heap[i / 2];
            else
                break;
        }
        else
            h->heap[i] = h->heap[i / 2];
    h->heap[i] = word;
}

char *delete_min_heap(Heap *h)
{
    char *tmp = h->heap[1], *key = h->heap[h->heap_size--];
    int parent = 1;

    for(int child = 2; child <= h->heap_size; parent = child, child *= 2)
    {
        if(child < h->heap_size && strlen(h->heap[child]) >= strlen(h->heap[child + 1]))
        {
            if(strlen(h->heap[child]) > strlen(h->heap[child + 1]))
                child++;
            else
                if(strcmp(h->heap[child], h->heap[child + 1]) == 1)
                    child++;
        }

        if(strlen(h->heap[child]) <= strlen(key))
        {
            if(strlen(h->heap[child]) < strlen(key))
                h->heap[parent] = h->heap[child];
            else
                if(strcmp(h->heap[child], key) == -1)
                    h->heap[parent] = h->heap[child];
                else
                    break;
        }
        else
            break;
    }
    h->heap[parent] = key;

    return tmp;
}

int main(void)
{
    Heap *h;
    int N;
    char **arr;

    create(&h);
    init(h);

    scanf("%d", &N);

    arr = (char **)malloc(sizeof(char *) * N);
    for(int i = 0; i < N; i++)
    {
        arr[i] = malloc(sizeof(char) * 51);
        h->heap[i + 1] = malloc(sizeof(char) * 51);
    }
        
    for(int i = 0, flag = 0; i < N; i++, flag = 0)
    {
        scanf("%50s", arr[i]);
        for(int j = 1; j <= h->heap_size; j++)
            if(!strcmp(h->heap[j], arr[i]))
            {
                flag = 1;
                break;
            }
        
        if(!flag)
            insert_min_heap(h, arr[i]);
    }

    for(int i = 0, count = h->heap_size; i < count; i++)
        printf("%s\n", delete_min_heap(h));

    return 0;
}