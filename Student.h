#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>
#include"nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

struct Student{
  string name;
  string rollNo;
  int quiz[3];
  int assignments[3];
  };

json readDataFromJson( json &data);
void ConvertJson(Student s[], int size, json j);
void AverageMarksInAssignment3(Student s[], int size);
void HighestMarksInQuiz2(Student s[], int size);
void StudentsCount(Student s[], int size);
void AvgMarksOfStudent(Student s[], int size);
void DisplayTopperData(Student s[], int size);
void MarksOfEachStudent(Student s[], int size);
void AverageMarksForEachQuiz(Student s[], int size);
#endif //STUDENT_H
