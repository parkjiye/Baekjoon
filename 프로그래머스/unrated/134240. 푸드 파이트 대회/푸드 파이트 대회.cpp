#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<int> food) {
    
    vector<int> count;
    
    string answer = "";
    for(int i=1;i<food.size();i++)
    {
        count.push_back(food[i]/2);
        cout<<count[i-1]<<endl;
    }

    for(int i=0;i<count.size();i++)
    {
        for(int j=0;j<count[i];j++)
        {
            answer.append(to_string(i+1));
        }
    }

    answer.append("0");

    for(int i=count.size()-1;i>=0;i--)
    {
        for(int j=0;j<count[i];j++)
        {
            answer.append(to_string(i+1));
        }
    }
    
    return answer;
}