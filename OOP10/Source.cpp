#include <iostream>
#include <assert.h>
#include <queue>
#include <vector>

using namespace std;
class Student {
	string name;
	double avg;
public:

	string GetName()const {
		return name;
	}
	double GetAvg()const {
		return avg;
	}

	void SetName(string n) {
		n = name;
	}
	void SetAvg(double a) {
		a = avg;
	}


	Student() {
		name = "";
		avg = 0;
	}

	Student(string name, double avg) {
		this->name = name;
		this->avg = avg;
	}

	// operator >
	bool operator>(const Student& obj) {
		return avg > obj.avg;
	}

	// operator <<
	friend ostream& operator<<(ostream& out, const Student& obj) {
		out << obj.name << " " << obj.avg << endl;
		return out;
	}
};

template<class T>
class PriorityQueue {
	T* arr;
	int capacity;
	int count;
	int rear;

	int GetMaxIndex() {
		int maxIndex = 0;
		for (int i = 0; i < count; i++) {
			if (arr[i] > arr[maxIndex])
				maxIndex = i;
		}
		return maxIndex;
	}

public:
	PriorityQueue(int size) {
		arr = new T[size];
		capacity = size;
		count = 0;
		rear = -1;
	}

	bool IsFull() const { return capacity == count; }
	bool IsEmpty() const { return 0 == count; }

	void Push(T value) {
		assert(!IsFull());
		arr[++rear] = value;
		count++;
	}

	void Pop() {
		assert(!IsEmpty());
		int index = GetMaxIndex();

		for (int i = index; i < count - 1; i++) {
			arr[i] = arr[i + 1];
		}
		count--;
	}

	void Print() {
		for (int i = 0; i < count; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~PriorityQueue()
	{
		delete[] arr;
	}
};

void main() {



	PriorityQueue<Student> pq(4);
	pq.Push(Student("Elchin", 3));
	pq.Push(Student("Rustam", 3.6));
	pq.Push(Student("Rufat", 4));
	pq.Push(Student("Ulvi", 9));

	pq.Print();
	cout << "*********************************************\n";
	pq.Pop();
	pq.Print();
	cout << "*********************************************\n";
	pq.Pop();
	pq.Print();
	cout << "*********************************************\n";


}