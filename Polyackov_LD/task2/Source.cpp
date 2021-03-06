/*
    ����������� ����� ��������� �������.

    ����� ������ ��������� ��������� ���� �������� ������� � �������: ���, �����, ����, ������������ �������. 
    �� ������ ���� ����� ����������� ������ ���� �������. ����� ����� ������� � �� ����� 30.
    
    ����� ������ ������������� ��������: 
    1) ���������� �������, 
    2) ������ ���� ���������� �������, 
    3) ��������� ������� ����� �������� ����� � ����� ������� (� ����), 
    4) ������������ ����� �������, ������� ��������� ������������ ������� �� �������� �������� (� ����) � ������� � � ������� �������.
    
    ����� ������ ��������� ��� ����������� ������������, ����������, �������� ������������, � ����� ������� �������� ���� �� �������.
*/

#ifndef MAX_EVENTS
    #define MAX_EVENTS 2
#endif // !MAX_EVENTS

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h> //��� setconsole...(1251). ����� ��� ���������� ��������� �������� �������, ���������� ��-������
#include <string>
using namespace std;

int MonthDays(int month, int year)
{
    int Days[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((month==2)&&((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))
        return Days[0];
    return Days[month];
}
const string MonthName[12] = { "������", "�������", "�����", "������", "���", "����", "����", "�������", "��������", "�������", "������", "�������"};

class Date
{
private:
    int year;
    int month;
    int day;
    string event;
    int SumOfDays()
    {
        int sum = 0;
        for (int i = 1; i < year; i++)
        {
            sum += 365;
            if ((i % 400 == 0) || ((i % 4 == 0) && (i % 100 != 0)))
                sum += 1;
        }
        for (int i = 1; i < month; i++)
            sum += MonthDays(i, year);
        sum += day;
        return sum;
    }
public:
    //�����������
    Date(int _day = 1, int _month = 1, int _year = 1, string _event = "�����\0") : day(_day), month(_month), year(_year), event(_event)
    {
        //cout << "�������� �����������: " << this << endl;
    }
    //����������� �����������
    Date(const Date& other)
    {
        year = other.year;
        month = other.month;
        day = other.day;
        event = other.event;
        //cout << "�������� ����������� �����������: " << this << endl;
    }
    //�������
    int GetYear()
    {
        return year;
    }
    int GetMonth()
    {
        return month;
    }
    int GetDay()
    {
        return day;
    }
    string GetEvent()
    {
        return event;
    }
    //����� �� �����
    void PrintDate()
    {
        cout << " " << day << " " << MonthName[month-1] << " " << year << " ����" << endl;
    }
    //�������
    void SetYear(int year)
    {
        this->year = year;
    }
    void SetMonth(int month)
    {
        this->month = month;
    }
    void SetDay(int day)
    {
        this->day = day;
    }
    void SetEvent(string event)
    {
        this->event = event;
    }
    //������� ����� ������
    int DateDifference(Date& other)
    {
        return abs(SumOfDays() - other.SumOfDays());
    }
    //���������
    bool operator== (const Date& other)
    {
        return (year == other.year) && (month == other.month) && (day == other.day);
    }
    bool operator!= (const Date& other)
    {
        return (year != other.year) && (month != other.month) && (day != other.day);
    }
    Date& operator= (const Date& other)
    {
        if (this == &other)
            return *this;
        year = other.year;
        month = other.month;
        day = other.day;
        event = other.event;
        return *this;
    }
    Date operator+ (const int& otherday)
    {
        Date tmp;
        tmp.year = year;
        tmp.month = month;
        tmp.day = day + otherday;
        char* days = new char[11];
        _itoa(otherday, days, 10);
        tmp.event = event + " (+" + days + " �.)";
        delete[]days;
        //���������
        while (tmp.day > MonthDays(tmp.month, tmp.year))
        {
            tmp.day -= MonthDays(tmp.month, tmp.year);
            tmp.month++;
            if (tmp.month == 13)
            {
                tmp.month = 1;
                tmp.year++;
            }
        }
        return tmp;
    }
    Date operator- (const int& otherday)
    {
        Date tmp;
        tmp.year = year;
        tmp.month = month;
        char* days = new char[11];
        _itoa(otherday, days, 10);
        tmp.event = event + " (-" + days + " �.)";
        delete[]days;
        //���������
        if (day > otherday)
        {
            tmp.day = day - otherday;
            return tmp;
        }
        if (day == otherday)
        {
            tmp.month--;
            if (tmp.month == 0)
                tmp.month = 12;
            tmp.day = MonthDays(tmp.month, tmp.year);
            return tmp;
        }
        if (day < otherday)
        {
            tmp.month--;
            if (tmp.month == 0)
            {
                tmp.month = 12;
                tmp.year--;
            }
            tmp.day = otherday - day;
            while (tmp.day >= MonthDays(tmp.month, tmp.year))
            {
                tmp.day -= MonthDays(tmp.month, tmp.year);
                tmp.month--;
                if (tmp.month == 0)
                {
                    tmp.month = 12;
                    tmp.year--;
                }
            }
            tmp.day = MonthDays(tmp.month, tmp.year) - tmp.day;
        }
        system("pause");
        return tmp;
    }
    //����������
    ~Date()
    {
        //cout << "�������� ����������: " << this << endl;
    }
};

int proverka(int a, int b)
{
    int vibor = -1;
    while ((vibor < a) || (vibor > b))
    {
        cin >> vibor;
        if ((vibor < a) || (vibor > b))
        {
            cout << "������� �������� �����. ���������� ������ �����." << endl;
            while (getchar() != '\n');
            cin.clear();
        }
    }
    return vibor;
}

Date CreateNewDate()
{
    Date tmpDate;
    string tmpStr; //��� ����� ����������
    int tmpdays;
    cout << "\n ������� ��� (>=1): ";
    tmpDate.SetYear(proverka(1, INT_MAX));
    cout << "\n ������� ����� (�� 1 �� 12): ";
    tmpDate.SetMonth(proverka(1, 12));
    tmpdays = MonthDays(tmpDate.GetMonth(), tmpDate.GetYear());
    cout << "\n ������� ���� (�� 1 �� " << tmpdays << "): ";
    tmpDate.SetDay(proverka(1, tmpdays));
    cout << "\n ������� �������: ";
    while (getchar() != '\n');
    cin.clear();
    getline(cin, tmpStr);
    tmpDate.SetEvent(tmpStr);
    return tmpDate;
}

int SelectedEvent(int counter, Date* arr)
{
    int tmpnum = -1;
    if (counter == 0)
    {
        cout << "\n � ���������, � ��� ��� ������������� �������.\n" << endl;
        return -1;
    }
    cout << "\n �������� �������: " << endl;
    for (int i = 0; i < counter; i++)
        cout << i + 1 << ") " << arr[i].GetEvent() << endl;    
    cout << "\n �������� ������ ��� �������: " << endl;
    tmpnum = proverka(1, counter);
    tmpnum--;
    system("cls");
    cout << "\n ��������� �������: " << tmpnum + 1 << ") " << arr[tmpnum].GetEvent() << endl;
    return tmpnum;
}

Date* RecreateArr(Date* arr, int& size, int counter)
{
    Date* tmparr = new Date[counter];
    for (int i = 0; i < counter; i++)
        tmparr[i] = arr[i];
    size *= 2;
    delete[]arr;
    arr = nullptr;
    arr = new Date[size];
    for (int i = 0; i < counter; i++)
        arr[i] = tmparr[i];
    delete[]tmparr;
    tmparr = nullptr;
    return arr;
}

Date* ExistDate(Date* arr, int& counter)
{
    if (arr[counter - 1].GetYear() <= 0)
    {
        cout << "\n � ���������, ���� ���������� ������� �������� ���������������� ��������.\n ��������� ������� ������ �������." << endl;
        Date tmp;
        arr[counter - 1] = tmp;
        counter--;
        return arr;
    }
    for (int i = 0; i < counter - 1; i++)
        if (arr[counter-1] == arr[i])
        {
            cout << "\n � ���������, ���� ���������� ������� ������� � ����� �� ������������ ���.\n ��������� ������� ������ �������." << endl;
            Date tmp;
            arr[counter - 1] = tmp;
            counter--;
            return arr;
        }
    return arr;
}

void rezhim3(Date* arr, int& counter)
{
    int tmpnum = -1;
    Date tmpDate;
    int tmpdays;
    cout << "\n �� ������� �������� \n\t\"��������� ������� ����� �������� ����� � ����� ������� (� ����)\".\n\n ������� ����.\n\n ������� ��� (>=1): " << endl;
    cout << "";
    tmpDate.SetYear(proverka(1, INT_MAX));
    cout << "\n ������� ����� (�� 1 �� 12): ";
    tmpDate.SetMonth(proverka(1, 12));
    tmpdays = MonthDays(tmpDate.GetMonth(), tmpDate.GetYear());
    cout << "\n ������� ���� (�� 1 �� " << tmpdays << "): ";
    tmpDate.SetDay(proverka(1, tmpdays));
    cout << "\n ������ �������� ������ ������� " << endl;
    tmpnum = SelectedEvent(counter, arr);
    cout << "\n �������� ����: ";
    tmpDate.PrintDate();
    cout << "\n ������� ����� ����� ������� � ����� �����: " << arr[tmpnum].DateDifference(tmpDate) << " �." << endl << endl;
}

void rezhim4(Date* arr, int& counter)
{
    int tmpnum = -1;
    int vibor = -1;
    int tmpdays = -1;
    cout << "\n �� ������� �������� \n\t\"������������ ����� �������, ������� ��������� ������������\n\t������� �� �������� �������� � ������� ��� � ������� �������\"." << endl;
    tmpnum = SelectedEvent(counter, arr);
    cout << "\n �� ������� ���� �� ������ ����������� �������? (>=1)" << endl;
    tmpdays = proverka(1, INT_MAX);
    cout << "\n � ����� ������� �� ������ ����������� ��������� �������?\n\t1) � ������� �������\n\t2) � ������� �������" << endl;
    vibor = proverka(1,2);
    if (vibor == 1)
        arr[counter++] = arr[tmpnum] + tmpdays;
    if (vibor == 2)
        arr[counter++] = arr[tmpnum] - tmpdays;
    system("cls");
    cout << "\n �� ������������ ������� \"" << arr[counter-1].GetEvent() << "\"\n ����� �������: " << counter << endl << endl;
}

bool menu()
{
    int tmpnum = -1;
    static int counter = 0;
    static int size = MAX_EVENTS;
    static Date* arr = new Date[size]; //��� �������� �������
    int vibor = -1;
    cout << "\n ������ �� ���������� � ����. ��������, ��� ����� ������� :\n\t(1) ���������� ������� \n\t(2) ������ ���� ���������� ������� \n\t(3) ��������� ������� ����� �������� ����� � ����� ������� \n\t(4) ������������ ����� �������, ������� ��������� ������������\n\t������� �� �������� �������� � ������� ��� � ������� �������\n\t(0) ����� �� ���������" << endl;
    vibor = proverka(0,4);
    if ((counter == 0) && ((vibor == 2) || (vibor == 3) || (vibor == 4)))
    {
        cout << "\n ��� ������ ������ (" << vibor << ") ��������� ���� �� ���� �������.\n � ���������, � ��� ��� ������������� �������.\n" << endl;
        system("pause");
        system("cls");
        return true;
    }
    system("cls");
    switch (vibor)
    {
    case 1:
        cout << "\n �� ������� �������� \n\t\"���������� �������\"." << endl;
        arr[counter++] = CreateNewDate();
        break;
    case 2:
        cout << "\n �� ������� �������� \n\t\"������ ���� ���������� �������\"." << endl;;
        tmpnum = SelectedEvent(counter, arr);
        cout << "\n ���� ���������� �������: ";
        arr[tmpnum].PrintDate();
        break; 
    case 3:
        // 3) ��������� ������� ����� �������� ����� � ����� ������� (� ����), 
        rezhim3(arr, counter);
        break;
    case 4:
        // 4) ������������ ����� �������, ������� ��������� ������������ ������� �� �������� ��������(� ����) � ������� � � ������� �������.
        rezhim4(arr, counter);
        break;
    case 0:
        delete[]arr;
        arr = nullptr;
        return false;
        break; 
    default:
        cout << "�������������� ������." << endl;
        delete[]arr;
        arr = nullptr;
        return false;
        break;
    }
    if (counter == size)
        arr = RecreateArr(arr, size, counter);
    ExistDate(arr, counter);
    system("pause");
    system("cls");
    return true;
}

void main()
{
    setlocale(LC_ALL, "Ru");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    cout << "\n ��������� �������!" << endl;
    while (menu()) {}
    system("pause");
}