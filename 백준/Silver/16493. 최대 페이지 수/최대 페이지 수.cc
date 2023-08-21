#include <iostream>

using namespace std;

int N, M;
int spent[25];
int pages[25];

int ans = 0;

void library(int idx, int day, int page)
{
    if (idx == M)
    {
        if (page > ans && day <= N)
        {
            ans = page;
        }

        return;
    }

    library(idx + 1, day + spent[idx], page + pages[idx]);
    library(idx + 1, day, page);
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> spent[i] >> pages[i];
    }

    library(0, 0, 0);

    cout << ans << endl;
}