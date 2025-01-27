class Solution 
{

    bool helper(unordered_map<int , vector<int>>& graph , int& numCourses , int& start , int& end)
    {
        if(start == end) return true;

        vector<int> visited(numCourses , 0);
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while(!q.empty())
        {
            int top = q.front();
            q.pop();
            if(top == end)
            {
                return true;
            }
            for(auto it : graph[top])
            {
                if(visited[it] == 0)
                {
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        unordered_map<int , vector<int>> graph;
        for(auto it : prerequisites)
        {
            int prev = it[0];
            int next = it[1];
            graph[prev].push_back(next);
        }
        vector<bool> res;

        for(auto it : queries)
        {
            int start = it[0];
            int end = it[1];
            res.push_back(helper(graph , numCourses , start , end));
        }

        return res;
    }
};