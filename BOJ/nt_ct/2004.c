#include <stdio.h>

unsigned long get_count_of_factor(unsigned long n, unsigned long factor)
{
    unsigned long result = 0;

    for(unsigned long tmp = factor; factor <= n; factor *= tmp)
        result += n / factor;
    
    return result;
}

int main(void)
{
    unsigned long n, m, count_5, count_2;

    scanf("%lu %lu", &n, &m);

    count_5 = get_count_of_factor(n, 5UL) - get_count_of_factor(n - m, 5UL) - get_count_of_factor(m, 5UL);
    count_2 = get_count_of_factor(n, 2UL) - get_count_of_factor(n - m, 2UL) - get_count_of_factor(m, 2UL);
    printf("%lu\n", count_2 > count_5 ? count_5 : count_2);

    return 0;
}