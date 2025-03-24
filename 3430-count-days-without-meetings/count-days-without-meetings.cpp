class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if(meetings.size()==1){
            return (meetings[0][0] -1) + (days - meetings[0][1]);
        }
        std::sort(meetings.begin(),meetings.end(),[](const auto& a, const auto& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
        });
        int ans = 0;
        if(meetings[0][0] !=1){
            ans+= meetings[0][0]-1;
        }
        for(int i = 1; i < meetings.size();i++){
            if(meetings[i-1][1] < meetings[i][0]){
                ans+= meetings[i][0] - meetings[i-1][1] -1;
            }else{
                meetings[i][0] = meetings[i-1][0];
                if(meetings[i][1] < meetings[i-1][1]){
                    meetings[i][1] = meetings[i-1][1];
                }
            }
        }
        if(meetings[meetings.size()-1][1] != days){
            ans+= days - meetings[meetings.size()-1][1];
        }

        return ans;
    }
};