#include <iostream>
#include <fstream>

#include <biocode.hpp>

using namespace std;

int main() {
  try {
    { //Read input and solve ReverseComplement problem
      ifstream ifs("../data/datasets/dataset_3_2.txt", ios::in);
      string text{ };
      getline(ifs, text);
      ofstream ofs("result.txt");
      ofs << static_cast<string>(DNA<false>{ text }.reverse_complement()) << endl;
    }
  } 
  catch (...) {
    cout << "Fatal error!" << endl;
    terminate();
  }
}