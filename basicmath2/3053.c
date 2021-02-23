#include <stdio.h>
#include <math.h>

int main(void)
{
    int R;

    scanf("%d", &R);

    printf("%lf\n", M_PI * pow(R, 2));
    printf("%lf\n", pow(R * sqrt(2), 2));

    return 0;
}