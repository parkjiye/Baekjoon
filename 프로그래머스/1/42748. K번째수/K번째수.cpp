#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i=0;i<commands.size();i++)
    {
        int start = commands[i][0];
        int end = commands[i][1];
        int idx = commands[i][2];
        
        vector<int> nums;
        for(int j=start-1;j<end;j++)
        {
            nums.push_back(array[j]);
        }
        
        sort(nums.begin(), nums.end());
        
        answer.push_back(nums[idx-1]);
    }
    return answer;
}