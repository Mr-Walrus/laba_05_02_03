#include "Double_List.h"
using namespace std;

template<class T>
inline List<T>::List() {}

template<class T>
inline List<T>::List(T* arr, size_t amount)
{
	for (size_t i = 0; i < amount; i++)
		this->push_back(arr[i]);
}

template<class T>
inline List<T>::List(const List<T>& other)
{
	this->_size = 0;
	List::Node* temp = other.first;	// начина€ с первого
	for (size_t i = 0; i < other._size; i++)	// в цикле дл€ каждого элемента
	{
		this->push_back(temp->data);		// добавл€ем в конец текущий элемент
		temp = temp->next_ptr;				// переходим к следующему элементу
	}
}

template<class T>
inline List<T>::~List()
{
	if (!empty()) // если не пусто 
		while (!(empty())) // удал€ем все элементы
			pop_front();
}

template<class T>
inline bool List<T>::empty() const { return !first; }

template<class T>
inline size_t List<T>::size() const { return _size; }

template<class T>
inline void List<T>::push_back(T new_data)
{
	if (empty()) // если элементов нет
	{
		first = last = new Node;
		last->data = new_data;
		last->next_ptr = nullptr;
		last->prev_ptr = nullptr;
	}
	else // если есть хот€бы 1 элемент
	{
		Node* temp = new Node;
		temp->prev_ptr = last;
		temp->next_ptr = nullptr;
		last->next_ptr = temp;
		temp->data = new_data;
		last = temp;
	}
	++_size;
}

template<class T>
inline T List<T>::pop_back()
{
	if (empty()) throw Exception("List is empty");		// если элементов нет, вызываем исключени€
	T data = last->data;
	if (last == first)		// если элемент 1
	{
		delete last;
		first = last = nullptr;
	}
	else						// если элементов больше 1
	{
		Node* temp = last->prev_ptr;
		delete last;
		temp->next_ptr = nullptr;
		last = temp;
	}
	--_size;
	return data;
}

template<class T>
inline void List<T>::push_front(T new_data)
{
	if (empty()) // если элементов нет
	{
		first = last = new Node;
		last->data = new_data;
		last->next_ptr = nullptr;
		last->prev_ptr = nullptr;
	}
	else // если есть хот€бы 1 элемент
	{
		Node* temp = new Node;
		temp->data = new_data;
		temp->next_ptr = first;
		temp->prev_ptr = nullptr;
		first->prev_ptr = temp;
		first = temp;
	}
	++_size;
}

template<class T>
inline T List<T>::pop_front()
{
	if (empty()) throw Exception("List is empty");		// если элементов нет, вызываем исключени€
	T temp_data = first->data;
	if (last == first)		// если элемент 1
	{
		delete first;
		first = last = nullptr;
	}
	else						// если элементов больше 1
	{
		Node* temp = first->next_ptr;
		delete first;
		temp->prev_ptr = nullptr;
		first = temp;
	}
	--_size;
	return temp_data;
}

template<class T>
inline void List<T>::push(size_t index, T new_data)
{
	if (index < 0) throw Exception("Incorrect index");
	if (empty()) // если элементов нет
	{
		first = last = new Node;
		last->data = new_data;
		last->next_ptr = nullptr;
		last->prev_ptr = nullptr;
		++_size;
	}
	else if (index == 0)
	{
		this->push_front(new_data);
	}
	else if (index >= _size)
	{
		this->push_back(new_data);
	}
	else
	{
		Node* temp = get_element(index);
		Node* temp_new = new Node;
		temp_new->data = new_data;
		temp_new->prev_ptr = temp->prev;
		temp_new->next_ptr = temp;
		temp->prev_ptr->next_ptr = temp_new;
		temp->prev_ptr = temp_new;
		++_size;
	}
}

template<class T>
inline T List<T>::pop(size_t index)
{
	if (empty()) throw Exception("List is empty");
	if (index >= _size || index < 0) throw Exception("Incorrect index");
	T temp_data;
	if (last == first)		// если элемент 1
	{
		temp_data = first->data;
		delete first;
		first = last = nullptr;
	}
	else if (index == 0)
	{
		Node* temp = first->next_ptr;
		temp_data = first->data;
		delete first;
		temp->prev_ptr = nullptr;
		first = temp;
	}
	else if (index == _size - 1)
	{
		Node* temp = last->prev_ptr;
		temp_data = last->data;
		delete last;
		temp->next_ptr = nullptr;
		last = temp;
	}
	else
	{
		Node* temp = get_element(index);
		temp->next_ptr->prev_ptr = temp->prev_ptr;
		temp->prev_ptr->next_ptr = temp->next_ptr;
		temp_data = temp->data;
		delete temp;
	}
	--_size;
	return temp_data;
}

template<class T>
inline List<T>& List<T>::operator=(const List<T>& other)
{
	while (!(this->empty())) // удал€ем все элементы
		this->pop_front();
	this->_size = other._size; // копируем размер
	List::Node* temp = other.first;	// начина€ с первого
	for (size_t i = 0; i < this->_size; i++)	// в цикле дл€ каждого элемента
	{
		this->push_back(temp->data);		// добавл€ем в конец текущий элемент
		temp = temp->next_ptr;				// переходим к следующему элементу
	}
	return *this;
}

template<class T>
inline T& List<T>::operator[](size_t const& index)
{
	return get_element(index)->data;
}

template<class U>
inline std::ostream& operator<<(std::ostream& out, const List<U>& other)
{
	List<U> A(other); // создаю копию
	while (!(A.empty())) // пока копи€ не пуста
		out << A.pop_front() << " "; // вывожу ее элементы
	return out;
}

template<class U>
istream& operator>>(istream& in, List<U>& V)
{
	U a;
	cout << "   ¬ведите " << V._size << " элементов: ";
	for (size_t i = 0; i < V._size; i++)	// в цикле
	{
		in >> a;
		V.push_back(a);
	}
	return in;
}