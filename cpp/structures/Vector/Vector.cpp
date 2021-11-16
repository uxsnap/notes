#include "Vector.hpp"

Vector::Vector(int *arr, int size) {
  _size = size;
  _capacity = size * 2;
  int* narr = new int[_capacity];
  for (int i = 0; i < size; i++) {
    narr[i] = arr[i];
  }
  
  _arr = narr;
}

Vector::~Vector() {
  delete [] _arr;
}

int Vector::size() { return _size; }
int Vector::capacity() { return _capacity; }
bool Vector::is_empty() { return !_size; }
void Vector::resize(int nsize) {
  if (_capacity > nsize) 
  {
    return;
  }

  int *narr = new int[nsize];
  for (int i = 0; i < _size; i++) {
    narr[i] = _arr[i];
  }

  delete [] _arr;
  _arr = narr;
  
  _capacity = nsize;
}

int Vector::at(int ind) {
  if (ind > _size || _arr == nullptr) return -1;

  return _arr[ind];
}

void Vector::push(int nelem) {
  if (_size + 1 >= _capacity) {
    resize(_capacity * 2);
  }

  _arr[_size] = nelem; 

  _size++;
}

void Vector::print() {
  for (int i = 0; i < _size; i++) cout << _arr[i] << " ";
}

int Vector::insert(int index, int elem) {
  if (index > _size || index < 0) return -1;

  if (_size + 1 >= _capacity) {
    resize(_capacity * 2);
  }

  for (int i = _size; i > index ; i--)
  {
    _arr[i] = _arr[i - 1];
  }
  
  _size++;
  _arr[index] = elem;

  return index;
}

void Vector::prepend(int item) {
  insert(0, item);
}

int Vector::pop() {
    if (is_empty()) throw runtime_error("empty array");
    
    return _arr[--_size];
}

void Vector::delete_at(int index) {
  if (index > _size || index < 0) return;

  for (int i = index; i < _size + 1; i++)
  {
    _arr[i] = _arr[i + 1];
  }
  
  _size--;
}
