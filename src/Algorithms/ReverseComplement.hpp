#pragma once

using namespace std;

string ReverseComplement(const string& pattern) {

  auto sz = pattern.size();
  string reversePattern{pattern};
  
  for (auto i = 0; i < sz; i++) {

    switch (pattern[i]) {
    case 'A':
      reversePattern[sz - 1 - i ] ='T'; 
      break;
    case 'T':
      reversePattern[sz - 1 - i] = 'A';
      break;
    case 'G':
      reversePattern[sz - 1 - i] = 'C';
      break;
    case 'C':
      reversePattern[sz - 1 - i] = 'G';
      break;
    default:
      cout << "Error" << endl; 
      break;
    };
  };

  return reversePattern;
};
