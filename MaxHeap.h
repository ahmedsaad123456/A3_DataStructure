#ifndef STUDENTS_CPP
#define STUDENTS_CPP
#include "Students.cpp"
#include<vector>
#endif

class MaxHeap {

    void ReadFromFile(string filename );
    vector<Student> studentsVec;
    
public:

    MaxHeap();

    void Add( Student s);

    void heapify( int n, int i);

    void Sort();

    void print();

    void departmentReport();

    bool checkRepeatedID(int id);
        
        
};
