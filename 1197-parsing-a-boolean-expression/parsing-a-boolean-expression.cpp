class Solution {
 public:
  bool parseBoolExpr(string expression) {
    ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    int i = 0;
    return parse(expression, i);
  }
  bool parse(const string& exp, int& i) {
    if (exp[i] == 't') {
      ++i;
      return true;
    }
    if (exp[i] == 'f') {
      ++i;
      return false;
    }
    if (exp[i] == '!') {
      i += 2;
      bool ans = !parse(exp, i);
      ++i;
      return ans;
    }

    bool isAnd = exp[i] == '&';
    bool ans = isAnd;
    i += 2;
    while (exp[i] != ')') {
      bool parsed = parse(exp, i);
      if (isAnd)
        ans &= parsed;
      else
        ans |= parsed;
      if (exp[i] == ',')
        ++i;
    }
    ++i;
    return ans;
  }
};