#pragma once

class Calendar
{
private:
	int size;
	int counter;
	Date* arr; //��� �������� �������
public:
	//�����������
	Calendar();

	//����������� �����������
	Calendar(const Calendar& other);

	//�������
	int GetSize() { return size; }
	int GetCounter() { return counter; }

	//�������
	void SetCounterPlusOne() { counter++; }

	//����� �� ����� 
	void PrintCalendar();

	//������� �� ������������� ���������� ������������ �������
	int ExistLastDate();

	//�������� ���������� ������������ �������
	void DeleteLastDate();

	//���������� ������
	void Calendar::AddMemory();

	//��������
	Date& operator[] (const int index);

	//����������
	~Calendar();
};
