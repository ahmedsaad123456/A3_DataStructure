#ifndef STUDENTS_CPP
#define STUDENTS_CPP
#include "Students.cpp"
#endif



struct node{
    Student student;
    node* left;
    node* right;
    int height;

    node(Student student){
        this->student = student;
        left = NULL;
        right = NULL;
        height = 1;
    }
};




class AVL{


    node* root;
    int size=0;
    void ReadFromFile(string filename );


    node* insert(Student s , node* current);
    node* leftRotate(node*);
    node* rightRotate(node*);
    int getHeight(node* n);
    node* erase(int id , node* current);
    node* getSuccessor(node* n);
    int get_balance_factor(node* n);



    public:

    AVL(){root=NULL; this->ReadFromFile("students.txt");};

    void insert(Student s);

    node* getRoot(){return root;};

    void inorder(node* root);

    bool search(int id) ;

    void erase(int id);


};




