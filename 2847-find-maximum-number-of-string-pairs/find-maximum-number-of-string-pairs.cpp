class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int n=words.size();
        int count=0;
        unordered_set<string> us;
        for(int i=0;i<n;i++){
            string rev=words[i];
            reverse(rev.begin(), rev.end());
            if(us.find(rev)!=us.end()) count++;
            else us.insert(words[i]);
        }
        return count;
    }
};