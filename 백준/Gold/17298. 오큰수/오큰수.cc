#include <iostream>
#include <stack>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();

    int N;
    cin >> N;

    vector<int> ans(N, -1);
    vector<int> v(N);

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    stack<int> s;

    for (int i = 0; i < N; i++)
    {
        // 현재 요소가 스택의 top 요소보다 크면, 스택에서 pop하고 그 인덱스의 ans에 현재 요소를 넣음
        while (!s.empty() && v[s.top()] < v[i])
        {
            ans[s.top()] = v[i];
            s.pop();
        }
        // 현재 인덱스를 스택에 push
        s.push(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";

    return 0;
}
