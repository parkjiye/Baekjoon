#include <iostream>
#include <vector>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int M, N;
int myMap[707][707];
int growing[707][707];
bool visited[707][707];

int dx[3] = {-1, -1, 0};
int dy[3] = {-1, 0, -1};

int main()
{
    FASTIO();
    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            myMap[i][j] = 1;
        }
    }

    for (int d = 0; d < N; d++)
    {
        memset(growing, 0, sizeof(growing));
        memset(visited, 0, sizeof(visited));

        vector<int> v;

        for (int i = 0; i < 3; i++)
        {
            int x;
            cin >> x;

            for (int j = 0; j < x; j++)
            {
                v.push_back(i);
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (i < M)
            {
                growing[M - 1 - i][0] = v[i];
                visited[M - 1 - i][0] = true;
            }
            else
            {
                growing[0][i - M + 1] = v[i];
                visited[0][i - M + 1] = true;
            }
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (!visited[i][j])
                {
                    int scale = 0;

                    for (int k = 0; k < 3; k++)
                    {
                        int next_x = i + dx[k];
                        int next_y = j + dy[k];

                        if (growing[next_x][next_y] > scale)
                        {
                            scale = growing[next_x][next_y];
                        }
                    }

                    growing[i][j] = scale;
                    visited[i][j] = true;
                }
            }
        }

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                myMap[i][j] += growing[i][j];
            }
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << myMap[i][j] << " ";
        }
        cout << "\n";
    }
}
