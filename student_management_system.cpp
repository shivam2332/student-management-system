#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int age;
    string course;

    void inputStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);
    }

    void displayStudent() const {
        cout << "\nRoll No: " << rollNo
             << "\nName: " << name
             << "\nAge: " << age
             << "\nCourse: " << course << "\n";
    }
};

class StudentManagement {
private:
    vector<Student> students;
public:
    void addStudent() {
        Student s;
        s.inputStudent();
        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void showStudents() const {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }
        for (const auto& s : students) {
            s.displayStudent();
            cout << "----------------------\n";
        }
    }

    void searchStudent() const {
        int roll;
        cout << "Enter Roll Number to search: ";
        cin >> roll;
        for (const auto& s : students) {
            if (s.rollNo == roll) {
                s.displayStudent();
                return;
            }
        }
        cout << "Student not found!\n";
    }

    void updateStudent() {
        int roll;
        cout << "Enter Roll Number to update: ";
        cin >> roll;
        for (auto& s : students) {
            if (s.rollNo == roll) {
                cout << "Enter new details:\n";
                s.inputStudent();
                cout << "Student details updated successfully!\n";
                return;
            }
        }
        cout << "Student not found!\n";
    }
};

int main() {
    StudentManagement sm;
    int choice;
    do {
        cout << "\nStudent Management System";
        cout << "\n1. Add Student";
        cout << "\n2. Show Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: sm.addStudent(); break;
            case 2: sm.showStudents(); break;
            case 3: sm.searchStudent(); break;
            case 4: sm.updateStudent(); break;
            case 5: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
