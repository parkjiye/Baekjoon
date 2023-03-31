#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> myMap;
vector<int> cnt;

int main()
{
    cin >> N;

    myMap.resize(N);
    cnt.resize(N);

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        myMap[i] = x;
    }

    cnt[0] = 1;

    for (int i = 1; i < N; i++)
    {
        int temp = 0;
        for (int j = 0; j < i; j++)
        {
            if (myMap[j] >= myMap[i])
                continue;
            else
            {
                if (cnt[j] > temp)
                    temp = cnt[j];
            }
        }
        cnt[i] = temp + 1;
    }

    cout << *max_element(cnt.begin(), cnt.end()) << endl;

    return 0;
}