class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double sum = 0;
    for(int i=0;i<k;i++){
        sum+=nums[i];
    }
    double ans=sum;
    for(int i=k;i<nums.size();i++){
      sum += nums[i]-nums[i-k];
      ans = max(ans, sum);
    }
    return ans/k;
  }
};