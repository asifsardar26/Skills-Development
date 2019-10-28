/*
 * DynamicArray.cpp
 *
 *  Created on: 24 okt. 2019
 *      Author: A551226
 */

#include <string>
#include <DynamicArray.h>

namespace DataStruct {

  template class DynamicArray<int>;
  template class DynamicArray<float>;
  template class DynamicArray<double>;

  template <class T>
  DynamicArray<T>::DynamicArray(int cap) {
    if(cap <= 0) throw std::invalid_argument("Illegal Capacity: " + cap);
    this->capacity = cap;
    this->len = cap;
    arr = new T[cap];
  }

  template <class T>
  DynamicArray<T>::DynamicArray(std::initializer_list<T> arr_vals) {
    this->capacity = arr_vals.size();
    this->len = arr_vals.size();
    arr = new T[this->capacity];
    int idx = 0;
    for(auto val : arr_vals) {
      arr[idx++] = val;
    }
  }

  template <class T>
  void DynamicArray<T>::add(T data) {
    // Resize if required!
    if(this->len + 1 >= this->capacity) {
      if(this->capacity == 0) this->capacity = 1;
      else this->capacity *= 2; // double the size
      T* new_arr = new T[this->capacity];
      for(int i = 0; i<this->len; i++) {
        new_arr[i] = this->arr[i];
      }
      delete[] this->arr;
      this->arr = new_arr;
    }
    this->arr[len++] = data;
  }

  template <class T>
  T DynamicArray<T>::removeAt(int rm_idx) {
    if(rm_idx < 0 || rm_idx >= len) throw std::out_of_range("Index out of range: 0 to " + this->len);
    auto data = this->arr[rm_idx];
    T* new_arr = new T[this->len - 1];
    int idx = 0;
    for(int i = 0; i<this->len; i++) {
      if(i == rm_idx) --idx;
      else new_arr[idx] = this->arr[i];
      ++idx;
    }
    delete[] this->arr;
    this->arr = new_arr;
    this->capacity = --this->len;
    return data;
  }

  template <class T>
  bool DynamicArray<T>::remove(T data) {
    auto idx = this->indexOf(data);
    if(idx == -1) return false;
    this->removeAt(idx);
    return true;
  }

  template <class T>
  auto DynamicArray<T>::indexOf(T data) {
    for(int i = 0; i<this->len; i++) {
      if(this->arr[i] == data) return i;
    }
    return -1;
  }

  template <class T>
  bool DynamicArray<T>::contains(T data) {
    return this->indexOf(data) != -1;
  }

  template <class T>
  std::string DynamicArray<T>::toString() {
    std::string toString;
    toString += "[";
    for(int i = 0; i<this->len; i++) {
      toString = toString + std::to_string(this->arr[i]) + ", ";
    }
    toString = toString + "]";
    return toString;
  }

} /* namespace DataStruct */
