#include "MaxHeap.h"


void MaxHeap:: ReadFromFile(string filename ){
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

//--------------------------------------------------------------------------

MaxHeap::MaxHeap(){
    this->ReadFromFile("students.txt");
}

//--------------------------------------------------------------------------

void MaxHeap:: Add( Student s){
    while(checkRepeatedID(s.getID())){
        cout<<"Student with ID: "<<s.getID()<<" already exists"<<endl;
        int id;
        cout<<"Enter new ID: ";
        cin>>id;
        s.setID(id);
        checkRepeatedID(s.getID());
    }
    

    studentsVec.push_back(s);

    int index = studentsVec.size() - 1;
    
    while(index > 0     &&    studentsVec[index].getGPA()  >  studentsVec[( index - 1 ) / 2 ].getGPA()) {
        
        swap(studentsVec[( index - 1 ) / 2], studentsVec[index]);
        index = ( index - 1 ) / 2;
    }
    

}

//--------------------------------------------------------------------------

void MaxHeap :: heapify( int n, int i){
     
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
            heapify(n, largest);
        }

}

//--------------------------------------------------------------------------

void MaxHeap::Sort(){

    int n = studentsVec.size();
    for(int i =(n - 1) / 2; i >= 0; i--){
        heapify(n, i);
    }
    
    for(int i = n - 1; i >= 0; i--){
        swap(studentsVec[0], studentsVec[i]);
        heapify(i, 0);
    }
    
}

//--------------------------------------------------------------------------

void MaxHeap:: print(){
    cout<<endl;
    cout<<"Print "+to_string(studentsVec.size())+" students"<<'\n'<<endl;
    Sort();
    
    for(int i = studentsVec.size() -1 ; i >= 0 ; i--){
        studentsVec[i].print();
    }
    cout<<endl;
}

//--------------------------------------------------------------------------

void MaxHeap:: departmentReport(){
   static int DS = 0, CS = 0, IS = 0, IT = 0;
    
   for(int i=studentsVec.size() -1;i>=0 ;i--){
        if(studentsVec[i].getDepartment() == "CS")
            CS++;
        
        else if(studentsVec[i].getDepartment() == "IS")
            IS++;
        
        else if(studentsVec[i].getDepartment() == "DS")
            DS++;
        
        else if(studentsVec[i].getDepartment() == "IT")
            IT++;

   }


   cout << "--------------------------------------" << endl;
        cout << "Students per department:" << endl<<endl;
        cout << "CS " << CS << " students" << endl;
        cout << "IT " << IT << " students" << endl;
        cout << "DS " << DS << " students" << endl;
        cout << "IS " << IS << " students" << endl<<endl;
   
}

//--------------------------------------------------------------------------

bool MaxHeap:: checkRepeatedID(int id){
    for(int i = 0; i < studentsVec.size(); i++){
        if(studentsVec[i].getID() == id)
            return true;
    }
    return false;
}
