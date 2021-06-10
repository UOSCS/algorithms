#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, M, answer = 0;
    vector<int> crane, box;

    cin >> N;
    for(int i = 0, tmp; i < N; i++)
    {
        cin >> tmp;
        crane.push_back(tmp);
    }
    cin >> M;
    for(int i = 0, tmp; i < M; i++)
    {
        cin >> tmp;
        box.push_back(tmp);
    }
    
    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());
    if(crane.front() < box.front())
        cout << -1;
    else
    {
        while(box.size())
        {
            for(int i = 0; i < crane.size(); i++)
                for(int j = 0; j < box.size(); j++)
                    if(crane[i] >= box[j])
                    {
                        box.erase(box.begin() + j);
                        break;
                    }
            answer++;
        }
        cout << answer;
    }

    return 0;
}