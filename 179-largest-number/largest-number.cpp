class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }
        sort(v.begin(), v.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        if(v[0]=="0") return "0";
        string largest;
        for(const string& str:v){
            largest+=str;
        }
        return largest;
    }
};