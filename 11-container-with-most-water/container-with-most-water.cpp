class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int ans = 0;
        int l = 0;
        int r = height.size()-1;
        while(l<r){
            int minh = min(height[l],height[r]);
            ans = max(ans, minh*(r-l));
            if(height[l]<height[r]) {++l;}
            else{--r;}
        }
        return ans;
    }
};