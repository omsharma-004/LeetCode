class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int notEqual1 = -1;
        int notEqual2 = -1;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (notEqual1 == -1) {
                    notEqual1 = i;
                } else if (notEqual2 == -1) {
                    notEqual2 = i;
                } else {
                    return false;

                }
            }
        }
        if (notEqual1 == -1) {
            return true;
        } else if (notEqual2 == -1) {
            return false;
        } else {
            return (s1[notEqual1] == s2[notEqual2]) && (s1[notEqual2] == s2[notEqual1]); 
        }
    }
};