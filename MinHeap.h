#ifndef STUDENTS_CPP
#define STUDENTS_CPP
#include "Students.cpp"
#include<vector>
#endif

class MinHeap {

    void ReadFromFile(string filename );
    vector<Student> studentsVec;
    
public:

    MinHeap();

    void Add( Student s);

    void heapify( int n, int i);

    void Sort();

    void print();
        
        
};
