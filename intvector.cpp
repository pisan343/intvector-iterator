
#include "intvector.h"
#include <cassert>

IntVector::IntVector(unsigned int ASize) { Nums.resize(ASize); }

int IntVector::size() const { return Nums.size(); }

int &IntVector::operator[](int Index) { return Nums[Index]; }

IntVector::Iterator IntVector::begin() {
  Iterator NewIt(this, 0);
  return NewIt;
}

IntVector::Iterator IntVector::end() {
  Iterator NewIt(this, this->Nums.size());
  return NewIt;
}

IntVector::Iterator::Iterator(IntVector *MyVectorPtr, int AtIndex)
    : MyVectorPtr{MyVectorPtr}, AtIntex{AtIndex} {}

bool IntVector::Iterator::operator==(const Iterator &Other) {
  return MyVectorPtr == Other.MyVectorPtr && AtIntex == Other.AtIntex;
}

bool IntVector::Iterator::operator!=(const Iterator &Other) {
  // same as:  return ! (*this == Other);
  return !this->operator==(Other);
}

int &IntVector::Iterator::operator*() { return MyVectorPtr->Nums[AtIntex]; }

// Prefix increment operator.
IntVector::Iterator &IntVector::Iterator::operator++() {
  ++AtIntex;
  return *this;
}

// Postfix increment operator.
IntVector::Iterator IntVector::Iterator::operator++(int) {
  Iterator Temp = *this;
  ++Temp;
  return Temp;
}

// Prefix decrement operator.
IntVector::Iterator &IntVector::Iterator::operator--() {
  assert(AtIntex > 0 && "IntVector size cannot go below 0");
  --AtIntex;
  return *this;
}
// Postfix decrement operator.
IntVector::Iterator IntVector::Iterator::operator--(int) {
  Iterator Temp = *this;
  --Temp;
  return Temp;
}
