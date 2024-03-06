#include <iostream>
#include <vector>
#include <string.h>

#define FASTIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
struct p
{
    int w;
    int h;

    p() {}
    p(int w, int h) : w(w), h(h) {}
};
vector<p> v;
int score[55];

int main()
{
    FASTIO();
    cin >> N;
    memset(score, 0, sizeof(score));

    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;

        v.push_back(p(x, y));
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (v[i].h > v[j].h && v[i].w > v[j].w)
            {
                score[j] += 1;
            }
            else if (v[i].h < v[j].h && v[i].w < v[j].w)
            {
                score[i] += 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << score[i] + 1 << " ";
    }
    cout << "\n";
}