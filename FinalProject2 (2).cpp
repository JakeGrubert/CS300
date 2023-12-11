#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define the structure for a course
struct Course {
    string courseNumber;
    string courseTitle;
    // Add other necessary properties, such as prerequisites
};

// Function to load data from a file into the data structure
void loadDataStructure(vector<Course>& courses) {
    ifstream inputFile("course_data.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening the file.\n";
        return;
    }

    Course course;
    while (inputFile >> course.courseNumber >> ws && getline(inputFile, course.courseTitle)) {
        // Add the course to the vector
        courses.push_back(course);
    }

    inputFile.close();
}


// Function to print the course list in alphanumeric order
void printCourseList(const vector<Course>& courses) {
    // Implement code to sort the courses and print the list
    // Example: Sort courses alphanumerically
    vector<Course> sortedCourses = courses;
    sort(sortedCourses.begin(), sortedCourses.end(), [](const Course& a, const Course& b) {
        return a.courseNumber < b.courseNumber;
        });

    // Print the sorted list
    for (const auto& course : sortedCourses) {
        cout << course.courseNumber << ", " << course.courseTitle << endl;
    }
}

// Function to print course information based on course number
void printCourseInfo(const vector<Course>& courses, const string& courseNumber) {
    // Convert to lowercase for case-insensitive comparison
    string courseNumberLowerCase = courseNumber;
    transform(courseNumberLowerCase.begin(), courseNumberLowerCase.end(), courseNumberLowerCase.begin(), ::tolower);

    // Find the course in the data structure
    for (const auto& course : courses) {
        // Convert course number to lowercase for comparison
        string currentCourseNumber = course.courseNumber;
        transform(currentCourseNumber.begin(), currentCourseNumber.end(), currentCourseNumber.begin(), ::tolower);

        if (currentCourseNumber == courseNumberLowerCase) {
            // Print course information
            cout << course.courseNumber << ", " << course.courseTitle << "\nPrerequisites: "; // Add prerequisites
            // Implement code to print prerequisites
            cout << endl;
            return;
        }
    }

    // If the course is not found
    cout << "Course not found.\n";
}

int main() {
    cout << "Welcome to the course Planner\n";
    vector<Course> courses; // Your data structure to store courses

    while (true) {
        int userChoice;
        string courseNumberInput;

        cout << "\t 1. Load Data Structure.\n";
        cout << "\t 2. Print Course List.\n";
        cout << "\t 3. Print Course.\n";
        cout << "\t 9. Exit.\n";
        cout << "What would you like to do? ";
        cin >> userChoice;
        cout << "\n";

        if (userChoice == 9) {
            break;
        }
        else if (userChoice == 1) {
            // Load data into the data structure
            loadDataStructure(courses);
            cout << "Data loaded into the data structure.\n";
        }
        else if (userChoice == 2) {
            // Print the course list
            printCourseList(courses);
        }
        else if (userChoice == 3) {
            // Print course information
            cout << "Enter the course number you want to know about: ";
            cin >> courseNumberInput;
            printCourseInfo(courses, courseNumberInput);
        }
        else {
            cout << userChoice << " is not a valid option\n";
        }
    }

    return 0;
}