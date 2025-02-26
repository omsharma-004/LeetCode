class Solution {
public:
    string repeatLimitedString(string s, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<char, int> mp;
        for(auto i:s){
            mp[i]++;
        }
        priority_queue<pair<char, int>> pq;
        for(auto i:mp){
            pq.push(i);
        }
        string ans="";
        while(!pq.empty()){
            auto largest=pq.top();
            pq.pop();
            int len=min(largest.second, k);
            for(int i=0;i<len;i++){
                ans+=largest.first;
            }
            pair<char, int> slargest;
            if(largest.second-len>0){
                if(!pq.empty()){
                    slargest=pq.top();
                    pq.pop();
                    ans+=slargest.first;
                }
                else{
                    return ans;
                }
                if(slargest.second-1>0){
                    pq.push({slargest.first, slargest.second-1});
                }
                pq.push({largest.first, largest.second-len});
            }
        }
        return ans;
    }
};