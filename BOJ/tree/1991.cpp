#include <iostream>

using namespace std;

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} Node;

Node arr[26];

void pre_order(Node *node)
{
    cout << node->data;
    if(node->left)
        pre_order(node->left);
    if(node->right)
        pre_order(node->right);
}

void in_order(Node *node)
{
    if(node->left)
        in_order(node->left);
    cout << node->data;
    if(node->right)
        in_order(node->right);
}

void post_order(Node *node)
{
    if(node->left)
        post_order(node->left);
    if(node->right)
        post_order(node->right);
    cout << node->data;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int index;
        char value, left_child, right_child;
        cin >> value >> left_child >> right_child;
        index = value - 'A';
        arr[index].data = value;
        if(left_child != '.')
            arr[index].left = &arr[left_child - 'A'];
        else
            arr[index].left = nullptr;
        if(right_child != '.')
            arr[index].right = &arr[right_child - 'A'];
        else
            arr[index].right = nullptr;
    }

    pre_order(arr);
    cout << '\n';
    in_order(arr);
    cout << '\n';
    post_order(arr);
    cout << '\n';

    return 0;
}