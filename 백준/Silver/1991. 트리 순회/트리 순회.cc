#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    char data;
    char left;
    char right;
};

Node make_n(char a, char b, char c)
{
    Node temp;
    temp.data = a;
    temp.left = b;
    temp.right = c;
    return temp;
}

vector<Node> arr;
vector<char> idx;

void preorder(Node start)
{
    cout << start.data;

    if (start.left != '.')
    {
        auto left = find(idx.begin(), idx.end(), start.left);
        if (left != idx.end())
        {
            preorder(arr[left - idx.begin()]);
        }
    }

    if (start.right != '.')
    {
        auto right = find(idx.begin(), idx.end(), start.right);
        if (right != idx.end())
            preorder(arr[right - idx.begin()]);
    }
}

void inorder(Node start)
{

    if (start.left != '.')
    {
        auto left = find(idx.begin(), idx.end(), start.left);
        if (left != idx.end())
        {
            inorder(arr[left - idx.begin()]);
        }
    }

    cout << start.data;

    if (start.right != '.')
    {
        auto right = find(idx.begin(), idx.end(), start.right);
        if (right != idx.end())
            inorder(arr[right - idx.begin()]);
    }
}

void postorder(Node start)
{

    if (start.left != '.')
    {
        auto left = find(idx.begin(), idx.end(), start.left);
        if (left != idx.end())
        {
            postorder(arr[left - idx.begin()]);
        }
    }

    if (start.right != '.')
    {
        auto right = find(idx.begin(), idx.end(), start.right);
        if (right != idx.end())
            postorder(arr[right - idx.begin()]);
    }

    cout << start.data;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        char a, b, c;
        cin >> a >> b >> c;

        arr.push_back(make_n(a, b, c));
        idx.push_back(a);

        // preorder(arr[0]);
    }

    preorder(arr[0]);
    cout << endl;
    inorder(arr[0]);
    cout << endl;
    postorder(arr[0]);
    cout << endl;
}
