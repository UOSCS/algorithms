#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);

    int N, K;
    list<int> arr;

    cin >> N >> K;

    for(int i = 1; i <= N; i++)
        arr.push_back(i);

    cout << "<";

    int print_count = 0;

    list<int>::iterator index = arr.begin();

    while(arr.size())
    {
        for(int i = 0; i < K - 1; i++)
            if(++index == arr.end())
                index = arr.begin();

        cout << *index;

        index = arr.erase(index);

        if(index == arr.end())
            index = arr.begin();

        if(++print_count < N)
            cout << ", ";
    }

    cout << ">";

    return 0;
}