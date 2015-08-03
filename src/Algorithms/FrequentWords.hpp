#ifndef BioCode_Algorithms_FrequentWords_hpp
#define BioCode_Algorithms_FrequentWords_hpp

template< bool IsCyclic >
std::vector<DNA<false>> FrequentWords(const DNA<IsCyclic>& dnaString, int k) {
  //Initialize dictionary
  std::unordered_map<DNA<false>, int> counts{ };
  size_t n{ dnaString.size() };

  //Fill dictionary and count kmer frequencies
  for (size_t i = 0; i < n - k + 1; i++) {
    DNA<false> part{ dnaString.slice(i, k) };
    counts[part] = 1;
  };

  //Extract most frequent words
  int maxCount{ 1 };
  std::vector<DNA<false>> most_frequent_words{ };
  for (auto& p : counts) if (p.second == maxCount) most_frequent_words.push_back(p.first);

  return most_frequent_words;
};

#endif