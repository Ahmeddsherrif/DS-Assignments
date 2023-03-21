/*
 * Student.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Master
 */

#ifndef STUDENT_H_
#define STUDENT_H_



struct Student {

		Student() {
			memset(this, 0, sizeof(*this));
		}

		Student(const int &id, const string &name, const int &grade) :
				id { id }, name { name }, grade { grade } {

		}

		~Student() {
			memset(this, 0, sizeof(*this));
		}

		int id;
		string name;
		int grade;
};

void printStudent(const Student &s) {
	cout << "ID = " << s.id << endl;
	cout << "Name = " << s.name << endl;
	cout << "Grade = " << s.grade << endl;

	cout << endl;
}

#endif /* STUDENT_H_ */
