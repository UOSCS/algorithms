#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main(void)
{
    int N, K, arr[100], flag[101] = {0}, count = 0, result = 0;
    vector<int> v;

    cin >> N >> K;
    for(int i = 0; i < K; i++)
        cin >> arr[i];

    for(int i = 0; i < K; i++)
    {
        if(count < N && !flag[arr[i]])
        {
            flag[arr[i]] = 1;
            count++;
            v.push_back(arr[i]);
        }
        else if(!flag[arr[i]])
        {
            priority_queue<tuple<int, int, int>> pq;
            int index = 0;
            while(index < v.size())
            {
                int tmp = v[index];
                for(int j = i + 1; j < K; j++)
                    if(arr[j] == tmp)
                    {
                        pq.push({ j, tmp, index });
                        break;
                    }
                    else if(j == K - 1)
                        pq.push({ K, tmp, index });
                index++;
            }
            if(!pq.empty())
            {
                flag[get<1>(pq.top())] = 0;
                flag[arr[i]] = 1;
                v[get<2>(pq.top())] = arr[i];
            }
            result++;
        }
    }

    cout << result << '\n';

    return 0;
}