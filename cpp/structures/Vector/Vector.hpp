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
  int delete_at(int);
  int remove(int);
  int find(int);
  int resize(int);

  void print();

private:
  int *_arr;
  int _capacity;
  int _size;
};