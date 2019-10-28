/*
 * DynamicArray.h
 *
 *  Created on: 24 okt. 2019
 *      Author: A551226
 */

#ifndef INC_DYNAMICARRAY_H_
#define INC_DYNAMICARRAY_H_

#include <stdexcept>
#include <string>

namespace DataStruct {

template <class T>
  class DynamicArrayIterator;

  template <class T>
  class DynamicArray {
    friend class DynamicArrayIterator<T>;
    T* arr;
    int len;
    int capacity;

  public:
    DynamicArray(int cap);
    DynamicArray(std::initializer_list<T> arr_vals);

    auto size() const { return this->len; }
    bool isEmpty() { return this->size() == 0; }
    auto get(int idx) { return arr[idx]; }
    void set(int idx, T data) { arr[idx] = data; }
    T removeAt(int rm_idx);
    void add(T data);
    bool remove(T data);
    auto indexOf(T data);
    bool contains(T data);
    std::string toString();
  };

  template <class T>
  class DynamicArrayIterator {
    int index = 0;

    public:
      DynamicArrayIterator();
      bool hasNext(const DynamicArray<T>& arr) { return this->index < arr.len; }
      T next(const DynamicArray<T>& arr) { return arr[index++]; }
      void remove() = delete;
  };

} /* namespace DataStruct */

//using DataStruct::DynamicArray;
//template class DynamicArray<int>;

#endif /* INC_DYNAMICARRAY_H_ */
