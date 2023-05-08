#ifndef STUDENTS_CPP
#define STUDENTS_CPP
#include "Students.cpp"
#include<vector>
#endif

class MaxHeap {

    vector<Student> ReadFromFile(string filename );
    vector<Student> studentsVec;
    
public:

    MaxHeap();

    void Add( Student s);

    void heapify(vector<Student>& vec, int n, int i);

    vector<Student>& Sort(vector<Student>& stVec);

    void print();
        
        
};
