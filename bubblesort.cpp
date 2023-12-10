#include<iostream>
using namespace std;

struct Student
{
    int roll;
    string name;
    double cgpa;
};



int findStudent(Student arr[],int l,int u,string name){
    // int mid = (l + u) /2;
    while(l<=u){
        int mid = l + (u - l) / 2;

        if(arr[mid].name == name){
            return mid;
        }else if(arr[mid].name > name){
            u = mid-1;
        }else{
            l = mid + 1;
        }
    }
    return -1;
}

void rollcall(Student arr[],int size){
    bool isSwaap = false;
    for(int i=0;i<size;i++){
        for(int j = 0;j<size - i -1;j++){
            if(arr[j].roll > arr[j+1].roll){
                Student s = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = s;
                isSwaap = true;
            }
            if(!isSwaap){
                break;
            }
        }
    }
}
int main(){
    Student data[5] = {
        {10,"arohan",8.999},
        {11,"brohan",7.999},
        {12,"crohan",6.999},
        {13,"drohan",8.999},
        {14,"erohan",8.999}
    } ;
    cout << findStudent(data,0,4,"arohan");
    rollcall(data,5);
    for(int i = 0;i<5;i++){
        cout << data[i].roll<< " ";
    }
    return 0;
}