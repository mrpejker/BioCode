#ifndef BioCode_Algorithms_PatternCount_hpp
#define BioCode_Algorithms_PatternCount_hpp

using namespace std;

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
//PatternCount(Text, Pattern)
//count ← 0
//for i ← 0 to | Text | − | Pattern |
//if Text(i, | Pattern | ) = Pattern
//count ← count + 1
//return count
int PatternCount(const string& dnaString, const  string& Pattern) {
	auto count{ 0 };
	size_t n{ dnaString.size() };
	size_t k{ Pattern.size() };

	for (size_t i = 0; i < n - k + 1; i++) {
		bool same{ true };
		for (size_t j = 0; j < k; j++) {
			if (dnaString[i + j] != Pattern[j]) {
				same = false;
				break;
			};
		};
		if (same) count++;
	};
	return count;
};


#endif