#pragma once

using namespace std;

vector<int> PatternMatchingProblem(const string& pattern, const string& genome) {

  auto k = pattern.size();
  auto n = genome.size();
  cout << k << endl << n << endl;

  auto count{ 0 };
  vector<int> ans(n, n+1 );
  string temp{};

  for (auto i = 0; i < n - k + 1; i++) {
    temp = genome.substr(i, k);
   // cout << temp << endl;
    if (pattern.compare(temp) == 0) {
      ans[count] = i;
      count++;
    }
  };
  
  return ans;
};
