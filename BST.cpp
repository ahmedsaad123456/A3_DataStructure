#include "BST.h"


BST::BST(){
    this->root = NULL;
    size = 0;
    this->ReadFromFile("students.txt");
}

Node* BST::getRoot() {
    return root;
}

void BST::ReadFromFile(string filename){
    fstream datafile;
    string line;
    int counter = 1;
    Student s;
    datafile.open(filename, ios::in |ios::out);
    if (!datafile) {
       cout << "Can't open file " << filename << endl;
        return;
    }
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
            addStudent(s);
        }
        counter++;
        getline(datafile, line);
    }

    datafile.close();

}


Node* BST::insertNode(Node* curr, Student student) {
    if (curr == nullptr) {
        curr = new Node(student);
    }
    else if (student.getID() < curr->student.getID()) {
        curr->left = insertNode(curr->left, student);
    }
    else if (student.getID() > curr->student.getID()) {
        curr->right = insertNode(curr->right, student);
    }
    return curr;
}

void BST::addStudent(Student student) {
     root = insertNode(root, student);
     size++;
}

Node* BST::minNode(Node* curr) {
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* BST::deleteNode(Node* curr, int id){
    if(curr == NULL){
        cout << "Not found\n";
        return curr;
    }
    if(id < curr->student.getID()){
        curr->left = deleteNode(curr->left, id);
    }
    else if(id > curr->student.getID()){
        curr->right = deleteNode(curr->right, id);
    }
    else{
        if(curr->left == NULL && curr->right == NULL){ //if no child
            delete curr;
            curr = NULL;
        }
        else if(curr->left == NULL){ //if one child in right
            Node* temp = curr;
            curr  = curr->right;
            delete temp;
        }
        else if(curr->right == NULL){ //if one child in left
            Node* temp = curr;
            curr  = curr->left;
            delete temp;
        }
        else{ //if two child
            Node* temp = minNode(curr); //find the successor of this node
            curr->student = temp->student;
            curr->right = deleteNode(curr->right, temp->student.getID());
        }
    }
    return curr;
}

void BST::removeStudent(int id){
    root = deleteNode(root, id);
    size--;
}

bool BST::searchStudent(int id) {
    Node* current = root;
    while (current != nullptr) {
        if (current->student.getID() == id) {
            cout<<"student is found"<<endl;
            current->student.print();
            return true;
        }
        else if (id < current->student.getID()) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
    return false;
}

void BST::printAll(Node* root) {
    static int n = 0, DS = 0, CS = 0, IS = 0, IT = 0;
    if (n == 0) {
        cout << "--------------------------------------" << endl;
        cout << "print " << size << " students" << endl;
        n = 1;
    }

    if (root != NULL) {
        printAll(root->left);
        root->student.print();
        n++;
        if (root->student.getDepartment() == "CS")
            CS++;
        else if (root->student.getDepartment() == "IS")
            IS++;
        else if (root->student.getDepartment() == "DS")
            DS++;
        else if (root->student.getDepartment() == "IT")
            IT++;
        printAll(root->right);
    }

    if (size == n - 1) {
        cout << "--------------------------------------" << endl;
        cout << "Students per department" << endl;
        cout << "CS " << CS << " students" << endl;
        cout << "IT " << IT << " students" << endl;
        cout << "DS " << DS << " students" << endl;
        cout << "IS " << IS << " students" << endl;
        cout << "--------------------------------------" << endl;

        n = 0;
        CS = 0;
        IS = 0;
        DS = 0;
        IT = 0;
    }
}

