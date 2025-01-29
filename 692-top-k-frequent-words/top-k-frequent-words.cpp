#define pp pair<int, string>
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        for (auto i : words) {
            mp[i]++;
        }
        vector<string> v;
        priority_queue<pp, vector<pp>, function<bool(pp, pp)>> pq(
            [](pp a, pp b) {
                if (a.first != b.first) {
                    return a.first < b.first;
                }
                return a.second > b.second;
            });
        for (auto i : mp) {
            pq.push({i.second, i.first});
        }
        while (k-- && !pq.empty()) {
            pp curr = pq.top();
            pq.pop();
            v.push_back(curr.second);
        }
        return v;
    }
};