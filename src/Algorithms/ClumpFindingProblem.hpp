#pragma once

using namespace std;

vector<string> ClumpFindingProblem( string& genome, int k, int L, int t) {

  auto sz = genome.size();
  map<string, int> kmers{};
  vector<string> ans{};
  
  for (auto i = 0; i < sz - L + 1; i++) {
    string clump{ genome, size_t(i), size_t(L) };
    map<string, int> tempKmers{};

    for (auto j = 0; j < L - k + 1; j++) {

      string tempKmer{ clump, size_t(j), size_t(k) };

      auto it = tempKmers.find(tempKmer);
      if (it == end(tempKmers)) {
        tempKmers[tempKmer] = 1;
      }
      else {
          tempKmers[tempKmer]++;
      };
    };
    // we have a temporary map with kmers and their counter for current L-clump
   
    for (auto& tempCounter : tempKmers) {
      string k_mer{ tempCounter.first };
      auto it2 = kmers.find(k_mer);

      if (it2 == end(kmers)) {
        kmers[k_mer] = tempCounter.second;
      }
      else {
        if (kmers[k_mer] < tempCounter.second){
          kmers[k_mer] = tempCounter.second;
        };
      };
    };
    // kmers map - all kmers with frequencies
  };
  for (auto& counter : kmers) {
    if (counter.second >= t) {
      ans.push_back(counter.first);
    };
  };
  return ans;
};


//ClumpFinding(Genome, k, L, t)
//for i ← 0 to | Genome | -L
//count ← 0 for all kmers in Genome(i, L)
//for j ← 0 to L - k
//kmer = Genome(i + j, L)
//count(kmer) = count(kmer) + 1
//for all kmers in count
//if count(kmer) >= t and kmer has not been outputted
//output kmer