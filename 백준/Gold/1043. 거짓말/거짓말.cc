#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> myMap[51];
vector<int> myParty[51];
bool isReal[51];
bool party[51];

int N, M;

int main()
{
    cin >> N >> M;
    queue<int> q;
    memset(isReal, 0, sizeof(isReal));
    memset(party, 0, sizeof(party));

    int real_cnt;
    cin >> real_cnt;

    int real;
    // cout << real_cnt << endl;

    while (real_cnt != 0)
    {
        // cout << "dafd" << endl;
        cin >> real;
        isReal[real] = true;
        q.push(real);
        real_cnt -= 1;
    }

    for (int i = 1; i <= M; i++)
    {
        int party_nm;
        cin >> party_nm;

        int party;

        while (party_nm != 0)
        {
            cin >> party;
            myMap[party].push_back(i);
            myParty[i].push_back(party);
            party_nm -= 1;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < myMap[cur].size(); i++)
        {
            int next = myMap[cur][i];
            if (!party[next])
                party[next] = true;

            for (int j = 0; j < myParty[next].size(); j++)
            {
                if (!isReal[myParty[next][j]])
                {
                    isReal[myParty[next][j]] = true;
                    q.push(myParty[next][j]);
                }
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= M; i++)
    {
        if (!party[i])
            answer += 1;
    }

    cout << answer << endl;

    return 0;
}