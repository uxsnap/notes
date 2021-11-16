struct Vector {
  Vector(int *, int);
  ~Vector();   

  int size();
  int capacity();
  bool is_empty();
  int at(int);
  void push(int);
  int insert(int, int);
  void prepend(int);
  int pop();
  void delete_at(int);
  int remove(int);
  int find(int);
  void print();

private:
  void resize(int);
  int *_arr;
  int _capacity;
  int _size;
};