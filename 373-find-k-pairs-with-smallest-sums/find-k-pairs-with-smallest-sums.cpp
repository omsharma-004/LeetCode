#define pp pair<int, pair<int, int>>
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<vector<int>> v;
        pp res;
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        for(int i=0;i<nums1.size();i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        while(k-- && !pq.empty()){
            res=pq.top();
            pq.pop();
            int a=res.first;
            int n1=res.second.first;
            int n2=res.second.second;
            v.push_back({nums1[n1], nums2[n2]});
            if(n2+1<nums2.size()){
                pq.push({nums1[n1]+nums2[n2+1], {n1,n2+1}});
            }
        }
        return v;
    }
};