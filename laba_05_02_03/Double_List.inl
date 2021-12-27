#include "Double_List.h"
using namespace std;

template<class T>
inline List<T>::List() {}

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
inline bool List<T>::empty() { return !first; }

template<class T>
inline size_t List<T>::size()
{
	return _size;
}

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
inline T List<T>::pop_front()
{
	if (empty()) throw - 1;		// если элементов нет, вызываем исключени€
	else if (last == first)		// если элемент 1
	{
		T temp_data = first->data;
		delete first;
		first = last = nullptr;
		--_size;
		return temp_data;
	}
	else						// если элементов больше 1
	{
		Node* temp = first->next_ptr;
		T temp_data = first->data;
		delete first;
		temp->prev_ptr = nullptr;
		first = temp;
		--_size;
		return temp_data;
	}
}

template<class T>
inline T List<T>::pop(size_t i_i)
{
	if (empty() || i_i >= _size || i_i < 0) throw -1;
	else if (last == first)		// если элемент 1
	{
		T temp_data = first->data;
		delete first;
		first = last = nullptr;
		--_size;
		return temp_data;
	}
	else if (i_i == 0)
	{
		Node* temp = first->next_ptr;
		T temp_data = first->data;
		delete first;
		temp->prev_ptr = nullptr;
		first = temp;
		--_size;
		return temp_data;
	}
	else if (i_i == _size - 1)
	{
		Node* temp = last->prev_ptr;
		T temp_data = last->data;
		delete last;
		temp->next_ptr = nullptr;
		last = temp;
		--_size;
		return temp_data;
	}
	else
	{
		Node* temp = first;
		for (size_t i = 0; temp != nullptr && i < i_i; ++i)
			temp = temp->next_ptr;
		temp->next_ptr->prev_ptr = temp->prev_ptr;
		temp->prev_ptr->next_ptr = temp->next_ptr;
		T temp_data = temp->data;
		delete temp;
		--_size;
		return temp_data;
	}
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
inline T& List<T>::operator[](size_t const& i)
{
	if (empty() || i >= _size || i < 0) throw - 1;
	List::Node* temp = i < _size / 2 ? first : last; // если индекс ближе к первому элементу, то перебор начинаем с него, иначе с последнего
	if (i < _size / 2) // если индекс ближе к первому
		for (size_t _i = 0; _i < i; ++_i) // перебор с первого до iтого
			temp = temp->next_ptr; // переход к следующему
	else // если индекс ближе к последнему
		for (size_t _i = _size - 1; _i > i; --_i) // перебор с последнего до iтого
			temp = temp->prev_ptr; // переход к предыдущему
	return temp->data;
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