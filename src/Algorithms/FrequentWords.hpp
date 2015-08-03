#ifndef BioCode_Algorithms_FrequentWords_hpp
#define BioCode_Algorithms_FrequentWords_hpp

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

#endif