#ifndef BioCode_Algorithms_PatternCount_hpp
#define BioCode_Algorithms_PatternCount_hpp

template< bool IsCyclic >
int PatternCount(const DNA<IsCyclic>& dnaString, const DNA<false>& kmerString) {
  //Initialize counter
  auto count { 0 };
  size_t n { dnaString.size() };
  size_t k { kmerString.size() };

  //Count number of patter occurences
  //TO DO change to KMP algorithm for optimal complexity
  for (size_t i = 0; i < n - k + 1; i++) {
    bool same{ true };
    for (size_t j = 0; j < k; j++) {
      if (dnaString[i + j] != kmerString[j]) {
        same = false;
        break;
      };
    };
    if (same) count++;
  };

  return count;
};

#endif