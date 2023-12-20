#include <iostream>
#include <algorithm>
#include <vector>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

long long N;
vector<long long> dice;
vector<long long> two_dice;
vector<long long> three_dice;

int main()
{
    FASTIO();
    cin >> N;

    for (int i = 0; i < 6; i++)
    {
        long long int x;
        cin >> x;

        dice.push_back(x);
    }

    three_dice.push_back(dice[0] + dice[1] + dice[2]);
    three_dice.push_back(dice[0] + dice[1] + dice[3]);
    three_dice.push_back(dice[0] + dice[4] + dice[3]);
    three_dice.push_back(dice[0] + dice[4] + dice[2]);
    three_dice.push_back(dice[5] + dice[1] + dice[2]);
    three_dice.push_back(dice[5] + dice[1] + dice[3]);
    three_dice.push_back(dice[5] + dice[4] + dice[3]);
    three_dice.push_back(dice[5] + dice[4] + dice[2]);

    sort(three_dice.begin(), three_dice.end());

    for (int i = 1; i < 5; i++)
    {
        two_dice.push_back(dice[0] + dice[i]);
        two_dice.push_back(dice[5] + dice[i]);
    }
    two_dice.push_back(dice[1] + dice[2]);
    two_dice.push_back(dice[1] + dice[3]);
    two_dice.push_back(dice[4] + dice[2]);
    two_dice.push_back(dice[4] + dice[3]);

    sort(two_dice.begin(), two_dice.end());
    sort(dice.begin(), dice.end());

    if (N == 1)
    {
        int answer = 0;
        for (int i = 0; i < 5; i++)
        {
            answer += dice[i];
        }
        cout << answer << "\n";
        return 0;
    }

    long long answer;
    long long first = dice[0] * ((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2));
    long long second = two_dice[0] * (((2 + 3 * (N - 2)) * 4 + 4 * (N - 2))) / 2;
    long long third = three_dice[0] * 4;

    answer = first + second + third;
    cout << answer << "\n";
}
