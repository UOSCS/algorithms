#include <iostream>

using namespace std;

struct TRIE
{
    bool finish;
    TRIE *Node[10];

    TRIE()
    {
        finish = false;
        for(int  i = 0; i < 10; i++)
            Node[i] = nullptr;
    }
    void insert(char *str);
    bool is_consistent(char *str);
};

void TRIE::insert(char *str)
{
    if(!*str)
    {
        finish = true;
        return;
    }
    int next_node = *str - '0';
    if(!Node[next_node])
        Node[next_node] = new TRIE();
    Node[next_node]->insert(str + 1);
}
bool TRIE::is_consistent(char *str)
{
    if(*str)
    {
        if(finish)
            return false;
        else
            return Node[*str - '0']->is_consistent(str + 1);
    }
    else
        return true;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;

    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n, flag = 1;
        TRIE root;
        cin >> n;
        char str[n][11];
        for(int j = 0; j < n; j++)
        {
            cin >> str[j];
            root.insert(str[j]);
        }
        for(int j = 0; j < n; j++)
            if(!root.is_consistent(str[j]))
            {
                flag = 0;
                break;
            }
        if(flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}