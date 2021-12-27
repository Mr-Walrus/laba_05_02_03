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
		Node* temp = index < _size / 2 ? first : last; // ���� ������ ����� � ������� ��������, �� ������� �������� � ����, ����� � ����������
		if (index < _size / 2) // ���� ������ ����� � �������
			for (size_t _i = 0; _i < index; ++_i) // ������� � ������� �� i����
				temp = temp->next; // ������� � ����������
		else // ���� ������ ����� � ����������
			for (size_t _i = _size - 1; _i > index; --_i) // ������� � ���������� �� i����
				temp = temp->prev; // ������� � �����������
		return temp;
	}

public:
	List();
	List(T* arr, size_t amount);
	List(const List<T>& other);		// ����������� �����������
	~List();						// ����������
	bool empty() const;

	size_t size() const;

	void push_back(T new_data);	// ��������� ������� �����
	T pop_back();		// ���������� ��������� ������� ����� ��������
	void push_front(T new_data);	// ��������� ������� �������
	T pop_front();		// ���������� ������ ������� ����� ��������

	void push(size_t, T new_data);	// ��������� n-�� �������
	T pop(size_t);		// ���������� n-�� ������� ����� ��������

	List<T>& operator= (const List<T>& other); // �������� ������������

	T& operator[] (size_t const& i);

	template<class U>
	friend std::ostream& operator<< (std::ostream& out, const List<U>& other); // ��������� ������� ����� �� �����

	template<class U>
	friend std::istream& operator>> (std::istream& in, List<U>& V);
};
#include "Double_List.inl"
