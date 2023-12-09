#include<iostream>
#include<string.h>
using namespace std;

int const size = 3;

struct student{
    int rno;
    char name[20];
    float SGPA;
};

void accept(struct student list[size]);
void display(struct student list[80]);
void bubbleSort(struct student list[size]);
void insertionSort(struct student list[size]);
void search(struct student list[size]);

int main(){
    int ch,i;
    struct student data[20];
    accept(data);

    cout<<"\n 1: Bubble Sort";
    cout<<"\n 2: Insertion Sort";
    cout<<"\n 3: Search";
    // cout<<"\n 4: Exit";
    cout<<"\n Select your Choice";
    cin>>ch;

    switch (ch)
    {
    case 1: 
        bubbleSort(data);
        display(data); 
        break;

    case 2: 
        insertionSort(data);
        display(data);
        break;
    
    case 3:
        search(data);
        break;

    default:  
        cout<<"Invalid Choice";
        break;
    };
};

void bubbleSort(struct student list[size]){
    int i, j;
    struct student temp;
    for(i = 0;i<size-1;i++){
        for(j= 0;j<size-i-1;j++){
            if(list[j].rno > list[j+1].rno){
                temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
            }
        }
    }
} 

void insertionSort(struct student list[size]){
    int k,j;
    struct student temp;

    for(k=1;k<size;k++){
        temp=list[k];
        j=k-1;

        while (strcmp(list[j].name, temp.name)>0 && j>=0)   
        {
            list[j+1] = list[j];
            --j;
        }
        list[j+1]=temp;
    }
}

void accept(struct student list[size]){
    int i;
    for(i=0;i<size;i++){
        cout<<"Enter Roll No, name, SGPA";
        cin>> list[i].rno >>list[i].name >> list[i].SGPA;
    }
}

void display(struct student list[80]){
    int i;
    cout<<"\n Rollno \t Name \t SGPA \n";
    for(i = 0;i<=size;i++){
        cout<<"\n"<<list[i].rno <<"\t"<< list[i].name <<"\t"<<list[i].SGPA;
    }
}

void search(struct student list[size]){
    float SGPA;
    int i;
    cout<<"\n Enter SGPA: ";
    cin>>SGPA;

    cout<<"\n RollNo\t Name\t SGPA\n";
    for(i = 0;i<size; i++){
        if(SGPA==list[i].SGPA){
            cout<<"\n"<<list[i].rno <<"\t"<< list[i].name <<"\t"<<list[i].SGPA;
        }
    }
}
