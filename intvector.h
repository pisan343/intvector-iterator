/**
 * IntVector: A class similar to vector<int>
 * Demonstrating how iterators can be defined for
 * user-defined classes
 **/

#ifndef INTVECTOR_H
#define INTVECTOR_H

#include <vector>

class IntVector {
private:
  std::vector<int> Nums;

public:
  explicit IntVector(unsigned int ASize);
  int size() const;
  int &operator[](int Index);
  class Iterator {
  private:
    IntVector *MyVectorPtr;
    int AtIntex;

  public:
    Iterator(IntVector *MyVectorPtr, int AtIndex);
    bool operator==(const Iterator &Other);
    bool operator!=(const Iterator &Other);
    int &operator*();
    // Prefix increment operator.
    Iterator &operator++();
    // Postfix increment operator.
    Iterator operator++(int);
    // Prefix decrement operator.
    Iterator &operator--();
    // Postfix decrement operator.
    Iterator operator--(int);
  };
  Iterator begin();
  Iterator end();
};

#endif // INTVECTOR_H
