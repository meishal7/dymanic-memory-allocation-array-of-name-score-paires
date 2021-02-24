/*
main.cpp 
This program allocates array of objects dynamically. Takes user input, stores it into newly created object in array,sorts array in ascending order by object score and calculates score average. This program demonstrates traversign array of objects using pointers instead of array indices in printing array in main().

Author: Elena Mudrakova
Module: 3
Project: HW 3

Algorithm:
Before main()
1.  #include "Student.h"
    #include <iostream>
    #include <string>
2. Include functions prototypes. 
In main()
1. Declare int length, score;
   string name;
2. Take user input for length.
3. Allocate array of objects dynamically.
4. In for loop 
    4.1 Take user input for name and score.
    4.2 Validate score so it's not negative.
    4.3 Create pointer of Student type and initialize it to new obj.
    4.4 Store this pointer value into array.
5. Call bubbleSort(scores, length).
6. Print sorted array using pointers for traversing array.
7. Call avg(pScores, length).
8. Delete allocated array.
9. Set pScores to nullptr.
After main()
1. Declare void swap(Student *x, Student *y)  
    1. Student temp = *x;  
    2. *x = *y;  
    3. *y = temp; 
2. Declare void bubbleSort(Student *arr, int length)  
    1. int i, j;  
    2. Create outer for loop ( i < length-1)
      In outer for loop:
      2.1 Create another for loop (j < length-i-1)
        In inner for loop: 
        2.1.1 if (arr[j].getScore() > arr[j+1].getScore())  
        2.1.2 swap(&arr[j], &arr[j+1])
3. Declare int avg(Student arr[], int length)
    1. int total = 0
    2. int avg = 0;
    3. In for loop total += arr[i].getScore()
    4. After loop avg = total / length
    5. cout << avg << endl;
    6. return avg;
*/
#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

//Prototypes
void bubbleSort(Student *arr, int length);
void swap(Student *x, Student *y);
int avg(Student arr[], int length);

int main() {
  int length, score;
  string name;
  
  //Take user input
  cout << "How many scores you would like to enter? ";
  cin >> length;
  
  //Allocate array of objects
  Student *pScores = new Student[length];
  
  //Initialize array
  for(int i = 0; i<length; i++){
    //Take user input
    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student score: ";
    if(score < 0){
      cout << "Invalid score. Score can not be negative. Try again.";
      exit(0);
    }
    cin >> score;
    Student *ptr = new Student(name, score);
    pScores[i] = *ptr;

  }
  
  //Printing sorted array using pointers 
  cout << "Students scores:" << endl;
  bubbleSort(pScores, length);
  for(Student *ptr = pScores; ptr < (pScores + length); ptr++){
    cout << *ptr << endl;
  }
  //Print average
  cout << "\nScores average is ";
  avg(pScores, length);
  
  delete [] pScores;
  pScores = nullptr;


  
  return 0;
}

// Function declaration
// A function to swap elements of array
void swap(Student *x, Student *y)  
{  
    Student temp = *x;  
    *x = *y;  
    *y = temp;  
}
// A function to implement bubble sort  
void bubbleSort(Student *arr, int length)  
{  
    int i, j;  
    for (i = 0; i < length-1; i++){
      for (j = 0; j < length-i-1; j++)  
        if (arr[j].getScore() > arr[j+1].getScore())  
            swap(&arr[j], &arr[j+1]);  

    }      
}
// A function to calculate average score
int avg(Student arr[], int length){
  int total = 0;
  int avg = 0;
  for (int i = 0; i < length; i++){
    total += arr[i].getScore();
  }
  avg = total / length;
  cout << avg << endl;
  
  return avg;
}


