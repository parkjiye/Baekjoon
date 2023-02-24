#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

int start;
int finish;

bool visited[10000];

struct p
{
    int num;
    string sen;
};

p make_p(int a, string b)
{
    p temp;
    temp.num = a;
    temp.sen = b;
    return temp;
}

p bfs()
{
    queue<p> q;
    q.push(make_p(start, ""));
    visited[start] = true;

    while (!q.empty())
    {
        p cur = q.front();
        if (cur.num == finish)
            return cur;
        q.pop();

        // D
        int next = (cur.num * 2) % 10000;
        if (!visited[next])
        {
            q.push(make_p(next, cur.sen + "D"));
            visited[next] = true;
        }

        // S
        if (cur.num == 0)
            next = 9999;
        else
            next = cur.num - 1;

        if (!visited[next])
        {
            q.push(make_p(next, cur.sen + "S"));
            visited[next] = true;
        }

        // L
        next = cur.num % 1000 * 10 + cur.num / 1000;
        if (!visited[next])
        {
            q.push(make_p(next, cur.sen + "L"));
            visited[next] = true;
        }

        // R
        next = cur.num % 10 * 1000 + cur.num / 10;
        if (!visited[next])
        {
            q.push(make_p(next, cur.sen + "R"));
            visited[next] = true;
        }
    }
}

int main()
{
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++)
    {
        cin >> start >> finish;

        memset(visited, 0, sizeof(visited));

        p answer = bfs();

        cout << answer.sen << endl;
    }
}