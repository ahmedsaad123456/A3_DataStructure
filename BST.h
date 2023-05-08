#ifndef STUDENTS_CPP
#define STUDENTS_CPP
#include "Students.cpp"
#endif

struct Node{
    Student student;
    Node* left;
    Node* right;
    Node(Student student){
        this->student = student;
        this->left =NULL;
        this->right = NULL;
    }
};

class BST{
    Node* root;
    int size;
    void ReadFromFile(string filename);
    Node* insertNode(Node*, Student);
    Node* deleteNode(Node*, int);
    Node* minNode(Node*);

public:
    BST();
    Node* getRoot();
    void addStudent(Student);
    void removeStudent(int);
    bool searchStudent(int);
    void printAll(Node*);

};




