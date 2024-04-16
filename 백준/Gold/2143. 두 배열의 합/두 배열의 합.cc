#include <iostream>
#include <vector>
#include <map>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

vector<int> A;
vector<int> B;
map<long, long> MA;
map<long, long> MB;

long T;

int main()
{
    FASTIO();
    cin >> T;

    int a;
    cin >> a;

    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;

        A.push_back(x);
        MA[x] += 1;
    }

    int b;
    cin >> b;

    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;

        B.push_back(x);
        MB[x] += 1;
    }

    for (int i = 0; i < a; i++)
    {
        long sum = A[i];

        for (int j = i + 1; j < a; j++)
        {
            sum += A[j];
            MA[sum] += 1;
        }
    }

    for (int i = 0; i < b; i++)
    {
        long sum = B[i];

        for (int j = i + 1; j < b; j++)
        {
            sum += B[j];
            MB[sum] += 1;
        }
    }

    long long answer = 0;

    for (auto it = MA.begin(); it != MA.end(); it++)
    {
        long opp = T - it->first;

        if (MB.find(opp) != MB.end())
        {
            answer += (MB[opp]) * (it->second);
        }
    }

    cout << answer << "\n";
}