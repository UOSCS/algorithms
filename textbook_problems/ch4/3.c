#include <stdio.h>
#include <stdlib.h>

typedef struct Candle
{
    int elem;
    struct Candle *next;
} Candle;

int candle(int, int);
void build_list(Candle *, int);
int run_simulation(Candle *, int, int);

int main(void)
{
    int n, k;

    printf("Enter 'n' and 'k' in order: ");
    scanf("%d %d", &n, &k);

    printf("The position of the last candle: %d\n", candle(n, k));

    return 0;
}

int candle(int n, int k)
{
    Candle head;
    build_list(&head, n);
    return run_simulation(&head, n, k);
}

void build_list(Candle *head, int n)
{
    Candle *node = malloc(sizeof(Candle));

    node->elem = 1;
    head->next = node;
    for(int i = 2; i <= n; i++)
    {
        node->next = malloc(sizeof(Candle));
        node = node->next;
        node->elem = i;
    }
    node->next = head->next;
}

int run_simulation(Candle *head, int n, int k)
{
    Candle *p = head->next;
    int re_tmp;

    for(Candle *ca_tmp ; p != p->next; p = p->next)
    {
        for(int i = 0; i < k - 1; i++)
            p = p->next;
        ca_tmp = p->next;
        p->next = p->next->next;
        free(ca_tmp);
    }
    re_tmp = p->elem;
    free(p);
    return re_tmp;
}