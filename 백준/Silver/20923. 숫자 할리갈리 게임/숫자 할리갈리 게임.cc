#include <iostream>
#include <deque>

using namespace std;

deque<int> dodo;
deque<int> soso;

deque<int> dodoground;
deque<int> sosoground;

int main()
{
    int N, M;
    int length;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int d, s;
        cin >> d >> s;

        dodo.push_front(d);
        soso.push_front(s);
    }

    int cur_do = 0;
    int cur_so = 0;

    for (int i = 0; i < M; i++)
    {
        if (i % 2 == 0)
        {
            cur_do = dodo.front();
            dodo.pop_front();

            if (dodo.empty())
            {
                cout << "su" << endl;
                return 0;
            }

            dodoground.push_front(cur_do);

            if (cur_so != 0 && cur_do + cur_so == 5)
            {
                length = dodoground.size();
                for (int d = 0; d < length; d++)
                {
                    soso.push_back(dodoground.back());
                    dodoground.pop_back();
                    cur_do = 0;
                }

                length = sosoground.size();

                for (int s = 0; s < length; s++)
                {
                    soso.push_back(sosoground.back());
                    sosoground.pop_back();
                    cur_so = 0;
                }
            }

            if (cur_do == 5)
            {
                length = sosoground.size();

                for (int s = 0; s < length; s++)
                {
                    dodo.push_back(sosoground.back());
                    sosoground.pop_back();
                    cur_so = 0;
                }

                length = dodoground.size();

                for (int d = 0; d < length; d++)
                {
                    dodo.push_back(dodoground.back());
                    dodoground.pop_back();
                    cur_do = 0;
                }
            }
        }
        else
        {
            cur_so = soso.front();
            soso.pop_front();

            if (soso.empty())
            {
                cout << "do" << endl;
                return 0;
            }
            sosoground.push_front(cur_so);


            if (cur_do != 0 && cur_do + cur_so == 5)
            {
                length = dodoground.size();

                for (int d = 0; d < length; d++)
                {
                    soso.push_back(dodoground.back());
                    dodoground.pop_back();
                    cur_do = 0;
                }

                length = sosoground.size();

                for (int s = 0; s < length; s++)
                {
                    soso.push_back(sosoground.back());
                    sosoground.pop_back();
                    cur_so = 0;
                }
            }

            if (cur_so == 5)
            {
                length = sosoground.size();

                for (int s = 0; s < length; s++)
                {
                    dodo.push_back(sosoground.back());
                    sosoground.pop_back();
                    cur_so = 0;
                }
                length = dodoground.size();

                for (int d = 0; d < length; d++)
                {
                    dodo.push_back(dodoground.back());
                    dodoground.pop_back();
                    cur_do = 0;
                }
            }
        }

        if (dodo.empty())
        {
            cout << "su" << endl;
            return 0;
        }
        else if (soso.empty())
        {
            cout << "do" << endl;
            return 0;
        }
    }

    if (dodo.size() > soso.size())
    {
        cout << "do" << endl;
    }
    else if (dodo.size() == soso.size())
    {
        cout << "dosu" << endl;
    }
    else
    {
        cout << "su" << endl;
    }
}
