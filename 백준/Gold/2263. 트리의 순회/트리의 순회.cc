#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

vector<int> inorder;
vector<int> postorder;

void make_tree(int in_idx, int post_idx, int size)
{
    int root = postorder[post_idx + size - 1];
    int root_idx = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    cout << root << " ";

    int left_size = root_idx - in_idx;
    int right_size = size - left_size - 1;

    if (left_size > 0)
        make_tree(in_idx, post_idx, left_size);
    if (right_size > 0)
        make_tree(root_idx + 1, post_idx + left_size, right_size);
}

int main()
{
    cin >> N;
    int x;

    for (int i = 0; i < N; i++)
    {
        cin >> x;

        inorder.push_back(x);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> x;
        postorder.push_back(x);
    }

    make_tree(0, 0, N);

    cout << endl;
    return 0;
}
