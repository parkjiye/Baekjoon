#include <iostream>
#include <set>
#include <queue>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int board[5][5];
set<string> s;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int ans = INT32_MAX;
string success = "123456789";

struct p
{
    int x;
    int y;

    p(int x, int y) : x(x), y(y) {}
    p() {}
};

struct puz
{
    p blank;
    string s;
    int tr;

    puz(p blank, string s, int tr) : blank(blank), s(s), tr(tr) {}
    puz() {}
};

string toString()
{
    string s = "";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            s += to_string(board[i][j]);
        }
    }

    return s;
}

void swap(p cur, p next)
{
    int temp = board[cur.x][cur.y];
    board[cur.x][cur.y] = board[next.x][next.y];
    board[next.x][next.y] = temp;
}

void toArray(string s)
{
    int idx = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = s[idx] - '0';
            idx += 1;
        }
    }
}

void print_all()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

queue<puz> q;

void puzzle()
{
    while (!q.empty())
    {
        puz cur = q.front();
        // cout << cur.s << "\n";
        q.pop();

        if (cur.s == success)
        {
            ans = cur.tr;
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int next_x = cur.blank.x + dx[k];
            int next_y = cur.blank.y + dy[k];

            if (next_x >= 0 && next_y >= 0 && next_x < 3 && next_y < 3)
            {
                toArray(cur.s);
                // print_all();
                swap(cur.blank, p(next_x, next_y));
                string nxt_s = toString();

                if (s.find(nxt_s) == s.end())
                {
                    s.insert(nxt_s);
                    q.push(puz(p(next_x, next_y), nxt_s, cur.tr + 1));
                }
            }
        }
    }
}

int main()
{
    FASTIO();

    p start;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;

            if (x == 0)
            {
                board[i][j] = 9;
                start = p(i, j);
                continue;
            }

            board[i][j] = x;
        }
    }

    s.insert(toString());
    q.push(puz(start, toString(), 0));

    puzzle();

    if (ans == INT32_MAX)
    {
        cout << -1 << "\n";
        return 0;
    }
    cout << ans << "\n";
}