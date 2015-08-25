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

    //{ //Read input and solve Reverse Complement problem
    // // cout << "Reverse Complement for AAAACCCGGT is" << ReverseComplement("AAAACCCGGT") << endl; //Quiz 1 question 3
    //  ifstream ifs("../data/datasets/dataset_3_2.txt", ios::in);
    //  string text{};
    //  getline(ifs, text);

    //  ofstream myfile;
    //  myfile.open("../data/datasets/dataset_3.txt");
    //  myfile << ReverseComplement(text) << endl;
    //  myfile.close();
    //};

    //{ //Read input and solve Pattern Matching Problem
    //  /*cout << "Pattern mathcing for ATAT and GATATATGCATATACTT" << endl;
    //  vector<int> ans = PatternMatchingProblem("ATAT", "GATATATGCATATACTT"); 
    //  for ( auto i = 0; i < ans.size(); i++ ){
    //    if ( ans[i] < 18) cout << ans[i] << endl;
    //  }
    //  */
    //  ifstream ifs("../data/datasets/Vibrio_cholerae.txt", ios::in);
    //  string text{ };
    //  string pattern{"CTTGATCAT"};
    //  //getline(ifs, pattern);
    //  getline(ifs, text);
    //  ofstream myfile;
    //  myfile.open("../data/datasets/dataset6.txt");
    //  
    //  cout << "PatternMatching Result:" << endl;
    //  vector<int> ans = PatternMatchingProblem(pattern, text);
    //  for (auto i = 0; i < ans.size(); i++) {
    //    if (ans[i] < text.size()+1 ) myfile << ans[i] << endl;
    //  };
    // 
    // myfile.close();

    //};


    { //Read input and solve Clump Finding Problem  // so-called nameless namepace makes temporary objects invoke destructors at their end
      ifstream ifs("../data/datasets/dataset_4_5.txt", ios::in);
      string text{};
      int L = 0;
      int k = 0; 
      int t = 0;
     
      getline(ifs, text);
      ifs >> k;
      ifs >> L;
      ifs >> t;	

	  // RAII (Resouce aquisition is initialization) is the very useful  
	  // technique that makes you forget about cleaning things up after
	  // resource hadler (ofstream in our case) and should always be used
	  ofstream myfile("../data/datasets/dataset45.txt"); 		
	  cout << "ClumpFindingProblem" << endl << text << endl << k << endl << L << endl << t;
	  vector<string> ans = ClumpFindingProblem(text, k, L, t);
	  for (auto i = 0; i < ans.size(); i++) {
	    myfile << ans[i] << endl;
	  };		
	} // here destructor of myfile properly finalizes the output stream  and destructor of ifs closes input  
  } 
  catch (...) {
    cout << "Fatal error!" << endl;
    terminate();
  }
}