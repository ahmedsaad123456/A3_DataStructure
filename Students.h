#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Student {

    int id;
    double GPA;
    string department;
    string name;

    public:

    Student();

    Student(int i, double g, string d, string n);

    void setID(int i);

    void setName(string n);

    void setGPA(double g);

    void setDepartment(string d);

    int getID() ;

    double getGPA();

    string getName() ;

    string getDepartment() ;

    void print();


};