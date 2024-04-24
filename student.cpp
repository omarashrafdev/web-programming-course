#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM_OF_STUDENTS = 3;

struct Student {
	string name;
	int rollNumber;
	string marks[NUM_OF_STUDENTS][2] = {
		{"Math", "0"}, {"Physics", "0"}, {"Chemistry", "0"}
	};
};

void addStudent(Student &student, string name, int rollNumber, string math, string physics, string chemistry) {
	student.name = name;
	student.rollNumber = rollNumber;
	student.marks[0][1] = math;
	student.marks[1][1] = physics;
	student.marks[2][1] = chemistry;
}

void displayAllStudents(Student (&students)[NUM_OF_STUDENTS]) {
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		cout << "Student name: " << students[i].name << endl;
		cout << "Student roll number: " << students[i].rollNumber << endl;
		cout << "Student grades:-\n";
		for (int j = 0; j < NUM_OF_STUDENTS; j++) {
			cout << students[i].marks[j][0] << " : " << students[i].marks[j][1] << endl;
		}
		cout << endl;
	}
}

void searchStudentByName(Student(&students)[NUM_OF_STUDENTS], string name) {
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		if (students[i].name == name) {
			cout << "Student found!\n";
			return;
		}
	}
	cout << "Student not found!\n";
}

void saveStudentsToFile(Student(&students)[NUM_OF_STUDENTS]) {
	fstream file;
	file.open("students.txt", ios::out);

	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		file << "Student name: " << students[i].name << endl;
		file << "Student roll number: " << students[i].rollNumber << endl;
		for (int j = 0; j < NUM_OF_STUDENTS; j++) {
			file << students[i].marks[j][0] << " Grade : " << students[i].marks[j][1] << endl;
		}
		file << endl;
	}

	file.close();
}

void readStudentsFile(Student(&students)[NUM_OF_STUDENTS], string fileName) {
	fstream file;
	string line;
	file.open("students.txt");

	while (!file.eof()) {
		getline(file, line);
		cout << line << endl;
	}


	file.close();
}

void displayStudentsScores(Student(&students)[NUM_OF_STUDENTS]) {
	for (int i = 0; i < NUM_OF_STUDENTS; i++) {
		int totalScore = 0;
		int averageScore = 0;
		for (int j = 0; j < NUM_OF_STUDENTS; j++) {
			totalScore += stoi(students[i].marks[j][1]);
		}
		averageScore = totalScore / 3;
		if (averageScore >= 60) {
			cout << "Student " << students[i].name << " passed!\n";
		}
		else {
			cout << "Student " << students[i].name << " failed!\n";
		}
	}
}

int main() {
	Student students[NUM_OF_STUDENTS];

	addStudent(students[0], "Omar", 545616, "50", "15", "65" );
	addStudent(students[1], "Mohamed", 321683, "57", "66", "0");
	addStudent(students[2], "Ali", 477515, "85", "10", "95");

	//displayAllStudents(students);

	//searchStudentByName(students, "Ali");

	//saveStudentsToFile(students);

	//readStudentsFile(students, "students.txt");

	displayStudentsScores(students);

	return 0;
}