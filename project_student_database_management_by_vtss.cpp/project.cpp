#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string roll_no;
    string name;
    string branch_name;
    string course;
    string mobile_no;
    string admission_year;
};

vector<Student> students;

void getStudentData(Student &student) {
    cout << "Enter Roll NO: ";
    cin >> student.roll_no;
    cout << "Enter Name: ";
    cin.ignore(); // Clear the newline character
    getline(cin, student.name);
    cout << "Enter Branch: ";
    getline(cin, student.branch_name);
    cout << "Enter Course: ";
    getline(cin, student.course);
    cout << "Enter Mobile NO: ";
    cin >> student.mobile_no;
    cout << "Enter Admission Year: ";
    cin >> student.admission_year;
}

void enter() {
    int ch;
    cout << "How many students do you want to enter? ";
    cin >> ch;

    if (ch < 0) {
        cout << "Invalid number!" << endl;
        return;
    }

    for (int i = 0; i < ch; i++) {
        cout << "\nEntering data for student " << (students.size() + 1) << endl;
        Student student;
        getStudentData(student);
        students.push_back(student);
    }
}

void show() {
    if (students.empty()) {
        cout << "No Data is Entered" << endl;
        return;
    }

    for (size_t i = 0; i < students.size(); i++) {
        cout << "\nData of Student " << (i + 1) << endl;
        cout << "Roll NO: " << students[i].roll_no << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Branch: " << students[i].branch_name << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "Mobile NO: " << students[i].mobile_no << endl;
        cout << "Admission Year: " << students[i].admission_year << endl;
    }
}

void search() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
        return;
    }

    string rollno;
    cout << "Enter the roll no of student: ";
    cin >> rollno;

    for (const auto& student : students) {
        if (rollno == student.roll_no) {
            cout << "Roll NO: " << student.roll_no << endl;
            cout << "Name: " << student.name << endl;
            cout << "Branch: " << student.branch_name << endl;
            cout << "Course: " << student.course << endl;
            cout << "Mobile NO: " << student.mobile_no << endl;
            cout << "Admission Year: " << student.admission_year << endl;
            return; // Found the student
        }
    }
    cout << "No student found with Roll NO: " << rollno << endl;
}

void update() {
    if (students.empty()) {
        cout << "No data is entered" << endl;
        return;
    }

    string rollno;
    cout << "Enter the roll no of student which you want to update: ";
    cin >> rollno;

    for (auto& student : students) {
        if (rollno == student.roll_no) {
            cout << "\nUpdating data for Roll NO: " << student.roll_no << endl;
            getStudentData(student);
            return; // Updated the student
        }
    }
    cout << "No student found with Roll NO: " << rollno << endl;
}

void deleteAll() {
    students.clear();
    cout << "All records deleted!" << endl;
}

int main() { 
      cout<<"student Database managment system ";
    int choice;
    while (true) {
        cout << "\n1. Enter data\n2. Show data\n3. Search data\n4. Update data\n5. Delete all data\n6. Quit\n";
        cin >> choice;

        switch (choice) {
            case 1: enter(); break;
            case 2: show(); break;
            case 3: search(); break;
            case 4: update(); break;
            case 5: deleteAll(); break;
            case 6: return 0; // exit the program
            default: cout << "Invalid input" << endl; break;
        }
    }
};













  









































































































































































































