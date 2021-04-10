#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int heap[SIZE];
    int size;
} Heap;

void init(Heap *h);
void get_user_input(Heap *h);
void print_lastnode(Heap *h);
void insert_item(Heap *h, int key);
char *binary_expansion(int n);
int find_lastnode(Heap *h);

int main(void)
{
    Heap *h = malloc(sizeof(Heap));

    init(h);

    get_user_input(h);

    print_lastnode(h);

    free(h);

    return 0;
}

void init(Heap *h)
{
    h->size = 0;
}

void get_user_input(Heap *h)
{
    int n;
    printf("Enter the size of heap: ");
    scanf("%d", &n);
    if(n < 1)
    {
        printf("Invalid value of 'n'\n");
        exit(0);
    }
    printf("Enter the key of %d nodes: ", n);
    for(int i = 0, tmp; i < n; i++)
    {
        scanf("%d", &tmp);
        insert_item(h, tmp);
    }
}

void print_lastnode(Heap *h)
{
    printf("The last node of heap: %d\n", find_lastnode(h));
}

void insert_item(Heap *h, int key)
{
    int i;
    
    for(i = ++(h->size); i > 1 && (key < h->heap[i / 2]); i /= 2)
        h->heap[i] = h->heap[i / 2];
    h->heap[i] = key;
}

char *binary_expansion(int n)
{
    int pos_of_mib = 32, index = 0;
    int length_of_int = sizeof(int) << 3;
    char *arr = malloc(length_of_int);

    for(int i = 1 << (length_of_int - 2), count = 1; i > 0; i >>= 1, count++)
        if(i & n)
        {
            pos_of_mib = length_of_int - count;
            break;
        }
    for(int i = 1 << (pos_of_mib - 2); i > 0; i >>= 1)
        if(i & n)
            arr[index++] = '1';
        else
            arr[index++] = '0';
    arr[index] = '\0';

    return arr;
}

int find_lastnode(Heap *h)
{
    char *bin = binary_expansion(h->size);
    int  lastnode = 1;

    for(int  i = 0; bin[i]; i++)
        if(bin[i] == '1')
            lastnode = (lastnode << 1) + 1;
        else
            lastnode <<= 1;

    free(bin);

    return h->heap[lastnode];
}