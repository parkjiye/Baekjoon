#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> occupied;
int N, M;

vector<int> crain;
vector<int> box;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        crain.push_back(x);
        occupied.push_back(0);
    }

    cin >> M;

    for (int i = 0; i < M; i++)
    {
        int x;
        cin >> x;

        box.push_back(x);
    }

    sort(crain.begin(), crain.end(), greater<>());
    sort(box.begin(), box.end(), greater<>());

    for (int i = 0; i < M; i++)
    {
        int round = *max_element(occupied.begin(), occupied.end());
        if (box[i] > crain[0])
        {
            cout << -1 << "\n";
            return 0;
        }

        bool found = false;

        for (int j = 0; j < N; j++)
        {
            if (crain[j] >= box[i])
            {
                if (occupied[j] < round || round == 0)
                {
                    occupied[j] += 1;
                    found = true;
                    break;
                }
            }
        }

        if (!found)
        {
            for (int j = 0; j < N; j++)
            {
                if (crain[j] >= box[i])
                {
                    occupied[j] += 1;
                    break;
                }
            }
        }
    }

    cout << *max_element(occupied.begin(), occupied.end()) << "\n";
}