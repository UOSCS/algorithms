#include <iostream>

using namespace std;

struct TRIE
{
    bool finish;
    TRIE *Node[26];

    TRIE()
    {
        finish = false;
        for(int  i = 0; i < 26; i++)
            Node[i] = nullptr;
    }
    void insert(char *str);
    bool is_exist(char *str);
};

void TRIE::insert(char *str)
{
    if(!*str)
    {
        finish = true;
        return;
    }
    int next_node = *str - 'a';
    if(!Node[next_node])
        Node[next_node] = new TRIE();
    Node[next_node]->insert(str + 1);
}
bool TRIE::is_exist(char *str)
{
    if(!*str)
    {
        if(finish)
            return true;
        else
            return false;
    }

    if(Node[*str - 'a'])
        return Node[*str - 'a']->is_exist(str + 1);
    else
        return false;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    TRIE root;
    char str[10000][501];
    int N, M, count = 0;

    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> str[i];
        root.insert(str[i]);
    }
    for(int i = 0; i < M; i++)
    {
        char tmp[501];
        cin >> tmp;
        if(root.is_exist(tmp))
            count++;
    }
    
    cout << count;

    return 0;
}