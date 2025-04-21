#include <iostream>
#include <string>
using namespace std;

class Student{
public:
// student attributes (represent a blue print)
  int id;
  string major;
  int listEnrolledCourses;
  int academicYear;

// student methods (represent the behaviour)
  void schedule (){
    cout << "id : " << id << endl;
    cout << "major:  " << major<< endl;
    cout << "listEnrolledCourses : " << listEnrolledCourses << endl;
    cout << "academicYear: " << academicYear << endl;
     
  }
};

class student{
public:
// student attributes (represent a blue print)
  int id; ;
  string major;
  int listEnrolledCourses;
  int academicYear;
  

// student (represent the behaviour)
  void schedule (){
    cout << "id: " << id<< endl;
    cout << "major:  " << major << endl;
    cout << "listEnrolledCourses:  " << listEnrolledCourses << endl;
    cout << "academicYear: " <<academicYear << endl;
     
  }
};

// create a student object for class Student
int main () {
   Student student1;
   student1.id = 40154392;
   student1.major = "BSCIT";
   student1.listEnrolledCourses = 300;
   student1.academicYear = 2025;
   student1.schedule();   
  cout<< endl<< endl;
  
  Student student2;
  student2.id = 401102443;
  student2.major = "DIPMAN";
  student2.listEnrolledCourses = 100;
  student2.academicYear = 2025;
  student2.schedule();   
 cout<< endl<< endl;



student student1;
 student1.id = 40154392;
 student1.major = "BSCIT";
 student1.listEnrolledCourses = 300;
 student1.academicYear = 2025;
 student1.schedule();   
cout<< endl<< endl;

student student2;
student2.id = 401102443;
student2.major = "DIPMAN";
student2.listEnrolledCourses = 100; 
student2.academicYear = 2025;
student2.schedule();   
cout<< endl<< endl;

    return 0;
}
