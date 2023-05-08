#ifndef STUDENTS_CPP
#define STUDENTS_CPP
#include "Students.cpp"
#include<vector>
#endif

class MinHeap {

    vector<Student> ReadFromFile(string filename );
    vector<Student> studentsVec;
    
public:

    MinHeap();

    void Add( Student s){

        studentsVec.push_back(s);
 
        int index = studentsVec.size() - 1;
        
        while(index > 0     &&    studentsVec[index].getGPA()  <  studentsVec[( index / 2 ) - 1].getGPA()) {
            
            swap(studentsVec[(index / 2) - 1], studentsVec[index]);
            index = (index / 2) - 1 ;
        }

        cout<<"The Student is added"<<'\n';
    }
    void heapify(vector<Student>& vec, int n, int i){
        
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if(l < n && studentsVec[l].getGPA() < studentsVec[largest].getGPA()){
            largest = l;
        }
        
        if(r < n && studentsVec[r].getGPA() < studentsVec[largest].getGPA()){
            largest = r;
        }
        
        if(largest != i){
            swap(vec[i], vec[largest]);
            heapify(vec, n, largest);
        }
    }


    vector<Student>& Sort(vector<Student>& stVec){
    
        int n = stVec.size();
        for(int i = n / 2 - 1; i >= 0; i--){
            heapify(stVec, n, i);
        }
        
        for(int i = n - 1; i >= 0; i--){
            swap(stVec[0], stVec[i]);
            heapify(stVec, i, 0);
        }
        
        return studentsVec;
    }


    void print(){
        
        studentsVec = Sort(studentsVec);
        
        for(int i = 0; i < studentsVec.size(); i++){
            studentsVec[i].print();
        }
    }
        
        


};
