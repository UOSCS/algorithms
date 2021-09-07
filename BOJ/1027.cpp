#include <iostream>

using namespace std;

int arr[50];

double get_slope(int i, int j)
{
    return ((double) arr[i] - (double) arr[j]) / ((double) i - (double) j);
}

int main(void)
{
    ios::sync_with_stdio(0);

    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    int answer = 0;

    for(int i = 0; i < N; i++)
    {
        int count = 0;

        for(int j = 0; j < N; j++)
        {
            if(i == j)
                continue;

            bool flag = true;
            int k = i;
            double threshold = get_slope(i, j);

            while(k != j)
            {
                double temp = get_slope(i, k);

                if((i > j && temp <= threshold) || (i < j && temp >= threshold))
                {
                    flag = false;
                    break;
                }

                if(k < j)
                    k++;
                else
                    k--;
            }

            if(flag)
                count++;
        }

        answer = max(answer, count);
    }

    cout << answer;

    return 0;
}