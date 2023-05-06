#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int myMap[21][21];

int N;
int answer;

void move(int cnt)
{
    if (cnt == 5)
    {

        int max_value = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (myMap[i][j] > max_value)
                {
                    max_value = myMap[i][j];
                }
            }
        }

        if (max_value > answer)
        {
            answer = max_value;
        }

        return;
    }

    int copy[21][21];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            copy[i][j] = myMap[i][j];
        }
    }

    int temp[21][21];

    // 왼쪽
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; i++)
    {
        vector<int> nums;
        for (int j = 0; j < N; j++)
        {
            if (myMap[i][j] == 0)
            {
                continue;
            }
            else
            {
                nums.push_back(myMap[i][j]);
            }
        }

        int idx = 0;

        for (int k = 0; k < nums.size(); k++)
        {
            if (nums.size() > 1 && k < nums.size() - 1)
            {
                if (nums[k] == nums[k + 1])
                {
                    temp[i][idx] = nums[k] * 2;
                    k++;
                }
                else
                {
                    temp[i][idx] = nums[k];
                }
            }
            else
            {
                temp[i][idx] = nums[k];
            }
            idx += 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = temp[i][j];
        }
    }
    move(cnt + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = copy[i][j];
        }
    }

    // 오른쪽
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; i++)
    {
        vector<int> nums;
        for (int j = N - 1; j >= 0; j--)
        {
            if (myMap[i][j] == 0)
            {
                continue;
            }
            else
            {
                nums.push_back(myMap[i][j]);
            }
        }

        int idx = N - 1;

        for (int k = 0; k < nums.size(); k++)
        {
            if (nums.size() > 1 && k < nums.size() - 1)
            {
                if (nums[k] == nums[k + 1])
                {
                    temp[i][idx] = nums[k] * 2;
                    k++;
                }
                else
                {
                    temp[i][idx] = nums[k];
                }
            }
            else
            {
                temp[i][idx] = nums[k];
            }
            idx -= 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = temp[i][j];
        }
    }
    move(cnt + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = copy[i][j];
        }
    }

    // 위
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; i++)
    {
        vector<int> nums;
        for (int j = 0; j < N; j++)
        {
            if (myMap[j][i] == 0)
            {
                continue;
            }
            else
            {
                nums.push_back(myMap[j][i]);
            }
        }

        int idx = 0;

        for (int k = 0; k < nums.size(); k++)
        {
            if (nums.size() > 1 && k < nums.size() - 1)
            {
                if (nums[k] == nums[k + 1])
                {
                    temp[idx][i] = nums[k] * 2;
                    k++;
                }
                else
                {
                    temp[idx][i] = nums[k];
                }
            }
            else
            {
                temp[idx][i] = nums[k];
            }
            idx += 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = temp[i][j];
        }
    }
    move(cnt + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = copy[i][j];
        }
    }

    // 아래
    memset(temp, 0, sizeof(temp));
    for (int i = 0; i < N; i++)
    {
        vector<int> nums;
        for (int j = N - 1; j >= 0; j--)
        {
            if (myMap[j][i] == 0)
            {
                continue;
            }
            else
            {
                nums.push_back(myMap[j][i]);
            }
        }

        int idx = N - 1;

        for (int k = 0; k < nums.size(); k++)
        {
            if (nums.size() > 1 && k < nums.size() - 1)
            {
                if (nums[k] == nums[k + 1])
                {
                    temp[idx][i] = nums[k] * 2;
                    k++;
                }
                else
                {
                    temp[idx][i] = nums[k];
                }
            }
            else
            {
                temp[idx][i] = nums[k];
            }
            idx -= 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = temp[i][j];
        }
    }
    move(cnt + 1);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            myMap[i][j] = copy[i][j];
        }
    }
}

int main()
{
    cin >> N;
    answer = 0;
    memset(myMap, 0, sizeof(myMap));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;

            myMap[i][j] = x;
        }
    }

    move(0);

    cout << answer << endl;
}