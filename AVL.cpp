#include "AVL.h"



void AVL::insert(Student s){
    size++;
    root = insert(s , root);
}

int AVL::getHeight(node * n){
    if(n==NULL) return 0;
    else return n->height;
    
}

int AVL::get_balance_factor(node * n){
    if(n==NULL) return 0;
    return getHeight(n->left) - getHeight(n->right);
}


node* AVL::leftRotate(node * n){
    node * newRight = n->right;
    n->right = newRight->left;
    newRight->left = n;

    n->height = max(getHeight(n->left) , getHeight(n->right))+1;
    newRight->height = max(getHeight(newRight->left) , getHeight(newRight->right))+1;


    return newRight;
    
}


node* AVL::rightRotate(node * n){

    node* newLeft = n->left;
    n->left = newLeft->right;
    newLeft->right = n;

    n->height = max(getHeight(n->left) , getHeight(n->right))+1;
    newLeft->height = max(getHeight(newLeft->left) , getHeight(newLeft->right))+1;


    return newLeft;

}


node* AVL::insert(Student s, node *current){
    if(current==NULL){
        return new node(s);
    }

    // get the correct position of the inserted node 
    
    if(s.getID()< current->student.getID()){
        current->left = insert(s, current->left);
    }
    else{
        current->right = insert(s, current->right);
    }
    
    // update the height
    current->height = max(getHeight(current->left) , getHeight(current->right))+1;

    int balance = get_balance_factor(current);

    // left left 
    // the second condition is to ensure that the new node is in left left of the current node
    if(balance>1 && s.getID() < current->left->student.getID()){
        return rightRotate(current);
    }

    // right right
    // the second condition is to ensure that the new node is in right right of the current node
    if(balance < -1 && s.getID() > current->right->student.getID()){
        return leftRotate(current);
    }

    // left right
    // the second condition is to ensure that the new node is in left right of the current node
    if(balance > 1 && s.getID() > current->left->student.getID()){
        current->left = leftRotate(current->left); // left rotation in the left of the current node
        return rightRotate(current); // then right rotation in the current node
    }

    // right left
    // the second condition is to ensure that the new node is in right left of the current node
    if(balance <-1 && s.getID() < current->right->student.getID()){
        current->right = rightRotate(current->right);   // right rotation in the right of the current node
        return leftRotate(current);      // then left rotation in the current node
    }


    return current;
    


}

void AVL::erase(int id){
    
    if(size==1){
        delete root;
        root = NULL;
        size--;
        return;
    }
    root = erase(id , root);
    size--;


}

// get minimum 
node* AVL::getSuccessor(node* n){
    node *cur = n;
    while (cur->left != NULL) {
        cur = cur->left;
    }
    return cur;
}


node* AVL::erase(int id , node* current){
    if(current==NULL){
        return current;
    }
    if(id <current->student.getID()){
        current->left = erase(id , current->left);
    }
    else if(id > current->student.getID()){
        current->right = erase(id , current->right);
    }
    else{
        // node has child in right or has no child
        if(current->left==NULL){
            node* temp = current;
            current  = current->right;
            delete temp;
        }

        // node has child in left or has no child
        else if (current->right==NULL){
            node* temp = current;
            current = current->left;
            delete temp;
        }
        // node has two child
        else{
            // get the minimum node of the right subtree 
            node* temp  = getSuccessor(current->right);
            // put it in the current node 
            current->student = temp->student;
            // delete the temp node
            current->right = erase(temp->student.getID() , current->right);
        }
        if(current==NULL ){
            return NULL;
        }
    }
    // update height
    current->height =  max(getHeight(current->left), getHeight(current->right)) +1;
    int balance = get_balance_factor(current);
    // the first condition that is to ensure that the tree is unbalanced 
    // left left
    if (balance > 1 && get_balance_factor(current->left) >= 0) {
        return rightRotate(current);
    }
    // the first condition that is to ensure that the tree is unbalanced 
    // left right
    if (balance > 1 && get_balance_factor(current->left) < 0) {
        current->left = leftRotate(current->left);
        return rightRotate(current);
    }
    // the first condition that is to ensure that the tree is unbalanced 
    // the second condition that is to ensure that the right subtree of the right child node has height greater than the left subtree of the right child node
    // that mean we will apply the left rotation in the current node 
    // right right
    if (balance < -1 && get_balance_factor(current->right) <= 0) {
        return leftRotate(current);
    }
    // the first condition that is to ensure that the tree is unbalanced
    // right left 

    if (balance < -1 && get_balance_factor(current->right) > 0) {
        current->right = rightRotate(current->right);
        return leftRotate(current);
    }


    return current;
    
}

    

bool AVL::search(int id) {
    node * current = root;
    while (current != NULL) {
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




void AVL::inorder(node* root){
    static int n=0 , DS=0 , CS=0 , IS=0 , IT=0;
   

    if(n==0){
        cout<<"--------------------------------------"<<endl;
        cout<<"print "<<size<<" students"<<endl;
        n=1;
    }
    
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    root->student.print();
    n++;
    if(root->student.getDepartment()=="CS")
    CS++;
    else if(root->student.getDepartment()=="IS")
    IS++;
    else if(root->student.getDepartment()=="DS")
    DS++;
    else if(root->student.getDepartment()=="IT")
    IT++;
    inorder(root->right);

    if(size==(n-1)){
        cout<<"--------------------------------------"<<endl;
        cout<<"Students per department"<<endl;
        cout<<"CS "<<CS<<" students"<<endl;
        cout<<"IT "<<IT<<" students"<<endl;
        cout<<"DS "<<DS<<" students"<<endl;
        cout<<"IS "<<IS<<" students"<<endl;
        cout<<"--------------------------------------"<<endl;


        n=0;
        CS=0;
        IS=0;
        DS=0;
        IT=0;

    }


}


void AVL::ReadFromFile(string filename){
    fstream datafile;
    string line;
    int counter =1;
    Student s;
    datafile.open(filename, ios::in |ios::out);
    getline(datafile, line);
    getline(datafile, line);
    while (!datafile.eof()) {
        if(counter ==1)
            s.setID(stoi(line));
        else if (counter == 2 )
            s.setName(line);
        else if (counter == 3)
            s.setGPA( stod(line));
        else {
            s.setDepartment(line);
            counter=0;
            insert(s);  //use insert function to insert student to tree 
        }

        
        counter++;
        getline(datafile, line);
    }

    datafile.close();

}



