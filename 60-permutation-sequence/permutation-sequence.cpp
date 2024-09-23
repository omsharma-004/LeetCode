class Solution {
public:
    string helper(string str,int k,string ans ){
        int n=str.length();
        if(n==1){
            ans += str;
            return ans;
        }
        int fact=1;
        for(int i=2;i<=n-1;i++){
            fact*=i;
        }
        int idx=k/fact;
        if(k%fact==0) idx--;
        char ch=str[idx];
        string l=str.substr(0,idx);
        string r=str.substr(idx+1);
        str=l+r;
        int a=1;
        if(k%fact==0) a=fact;
        else a=k%fact;
        return helper(str,a,ans+ch);
    }
    string getPermutation(int n, int k) {
        string str="";
        for(int i=1;i<=n;i++){
            str+=to_string(i);
        }
        return helper(str,k,"");
    }
};