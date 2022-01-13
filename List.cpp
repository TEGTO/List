#include <iostream>
#include <string>
using namespace std;
template <typename T>
class List
{
public:
	int GetSize() { return Size; };
	T& operator [](const int index);
	List();
	~List();
	void push_back(T data);
	void pop_front();
	void clear();
private:

	template <typename T>
	class Node 
	{
	public:
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;

		}
	};
	int Size;
	Node <T> *head;
};

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node <T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template <typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}
template <typename T>
List<T>::~List()
{
}

template<typename T>
void List<T>::push_back(T data)// добавляет элемент в конец
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node <T>* current = this->head;
		while (current->pNext != nullptr)
		{

			current = current->pNext;

		}
		current->pNext = new Node <T>(data);
	}
	Size++;
}

template<typename T>
void List<T>::pop_front() // удаляет первый элмент в списке
{
	Node <T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;


}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();


	}
}






int main()
{
	setlocale(LC_ALL, "RUS");
	
	List<int>lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(800);
	cout << lst[2] << endl;
	system("pause");
	return 0;
}