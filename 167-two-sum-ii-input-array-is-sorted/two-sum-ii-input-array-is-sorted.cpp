class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int t) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans;
        int left=0;
        int right=arr.size()-1;
        while (left<right) {
            int sum=arr[left]+arr[right];
            if (sum==t) {
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            } 
            else if (sum<t) left++;
            else right--;
        }
        return ans;
    }
};