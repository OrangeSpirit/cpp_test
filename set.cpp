#include <iostream>
#include <string>
#include <set>



int main() {
  std::set<int> mySet;
  std::set<std::string> String_Set;

  mySet.insert(111);
  mySet.insert(222);
  mySet.insert(333);
  mySet.insert(444);
  mySet.insert(555);
  mySet.insert(300);
  mySet.insert(400);

  String_Set.insert("aaa");
  String_Set.insert("bbb");
  String_Set.insert("ccc");
  String_Set.insert("baa");
  String_Set.insert("aab");

  std::cout << mySet.size() << std::endl;
  for (auto &item : mySet) {
    std::cout << item << "   ";
  }
  std::cout << std::endl;


  std::cout << String_Set.size() << std::endl;
  for (auto &item : String_Set) {
    std::cout << item << "   ";
  }
  std::cout << std::endl;

  auto it = mySet.find(300);
  std::cout << &it << std::endl;
  return 0;
}