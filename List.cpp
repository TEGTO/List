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
	void push_back(T data);// добавляет элемент в конец списка
	void pop_front();// удаляет первый элемент в списке
	void clear();//удаляет все элементы в списке
	void push_front(T data);// добавляет элемент в начало списка
	void insert(T value, int index); // добавление выбранному индексу новые данные
	void removeAt(int index);// удаление элемента по указанному индексу
	void pop_back();// удаляет последний элемент
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
void List<T>::push_front(T data)// добавляет элемент в начало списка
{
	head = new Node<T>(data,head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index) // добавление выбранному индексу новые данные 
{
	if (index ==0)
	{
		push_front(data);
	}
	else
	{
		Node <T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* NewNode = new Node <T>(data, previous->pNext);
		previous->pNext = NewNode;
		Size++;
	}
	
}

template<typename T>
void List<T>::removeAt(int index)// удаление элемента по указанному индексу
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node <T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		Size--;
	}
}

template<typename T>
void List<T>::pop_back()// удаляет последний элемент
{
	removeAt(Size - 1);
}

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
	clear();
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
void List<T>::pop_front() // удаляет первый элемент в списке
{
	Node <T>* temp = head;
	head = head->pNext;
	delete temp;
	Size--;


}

template<typename T>
void List<T>::clear() //удаляет все элементы в списке
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
	lst.insert(99, 2);
	cout << lst[2] << endl;
	system("pause");
	return 0;
}