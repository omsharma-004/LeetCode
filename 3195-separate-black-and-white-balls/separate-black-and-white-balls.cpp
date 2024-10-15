class Solution {
 public:
  long long minimumSteps(string s) {
    long fast = 0;
    int slow = 0;

    for (auto c : s)
      if (c == '1')
        slow++;
      else
        fast+=slow;

    return fast;
  }
};