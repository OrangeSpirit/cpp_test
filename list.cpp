#include <iostream>
// #include <string>
using namespace std;

template<typename T>
class List {
  public:
    List();
    ~List();

    void push_back(T data);
    void pop_front();
    void clear();
    int GetSize() {return Size;};
    T& operator[](const int index);

    void push_front(T data);
    void pop_back();
    void insert(T data, int index);
    void removeAt(int index);

    
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
  cout << "destructor" << endl;
  clear();
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
void List<T>::pop_front() {
  Node<T>* temp = head;
  head = head->pNext;
  delete temp;
  Size--;
}

template <typename T>
void List<T>::clear() {
  while (Size) {
    pop_front();
  }
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

template <typename T>
void List<T>::push_front(T data) {
  head = new Node<T>(data, head);
  Size++;
}

template <typename T>
void List<T>::pop_back() {
  removeAt(Size - 1);
}

template <typename T>
void List<T>::insert(T data, int index) {
  if (index == 0) {
    push_front(data);
  } else {
    Node<T>* previus = this->head;
    for (int i = 0; i < index - 1; i++) {
      previus = previus->pNext;
    }

    Node<T>* newNode = new Node<T>(data, previus->pNext);
    previus->pNext = newNode;

    Size++;
  }
}

template <typename T>
void List<T>::removeAt(int index) {
  if (index == 0) {
    pop_front();
  } else {
    Node<T>* previous = this->head;
    for (int i = 0; i < index - 1; i++) {
      previous = previous->pNext;
    }
    Node<T>* toDelete = previous->pNext;
    previous->pNext = toDelete->pNext;
    delete toDelete;
    
    Size--;
  }
}

int main() {
  List<int> lst;
  lst.push_back(5);
  lst.push_back(10);
  lst.push_back(20);

  cout << "Size = " << lst.GetSize() << endl;
  lst.push_back(33);
  lst.push_back(99);
  cout << "Size = " << lst.GetSize() << endl;
  lst.push_back(111);
  cout << "Size = " << lst.GetSize() << endl;

  cout << "lst[2] = " << lst[2] << endl;
  cout << "lst[6] = " << lst[5] << endl;

  lst.pop_front();
  cout << "Size after pop_front = " << lst.GetSize() << endl;
  cout << "lst[2] = " << lst[2] << endl;
  
  lst.pop_front();
  cout << "Size after pop_front = " << lst.GetSize() << endl;
  cout << "lst[2] = " << lst[2] << endl;

  //lst.clear();
  // cout << "Size = " << lst.GetSize() << endl;

  cout << "lst[0] = " << lst[0] << endl;
  lst.push_front(555);
  cout << "Size after push_front = " << lst.GetSize() << endl;
  cout << "lst[0] = " << lst[0] << endl;

  cout << "Size before insert = " << lst.GetSize() << endl;
  cout << "lst[3] = " << lst[3] << endl;
  lst.insert(888, 3);
  cout << "Size after insert = " << lst.GetSize() << endl;
  cout << "lst[3] = " << lst[3] << endl;

  lst.removeAt(3);
  cout << "Size after remove = " << lst.GetSize() << endl;
  cout << "lst[3] = " << lst[3] << endl;

  int Size = lst.GetSize();
  cout << "lst[Size] = " << lst[Size - 1] << endl;
  lst.pop_back();
  cout << "Size after pop_back = " << lst.GetSize() << endl;
  Size = lst.GetSize();
  cout << "lst[Size] = " << lst[Size - 1] << endl;

  return 0;
}