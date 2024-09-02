// 장르별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범 출시
// 노래 수록 기준 : 속한 노래가 많이 재생된 장르 > 장르 내에서 많이 재생된 노래 > 장르 내에서 고유번호가 낮은 노래


#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> m;

struct song
{
    int idx;
    int p;
    string g;
    
    song(){};
    song(int idx, int p, string g):idx(idx),p(p),g(g){};
    
    bool const operator<(const song tmp)const{
        if(m[g]==m[tmp.g])
        {
            if(p==tmp.p)
            {
                return idx<tmp.idx;
            }
            return p>tmp.p;
        }
        return m[g]>m[tmp.g];
    }
};

vector<song> v;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    for(int i=0;i<genres.size();i++)
    {
        if(m.find(genres[i])==m.end()){
            m.insert({genres[i], plays[i]});
        }
        else{
            m[genres[i]]+=plays[i];
        }
        
        v.push_back(song(i, plays[i], genres[i]));
    }
    
    sort(v.begin(), v.end());
    
    map<string, int> t;
    
    for(int i=0;i<v.size();i++)
    {
        if(t.find(v[i].g)==t.end())
        {
            answer.push_back(v[i].idx);
            t.insert({v[i].g, 1});
        }
        else
        {
            if(t[v[i].g]==1)
            {
                answer.push_back(v[i].idx);
                t[v[i].g]=2;
            }
        }
    }
    return answer;
}