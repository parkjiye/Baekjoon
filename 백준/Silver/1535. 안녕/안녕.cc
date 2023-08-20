#include <iostream>

using namespace std;

int happy[25];
int sad[25];
int total[25];

int N;

int healthy;
int happiness;

void hello(int idx, int health, int hap)
{
    if (idx == N)
    {
        if (hap > happiness && health > 0)
        {
            happiness = hap;
            healthy = health;
        }

        return;
    }

    // 인사 함
    hello(idx + 1, health - sad[idx], hap + happy[idx]);

    // 인사 안함
    hello(idx + 1, health, hap);
}

int main()
{
    cin >> N;
    healthy = 100;
    happiness = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> sad[i];
    }

    for (int j = 0; j < N; j++)
    {
        cin >> happy[j];
    }

    hello(0, 100, 0);

    if (healthy <= 0)
    {
        cout << 0 << endl;
        return 0;
    }

    cout << happiness << endl;
}