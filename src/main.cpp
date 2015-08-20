#include <iostream>
#include <fstream>

#include <biocode.hpp>

using namespace std;

int main() {
  try {
    //Week 1 Quiz
    //cout << PatternCount<false>({ "GACCATCAAAACTGATAAACTACTTAAAAATCAGT" }, { "AAA" }) << endl; //Quiz 1 question 2
    //for (auto& str : FrequentWords<false>({ "CGCCTAAATAGCCTCGCGGAGCCTTATGTCATACTCGTCCT" }, 3)) //Quiz 1 question 3
    //{
    //  cout << static_cast<string>(str) << endl;
    //};
    
    //Week 1 Programming assignments

   // { //Read input and solve PatternCount problem
   //   ifstream ifs("../data/datasets/dataset_2_6.txt", ios::in);
   //   string text{ };
   //   string pattern{ };
   //   getline(ifs, text);
   //   getline(ifs, pattern);
   //   cout << "PatternCount Result:" << PatternCount<false>(text, pattern) << endl;
	  ////cout << PatternCount(text, pattern) << endl;
   // }

    //{ //Read input and solve FrequentWords problem
    //  ifstream ifs("../data/datasets/dataset_2_9.txt", ios::in);
    //  string text{ };
    //  int k{ };
    //  getline(ifs, text);
    //  ifs >> k;
    //  for (auto& str : FrequentWords(text, k)) 
    //  {
    //    cout << static_cast<string>(str) << endl;
    //  };
    //}

    { //Read input and solve Reverse Complement problem
      cout << "Reverse Complement for AAAACCCGGT is" << ReverseComplement("AAAACCCGGT") << endl; //Quiz 1 question 3
      //ifstream ifs("../data/datasets/dataset_2_9.txt", ios::in);
      //string text{};
      //getline(ifs, text);
      //for (auto& str : ReverseComplement(text))
      //{
      //  cout << static_cast<string>(str) << endl;
      //};
    }
  } 
  catch (...) {
    cout << "Fatal error!" << endl;
    terminate();
  }
}