#include <iostream>
using namespace std;

// BAI 2: Chuyen doi so nguyen duong thap phan => nhi phan

// Khai bao cau truc Node
struct Node
{
	int data;
	Node* next;
};

// Khai bao cau truc Stack
struct Stack
{
	Node* head;
};

// Khoi tao ds rong
void init(Stack& s)
{
	s.head = NULL;
}

// Kiem tra ds rong
bool isEmpty(Stack s)
{
	return (s.head == NULL);
}

//Tao Node
Node* createNode(int data)
{
	Node* p = new Node();
	if (p == NULL)
	{
		return NULL;
	}
	p->data = data;
	p->next = NULL;

	return p;
}

// Them ptu vao dau ds
void push(Stack& s, int data)
{
	// Tao Node moi
	Node* ptr = createNode(data);

	// Kiem tra Stack rong
	if (isEmpty(s) == true)
	{
		s.head = ptr;
	}
	// Neu ton tai tro den dau ds
	else
	{
		ptr->next = s.head;
		s.head = ptr;
	}
}

// Chuyen doi thap phan => nhi phan
void chuyendoi(int n)
{
	Stack s;
	init(s);

	// push cac so du cua phep chia cho 2 vao Stack
	while (n != 0)
	{
		int sodu = n % 2;
		push(s, sodu);
		n = n / 2;
	}

	// Xuat ptu trong Stack ra
	Node* p = s.head;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}

	cout << endl;;
}

int main() {
	Stack s;
	init(s);
	int n = 0;

	cout << "Nhap so nguyen duong: ";
	cin >> n;
	cout << "Thap phan => Nhi phan: ";
	chuyendoi(n);

	system("pause");
	return 0;
}