#include <iostream>
using namespace std;

// BAI 1:
// Khai bao cau truc Node
struct Node
{
	int data;
	Node* next;
};

// Khai bao cau truc stack
struct Stack
{
	Node* head;
};

// Khoi tao ds rong
void init(Stack& s)
{
	s.head = NULL;
}

// Kiem tra stack rong
bool isEmpty(Stack s)
{
	return (s.head == NULL);
}

// Tao Node
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

//  Them vao dau ds
void Push(Stack& s, int data)
{
	// tao node moi
	Node* ptr = createNode(data);
	// kiem tra stack rong
	if (isEmpty(s))
	{
		s.head = ptr;
	}
	// neu ton tai ptu, tro den dau ds
	else
	{
		ptr->next = s.head;
		s.head = ptr;
	}
}

// Hien thi ptu dau tien
void ptudau(Stack s)
{
	Node* p = s.head;
	if (p != NULL)
	{
		cout << "\t" << p->data << endl;
	}
}

// Hien thi tat ca ptu trong stack
void output(Stack s)
{
	Node* p = s.head;
	while (p != NULL)
	{
		cout << "\t" << p->data;
		p = p->next;
	}
}

// Xoa ptu dau trong stack
int pop(Stack& s, int x)
{
	Node* p = s.head;
	if (p != NULL)
	{
		x = p->data;
		s.head = p->next;
		delete p;
		return 1;
	}
	return 0;
}

int main() {
	int op = 1;

	Stack s;
	int data = 0;
	init(s);

	while (op > 0 && op < 5)
	{
		cout << "\t\t========== MENU ==========\n";
		cout << "\t 1. Them ptu vao stack\n";
		cout << "\t 2. Chi hien thi ptu dau trong Stack\n";
		cout << "\t 3. Xoa ptu trong Stack\n";
		cout << "\t 4. Hien thi cac ptu trong Stack\n";
		cout << "\t 0. Ket thuc\n\n";
		cout << "\t\t========== END ==========\n";
		cout << "Nhap lua chon ban muon: "; cin >> op;
		switch (op)
		{
			case 1:
			{
				cout << "Nhap ptu can them: ";
				cin >> data;
				Push(s, data);
				break;
			}
			case 2:
			{
				ptudau(s);
				break;
			}
			case 3:
			{
				if (pop(s, 0) == 1)
				{
					cout << "Xoa thanh cong!\n";
					output(s);
				}
				else
				{
					cout << "Xoa ko thanh cong\n";
				}
				cout << endl;
				break;
			}
			case 4:
			{
				output(s);
				cout << endl;
				break;
			}
		}
	}

	system("pause");
	return 0;
}
