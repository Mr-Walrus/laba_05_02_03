#pragma once
#include <iostream>
#include <ctime>
#include "Exception.h"
using namespace std;

template<class T>
class List
{
private:
	class Node
	{
	public:
		Node* next_ptr = nullptr;
		Node* prev_ptr = nullptr;
		T data;
	};

	size_t _size = 0;
	Node* first = nullptr;
	Node* last = nullptr;
	Node* get_element(size_t index)
	{
		if (empty()) throw Exception("List is empty");
		if (index >= _size || index < 0) throw Exception("Incorrect index");
		Node* temp = index < _size / 2 ? first : last; // если индекс ближе к первому элементу, то перебор начинаем с него, иначе с последнего
		if (index < _size / 2) // если индекс ближе к первому
			for (size_t _i = 0; _i < index; ++_i) // перебор с первого до iтого
				temp = temp->next; // переход к следующему
		else // если индекс ближе к последнему
			for (size_t _i = _size - 1; _i > index; --_i) // перебор с последнего до iтого
				temp = temp->prev; // переход к предыдущему
		return temp;
	}

public:
	List();
	List(T* arr, size_t amount);
	List(const List<T>& other);		// конструктор копирования
	~List();						// деструктор
	bool empty() const;

	size_t size() const;

	void push_back(T new_data);	// вставляет элемент сзади
	T pop_back();		// возвращает последний элемент после удаления
	void push_front(T new_data);	// вставляет элемент спереди
	T pop_front();		// возвращает первый элемент после удаления

	void push(size_t, T new_data);	// вставляет n-ый элемент
	T pop(size_t);		// возвращает n-ый элемент после удаления

	List<T>& operator= (const List<T>& other); // оператор присваивания

	T& operator[] (size_t const& i);

	template<class U>
	friend std::ostream& operator<< (std::ostream& out, const List<U>& other); // дружеская функция вывод на экран

	template<class U>
	friend std::istream& operator>> (std::istream& in, List<U>& V);
};
#include "Double_List.inl"
