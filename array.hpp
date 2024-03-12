#pragma once
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
template <typename T> struct Array {
  Array() {
    array = new T[max];
  }
  Array(const size_t &init_capacity) {
    max = init_capacity;
    array = new T[max];
  }
  ~Array() {
    free(array);
  }
  
  const int size() const { return this->length; }
  const T get(const size_t &index) const {
    if (index > length) {
      throw std::runtime_error("index out of bounds: index(" +
                               std::to_string(index) + ") length(" +
                               std::to_string(length) + ")");
    }
    return array[index];
  }
  const void push(const T &element) {
    if (length >= max) {
      grow();
    }
    this->array[length++] = element;
  }
  const T pop() {
    auto element = this->array[length];
    length--;
    if (length < max - 100) {
      shrink();
    }
    return element;
  }
private:
   void grow() {
    max += 100;
    std::cout << "reallocating at max size: " << max << std::endl;
    T *array = new T[max];
    for (int i = 0; i < length; ++i) {
      array[i] = this->array[i];
    }
    delete[] this->array;
    this->array = std::move(array);
  }
  void shrink() {
    max -= 100;
    std::cout << "deallocating at max size: " << max << std::endl;
    T *array = new T[max];
    for (int i = 0; i < length; ++i) {
      array[i] = this->array[i];
    }
    delete[] this->array;
    this->array = std::move(array);
  }
  static constexpr size_t init_max = 10;
  size_t max = init_max;
  T *array;
  size_t length = 0;
};