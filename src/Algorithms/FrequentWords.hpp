#ifndef BioCode_Algorithms_FrequentWords_hpp
#define BioCode_Algorithms_FrequentWords_hpp

#include <algorithm>
#include <map>

using namespace std;

template< bool IsCyclic >
vector<DNA<false>> FrequentWords(const DNA<IsCyclic>& dnaString, int k) {
  //Initialize dictionary
  unordered_map<DNA<false>, int> counts{ };
  size_t n{ dnaString.size() };

  //Fill dictionary and count kmer frequencies
  int maxCount{ 1 };
  for (size_t i = 0; i < n - k + 1; i++) {
    DNA<false> part{ dnaString.slice(i, k) };
    auto it = counts.find(part);
    if (it == end(counts)) { 
      counts[part] = 1; 
    } else { 
      it->second++; 
      if (maxCount < it->second) maxCount = it->second;
    };
  };

  //Extract most frequent words
  vector<DNA<false>> most_frequent_words{ };
  for (auto& p : counts) if (p.second == maxCount) most_frequent_words.push_back(p.first);

  return most_frequent_words;
};

//FrequentWordsProblem(Text, k)
//counts ← 0 for all possible kmers
//for i ← 0 to | Text | -k
//kmer ← Text(i, k )
//counts(kmer) ← counts(kmer) + 1
//count ← count + 1
//return all kmers where counts(kmer) = max(counts)
//string& FrequentWords(const string& dnaString, int k) {
//
//
//}

vector<string> FrequentWords(const string& text, int k) {

  auto sz =  text.size()  ;
  map<string, int> frequentWords{ };

  for (auto i = 0; i < sz - k + 1; i++){
    string kmer{ text, size_t(i), size_t(k) };
    auto it = frequentWords.find(kmer);
    if (it == end(frequentWords)) {
      frequentWords[kmer] = 1;
    } else {
      frequentWords[kmer]++;
    };
  };
  
  auto maxCount{ 0 };
  for (auto& p : frequentWords) {
    maxCount = max(maxCount, p.second);
  };

  vector<string> result{ };
  for (auto& p : frequentWords) {
    if (p.second == maxCount) result.push_back(p.first);
  };

  return result;
};

#endif