class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n=nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            arr.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==pivot)
            arr.push_back(nums[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>pivot)
            arr.push_back(nums[i]);
        }
    return arr;
    }
};