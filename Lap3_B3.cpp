#include <iostream>
using namespace std;

// Khai bao cau truc Queue theo ds dac
#define Max 100
int Q[Max] = { 0 };
// front vi tri lay ra, rear vi tri them vao
int front, rear;

// Khai bao Queue rong
void init()
{
	front = -1;
	rear = -1;
}

// Kiem tra Queue rong
bool isEmpty()
{
	if (front == -1)
		return true;
	return false;
}

// Kiem tra Queue day
bool isFull()
{
	if (rear - front == Max - 1)
		return true;
	return false;
}

// Them 1 ptu vao Queue
int push(int Q[], int x)
{
	if (isFull() == true) // Queue day
	{
		return 0;
	}
	else
	{
		if (isEmpty() == true) // Queue rong
		{
			front = 0;
		}
		if (rear == Max - 1) // Queue tran
		{
			for (int i = front; i <= rear; i++)
			{
				// Thuc hien doi tinh tien cac ptu trong hang
				Q[i - front] = Q[i];
			}
			// rear nhan gia tri moi sau khi tinh tien
			rear = Max - 1 - front;
			// front nhan gia tri moi sau khi tinh tien
			front = 0;
		}
		Q[++rear] = x;
		return 1;
	}
}

// Hien thi tat ca ptu trong Queue
void output()
{
	if (isEmpty() == true)
	{
		cout << "DS rong!\n";
	}

	cout << "Cac phan tu trong Queue: ";
	for (int i = front; i <= rear; i++)
	{
		cout << "\t" << Q[i];
	}
	cout << endl;
}

// Xoa ptu khoi Queue  
int pop(int &x)
{
	if (isEmpty() == true)
	{
		return 0;
	}
	else
	{
		x = Q[front++];
		// Truong hop Queue co 1 ptu, sau khi xoa => rong
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}

int main() {
	int op = 0;
	int x = 0;
	init();

	while (op < 4)
	{
		cout << "\t------------- Menu -------------\n";
		cout << "1) Them phan tu vao Queue\n";
		cout << "2) Xoa phan tu khoi QUeue\n";
		cout << "3) Hien thi tat ca phan tu trong Queue\n";
		cout << "4) Thoat\n";
		cout << "Nhap lua chon cua ban: ";
		cin >> op;
		switch (op)
		{
		case 1:
		{
			cout << "\n=======Them phan tu vao hang doi========\n";
			cout << "Nhap phan tu can them vao hang doi: ";
			cin >> x;
			if (push(Q, x) != 0)
			{
				cout << " Da them thanh cong!\n";
			}
			else
			{
				cout << " Them khong thanh cong!\n";
			}
			break;
		}
		case 2:
		{
			pop(x);
			break;
		}
		case 3:
		{
			output();
			break;
		}
		default:
			break;
		}
	}

	system("pause");
	return 0;
}