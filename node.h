#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"
using namespace std;

class node {
 public:
  node();
  virtual ~node();
  void setValue(student*);
  student* getValue();
  void setNext(node*);
  node* getNext();
 private:
  student* value;
  node* next;
};
#endif
