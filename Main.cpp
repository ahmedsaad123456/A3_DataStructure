#include "MinHeap.cpp"
#include "MaxHeap.cpp"
#include "BST.cpp"
#include "AVL.cpp"


int main(){
    int id;
    double gpa;
    string name ,dep;
    int chosen =0;
    // MinHeap minH; create object of MinHeap
    // MaxHeap maxH;  create object of MaxHeap
    // BST b;   create object of BST
    // AVL avl; create object of AVL

    while(chosen!=5){
        
        cout<<"Choose Data Structure"<<endl;
        cout<<"1. BST"<<endl;
        cout<<"2. AVL "<<endl;
        cout<<"3. Min Heap"<<endl;
        cout<<"4. Max Heap"<<endl;
        cout<<"5. Exit Program"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"Enter number of option : "<<endl;
        cin>>chosen;

        if(chosen==1){
            int BSTchosen =0;
            while(BSTchosen!=5){
                cout<<"Choose one of the following options"<<endl;
                cout<<"1. Add student"<<endl;
                cout<<"2. Remove student "<<endl;
                cout<<"3. search student"<<endl;
                cout<<"4. print All (sorted by id)"<<endl;
                cout<<"5. return to main menu"<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Enter number of option : "<<endl;
            
                cin>>BSTchosen;

                if(BSTchosen==1){
                    cout<<"id : "<<endl;
                    cin>>id;
                    cin.ignore();
                    cout<<"Name : "<<endl;
                    getline(cin, name);
                    cout<<"GPA : "<<endl;
                    cin>>gpa;
                    cout<<"Department : "<<endl;
                    cin>>dep;
                    // b.insert(Student(id , gpa , name , dep));
                    cout<<"The student is added"<<endl;
                    cout<<"--------------------------------------"<<endl;

                }
                else if(BSTchosen==2){
                    // remove student
                }
                else if(BSTchosen==3){
                    // search student
                }
                else if (BSTchosen==4){
                    // print all
                }
                else if (BSTchosen!=5){
                    cout<<"please enter valid number from menu"<<endl;

                }

            }
        }
        else if(chosen==2){
            int AVLchosen =0;
            while(AVLchosen!=5){
                cout<<"Choose one of the following options"<<endl;
                cout<<"1. Add student"<<endl;
                cout<<"2. Remove student "<<endl;
                cout<<"3. search student"<<endl;
                cout<<"4. print All (sorted by id)"<<endl;
                cout<<"5. return to main menu"<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Enter number of option : "<<endl;
                cin>>AVLchosen;

                if(AVLchosen==1){
                    cout<<"id : "<<endl;
                    cin>>id;
                    cin.ignore();
                    cout<<"Name : "<<endl;
                    getline(cin, name);
                    cout<<"GPA : "<<endl;
                    cin>>gpa;
                    cout<<"Department : "<<endl;
                    cin>>dep;
                    // avl.insert(Student(id , gpa , name , dep)); 
                    cout<<"The student is added"<<endl;
                    cout<<"--------------------------------------"<<endl;

                }
                else if(AVLchosen==2){
                    // remove student
                }
                else if(AVLchosen==3){
                    // search student
                }
                else if (AVLchosen==4){
                    // print all
                }
                else if (AVLchosen!=5){
                    cout<<"please enter valid number from menu"<<endl;

                }

            }
            
        }
        else if(chosen==3){
            int MinHeapChosen=0;
            while(MinHeapChosen!=3){
                cout<<"Choose one of the following options"<<endl;
                cout<<"1. Add student"<<endl;
                cout<<"2. print All (sorted by gpa)"<<endl;
                cout<<"3. return to main menu"<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Enter number of option : "<<endl;
                cin>>MinHeapChosen;

                if(MinHeapChosen==1){
                    cout<<"id : "<<endl;
                    cin>>id;
                    cin.ignore();
                    cout<<"Name : "<<endl;
                    getline(cin, name);
                    cout<<"GPA : "<<endl;
                    cin>>gpa;
                    cout<<"Department : "<<endl;
                    cin>>dep;
                    // minH.insert(Student(id , gpa, name ,dep));
                    cout<<"The student is added"<<endl;
                    cout<<"--------------------------------------"<<endl;

                }

                else if (MinHeapChosen==2){
                    // minH.print();
                    cout<<"--------------------------------------"<<endl;

                }
                else if (MinHeapChosen!=3){
                    cout<<"please enter valid number from menu"<<endl;
                    cout<<"--------------------------------------"<<endl;

                }
            }

        }
        else if (chosen==4){
            int MaxHeapChosen=0;
            while(MaxHeapChosen!=3){
                cout<<"Choose one of the following options"<<endl;
                cout<<"1. Add student"<<endl;
                cout<<"2. print All (sorted by gpa)"<<endl;
                cout<<"3. return to main menu"<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Enter number of option : "<<endl;
                cin>>MaxHeapChosen;
                

                if(MaxHeapChosen==1){
                    cout<<"id : "<<endl;
                    cin>>id;
                    cin.ignore();
                    cout<<"Name : "<<endl;
                    getline(cin, name);
                    cout<<"GPA : "<<endl;
                    cin>>gpa;
                    cout<<"Department : "<<endl;
                    cin>>dep;
                    // maxH.insert(Student(id , gpa, name ,dep));
                    cout<<"The student is added"<<endl;
                    cout<<"--------------------------------------"<<endl;
                }

                else if (MaxHeapChosen==2){
                    // maxH.print();
                    cout<<"--------------------------------------"<<endl;

                }
                else if (MaxHeapChosen!=3){
                    cout<<"please enter valid number from menu"<<endl;
                    cout<<"--------------------------------------"<<endl;

                }
            }

        }
        else if (chosen!=5){
            cout<<"please enter valid number from menu"<<endl;
        }
    }




   

}