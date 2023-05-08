#include "MinHeap.h"

void MinHeap::ReadFromFile(string filename ){
    
        fstream datafile;
        string line;
        int counter = 1;
        Student s;
        
        datafile.open(filename, ios::in | ios::out);
        getline(datafile, line);
        getline(datafile, line);
        
        while (!datafile.eof()) {
            if(counter == 1)
                s.setID(stoi(line));
            
            else if (counter == 2 )
                s.setName(line);
            
            else if (counter == 3)
                s.setGPA(stod(line));
            
            else {
                s.setDepartment(line);
                counter = 0;
                Add(s);
            }

            counter++;
            getline(datafile, line);
        }

        datafile.close();
}

MinHeap::MinHeap(){
    this->ReadFromFile("students.txt");
}

void MinHeap::Add( Student s){

    studentsVec.push_back(s);

    int index = studentsVec.size() - 1;
    
    while(index > 0     &&    studentsVec[index].getGPA()  <  studentsVec[( index - 1 ) / 2].getGPA()) {
        
        swap(studentsVec[( index - 1 ) / 2], studentsVec[index]);
        index = ( index - 1 ) / 2;
    }

}


void MinHeap::heapify( int n, int i){
    
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
        swap(studentsVec[i], studentsVec[largest]);
        heapify( n, largest);
    }
}


void MinHeap::Sort(){
    
    int n = studentsVec.size();
    for(int i = (n - 1) / 2; i >= 0; i--){
        heapify( n, i);
    }
    
    for(int i = n - 1; i >= 0; i--){
        swap(studentsVec[0], studentsVec[i]);
        heapify( i, 0);
    }
    
}


void MinHeap::print(){
    cout<<"Print "+to_string(studentsVec.size())+" students"<<'\n';
    Sort();
    
    for(int i = studentsVec.size() - 1 ; i >= 0 ; i--){
        studentsVec[i].print();
    }
}
