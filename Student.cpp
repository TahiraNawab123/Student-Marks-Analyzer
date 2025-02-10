#include<iostream>
#include"Student.h"
#include"nlohmann/json.hpp"
using json = nlohmann::json;
#include<fstream>
using namespace std;

json readDataFromJson( json & data){
    ifstream myFile;
    myFile.open("student_data.json");
    if(myFile.is_open()){
        myFile >> data;
        myFile.close();
      }else{
        cout<<"ERROR! in opening file "<<endl;
        }
        return data;
  }

void ConvertJson( Student s[], int size, json j){
  for( int i=0; i< size; i++){
    s[i].name = j[i]["name"];
     // cout<< s[i].name << endl;
    s[i].rollNo = j[i]["roll_no"];
    //cout<< s[i].rollNo << endl;
    s[i].quiz[0] = j[i]["quizzes"]["quiz1"];
    //cout<< s[i].quiz[0] << endl;
    s[i].quiz[1] = j[i]["quizzes"]["quiz2"];
    //cout<< s[i].quiz[1] << endl;
    s[i].quiz[2] = j[i]["quizzes"]["quiz3"];
    //cout<< s[i].quiz[2] << endl;
    s[i].assignments[0] = j[i]["assignments"]["assignment1"];
    //cout<< s[i].assignments[0] << endl;
    s[i].assignments[1] = j[i]["assignments"]["assignment2"];
    //cout<< s[i].assignments[1] << endl;
    s[i].assignments[2] = j[i]["assignments"]["assignment3"];
    //cout<< s[i].assignments[2] << endl;
    }
  }

void AverageMarksInAssignment3(Student s[], int size) {
  cout<<"\n\t\t==================task 1====================="<<endl;
  int sum = 0;
  float average ;
  for(int i = 0; i < size; i++) {
    sum += s[i].assignments[2];
  }
  average = sum / size;
  cout<<"\n\t\tThe Average Marks in Assignment is: " << average << endl;
}

void HighestMarksInQuiz2(Student s[], int size) {
  cout<<"\n\t\t==================task 2====================="<<endl;
  int rollNo;
  int StudentWithHighestMarks = s[0].quiz[1];
  for(int i = 0; i < size; i++) {
    if(s[i].quiz[1] > StudentWithHighestMarks) {
     StudentWithHighestMarks = s[i].quiz[1];
      rollNo = i;
    }
  }
  cout<<"\n\t\tHighest marks of the student is: "<<StudentWithHighestMarks<<endl;
  cout<<"\n\t\tName of the student is: "<<s[rollNo].name<<endl;
  cout<<"\n\t\tRoll no of the student is: "<<s[rollNo].rollNo<<endl;
}

void StudentsCount(Student s[], int size) {
  cout<<"\n\t\t==================task 3====================="<<endl;
  int StudentCount = 0;
  for(int i = 0; i < size; i++) {
    if(s[i].assignments[1] > 80) {
      StudentCount++;
    }
  }
  cout<<"\n\t\tThe total students who scored more than 80 marks in assignment1 are: "<<StudentCount<<endl;
}

void AvgMarksOfStudent(Student s[], int size) {
  cout<<"\n\t\t==================task 4====================="<<endl;
  string rollno;
  int sum=0;
  float AverageMarks;
  cout<<"\n\tPlease Enter the roll number of the student whose quizzes marks u want to know : ";
  cin>>rollno;
  for(int k = 0; k < size; k++) {
    if(rollno == s[k].rollNo) {
      sum = s[k].quiz[0] + s[k].quiz[1] + s[k].quiz[2] ;
    }
  }
  AverageMarks = sum/3;
  cout<<"\n\t\tThe student with roll no: "<<rollno<<" got average marks in all his quizzes are : "<<AverageMarks<<endl;
}

void DisplayTopperData(Student s[], int size) {
  cout<<"\n\t\t==================task 5====================="<<endl;
  int quiz1_marks =20;
  for(int t = 0; t < size; t++) {
    if(s[t].quiz[0] == quiz1_marks) {
      cout<<"\n\t\tThe student who obtained full marks in quiz 1 are : ";
      cout<<"\n\t\tName: "<<s[t].name<<endl;
      cout<<"\t\tRoll no: "<<s[t].rollNo<<endl;
    }
  }
}

void MarksOfEachStudent(Student s[], int size) {
  cout<<"\n\t\t==================task 6====================="<<endl;
  int TotalQuizMarks =0;
  int TotalAssignmentsMarks =0;
  for(int n = 0; n < size; n++) {
    TotalQuizMarks = s[n].quiz[0] + s[n].quiz[1] + s[n].quiz[2];
    cout<<"\n\t\tThe total quizzes marks for student "<<s[n].name<<" with roll_no "<<s[n].rollNo;
    cout<<" are : "<<TotalQuizMarks<<endl;
    TotalAssignmentsMarks = s[n].assignments[0]+s[n].assignments[1]+s[n].assignments[2];
    cout<<"\n\t\tHis Assignments marks are : "<<TotalAssignmentsMarks<<endl;
  }
}

void AverageMarksForEachQuiz(Student s[], int size) {
  cout<<"\n\t\t==================task 7====================="<<endl;
  int AverageMarks=0;
  int sum = 0 ;
  for(int a = 0; a < 3; a++) {
    for(int b = 0; b < size; b++) {
      sum += s[b].quiz[a] ;
    } AverageMarks = sum/100;
    cout<<"\n\t\tThe Average marks quiz "<<a+1<<" accross all students is: "<<AverageMarks<<endl;
    cout<<"\n\t\t============================================"<<endl;
  }
}