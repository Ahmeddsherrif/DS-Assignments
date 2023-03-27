#include "main.h"

int main() {
	Student student[10];

	student[0].id = 1;
	student[0].grade = 10;
	student[0].name = "Ahmed";

	student[1].id = 2;
	student[1].grade = 20;
	student[1].name = "sarah";

	student[2].id = 3;
	student[2].grade = 4;
	student[2].name = "Ali";

	QueueLL<Student> q;
	q.push(student[0]);
	q.push(student[1]);
	q.push(student[2]);

	Student tempStudent;

	while (q.isEmpty() == false) {
		tempStudent = q.front();
		q.pop();

		cout << tempStudent.name << endl;
	}


	cout << endl;

	StackLL<Student> s;
	s.push(student[0]);
	s.push(student[1]);
	s.push(student[2]);


	while (s.isEmpty() == false) {
		tempStudent = s.top();
		s.pop();

		cout << tempStudent.name << endl;
	}

	return 0;
}
