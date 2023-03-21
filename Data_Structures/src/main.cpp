#include "main.h"

int main() {
	Node<Student> student[10];

	student[0].data.id = 1;
	student[0].data.grade = 10;
	student[0].data.name = "Ahmed";

	student[1].data.id = 2;
	student[1].data.grade = 20;
	student[1].data.name = "sarah";


	student[2].data.id = 3;
	student[2].data.grade = 4;
	student[2].data.name = "Ali";



	Linked_list<Student> list;

	list.insert_front(student[0]);
	list.insert_front(student[1]);
	list.insert_front(student[2]);

	Node<Student> head = list.get_tail();

	cout << head.data.name << endl;

	return 0;
}
