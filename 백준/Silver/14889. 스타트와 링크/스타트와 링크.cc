#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;

int myMap[21][21];
bool visited[21];
int ans = 100000000;

void backtracking(int idx, int pos)
{
    if (idx == N / 2)
    {
        int team1 = 0;
        int team2 = 0;
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < N; j++)
                {
                    if (j != i && visited[j])
                    {
                        team1 += myMap[i][j];
                    }
                }
            }
            else
            {
                for (int j = 0; j < N; j++)
                {
                    if (j != i && !visited[j])
                    {
                        team2 += myMap[i][j];
                    }
                }
            }
        }

        int sum = (team1 > team2 ? team1 - team2 : team2 - team1);

        if (sum < ans)
        {
            ans = sum;
        }

        return;
    }

    for (int i = pos; i < N; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            backtracking(idx + 1, i + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    backtracking(0, 0);

    cout << ans << endl;
}