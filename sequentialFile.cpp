#include<iostream>
#include<fstream>
#include<string>
using namespace std;


void addStuden(){
    fstream myfile;
    myfile.open("myfile.txt",ios::app);
    if(myfile.is_open()){
        string name,roll,grade;
        cout << "Enter Name :";
        cin >> name;
        cout << "Enter roll: ";
        cin >> roll;
        cout << "Enter Greade : ";
        cin >> grade;
        myfile << name << "," << roll <<  "," << grade <<"\n";
        myfile.close();
    }
}

void deletStudent(){
    fstream myfile;
    myfile.open("myfile.txt",ios::in);
    string text = "";
    if(myfile.is_open()){
        string name,roll,grade;
        string d;
        cout << "Enter roll no to delete : ";
        cin >> d;
        while(getline(myfile,name,',') && getline(myfile,roll,',') && getline(myfile,grade,'\n')){
            if(roll != d){
                string l = name + "," + roll + "," + grade+ "\n";
                text += l;
            }
        }
        myfile.close();
    }
    myfile.open("myfile.txt",ios::out);
    if(myfile.is_open()){
        myfile << text;
    }
    myfile.close();
}

void searchStudent(){
    fstream myfile;
     myfile.open("myfile.txt",ios::in);
    if(myfile.is_open()){
        string name,roll,grade;
        string s;
        cout << "Enter roll no to search ";
        cin >> s;

        while(getline(myfile,name,',') && getline(myfile,roll,',') && getline(myfile,grade,'\n')){
            if(roll == s)
                cout << name << " " << roll << " " << grade ;
        }
        myfile.close();
    }
}

int main(){
    //add
    
    //search
   
    addStuden();
    addStuden();
    addStuden();
    searchStudent();
    deletStudent();
   

    
    return 0;
}