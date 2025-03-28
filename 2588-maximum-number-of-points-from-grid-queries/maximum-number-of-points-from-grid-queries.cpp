class Solution {
public:
    typedef pair<int,int>P;
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m=grid.size(),n=grid[0].size(),q=queries.size();
        vector<int>ans(q,0);

        vector<P>sortedQueries;
        for(int i=0;i<q;i++){
            sortedQueries.push_back({queries[i],i});
        }
        sort(begin(sortedQueries),end(sortedQueries));

        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int points=0;
        pq.push({grid[0][0],0,0});
        visited[0][0]=true;

        for(int i=0;i<q;i++){
            int queryVal=sortedQueries[i].first;
            int idx=sortedQueries[i].second;
            while(!pq.empty() && pq.top()[0]<queryVal){
                int i=pq.top()[1];
                int j=pq.top()[2];
                pq.pop();
                points++;

                for(auto &dir:directions){
                    int i_=i+dir[0];
                    int j_=j+dir[1];

                    if(i_>=0 && i_<m && j_>=0 && j_<n && !visited[i_][j_]){
                        pq.push({grid[i_][j_],i_,j_});
                        visited[i_][j_]=true;
                    }
                }
            }
            ans[idx]=points;
        }
        return ans;
    }
};