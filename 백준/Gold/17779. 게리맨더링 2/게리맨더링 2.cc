#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int myMap[22][22];
int check[22][22];
bool visited[22][22];

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    int x, y;
    int d1, d2;
    int answer = 1000000000;

    for (x = 1; x <= N; x++)
    {
        for (y = 1; y <= N; y++)
        {
            for (d1 = 1; d1 <= N; d1++)
            {
                for (d2 = 1; d2 <= N; d2++)
                {
                    if (1 <= x && x < x + d1 + d2 && x + d1 + d2 <= N && 1 <= y - d1 && y - d1 < y && y + d2 <= N)
                    {
                        int p1, p2, p3, p4, p5;
                        p1 = p2 = p3 = p4 = p5 = 0;
                        memset(visited, 0, sizeof(visited));
                        memset(check, 0, sizeof(check));

                        for (int i = 0; i <= d1; i++)
                        {
                            if (!visited[x + i][y - i])
                            {
                                p5 += myMap[x + i][y - i];
                                visited[x + i][y - i] = true;
                            }
                        }

                        for (int i = 0; i <= d2; i++)
                        {
                            if (!visited[x + i][y + i])
                            {
                                p5 += myMap[x + i][y + i];
                                visited[x + i][y + i] = true;
                            }
                        }

                        for (int i = 0; i <= d2; i++)
                        {
                            if (!visited[x + d1 + i][y - d1 + i])
                            {
                                p5 += myMap[x + d1 + i][y - d1 + i];
                                visited[x + d1 + i][y - d1 + i] = true;
                            }
                        }

                        for (int i = 0; i <= d1; i++)
                        {
                            if (!visited[x + d2 + i][y + d2 - i])
                            {
                                p5 += myMap[x + d2 + i][y + d2 - i];
                                visited[x + d2 + i][y + d2 - i] = true;
                            }
                        }

                        // 1번 구역
                        for (int i = 1; i < x + d1; i++)
                        {
                            for (int j = 1; j <= y; j++)
                            {
                                if (!visited[i][j])
                                {
                                    p1 += myMap[i][j];
                                    visited[i][j] = true;
                                    check[i][j] = 1;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }

                        // 2번 구역
                        for (int i = 1; i <= x + d2; i++)
                        {
                            for (int j = N; j > y; j--)
                            {
                                if (!visited[i][j])
                                {
                                    p2 += myMap[i][j];
                                    visited[i][j] = true;
                                    check[i][j] = 2;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }

                        // 3번 구역
                        for (int i = x + d1; i <= N; i++)
                        {
                            for (int j = 1; j < y - d1 + d2; j++)
                            {
                                if (!visited[i][j])
                                {
                                    p3 += myMap[i][j];
                                    visited[i][j] = true;
                                    check[i][j] = 3;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }

                        // 4번 구역
                        for (int i = x + d2 + 1; i <= N; i++)
                        {
                            for (int j = N; j >= y - d1 + d2; j--)
                            {
                                if (!visited[i][j])
                                {
                                    p4 += myMap[i][j];
                                    visited[i][j] = true;
                                    check[i][j] = 4;
                                }
                                else
                                {
                                    break;
                                }
                            }
                        }

                        for (int i = 1; i <= N; i++)
                        {
                            for (int j = 1; j <= N; j++)
                            {
                                if (!visited[i][j])
                                {
                                    p5 += myMap[i][j];
                                    check[i][j] = 5;
                                    visited[i][j] = true;
                                }
                            }
                        }

                        if (p1 * p2 * p3 * p4 * p5 == 0)
                        {
                            continue;
                        }

                        int max_value = max(p1, max(p2, max(p3, max(p4, p5))));
                        int min_value = min(p1, min(p2, min(p3, min(p4, p5))));
                        // cout << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << "\n";
                        // cout << x << " " << y << " " << d1 << " " << d2 << " " << max_value - min_value << "\n";

                        // for (int i = 1; i <= N; i++)
                        // {
                        //     for (int j = 1; j <= N; j++)
                        //     {
                        //         cout << check[i][j] << " ";
                        //     }
                        //     cout << "\n";
                        // }
                        // cout << "\n";

                        if (max_value - min_value < answer)
                        {
                            answer = max_value - min_value;
                        }
                    }
                }
            }
        }
    }

    cout << answer << "\n";
}