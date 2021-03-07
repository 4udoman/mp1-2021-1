
#include "all.h"

int MonthDays(int month, int year)
{
    int Days[13] = { 29,31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((month == 2) && ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))))
        return Days[0];
    return Days[month];
}

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
        cout << "\n � ���������, ���� ���������� ������� �������� ���������������� ��������.\n ��������� ������� ������ �������.\n" << endl;
        Date tmp;
        arr[counter - 1] = tmp;
        counter--;
        return arr;
    }
    for (int i = 0; i < counter - 1; i++)
        if (arr[counter - 1] == arr[i])
        {
            cout << "\n � ���������, ���� ���������� ������� ������� � ����� �� ������������ ���.\n ��������� ������� ������ �������.\n" << endl;
            Date tmp;
            arr[counter - 1] = tmp;
            counter--;
            return arr;
        }
    return arr;
}
