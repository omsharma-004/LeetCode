class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string str=countAndSay(n-1);
        string str2="";
        int frq=1;
        char ch=str[0];
        for(int i=1;i<str.length();i++){
            char dh=str[i];
            if(ch==dh){
                frq++;
            }
            else{
                str2 += (to_string(frq)+ch);
                ch=dh;
                frq=1;
            }
        }
        str2 += (to_string(frq)+ch);
        return str2;
    }
};