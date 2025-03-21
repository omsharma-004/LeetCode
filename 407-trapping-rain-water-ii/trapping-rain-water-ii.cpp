class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int m = heightMap.size() , n = heightMap[0].size();
        priority_queue<array<int,3> , vector<array<int,3>> , greater<array<int,3>>> q;
        vector<int> dic = {1,0,-1,0,1};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || i==m-1 || j==0 || j==n-1){
                    q.push({heightMap[i][j] , i , j});
                    heightMap[i][j] = -1;
                }
            }
        }
        int MX_height = -1;
        int res = 0;
        while(!q.empty()){
            auto [height , i , j] = q.top() ; q.pop();
            MX_height = max(MX_height , height);
            res += MX_height - height;
            for(int d=0;d<4;d++){
                int ni = i + dic[d];
                int nj = j + dic[d + 1];
                if(ni>=0 && nj>=0 && ni<m && nj<n && heightMap[ni][nj]!=-1){
                    q.push({heightMap[ni][nj] , ni ,nj});
                    heightMap[ni][nj] = -1;
                }
            }
        }
        return res;
    }
};