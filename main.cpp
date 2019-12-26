/**
 * Create a new class, IntVector, and show how
 * iterators are defined for this new class
 *
 * Author: Yusuf Pisan
 * Date: 26 Dec 2019
 */

#include "intvector.h"
#include <iostream>
#include <vector>

using namespace std;

// should work with vector<int>
// and IntVector data type
template <typename T> void vectorTest() {
  T V(5);
  cout << "Created a container with size: " << V.size() << endl;
  for (auto I = 0; I < V.size(); ++I) {
    V[I] = I * I;
    cout << "V[" << I << "] = " << V[I] << ", ";
  }
  cout << endl;

  // auto is vector<int>::Iterator OR IntVector::Iterator
  auto It = V.begin();
  cout << "First element is " << *It;
  ++It;
  cout << ", Second element is " << *It << endl;
  It = V.end();
  // end() It points to element beyond last
  --It;
  cout << "Last element is " << *It;
  --It;
  cout << ", Second to last element is " << *It << endl;
  cout << "Using begin/end in for loop: ";
  for (auto Itx = V.begin(); Itx != V.end(); ++Itx) {
    cout << *Itx << ", ";
  }
  cout << endl;
  cout << "Using range based for loop: ";
  // auto is int
  for (auto Item : V) {
    cout << Item << ",";
  }
  cout << endl;
}

int main() {
  vectorTest<vector<int>>();
  cout << "=====" << endl;
  vectorTest<IntVector>();
  cout << "Done!" << endl;
  return 0;
}