#include <iostream>
#include <vector>
#include <map>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct board
{
    int score;
    bool blue;
    int blue_dir;
    int red_dir;
    bool occupied = false;

    board() {}
    board(int score, bool blue, int blue_dir, int red_dir) : score(score), blue(blue), blue_dir(blue_dir), red_dir(red_dir) {}
};

map<int, board> m;
vector<int> nums;
int pos[5] = {
    0,
};

void init()
{
    m.insert({0, board(0, false, -1, 1)});
    m.insert({1, board(2, false, -1, 2)});
    m.insert({2, board(4, false, -1, 3)});
    m.insert({3, board(6, false, -1, 4)});
    m.insert({4, board(8, false, -1, 5)});
    m.insert({5, board(10, true, 7, 6)});
    m.insert({6, board(12, false, -1, 8)});
    m.insert({7, board(13, false, -1, 9)});
    m.insert({8, board(14, false, -1, 10)});
    m.insert({9, board(16, false, -1, 12)});
    m.insert({10, board(16, false, -1, 11)});
    m.insert({11, board(18, false, -1, 13)});
    m.insert({12, board(19, false, -1, 18)});
    m.insert({13, board(20, true, 14, 15)});
    m.insert({14, board(22, false, -1, 16)});
    m.insert({15, board(22, false, -1, 17)});
    m.insert({16, board(24, false, -1, 18)});
    m.insert({17, board(24, false, -1, 19)});
    m.insert({18, board(25, false, -1, 25)});
    m.insert({19, board(26, false, -1, 23)});
    m.insert({20, board(26, false, -1, 18)});
    m.insert({21, board(27, false, -1, 20)});
    m.insert({22, board(28, false, -1, 21)});
    m.insert({23, board(28, false, -1, 24)});
    m.insert({24, board(30, true, 22, 26)});
    m.insert({25, board(30, false, -1, 28)});
    m.insert({26, board(32, false, -1, 27)});
    m.insert({27, board(34, false, -1, 29)});
    m.insert({28, board(35, false, -1, 31)});
    m.insert({29, board(36, false, -1, 30)});
    m.insert({30, board(38, false, -1, 31)});
    m.insert({31, board(40, false, -1, -1)});
    m.insert({-1, board(-1, false, -1, -1)});
}

int answer = 0;

void game(int trn, int score)
{
    if (trn == 10)
    {
        // cout << score << "\n";

        if (score > answer)
        {
            answer = score;
        }
        return;
    }

    if (pos[0] == -1 && pos[1] == -1 && pos[2] == -1 && pos[3] == -1)
    {
        // cout << score << "\n";

        if (score > answer)
        {
            answer = score;
        }
        return;
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << pos[i] << " ";
    // }
    // cout << "\n";

    // for (auto it = m.begin(); it != m.end(); it++)
    // {
    //     cout << it->second.occupied << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < 4; i++)
    {
        if (pos[i] == -1)
        {
            continue;
        }

        board cur = m[pos[i]];
        int cur_pos = pos[i];
        int next_pos;

        board next, temp;

        // 빨간색 칸인 경우
        if (!cur.blue)
        {
            temp = cur;
            for (int j = 0; j < nums[trn]; j++)
            {
                next = m[temp.red_dir];
                next_pos = temp.red_dir;
                temp = next;

                if (next.score == -1)
                {
                    break;
                }
            }

            if (next.score == -1)
            {
                m[pos[i]].occupied = false;
                pos[i] = -1;
                game(trn + 1, score);
                pos[i] = cur_pos;
                m[pos[i]].occupied = true;
                continue;
            }
        }
        else
        {
            next = m[cur.blue_dir];
            next_pos = cur.blue_dir;
            temp = next;

            for (int j = 0; j < nums[trn] - 1; j++)
            {
                next = m[temp.red_dir];
                next_pos = temp.red_dir;
                temp = next;
            }
        }

        if (!next.occupied)
        {
            m[pos[i]].occupied = false;
            pos[i] = next_pos;
            m[pos[i]].occupied = true;

            game(trn + 1, score + next.score);

            m[pos[i]].occupied = false;
            pos[i] = cur_pos;
            m[pos[i]].occupied = true;
        }
    }
}

int main()
{
    FASTIO();
    init();

    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;

        nums.push_back(x);
    }

    game(0, 0);

    cout << answer << "\n";
}