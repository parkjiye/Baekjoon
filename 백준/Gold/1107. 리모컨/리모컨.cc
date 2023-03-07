#include <iostream>

using namespace std;

int main()
{
    int channel;
    cin >> channel;

    bool arr[11] = {false};
    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        int x;
        cin >> x;

        arr[x] = true;
    }

    int cur_num = 100;
    int cnt = 0;

    if (cur_num == channel)
    {
        cout << cnt << "\n";
        return 0;
    }

    int closest = 500001;
    int answer;

    for (int j = 0; j <= 999999; j++)
    {
        string cur = to_string(j);
        bool possible = true;

        for (int i = 0; i < cur.length(); i++)
        {
            if (arr[cur[i] - '0'])
            {
                possible = false;
                break;
            }
        }

        if (possible)
        {
            // cout << j << endl;
            if (abs(channel - j) < closest)
            {
                closest = abs(channel - j);
                answer = j;
            }
        }
    }

    // cout << answer << endl;
    // cout << closest << endl;

    cnt += to_string(answer).length();
    cnt += closest;

    if (abs(channel - cur_num) < cnt)
    {
        cout << abs(channel - cur_num) << endl;
    }
    else
    {
        cout << cnt << endl;
    }
}