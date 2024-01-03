#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
vector<int> plu;
vector<int> minu;

int main()
{
    FASTIO();
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if (x < 0)
        {
            minu.push_back(x);
        }
        else
        {
            plu.push_back(x);
        }
    }

    sort(minu.begin(), minu.end(), greater<>());
    sort(plu.begin(), plu.end());

    int answer = 0;

    if (minu.size() == 0)
    {
        answer += plu[plu.size() - 1];

        for (int i = plu.size() - M - 1; i >= 0; i -= M)
        {
            answer += plu[i] * 2;
        }
    }
    else if (plu.size() == 0)
    {
        answer += minu[minu.size() - 1] * -1;

        for (int i = minu.size() - M - 1; i >= 0; i -= M)
        {
            answer += minu[i] * -2;
        }
    }
    else if (abs(minu[minu.size() - 1]) > plu[plu.size() - 1])
    {
        answer += minu[minu.size() - 1] * -1;

        for (int i = minu.size() - M - 1; i >= 0; i -= M)
        {
            answer += minu[i] * -2;
        }
        for (int i = plu.size() - 1; i >= 0; i -= M)
        {
            answer += plu[i] * 2;
        }
    }
    else
    {
        answer += plu[plu.size() - 1];

        for (int i = plu.size() - M - 1; i >= 0; i -= M)
        {
            answer += plu[i] * 2;
        }
        for (int i = minu.size() - 1; i >= 0; i -= M)
        {
            answer += minu[i] * -2;
        }
    }

    cout << answer << "\n";
}