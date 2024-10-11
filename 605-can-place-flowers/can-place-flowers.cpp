class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        for(int i=0;i<arr.size();i++){
            if (arr[i] == 0 && (i == 0 || arr[i - 1] == 0) && (i == arr.size() - 1 || arr[i + 1] == 0)){
                arr[i]=1;
                n--;
            }
        }
        return (n<=0);
    }
};