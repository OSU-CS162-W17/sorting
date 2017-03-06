#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

template <class T>
void swap(T& a, T& b) {
  T tmp = a;
  a = b;
  b = tmp;
}

template <class T>
void selection_sort(std::vector<T>& vec) {
  for (int i = 0; i < vec.size() - 1; i++) {
    int min_idx = i;

    for (int j = i; j < vec.size(); j++) {
      if (vec[j] < vec[min_idx]) {
        min_idx = j;
      }
    }

    if (min_idx != i) {
      swap(vec[min_idx], vec[i]);
    }
  }
}

template <class T>
void insertion_sort(std::vector<T>& vec) {
  for (int i = 1; i < vec.size(); i++) {
    int j = i;
    while (j > 0 && vec[j] < vec[j-1]) {
      swap(vec[j], vec[j-1]);
      j--;
    }
  }
}

int main() {
  std::vector<int> vec;
  for (int i = 0; i < 16; i++) {
    vec.push_back(rand() % 100);
  }

  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;

  // selection_sort(vec);
  insertion_sort(vec);
  for (int i = 0; i < vec.size(); i++) {
    std::cout << "  " << vec[i];
  }
  std::cout << std::endl;
}
