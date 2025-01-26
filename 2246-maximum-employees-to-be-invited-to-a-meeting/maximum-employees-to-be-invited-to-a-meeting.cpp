class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int n = favorite.size();
        vector<int> depth(n, 1), inDegree(n);
        queue<int> q;

        for (int i = 0; i < n; ++i)
            inDegree[favorite[i]]++;
        for (int i = 0; i < n; ++i)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            depth[favorite[cur]] = max(depth[favorite[cur]], depth[cur] + 1);
            if (!--inDegree[favorite[cur]])
                q.push(favorite[cur]);
        }

        int twoCycle = 0, longest = 0;
        for (int i = 0; i < n; ++i) {
            if (!inDegree[i])
                continue;
            int len = 0, j = i;
            while (inDegree[j]) {
                inDegree[j] = 0;
                len++;
                j = favorite[j];
            }
            if (len == 2)
                twoCycle += depth[i] + depth[favorite[i]];
            else if (len > longest)
                longest = len;
        }

        return max(twoCycle, longest);
    }
};