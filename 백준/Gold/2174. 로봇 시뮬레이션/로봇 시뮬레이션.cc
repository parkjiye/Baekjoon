#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int myMap[101][101];
int A, B;
int N, M;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

struct p
{
    int x;
    int y;
    int d;
};

vector<p> robots;
bool flag;

p make_p(int x, int y, int d)
{
    p temp;
    temp.x = x;
    temp.y = y;
    temp.d = d;
    return temp;
}

int main()
{
    cin >> A >> B;

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x, y;
        char d;

        cin >> y >> x >> d;

        int w;
        if (d == 'N')
            w = 0;
        else if (d == 'W')
            w = 1;
        else if (d == 'E')
            w = 3;
        else
            w = 2;

        robots.push_back(make_p(B - x, y-1, w));

        myMap[B - x][y-1] = 1;
    }

    // for (int i = 0; i < B; i++)
    // {
    //     for (int j = 0; j < A; j++)
    //     {
    //         cout << myMap[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < M; i++)
    {
        int r, c;
        char o;

        cin >> r >> o >> c;

        if(flag) continue;

        if (o == 'F')
        {

            queue<p> q;
            q.push(robots[r - 1]);

            int next_x;
            int next_y;

            for (int j = 0; j < c; j++)
            {
                p cur = q.front();
                q.pop();

                next_x = cur.x + dx[cur.d];
                next_y = cur.y + dy[cur.d];


                if (next_x >= 0 && next_x < B && next_y >= 0 && next_y < A && myMap[next_x][next_y]!=1)
                {
                    myMap[cur.x][cur.y] = 0;
                    myMap[next_x][next_y] = 1;
                    robots[r - 1].x = next_x;
                    robots[r - 1].y = next_y;
                    
                    q.push(make_p(next_x, next_y, cur.d));
                    //continue;
                }
                else if (myMap[next_x][next_y] == 1)
                {
                    for (int k = 0; k < robots.size(); k++)
                    {
                        if (robots[k].x == next_x && robots[k].y == next_y)
                        {
                            cout << "Robot " << r << " crashes into robot " << k + 1 << endl;
                            flag = true;
                            break;
                        }
                    }
                }
                else
                {
                    cout << "Robot " << r << " crashes into the wall" << endl;
                    flag = true;
                    break;
                }

                if(flag) break;

                // for (int i = 0; i < B; i++)
                // {
                //     for (int j = 0; j < A; j++)
                //     {
                //         cout << myMap[i][j] << " ";
                //     }
                //     cout << endl;
                // }
            }
        }

        else if(o=='L')
        {
            robots[r - 1].d = (robots[r - 1].d + c) % 4;

            //cout<<robots[r-1].d<<endl;
        }
        else
        {
            robots[r-1].d = (robots[r-1].d + (4-c%4))%4;
            //cout<<robots[r-1].d<<endl;
        }
    }

    if(!flag) cout << "OK" << endl;
}