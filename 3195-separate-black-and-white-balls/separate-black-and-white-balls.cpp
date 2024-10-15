class Solution {
 public:
  long long minimumSteps(string s) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long fast = 0;
    int slow = 0;
    for (auto c : s)
      if (c == '1') slow++;
      else fast+=slow;
    return fast;
  }
};