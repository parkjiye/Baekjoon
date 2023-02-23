#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++)
    {
        int count;
        cin >> count;

        int inc = 0;
        int dec = 0;

        int input = 0;

        bool empty = false;

        priority_queue<long, vector<long>, less<long>> max_heap;
        priority_queue<long, vector<long>, greater<long>> min_heap;
        priority_queue<long, vector<long>, less<long>> min_heap_del;
        priority_queue<long, vector<long>, greater<long>> max_heap_del;

        for (int i = 0; i < count; i++)
        {
            char op;
            int num;
            cin >> op >> num;

            if (op == 'I')
            {
                min_heap.push(num);
                max_heap.push(num);
                input += 1;
                inc += 1;
            }
            else
            {
                if (input == 0)
                    continue;

                if (num == -1)
                {
                    while (!max_heap_del.empty())
                    {
                        if (min_heap.top() == max_heap_del.top())
                        {
                            min_heap.pop();
                            max_heap_del.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                    min_heap_del.push(min_heap.top());
                    min_heap.pop();
                    input -= 1;
                    dec += 1;
                }
                else
                {
                    while (!min_heap_del.empty())
                    {
                        if (max_heap.top() == min_heap_del.top())
                        {
                            max_heap.pop();
                            min_heap_del.pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                    max_heap_del.push(max_heap.top());
                    max_heap.pop();
                    input -= 1;
                    dec += 1;
                }
            }
        }

        int min;
        int max;

        if (dec == inc)
        {
            cout << "EMPTY" << endl;
            continue;
        }

        while (!max_heap.empty())
        {
            if (min_heap_del.empty())
            {
                max = max_heap.top();
                break;
            }

            if (max_heap.top() != min_heap_del.top())
            {
                max = max_heap.top();
                break;
            }
            else
            {
                max_heap.pop();
                min_heap_del.pop();
            }
        }

        while (!min_heap.empty())
        {
            if (max_heap_del.empty())
            {
                min = min_heap.top();
                break;
            }

            if (min_heap.top() != max_heap_del.top())
            {
                min = min_heap.top();
                break;
            }
            else
            {
                min_heap.pop();
                max_heap_del.pop();
            }
        }

        cout << max << " " << min << endl;
    }
}