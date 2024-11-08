#define pp pair<int, pair<int,int>>
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        priority_queue<pp, vector<pp>, greater<pp>> pq;
        int n=matrix.size();
        for(int i=0;i<min(n,k);i++){
            pq.push({matrix[i][0],{i,0}});
        }
        pp  ans;
        while(k-- and not pq.empty()){
            ans=pq.top();
            pq.pop();
            int val=ans.first;
            int row=ans.second.first;
            int col=ans.second.second;
            if(col+1<matrix[row].size()){
                pq.push({matrix[row][col+1],{row, col+1}});
            }
        }
        return ans.first;
    }
};