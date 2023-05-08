#include "MaxHeap.h"


vector<Student> MaxHeap:: ReadFromFile(string filename ){
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

//--------------------------------------------------------------------------

MaxHeap::MaxHeap(){
    this->studentsVec = ReadFromFile("students.txt");
}

//--------------------------------------------------------------------------

void MaxHeap:: Add( Student s){

    studentsVec.push_back(s);

    int index = studentsVec.size() - 1;
    
    while(index > 0     &&    studentsVec[index].getGPA()  >  studentsVec[( index - 1 ) / 2 ].getGPA()) {
        
        swap(studentsVec[( index - 1 ) / 2], studentsVec[index]);
        index = ( index - 1 ) / 2;
    }

    cout<<"The Student is added"<<'\n';
}

//--------------------------------------------------------------------------

void MaxHeap :: heapify(vector<Student>& studentsVec, int n, int i){
     
     int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if(l < n && studentsVec[l].getGPA() > studentsVec[largest].getGPA()){
            largest = l;
        }
        
        if(r < n && studentsVec[r].getGPA() > studentsVec[largest].getGPA()){
            largest = r;
        }
        
        if(largest != i){
            swap(studentsVec[i], studentsVec[largest]);
            heapify(studentsVec, n, largest);
        }

}

//--------------------------------------------------------------------------

vector<Student>& MaxHeap::Sort(vector<Student>& studentsVec){

    int n = studentsVec.size();
    for(int i =(n - 1) / 2; i >= 0; i--){
        heapify(studentsVec, n, i);
    }
    
    for(int i = n - 1; i >= 0; i--){
        swap(studentsVec[0], studentsVec[i]);
        heapify(studentsVec, i, 0);
    }
    
    return studentsVec;
}

//--------------------------------------------------------------------------

void MaxHeap:: print(){
    cout<<"Print "+to_string(studentsVec.size())+" students"<<'\n';
    studentsVec = Sort(studentsVec);
    
    for(int i = studentsVec.size() -1 ; i >= 0 ; i--){
        studentsVec[i].print();
    }
}
