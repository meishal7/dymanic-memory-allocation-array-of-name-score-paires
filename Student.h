/*
Student.h Header file of Student class. Countains members: string name, int score, constructors, destructor, overloaded ostream operator<< 

Author: Elena Mudrakova
Module: 3
Project: Homework 3
*/
#include <iostream>
#include <string>
using namespace std;

class Student{
  private:
    string name;
    int score;

  public:
    Student();
    Student(string name, int score);
    ~Student(){};
    

    void setName(string name);
    string getName();
    void setScore(int score);
    int getScore();
    

    friend std::ostream& operator<< (std::ostream &out, const Student &stu);

    
};



