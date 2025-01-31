class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i=0;
        int used=0;
        for(;i<heights.size()-1;i++){
            if(heights[i]>heights[i+1]) continue;
            int diff=heights[i+1]-heights[i];
            if(used+diff<=bricks){
                used+=diff;
                pq.push(diff);
            }
            else if(ladders>0){
                if(!pq.empty() && pq.top()>diff){
                    used=used-pq.top()+diff;
                    pq.pop();
                    pq.push(diff);
                }
                ladders--;
            }
            else{
                break;
            }
        }
        return i;
    }
};