#include "student.h"

student::student(){
}

student::~student(){
	delete firstName;
	delete lastName;
}

string* student::getFirstName() {
	return firstName;
}

string* student::getLastName() {
	return lastName;
}

float student::getGpa() {
	return gpa;
}

int student::getId() {
	return id;
}

void student::setFirstName(string* value) {
	firstName = value;
}

void student::setLastName(string* value) {
	lastName = value;
}

void student::setGpa(float value) {
	gpa = value;
}

void student::setId(int value) {
	id = value;
}