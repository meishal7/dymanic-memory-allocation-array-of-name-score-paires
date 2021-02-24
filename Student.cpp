/*
Student.cpp Implementation of Student class.
Author: Elena Mudrakova
Module: 3
Project: Homework 3

Algorithm:
1.#include "Student.h"
  #include <iostream>
  #include <iomanip> //for using formatting
  #include <string> 
2. Declare default constructor.
3. Declare two arguments constructor.
4. Declare getters and setters.
5. Overload ostream& operator<< for printitng the object.

*/
#include "Student.h"
#include <iostream>
#include <iomanip> //for using formatting
#include <string>
using namespace std;

Student::Student(){
  name = " ";
  score = 0;
};

Student::Student(string name, int score){
  this->name = name;
  this->score = score;
}

void Student::setName(string name){
  this->name = name;
}
string Student::getName(){
  return name;
}
void Student::setScore(int score){
  this->score = score;
}
int Student::getScore(){
  return score;
}

std::ostream& operator<< (std::ostream &out, const Student &stu)
{
    out << setw(10) << left << stu.name << setw(5) << right << stu.score << endl;
    
    return out; 
}