#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data) : data(data), left(nullptr), right(nullptr){};
};

void make_tree(Node *node, int x)
{
    if (x < node->data)
    {
        if (node->left == nullptr)
        {
            node->left = new Node(x);
        }
        else
        {
            make_tree(node->left, x);
        }
    }
    else
    {
        if (node->right == nullptr)
        {
            node->right = new Node(x);
        }
        else
        {
            make_tree(node->right, x);
        }
    }
}

void print_tree(Node *node)
{
    if (node->left != nullptr)
        print_tree(node->left);
    if (node->right != nullptr)
        print_tree(node->right);
    cout << node->data << endl;
}

int main()
{
    FASTIO();

    int x;
    cin >> x;

    Node *root = new Node(x);

    while (cin >> x)
    {
        make_tree(root, x);
    }

    print_tree(root);
}
