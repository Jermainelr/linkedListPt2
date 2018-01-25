//Program Created by Jermaine Lara
// 1/25/18
// Program adds, deletes, prints names of students, their ID's and GPA's 
// and also averages their GPA's. Similar to student list but uses linked lists and recursion instead of vectors
#include <iostream>
#include "node.h"
#include <string.h>
#include <iomanip>

using namespace std;
student* createStudent();
void addStudent(node* &head, node* previous, node* current, student* value);
void printStudent(node* n);
node* deleteStudent(node* current, int studentId);
void printAvgGpa(node* head);

int main() {
  char command[81];
  node* head = NULL;
  
  do {
	//Command word loop
    cout << "Enter a Command (ADD, PRINT, DELETE, AVERAGE or QUIT)" << endl;
    cin >> command;
    if (strcmp(command, "ADD") == 0) {
      student* newStudent = createStudent();
	  addStudent(head, head, head, newStudent);
    }
    else if (strcmp(command, "PRINT") == 0) {
      if (head == NULL ) {
			cout << "Nothing to print: list is empty!" << endl;
		}
		else {
			printStudent(head);
		}
    }
    
    else if (strcmp(command, "DELETE") == 0) {
		if (head == NULL ) {
			cout << "Nothing to delete: list is empty!" << endl;
		}
		else {
			int id;
			cout << "Enter the student ID number to delete them from the list" << endl;
			cin >> id;
			head = deleteStudent(head, id);
		}
    }
    
    else if (strcmp(command, "AVERAGE") == 0) {
		if (head == NULL ) {
			cout << "Nothing to average: list is empty!" << endl;
			}
			else {
				printAvgGpa(head);
			}
    } 
    else if (strcmp(command, "QUIT") != 0) {
      cout << "Invalid Command" << endl;
    }
  }while(strcmp(command, "QUIT") != 0);
  
}

//Prompts user for student parameters
student* createStudent() {
  char input[81];
  float gpa;
  int id;
  
  student* newStudent = new student();
  cout << "Enter First Name" << endl;
  cin >> input;
  newStudent->setFirstName(new string(input));

  cout << "Enter Last Name" << endl;
  cin >> input;
  newStudent->setLastName(new string(input));

  cout << "Enter student ID" << endl;
  cin >> id;
  newStudent->setId(id);
  
  cout << "Enter student GPA" << endl;
  cin >> gpa;
  newStudent->setGpa(gpa);
 
  return newStudent;
}

//Adds students parameters to next node
//Cases based off linked list vizualizer in Mr. G's video 
void addStudent(node* &head, node* previous, node* current, student* value) {
	if (head == NULL) {
		//Empty list:First student
		head = new node();
		head->setValue(value);
		head->setNext(NULL);
	}
	else if (value->getId() < head->getValue()->getId()) {
		//When the student will become the new head
		node* temp = head;
		head = new node();
		head->setValue(value);
		head->setNext(temp);
	}
	else if (current == NULL) {
		// When the student will go at the end
		node* next = new node();
		next->setValue(value);
		next->setNext(NULL);
		previous->setNext(next);
	}
	else if (value->getId() < current->getValue()->getId()) {
		// When the student will be in the middle of two existing students
		node* newNode = new node();
		newNode->setValue(value);
		previous->setNext(newNode);
		newNode->setNext(current);
	}
	else {
		addStudent(head, current, current->getNext(), value);
	}
		
}		 
//Float Precision reference: https://stackoverflow.com/questions/14677448/how-to-cout-a-float-number-with-n-decimal-places
void printStudent(node* n) {
	student* v = n->getValue();
    cout << *v->getFirstName() << ", " << *v->getLastName() << ", " << v->getId() << ", " << fixed << setprecision(2) << v->getGpa() << endl;
	if (n->getNext() != NULL) {
		printStudent(n->getNext());
	}
}

node* deleteStudent(node* current, int studentId) {
	if(current == NULL) {
		return NULL;
	}
	
	else if (current->getValue()->getId() == studentId){
		node* next = current->getNext();
		delete current->getValue();
		//The next line is the right thing to do to free memory however it is
		//commented out because the node.o causes a segmentation fault
		//delete current;
		return next;
	}
	else {
		current->setNext(deleteStudent(current->getNext(), studentId));
		return current;
	}	
}

void printAvgGpa(node* head) {
	// Iterate student to compute the Gpa sum and student count
	float sum = 0.0f;
	int count = 0;
	for(node* n = head; n != NULL; n = n->getNext()) {
		sum += n->getValue()->getGpa();
	    count++;
	}
	float avg = sum / count;
	cout << "Average GPA: " << fixed << setprecision(2) << avg << endl;
}
       
   
    
