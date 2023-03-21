#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, M;
vector<int> arr;
int path[8];
vector<vector<int>> s;
set<string> st;

void backtracking(int idx)
{
    if (idx == M)
    {
        vector<int> temp;
        string tmp;

        for (int i = 0; i < M; i++)
        {
            temp.push_back(arr[path[i]]);
            tmp += to_string(arr[path[i]]);
            tmp += " ";
        }

        if (st.find(tmp) != st.end())
        {
            return;
        }
        else
        {
            s.push_back(temp);
            st.insert(tmp);
        }
    }
    else
    {
        for (int i = 0; i < arr.size(); i++)
        {
            if (idx == 0 || path[idx - 1] <= i)
            {
                path[idx] = i;
                backtracking(idx + 1);
            }
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    backtracking(0);

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}