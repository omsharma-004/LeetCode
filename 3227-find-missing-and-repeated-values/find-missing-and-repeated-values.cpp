class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>temp(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[grid[i][j]]++;
            }
        }
        int a=0,b=0;
        for(int i=1;i<=n*n;i++){
            if(temp[i]==2){
               a=i;
            }
            else if(temp[i]==0){
                b=i;
            }
        }
        return {a,b};
    }
};