#include <stdio.h>

int N, nums[11], num_of_operators[4];
int result_of_calc, max = -1000000000, min = 1000000000;

void dfs(int depth)
{
    for(int i = 0, operator, tmp; i < 4; i++)
        if(num_of_operators[i])
        {
            operator = i;
            tmp = result_of_calc;
            switch(operator)
            {
                case 0:
                    result_of_calc += nums[depth];
                    break;
                case 1:
                    result_of_calc -= nums[depth];
                    break;
                case 2:
                    result_of_calc *= nums[depth];
                    break;
                case 3:
                    result_of_calc /= nums[depth];
                    break;
            }
            if(depth == N - 1)
            {
                if(result_of_calc > max)
                    max = result_of_calc;
                if(result_of_calc < min)
                    min = result_of_calc;
            }
            else
            {
                num_of_operators[i]--;
                dfs(depth + 1);
                num_of_operators[i]++;
            }
            result_of_calc = tmp;
        }
}

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%d", nums + i);
    for(int i = 0; i < 4; i++)
        scanf("%d", num_of_operators + i);

    result_of_calc = nums[0];
    dfs(1);

    printf("%d\n%d\n", max, min);

    return 0;
}