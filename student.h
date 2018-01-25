#pragma once

#include <iostream>

using namespace std;

class student {
 public:
  student();
  virtual ~student();

  string* getFirstName();
  string* getLastName();
  float getGpa();
  int getId();
  
  void setFirstName(string* value);
  void setLastName(string* value);
  void setGpa(float value);
  void setId(int value);
  
 private:
  string* firstName;
  string* lastName;
  float gpa;
  int id;
};
