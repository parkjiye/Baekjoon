#include <iostream>
#include <list>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct jewel
{
    int idx;
    int num;

    jewel() {}
    jewel(int idx, int num) : idx(idx), num(num) {}
};

int N, M;
int d, s;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int jx[4] = {0, 1, 0, -1};
int jy[4] = {-1, 0, 1, 0};

int myMap[50][50];
int temp[50][50];

int answer[5] = {0};

list<jewel> jewels;

void break_jewel()
{

    for (int k = 1; k <= s; k++)
    {
        int next_x = (N + 1) / 2 - 1 + dx[d - 1] * k;
        int next_y = (N + 1) / 2 - 1 + dy[d - 1] * k;

        int cur_idx = myMap[next_x][next_y];

        for (auto it = jewels.begin(); it != jewels.end(); it++)
        {
            if (it->idx == cur_idx)
            {
                jewels.erase(it++);
            }
        }
    }
}

bool explode_jewel()
{
    bool exploded = false;

    auto it = jewels.begin();
    int cur = jewels.begin()->num;
    auto start = jewels.begin();
    it++;
    int cnt = 1;
    for (it; it != jewels.end(); it++)
    {
        if (it->num == cur)
        {
            cnt += 1;
        }
        else
        {
            if (cnt >= 4)
            {
                exploded = true;
                for (int i = 0; i < cnt; i++)
                {
                    jewels.erase(start++);
                    answer[cur] += 1;
                }
            }
            start = it;
            cnt = 1;
            cur = it->num;
        }
    }
    if (it == jewels.end() && cnt >= 4)
    {
        exploded = true;
        for (int i = 0; i < cnt; i++)
        {
            jewels.erase(start++);
            answer[cur] += 1;
        }
    }

    return exploded;
}

void change_jewel()
{
    list<jewel> temp_j;

    auto it = jewels.begin();
    int cur = jewels.begin()->num;
    it++;

    int cnt = 1;
    int idx = 1;
    for (it; it != jewels.end(); it++)
    {
        if (it->num == cur)
        {
            cnt += 1;
        }
        else
        {
            temp_j.push_back(jewel(idx++, cnt));
            temp_j.push_back(jewel(idx++, cur));

            cur = it->num;
            cnt = 1;
        }
    }

    temp_j.push_back(jewel(idx++, cnt));
    temp_j.push_back(jewel(idx++, cur));

    while (temp_j.size() > N * N - 1)
    {
        temp_j.pop_back();
    }

    jewels = temp_j;
}

int main()
{
    cin >> N >> M;

    int x = (N + 1) / 2 - 1;
    int y = (N + 1) / 2 - 1;

    int dist = 1;
    int idx = 1;
    int next_x, next_y;

    for (int i = 0; i < N * 2 - 1; i++)
    {
        for (int j = 1; j <= dist; j++)
        {
            next_x = x + jx[i % 4] * j;
            next_y = y + jy[i % 4] * j;

            if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < N)
            {
                myMap[next_x][next_y] = idx++;
            }
        }

        x = next_x;
        y = next_y;

        if (i % 2 == 1)
            dist += 1;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            temp[i][j] = x;
        }
    }

    dist = 1;
    idx = 1;

    x = (N + 1) / 2 - 1;
    y = (N + 1) / 2 - 1;

    for (int i = 0; i < N * 2 - 1; i++)
    {
        for (int j = 1; j <= dist; j++)
        {
            next_x = x + jx[i % 4] * j;
            next_y = y + jy[i % 4] * j;

            if (temp[next_x][next_y] != 0 && next_x >= 0 && next_y >= 0 && next_x < N && next_y < N)
            {
                jewels.push_back(jewel(myMap[next_x][next_y], temp[next_x][next_y]));
            }
        }

        x = next_x;
        y = next_y;

        if (i % 2 == 1)
            dist += 1;
    }

    while (M--)
    {
        cin >> d >> s;

        if (jewels.size() > 0)
        {
            break_jewel();

            bool exploded = true;

            while (jewels.size() != 0 && exploded)
            {
                exploded = explode_jewel();
            }

            if (jewels.size() == 0)
            {
                continue;
            }

            change_jewel();
        }
    }

    cout << answer[1] + 2 * answer[2] + 3 * answer[3] << endl;

    return 0;
}
