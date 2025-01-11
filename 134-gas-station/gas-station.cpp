class Solution {
public:
    int canCompleteCircuit(vector<int>& gass, vector<int>& costs) {
        int fuel=0;
        int tfuel=0;
        int tcost=0;
        int start=0;
        for(int i=0;i<gass.size();i++){
            tcost+=costs[i];
            tfuel+=gass[i];
            fuel+=gass[i]-costs[i];
            if(fuel<0){
                start=i+1;
                fuel=0;
            }
        }
        if(tfuel<tcost){
            return -1;
        }
        return start;
    }
};