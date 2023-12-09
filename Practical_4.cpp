#include <iostream>
#include <algorithm> // Required for sorting
using namespace std;

// Assuming you have a structure definition for 'student'
struct student {
    int rollNo;
    string name;
    float sgpa;
};

// Function to perform Bubble Sort on the array of students by roll number
void bubbleSortByRollNo(student arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j].rollNo > arr[j + 1].rollNo) {
                // Swap the students if they are in the wrong order
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to perform binary search on the array of students by name
int binarySearchByName(student arr[], int size, string targetName) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target name is present at the middle
        if (arr[mid].name == targetName)
            return mid;

        // If the target name is greater, ignore the left half
        if (arr[mid].name < targetName)
            left = mid + 1;

        // If the target name is smaller, ignore the right half
        else
            right = mid - 1;
    }

    // If the target name is not present in the array
    return -1;
}

int main() {
    const int size = 5;
    student students[size] = {
        {101, "Alice", 3.8},
        {102, "Bob", 3.5},
        {103, "Charlie", 4.0},
        {104, "David", 3.2},
        {105, "Eva", 3.9}
    };

    int choice;
    cout << "Choose an option:\n";
    cout << "1. Search a student by name\n";
    cout << "2. Design a roll call list\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            string targetName;
            cout << "Enter the name of the student to search: ";
            cin >> targetName;

            // Sort the array of students by name (assuming it's not already sorted)
            sort(students, students + size, [](const student &a, const student &b) {
                return a.name < b.name;
            });

            int index = binarySearchByName(students, size, targetName);

            if (index != -1) {
                cout << "Student found! Roll No: " << students[index].rollNo << ", SGPA: " << students[index].sgpa << endl;
            } else {
                cout << "Student not found." << endl;
            }

            break;
        }

        case 2: {
            // Perform Bubble Sort to arrange students by roll number
            bubbleSortByRollNo(students, size);

            // Display the roll call list
            cout << "Roll Call List:" << endl;
            for (int i = 0; i < size; ++i) {
                cout << "Roll No: " << students[i].rollNo << ", Name: " << students[i].name << ", SGPA: " << students[i].sgpa << endl;
            }

            break;
        }

        default:
            cout << "Invalid choice\n";
            break;
    }

    return 0;
}
