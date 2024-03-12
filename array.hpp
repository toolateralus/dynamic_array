#pragma once
#include <cstddef>
#include <cstdlib>
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
    delete[] array;
  }
  
  const size_t Size() const { return this->length; }
  const T Get(const size_t &index) const {
    if (index >= length) {
      throw std::runtime_error("index out of bounds: index(" +
                               std::to_string(index) + ") length(" +
                               std::to_string(length) + ")");
    }
    return array[index];
  }
  const void Push(const T &element) {
    if (length >= max) {
      Grow();
    }
    this->array[length++] = element;
  }
  const T Pop() {
    if (length == 0) {
      throw std::runtime_error("Attempted to pop off an empty " + std::string("Array<") + typeid(T).name() + ">");
    }
    length--;
    auto element = this->array[length];
    if (length < max - 100) {
      Shrink();
    }
    return element;
  }
private:
   /*
  * @breif 
  * this function creates a new array at size new_max, moves all the elements from old_array into it, deletes the old array and
  * returns the new updated, resized array.
  *
  */
  static T *ResizeAndMove(const size_t &elementCount, const size_t &newMax, T *oldArray) {
    T *array = new T[newMax];
    for (int i = 0; i < elementCount; ++i) {
      array[i] = std::move(oldArray[i]);
    }
    delete[] oldArray;
    return array;
  }
   void Grow() {
    max += 100;
    T *array = new T[max];
    this->array = ResizeAndMove(length, max, this->array);
  }
  void Shrink() {
    max -= 100;
    this->array = ResizeAndMove(length, max, this->array);
  }
  static constexpr size_t INIT_MAX = 10;
  size_t max = INIT_MAX;
  T *array;
  size_t length = 0;
};