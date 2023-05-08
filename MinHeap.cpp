#include "MinHeap.h"

vector<Student> MinHeap:: ReadFromFile(string filename ){
    
        fstream datafile;
        string line;
        vector<Student> vec;
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
                vec.push_back(s);
            }

            counter++;
            getline(datafile, line);
        }

        datafile.close();
        return vec;
    }

MinHeap::MinHeap(){
    this->studentsVec = ReadFromFile("students.txt");
}

void MinHeap::Add( Student s){

    studentsVec.push_back(s);

    int index = studentsVec.size() - 1;
    
    while(index > 0     &&    studentsVec[index].getGPA()  <  studentsVec[( index / 2 ) - 1].getGPA()) {
        
        swap(studentsVec[(index / 2) - 1], studentsVec[index]);
        index = (index / 2) - 1 ;
    }

    cout<<"The Student is added"<<'\n';
}


void MinHeap::heapify(vector<Student>& vec, int n, int i){
    
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


vector<Student>& MinHeap::Sort(vector<Student>& stVec){
    
    int n = stVec.size();
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(stVec, n, i);
    }
    
    for(int i = n - 1; i >= 0; i--){
        swap(stVec[0], stVec[i]);
        heapify(stVec, i, 0);
    }
    
    return stVec;
}


void MinHeap::print(){
    for(int i = 0; i < studentsVec.size(); i++){
        cout<<studentsVec[i].getID()<<" "<<studentsVec[i].getName()<<" "<<studentsVec[i].getGPA()<<" "<<studentsVec[i].getDepartment()<<'\n';
    }
}

