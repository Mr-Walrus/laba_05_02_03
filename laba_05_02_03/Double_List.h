#pragma once
#include <iostream>
#include <ctime>
using namespace std;

template<class T>
class List
{
private:
	class Node
	{
	public:
		Node* next_ptr;
		Node* prev_ptr;
		T data;
	};

	size_t _size = 0;
	Node* first = nullptr;
	Node* last = nullptr;

public:
	List();
	List(const List<T>& other);		// конструктор копирования
	~List();						// деструктор
	bool empty();

	size_t size();

	void push_back(T new_data);
	T pop_front();
	T pop(size_t i);

	List<T>& operator= (const List<T>& other); // оператор присваивания

	T& operator[] (size_t const& i);

	template<class U>
	friend std::ostream& operator<< (std::ostream& out, const List<U>& other); // дружеская функция вывод на экран

	template<class U>
	friend std::istream& operator>> (std::istream& in, List<U>& V);
};
#include "Double_List.inl"
