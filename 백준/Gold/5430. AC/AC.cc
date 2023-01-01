#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

vector<string> split(string str, char Delimiter)
{
    istringstream iss(str); // istringstream에 str을 담는다.
    string buffer;          // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼

    vector<string> result;

    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter))
    {
        result.push_back(buffer); // 절삭된 문자열을 vector에 저장
    }

    return result;
}

int main()
{
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        string sentence;
        cin >> sentence;

        int count;
        cin >> count;

        string numbers;
        cin >> numbers;

        string number = numbers.substr(1, numbers.length() - 2);

        vector<string> line = split(number, ',');

        deque<int> nums;

        for (int i = 0; i < line.size(); i++)
        {
            nums.push_back(stoi(line[i]));
            // cout<<nums[i]<<endl;
        }

        bool error = false;
        bool reverse = false;

        for (int i = 0; i < sentence.length(); i++)
        {
            if (sentence[i] == 'R')
            {
                reverse = !reverse;
            }
            else
            {
                if (nums.size() == 0)
                {
                    error = true;
                    break;
                }
                else
                {
                    if (reverse)
                        nums.pop_back();
                    else
                        nums.pop_front();
                }
            }
        }

        if (error)
        {
            cout << "error" << endl;
            continue;
        }

        cout << "[";

        if (nums.size() == 0)
            cout << "]" << endl;

        else
        {
            if (!reverse)
            {
                while (!nums.empty())
                {
                    if (nums.size() != 1)
                        cout << nums.front() << ",";
                    else
                        cout << nums.front();
                    nums.pop_front();
                }
            }
            else
            {
                while (!nums.empty())
                {
                    if (nums.size() != 1)
                        cout << nums.back() << ",";
                    else
                        cout << nums.back();
                    nums.pop_back();
                }
            }

            cout << "]" << endl;
        }
    }
    return 0;
}