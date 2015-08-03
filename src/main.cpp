#include <iostream>
#include <fstream>

#include <biocode.hpp>

int main() {
  try {
    //Week 1 Quiz
    std::cout << PatternCount<false>({ "GACCATCAAAACTGATAAACTACTTAAAAATCAGT" }, { "AAA" }) << std::endl; //Quiz 1 question 2
    
    //Week 1 Programming assignments

    { //Read input and solve PatternCount problem
      std::ifstream ifs("../data/datasets/dataset_2_6.txt", std::ios::in);
      std::string text{ };
      std::string pattern{ };
      std::getline(ifs, text);
      std::getline(ifs, pattern);
      std::cout << PatternCount<false>(text, pattern) << std::endl;
    }

    { //Read input and solve FrequentWords problem
      std::ifstream ifs("../data/datasets/dataset_2_6.txt", std::ios::in);
      std::string text{ };
      int k{ };
      std::getline(ifs, text);
      ifs >> k;
      std::cout << FrequentWords<false>(text, k).size() << std::endl;
    }
    
  } 
  catch (...) {
    std::cout << "Fatal error!" << std::endl;
    terminate();
  }
}