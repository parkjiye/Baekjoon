#include <iostream>
#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main()
{
    FASTIO();
    int T;
    cin >> T;

    for (int t = 0; t < T; t++)
    {
        int R;
        string S;
        cin >> R >> S;

        string answer;
        for (int i = 0; i < S.length(); i++)
        {
            for (int j = 0; j < R; j++)
            {
                answer += S[i];
            }
        }

        cout << answer << "\n";
    }
}