
#include <iostream>
// #include <string>
#include <vector>
// // Hacemos una función que cuente las letras de una palabra
// int LettersOnAWord(std::string word) { 
//     int count = 0;
//     for (int i = 0; i < word.size(); i++) {
//         count++;
//     }
//     return count;
// }
// std::vector<int> Mergesort(std::vector<int> array) {

//     if (array.size() <= 1) {
//         return array;
//     }   
    
//     std::vector<int> left;
//     std::vector<int> right;
//     int middle = array.size() / 2;

//     for (int i = 0; i < middle; i++) {
//         left.push_back(array[i]);
//     }

//     for (int i = middle; i < array.size(); i++) {
//         right.push_back(array[i]);
//     }

//     left = Mergesort(left);
//     right = Mergesort(right);

//     std::vector<int> sorted;

//     while (left.size() > 0 && right.size() > 0) {
    
//         if (left[0] <= right[0]) {
//             sorted.push_back(left[0]);
//             left.erase(left.begin());
//         } else {
        
//             sorted.push_back(right[0]);


//             right.erase(right.begin()); 
            
//    }

//   int count = 0;
// int main() {
//     std::string s;
//     std::cin >> s;
//     std::cout << LettersOnAWord(s) << std::endl;
// }

int SortVector(std::vector<int>& v) {
  int count = 0;
  for (int i = 0; i < v.size(); i++) {
      for (int j = 0; j < v.size(); j++) {
          if (v[i] < v[j]) {
              int temp = v[i];
              v[i] = v[j];
              v[j] = temp;
              count++;
          }
      }
  }
  return count;
}
void PrintVector(std::vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
      std::cout << v[i] << " ";
  }
  std::cout << std::endl;
} 

class HashTable { 
 public:
  
  void Insert(int key) {
    int hash = Hash(key);
    table[hash].push_back(key);
  }
  void Print() {
    for (int i = 0; i < table_size; i++) {
      std::cout << i << ": ";
      PrintVector(table[i]);
    }
  }
  int Hash(int key) {
    return key % table_size;
  }
  void Insert(int key) {
    int hash = Hash(key);
    table[hash].push_back(key);
  }
  void Print() {
    for (int i = 0; i < table_size; i++) {
      std::cout << i << ": ";
      PrintVector(table[i]);
    }
  }
  int Hash(int key) {
    return key % table_size;
  }
 private:
  std::vector<std::vector<int>> table;
  int size;
  int count;
  int hash(int key) {
    return key % size;
  }
  int table_size;
};

int main() {
  std::vector<int> v{0,1,5,4,3,2,78,98,9,3,2};
  PrintVector(v);
  SortVector(v);
  PrintVector(v);
}
