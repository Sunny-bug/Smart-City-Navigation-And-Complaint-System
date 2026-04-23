#include<iostream>
using namespace std;

class student{
public:
    student* next;
    string name;
public:
    student(string s){
        name = s;
        next = nullptr;
    }
};
int main(){
    /*
    student* s1 = new student("Alice");
    student* s2 = new student("sunny");
    
    student* head = s1;
    s1 -> next = s2;*/
    student *head,*lastnodptr;
    head = new student("Alice");
    head ->next = NULL;
    lastnodptr = head;
    int n;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    for(int i = 0;i<n;i++){
        string name;
        cout<<"Enter name"<<endl;
        cin>>name;
        student* s1 = new student(name);
        lastnodptr -> next = s1;
        lastnodptr = s1;
        
    }
    
    cout<<endl;
    student * tem = head;
    while(tem!= NULL){
        cout<<tem -> name<<endl;
        tem = tem ->next;
    }
    return 0;
}