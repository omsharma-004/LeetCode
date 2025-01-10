class Solution {
public:
    string decodeString(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        stack<int> num;
        stack<string> str;
        int k=0;
        for(auto i:s){
            if(isdigit(i)){
                k = k * 10 + (i - '0');
            }
            else if(i=='['){
                num.push(k);
                k=0;
                str.push("");
            }
            else if(i==']'){
                string ch=str.top();
                str.pop();
                int repeat=num.top();
                num.pop();
                string temp="";
                for(int i=0;i<repeat;i++){
                    temp+=ch;
                }
                if(!str.empty()){
                    str.top()+=temp;
                }
                else{
                    str.push(temp);
                }
            }
            else{
                if(!str.empty()){
                    str.top()+=i;
                }
                else {
                    str.push(string(1, i));
                }
            }
        }
        return str.top();
    }
};