#include "main.h"

int main() {

	cout << "N = ";

	unsigned int N;
	cin >> N;

	QueueLL<int> q_even;
	QueueLL<int> q_odd;

	StackLL<int> s_even;
	StackLL<int> s_odd;

	int input;

	unsigned int i;
	for (i = 0; i < N; i++) {
		cout << "Number (" << i + 1 << ") : ";
		cin >> input;

		if (input % 2 == 0) {
			q_even.push(input);
			s_even.push(input);
		} else {
			q_odd.push(input);
			s_odd.push(input);
		}
	}

	cout << endl;

	int currentElement;

	cout << "E_Queue: ";
	while (q_even.isEmpty() == false) {
		currentElement = q_even.front();
		q_even.pop();

		cout << currentElement << "\t";
	}

	cout << endl;

	cout << "O_Queue: ";
	while (q_odd.isEmpty() == false) {
		currentElement = q_odd.front();
		q_odd.pop();

		cout << currentElement << "\t";
	}

	cout << "\n" << endl;

	cout << "E_Stack: ";
	while (s_even.isEmpty() == false) {
		currentElement = s_even.top();
		s_even.pop();
		cout << currentElement << "\t";
	}
	cout << endl;

	cout << "O_Stack: ";
	while (s_odd.isEmpty() == false) {
		currentElement = s_odd.top();
		s_odd.pop();
		cout << currentElement << "\t";
	}
	cout << endl;

	return 0;
}
