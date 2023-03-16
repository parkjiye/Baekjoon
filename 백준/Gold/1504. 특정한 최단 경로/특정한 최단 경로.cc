// 1번 정점에서 N번 정점으로 최단 거리
//  1. 입력으로 주어진 두 정점은 반드시 통과
//  2. 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동 가능
//  3. 반드시 최단 경로로 이동해야 함
//  4. 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

int N, E;

int x1, x2;
vector<pair<int, int>> myGraph[805];

int dijkstra(int start, int dest)
{
    priority_queue<pair<int, int>> pq;
    vector<int> dist(805, INF);

    dist[start] = 0;
    pq.push(make_pair(0, start));

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();

        if (cost > dist[cur])
            continue;

        for (int i = 0; i < myGraph[cur].size(); i++)
        {
            int next = myGraph[cur][i].first;
            int ncost = cost + myGraph[cur][i].second;

            if (ncost < dist[next])
            {
                dist[next] = ncost;
                pq.push(make_pair(-ncost, next));
            }
        }
    }

    return dist[dest];
}

int main()
{
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;

        myGraph[x].push_back(make_pair(y, c));
        myGraph[y].push_back(make_pair(x, c));
    }

    cin >> x1 >> x2;

    // start->경유지1->경유지2->dest
    int starttox1 = dijkstra(1, x1);
    int x1tox2 = dijkstra(x1, x2);
    int x2todest = dijkstra(x2, N);
    int starttox2 = dijkstra(1, x2);
    int x1todest = dijkstra(x1, N);

    long long int answer1 = starttox1 + x1tox2 + x2todest;
    long long int answer2 = starttox2 + x1todest + x1tox2;

    long long int answer = answer1 < answer2 ? answer1 : answer2;

    if (answer >= INF || answer <= 0)
        cout << -1;
    else
        cout << answer << endl;

    return 0;
}