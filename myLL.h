#include "LL.h"

class myLL :public LinkedList {
	int count;
	
public:
	void insertAtTail(int);
	void insertAtHead(int);
	void display();
	bool isEmpty();
	int deleteFromTail();
	int deleteFromHead();
	bool search(int);
	bool deleteValue(int);
	void insertSorted(int);
	int kiling(int a) {
		Node* temp = head;
		int count = a;
		while (head != tail) {
			int i = 0;
			while (i < count) {
				temp = temp->next;
				i++;
			}
			int b = temp->data;
			deleteValue(b);
		}
		return temp->data;
	}
};

void myLL::insertSorted(int value)
{
	if (isEmpty())
	{
		Node* nn = nullptr;
		nn = new Node;
		nn->data = value;
		nn->next = nullptr;

		head = nn;
		tail = nn;
	}

	else if (value <= head->data)
		insertAtHead(value);

	else if (value >= tail->data)
		insertAtTail(value);

	else	// insert in between
	{
		Node* nn = nullptr;
		nn = new Node;
		nn->data = value;
		nn->next = nullptr;


		Node* temp = head;

		while (1)
		{
			if (temp->data < value && temp->next->data >= value)
				break;

			else
				temp = temp->next;
		}

		nn->next = temp->next;
		temp->next = nn;
	}

}

bool myLL::deleteValue(int value)
{
	if (isEmpty())
		return false;

	else if (head == tail) //single node
	{
		return false;
	}

	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->next->data == value)
				break;

			else
				temp = temp->next;

			if (temp == tail)
				return false;
		}

		Node* t2 = temp->next;
		temp->next = temp->next->next;
		delete t2;
		t2 = nullptr;

		return true;
	}

}

bool myLL::search(int value)
{
	if (isEmpty())
		return false;

	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->data == value)
				return true;

			temp = temp->next;

			if (temp == tail)
				return false;
		}
	}
}

int myLL::deleteFromHead()
{
	if (isEmpty())
		return NULL;

	if (head == tail) //single node case
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		Node* temp = head;
		int returningValue = head->data;

		head = head->next;
		delete temp;
		temp = nullptr;
		tail->next = head;
		return returningValue;

	}
}


int myLL::deleteFromTail()
{
	if (isEmpty())
		return NULL;

	if (head == tail) //single node case
	{
		int returningValue = head->data;
		delete tail;
		head = nullptr;
		tail = nullptr;
		return returningValue;
	}

	else
	{
		Node* temp = head;

		while (1)
		{
			if (temp->next == tail)
				break;

			else
				temp = temp->next;

		}
		int returningValue = tail->data;
		delete tail;
		tail = temp;
		tail->next = head;
		return returningValue;

	}
}

bool myLL::isEmpty()
{
	return head == nullptr && tail == nullptr;
}

void myLL::display()
{
	if (head == nullptr && tail == nullptr)
		cout << "LL is empty" << endl;

	else
	{
		Node* temp = head;

		while (1)
		{
			cout << temp->data << endl;
			temp = temp->next;

			if (temp == tail)
				break;
		}
	}
}

void myLL::insertAtTail(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (head == nullptr && tail == nullptr) //empty LL
	{
		head = nn;
		tail = nn;
		
	}

	else //non-empty LL
	{
		tail->next = nn;
		tail = nn;
		tail->next = head;
	}
}

void myLL::insertAtHead(int value)
{
	Node* nn = new Node;
	nn->data = value;
	nn->next = nullptr;

	if (head == nullptr && tail == nullptr) //empty LL
	{
		head = nn;
		tail = nn;
	}

	else //non-empty LL
	{
		nn->next = head;
		head = nn;
		tail -> next = head;
	}
}