#include "MinHeap.h"


MinHeap::MinHeap(){
    this->studentsVec = ReadFromFile("students.txt");
}

//-------------------------------------------------------------------------------------------------------------------

vector<Student> MinHeap::ReadFromFile(string filename){
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
