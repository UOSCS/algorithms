#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *link;
} ListNode;
typedef struct
{
    ListNode *head;
} LinkedListType;

void init(LinkedListType *L);
void add_first(LinkedListType *L, int item);
void add_last(LinkedListType *L, int item);
void add(LinkedListType *L, int pos, int item);
int remove_first(LinkedListType *L);
int remove_last(LinkedListType *L);
int _remove(LinkedListType *L, int pos);
int get(LinkedListType *L, int pos);
void set(LinkedListType *L, int pos, int item);
void print_list(LinkedListType *L);

int main()
{
    LinkedListType list;
    int pos;

    init(&list);

    printf("Add...\n");
    add_first(&list, 10); print_list(&list);
    add_first(&list, 20); print_list(&list);
    add(&list, 2, 40);    print_list(&list);
    add_first(&list, 30); print_list(&list);
    
    printf("Remove...\n");
    remove_first(&list);  print_list(&list);
    _remove(&list, 2);    print_list(&list);
    remove_last(&list);   print_list(&list);
    _remove(&list, 0);  print_list(&list);
    
    printf("Add again...\n");
    add_first(&list, 10); print_list(&list);
    add_first(&list, 20); print_list(&list);
    add_last(&list, 40);  print_list(&list);
    add_first(&list, 30); print_list(&list);

    printf("Set new item...\n");
    set(&list, 1, 100);   print_list(&list);

    printf("\nEnter a position(started with 0): ");
    scanf("%d", &pos);
    printf("Here's what you want!: %d\n\n", get(&list, pos));
}

void init(LinkedListType *L)
{
    L->head = NULL;
}
void add_first(LinkedListType *L, int item)
{
    ListNode *node = malloc(sizeof(ListNode));

    node->data = item;
    node->link = L->head;
    L->head = node;
}
void add_last(LinkedListType *L, int item)
{
    ListNode *node = malloc(sizeof(ListNode));
    ListNode *p = L->head;

    node->data = item;
    node->link = NULL;
    while(p->link)
        p = p->link;
    p->link = node;
}
void add(LinkedListType *L, int pos, int item)
{
    ListNode *node = malloc(sizeof(ListNode));
    ListNode *before = L->head;

    for(int i = 0; i < pos - 1; i++)
        before = before->link;
    node->data = item;
    node->link = before->link;
    before->link = node;
}
int remove_first(LinkedListType *L)
{
    if(!(L->head))
    {
        fprintf(stderr, "List is already empty.\n");
        exit(1);
    }

    ListNode *p = L->head;
    int temp = p->data;

    L->head = p->link;
    free(p);

    return temp;
}
int remove_last(LinkedListType *L)
{
    if(!(L->head))
    {
        fprintf(stderr, "List is already empty.\n");
        exit(1);
    }

    ListNode *p, *before;
    int temp;

    for(before = p = L->head; p->link; before = p, p = p->link)
        continue;
    temp = p->data;
    p == L->head ? L->head = NULL : (before->link = NULL);
    free(p);

    return temp;
}
int _remove(LinkedListType *L, int pos)
{
    if(!(L->head))
    {
        fprintf(stderr, "List is already empty.\n");
        exit(1);
    }

    ListNode *p = L->head;
    int temp;

    for(int i = 0; i < pos - 1; i++)
        p = p->link;
    if(!(p->link))
    {
        temp = p->data;
        L->head = NULL;
        free(p);
    }
    else
    {
        temp = p->link->data;
        p->link = p->link->link;
        free(p->link);
    }

    return temp;
}
int get(LinkedListType *L, int pos)
{
    ListNode *p = L->head;

    for(int i = 0; i < pos; i++)
        p = p->link;
    return p->data;
}
void set(LinkedListType *L, int pos, int item)
{
    ListNode *p = L->head;

    for(int i = 0; i < pos; i++)
        p = p->link;
    p->data = item;
}
void print_list(LinkedListType *L)
{
    for(ListNode *p = L->head; p; p = p->link)
        printf("[%d] -> ", p->data);
    printf("NULL\n");
}