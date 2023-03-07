#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
    string sen;
    cin >> sen;

    string s;

    vector<int> numbers;
    vector<char> operators;

    bool minus = false;

    int p_cnt = 0;
    int m_cnt = 0;

    int answer = 0;

    for (int i = 0; i < sen.length(); i++)
    {
        if (minus && sen[i] == '+')
        {
            numbers.push_back(stoi(s));
            operators.push_back(sen[i]);
            p_cnt += 1;
            s = "";
        }
        else if (minus && sen[i] == '-')
        {
            numbers.push_back(stoi(s));
            operators.push_back(sen[i]);
            m_cnt += 1;
            s = "";
        }
        else if (sen[i] == '-' && !minus)
        {
            answer += stoi(s);
            minus = true;
            m_cnt += 1;
            s = "";
        }
        else if (sen[i] == '+' && !minus)
        {
            answer += stoi(s);
            p_cnt += 1;
            s = "";
        }
        else
        {
            s += sen[i];
        }
    }

    numbers.push_back(stoi(s));

    if (p_cnt == 0 && m_cnt == 0)
    {
        cout << numbers[0] << endl;
        return 0;
    }

    if (minus)
    {
        int min = numbers[0];

        for (int i = 0; i < operators.size(); i++)
        {
            min += numbers[i + 1];
        }

        cout << answer - min << endl;
    }
    else
    {
        cout << answer + numbers[0] << endl;
    }
}