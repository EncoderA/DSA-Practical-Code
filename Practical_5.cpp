#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

const int MAX = 20;

class Student {
    int rollNo;
    char name[MAX], city[MAX];
    char div;
    int year;

public:
    Student() {
        strcpy(name, "");
        strcpy(city, "");
        rollNo = year = div = 0;
    }

    Student(int rollNo, char name[MAX], int year, char div, char city[MAX]) {
        strcpy(this->name, name);
        strcpy(this->city, city);
        this->rollNo = rollNo;
        this->year = year;
        this->div = div;
    }

    // Add a displayRecord method
    void displayRecord() {
        cout << setw(5) << rollNo << setw(20) << name << setw(5) << div << setw(10) << city << endl;
    }

    // Add a getRollNo method
    int getRollNo() {
        return rollNo;
    }
};

class FileOperation {
    fstream file;

public:
    FileOperation(char* filename) {
        file.open(filename, ios::in | ios::out | ios::ate | ios::binary);
    }

    void insertRecord(int rollNo, char name[MAX], int year, char div, char city[MAX]) {
        Student s1(rollNo, name, year, div, city);
        file.seekp(0, ios::end);
        file.write((char*)&s1, sizeof(Student));
        file.clear();
    }

    void displayAll() {
        Student s1;
        file.seekg(0, ios::beg);
        while (file.read((char*)&s1, sizeof(Student))) {
            s1.displayRecord();
        }
        file.clear();
    }

    void displayRecord(int rollNo) {
        Student s1;
        file.seekg(0, ios::beg);
        bool flag = false;
        while (file.read((char*)&s1, sizeof(Student))) {
            if (s1.getRollNo() == rollNo) {
                s1.displayRecord();
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << "\n Record of " << rollNo << " is not present";
        }
        file.clear();
    }

    void deleteRecord(int rollNo) {
        ofstream outFile("new.dat", ios::binary);
        file.seekg(0, ios::beg);
        bool flag = false;
        Student s1;

        while (file.read((char*)&s1, sizeof(Student))) {
            if (s1.getRollNo() == rollNo) {
                flag = true;
                continue;
            }
            outFile.write((char*)&s1, sizeof(Student));
        }
        if (!flag) {
            cout << "\n Record of " << rollNo << " is not present";
        }
        file.close();
        remove("student.dat");
        rename("new.dat", "student.dat");
    }
};

int main() {
    ofstream newFile("student.dat", ios::app | ios::binary);
    newFile.close();
    FileOperation file((char*)"student.dat");
    int rollNo, year, Choice = 0;
    char div;
    char name[MAX], address[MAX];

    while (Choice != 5) {
        cout << "\n***********Student Database**********\n";
        cout << "1: Add New Record\n";
        cout << "2: Display All Records\n";
        cout << "3: Display By RollNo\n";
        cout << "4: Deleting a Records\n";
        cout << "5: Exit\n";
        cin >> Choice;

        switch (Choice) {
        case 1:
            cout << endl << "Enter RollNo and name: \n";
            cin >> rollNo >> name;
            cout << "Enter Year, Division : \n";
            cin >> year >> div;
            cout << "Enter Address: \n";
            file.insertRecord(rollNo, name, year, div, address);
            cout << "\n Record Inserted";
            break;
        case 2:
            cout << endl << setw(5) << "ROLL" << setw(20) << "NAME" << setw(5) << "DIV" << setw(10) << "CITY";
            file.displayAll();
            break;
        case 3:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            file.displayRecord(rollNo);
            break;
        case 4:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            file.deleteRecord(rollNo);
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice";
            break;
        }
    }
    return 0;
}
