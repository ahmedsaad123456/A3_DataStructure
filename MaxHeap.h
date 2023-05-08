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

    void heapify(vector<Student>& studentsVec, int n, int i);

    vector<Student>& Sort(vector<Student>& studentsVec);

    void print();
        
        
};
