#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int T, N, K, A;

int inDegree[1005];
int inTime[1005];
int outTime[1005];

int main()
{
    FASTIO();
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++)
    {
        cin >> N >> K;

        vector<int> myMap[1005];

        memset(inDegree, 0, sizeof(inDegree));
        memset(inTime, 0, sizeof(inTime));
        memset(outTime, 0, sizeof(outTime));

        for (int i = 1; i <= N; i++)
        {
            int t;
            cin >> t;

            inTime[i] = t;
        }

        for (int i = 0; i < K; i++)
        {
            int x, y;
            cin >> x >> y;

            myMap[x].emplace_back(y);
            inDegree[y] += 1;
        }

        cin >> A;

        queue<int> q;

        for (int i = 1; i <= N; i++)
        {
            if (inDegree[i] == 0)
            {
                outTime[i] = inTime[i];
                q.push(i);
            }
        }

        for (int i = 0; i < N; i++)
        {
            int cur = q.front();
            q.pop();

            inTime[cur] = outTime[cur];

            if (cur == A)
            {
                cout << outTime[cur] << endl;
                break;
            }

            for (int k = 0; k < myMap[cur].size(); k++)
            {
                int next = myMap[cur][k];
                int temp = inTime[next] + inTime[cur];

                if (temp > outTime[next])
                {
                    outTime[next] = temp;
                }

                if (--inDegree[next] == 0)
                {
                    q.push(next);
                }
            }
        }
    }
}