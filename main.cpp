#include<iostream>
#include"Student.h"
#include"nlohmann/json.hpp"
using json = nlohmann::json;
using namespace std;

int main(){
    json j;
    readDataFromJson(j);
    int size = j.size();
    Student s[size];
    //cout<<"The size of j is "<< size<< endl;
    ConvertJson( s, size, j);
    AverageMarksInAssignment3( s, size);
    HighestMarksInQuiz2( s, size);
    StudentsCount( s, size);
    AvgMarksOfStudent( s, size);
    DisplayTopperData( s, size);
    MarksOfEachStudent( s, size);
    AverageMarksForEachQuiz( s, size);
  return 0;
  }