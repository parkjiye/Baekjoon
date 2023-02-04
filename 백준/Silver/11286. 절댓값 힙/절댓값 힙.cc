#include <iostream>
#include <queue>

using namespace std;

struct cmp
{
    bool operator()(int n1, int n2)
    {
        if (abs(n1) > abs(n2))
            return true;
        else if (abs(n1) == abs(n2))
            if (n1 > n2)
                return true;
            else
                return false;
        return false;
    }
};

int main()
{
    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> pq;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        if (num == 0)
        {
            if (pq.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
}