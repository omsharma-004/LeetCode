class Solution {
public:
    vector<int> minOperations(string b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
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