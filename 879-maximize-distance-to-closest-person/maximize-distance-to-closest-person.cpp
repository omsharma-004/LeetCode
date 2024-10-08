class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int longest = 0, beg = 0, i=0;
        while(seats[i]==0){
            beg++;
            i++;
        }
        int count = beg;
        for(i=0;i<seats.size();i++){
            if(seats[i]==0) count++;
            else{
                longest = max({count,longest});
                count=0;
            }
        }

        longest = longest/2 + longest%2;
        return max({longest,count,beg});
    }
};