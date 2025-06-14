class Solution {
    int replace_all(int num, int from, int to){
        int res = 0 , p = 0 ;
        while(num){
            int d = num % 10 ;
            if(d == from) d = to ;
            res += d * pow(10,p++) ;
            num /= 10 ; 
        }
        return res ;
    }
public:
    int minMaxDifference(int num) {
        char ll = 'x', rr = 'x';
        string nums = to_string(num) ;
        for(int i = 0 ; i < nums.length() ; i++){
            if(ll == 'x' && nums[i] != '9') ll = nums[i] ;
            if(rr == 'x' && nums[i] != '0') rr = nums[i] ;
        }
        int l = ll == 'x' ? num : replace_all(num,ll-'0',9) ;
        int r = rr == 'x' ? num : replace_all(num,rr-'0',0) ;
        return l - r ;
    }
};