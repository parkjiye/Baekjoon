#include <iostream>
#include <string>

using namespace std;

int main()
{
    int A, B, C;
    string answer;

    cin >> A >> B >> C;
    answer = to_string(A * B * C);

    int cnt[10] = {
        0,
    };

    for (int i = 0; i < answer.length(); i++)
    {
        string temp = answer.substr(i, 1);
        cnt[stoi(temp)] += 1;
    }

    for (int i = 0; i <= 9; i++)
    {
        cout << cnt[i] << "\n";
    }
}