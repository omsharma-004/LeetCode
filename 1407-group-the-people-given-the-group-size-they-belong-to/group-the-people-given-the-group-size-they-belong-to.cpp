class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& v) 
    {
        vector<vector<int>> answer;
        map<int,vector<int>> m;
        int n=v.size();
        for(int i=0;i<n;i++)
        {
            if(m.find(v[i])!=m.end())
            {
                m[v[i]].push_back(i);
            }
            else
            {
                vector<int> v1;
                v1.push_back(i);
                m[v[i]]=v1;
            }
        }
        for(auto it=m.begin();it!=m.end();++it)
        {
            int x=it->first;
            int y=it->second.size();
            if(x==y)
            {
                answer.push_back(it->second);
            }
            else
            {
                 vector<int> temp;;
                 int count=0;
                 int i=0;
                 while(y--)
                 {
                     cout<<y<<" ";
                     temp.push_back(it->second[i]);
                     i++;
                     count++;
                     if(count==x)
                     {
                         answer.push_back(temp);
                         temp.clear();
                         count=0;
                     }
                 }
               
            }
        }
      return answer;
    }
};