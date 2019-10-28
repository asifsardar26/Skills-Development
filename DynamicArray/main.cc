/*
 * main.cc
 *
 *  Created on: 23 okt. 2019
 *      Author: A551226
 */

//#include "DynamicArray.h"
#include <iostream>
#include <DynamicArray.h>

using namespace DataStruct;

int main() {
  //DataStruct::DynamicArray<int> dyn_arr(4);
  DynamicArray<double>dyn_arr = {1, 3, 5, 7, 9};
  std::cout << "Array empty: " << dyn_arr.isEmpty() << std::endl;
  std::cout << "Array size: " << dyn_arr.size() << std::endl;
  std::cout << "Array get: " << dyn_arr.get(3) << std::endl;
  std::cout << "Array set: " << std::endl;
  dyn_arr.set(3, 13);
  std::cout << "Array get: " << dyn_arr.get(3) << std::endl;
  std::cout << "Array contains: " << dyn_arr.contains(6) << std::endl;
  std::cout << "Array contains: " << dyn_arr.contains(9) << std::endl;
  std::cout << "Array print: " << dyn_arr.toString() << std::endl;
  dyn_arr.add(11);
  std::cout << "Array print: " << dyn_arr.toString() << std::endl;
  std::cout << "Array remove: " << dyn_arr.removeAt(4) << std::endl;
  std::cout << "Array get: " << dyn_arr.toString() << std::endl;

  return 0;
}

