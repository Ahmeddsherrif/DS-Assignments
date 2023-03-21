#include "main.h"

int main() {
//	Queue<Student> q(3);
//
//
//	q.push( { 1, "Ahmed", 10 });
//	q.push( { 2, "Mohamed", 20 });
//	q.push( { 3, "sarah", 30 });
//
//	Student student[4];
//
//	if (q.isEmpty() == false) {
//		student[0] = q.front();		//ahmed
//		q.pop();
//		printStudent(student[0]);
//
//	}
//
//	if (q.isEmpty() == false) {
//		student[1] = q.front();			//mohamed
//		q.pop();
//		printStudent(student[1]);
//
//	}
//
//	q.push( { 4, "Yassmin", 40 });
//
//	if (q.isEmpty() == false) {
//		student[2] = q.front();			//sarah
//		q.pop();
//		printStudent(student[2]);
//	}
//
//	if (q.isEmpty() == false) {
//		student[3] = q.front();			//Yassmin
//		q.pop();
//		printStudent(student[3]);
//	}

	Stack<Student> s(3);


	s.push( { 1, "Ahmed", 10 });
	s.push( { 2, "Mohamed", 20 });
	s.push( { 3, "sarah", 30 });

	Student student[4];

	if (s.isEmpty() == false) {
		student[0] = s.top();		//ahmed
		s.pop();
		printStudent(student[0]);

	}

	if (s.isEmpty() == false) {
		student[1] = s.top();			//mohamed
		s.pop();
		printStudent(student[1]);

	}

	s.push( { 4, "Yassmin", 40 });

	if (s.isEmpty() == false) {
		student[2] = s.top();			//sarah
		s.pop();
		printStudent(student[2]);
	}


	if (s.isEmpty() == false) {
		student[3] = s.top();			//Yassmin
		s.pop();
		printStudent(student[3]);
	}



	return 0;
}
