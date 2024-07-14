#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {
  public:
    List();
    ~List();

    void push_back(T data);
    int GetSize() {return Size;};
    T& operator[](const int index);

    
  private:
    template<typename N>
    class Node {
      public:
      Node* pNext;
      N data;

      Node(N data = N(), Node* pNext = nullptr) {
        this->data = data;
        this->pNext = pNext;
      }
    };

    int Size;
    Node<T>* head;
};

template<typename T>
List<T>::List() {
  Size = 0;
  head = nullptr;
}

template<typename T>
List<T>::~List() {

}

template <typename T>
void List<T>::push_back(T data) {
  if (head == nullptr) {
    head = new Node<T>(data);
  } else {
    Node<T>* current = this->head;
    while (current->pNext != nullptr) {
      current = current->pNext;
    }
    current->pNext = new Node<T>(data);
  }
  Size++;
}

template <typename T>
T& List<T>::operator[](const int index) {
  int count = 0;
  Node<T>* current = this->head;
  while (current != nullptr) {
    if (count == index) {
      return current->data;
    }
    current = current->pNext;
    count++;
  }
  return current->data;
}

int main() {
  List<int> lst;
  lst.push_back(5);
  lst.push_back(10);
  lst.push_back(20);

  cout << "Size = " << lst.GetSize() << endl;
  lst.push_back(0);
  lst.push_back(99);
  cout << "Size = " << lst.GetSize() << endl;
  lst.push_back(111);
  cout << "Size = " << lst.GetSize() << endl;

  cout << "lst[2] = " << lst[2] << endl;
  cout << "lst[6] = " << lst[5] << endl;
  return 0;
}