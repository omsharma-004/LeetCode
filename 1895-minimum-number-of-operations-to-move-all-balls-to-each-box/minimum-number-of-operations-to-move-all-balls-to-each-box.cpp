class Solution {
public:
    vector<int> minOperations(string b) {
        vector<int> ans(b.length(), 0);
        for(int i = 0; i<b.length(); i++)
        {
            for(int j = 0; j<b.length(); j++)
            {
                if(i!=j && b[j]!='0')
                {
                    ans[i]+=abs(j-i);
                }
            }
        }

        return ans;

    }
};