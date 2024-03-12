#include "array.hpp"
#include <cassert>
#include <iostream>
#include <string>

struct Test {
  Test(const std::string &name, const int &num) : name(name), num(num) {
  } 
  int num = 0;
  std::string name;
  void print() {
    std::cout << "My name is : " << name << std::endl;
  }
};

int test_struct() {
  Array<Test*> structs(0);
  
  for (int i = 0; i < 1000; ++i) {
    structs.Push(new Test("hi", i));
  }
  for (int i = 0; i < 1000; ++i) {
    auto str = structs.Pop();
    //str->print();
  }
  return 0;
}

int test_ints() {
  Array<int> ints(0);
  
  for (int i = 0; i < 1000; ++i) {
    ints.Push(i);
  }
  
  for(int i = 0; i < 1000; ++i) {
    ints.Pop();
  }
  
  return 0;
}

int main() {
  int result = 0;
  result += test_ints();
  result += test_struct();
  std::cout << "test results : " << result << std::endl;
  std::cout << "0 means passing, otherwise the count is how many tests failed." << std::endl;
}