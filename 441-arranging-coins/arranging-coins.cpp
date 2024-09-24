class Solution {
public:
    int arrangeCoins(int n) {
        long long lo=1;
        long long hi=n;
        while(lo<=hi){
            long long mid=lo+(hi-lo)/2;
            if((long long)(mid*(mid+1))/2 == n) return (int)mid;
            else if((long long)(mid*(mid+1))/2 > n) hi=mid-1;
            else lo=mid+1;
        }
        return (int)hi;
    }
};