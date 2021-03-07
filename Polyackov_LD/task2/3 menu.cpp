
#include "all.h"

bool menu()
{
    int tmpnum = -1;
    static int counter = 0;
    static int size = MAX_EVENTS;
    static Date* arr = new Date[size]; //��� �������� �������
    int vibor = -1;
    cout << "\n ������ �� ���������� � ����. ��������, ��� ����� ������� :\n\t(1) ���������� ������� \n\t(2) ������ ���� ���������� ������� \n\t(3) ��������� ������� ����� �������� ����� � ����� ������� \n\t(4) ������������ ����� �������, ������� ��������� ������������\n\t������� �� �������� �������� � ������� ��� � ������� �������\n\t(0) ����� �� ���������" << endl;
    vibor = proverka(0, 4);
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
        system("cls");
        cout << "\n �� ������������ ������� \"" << arr[counter - 1].GetEvent() << "\"\n ����� �������: " << counter << endl << endl;
        break;
    case 2:
        cout << "\n �� ������� �������� \n\t\"������ ���� ���������� �������\"." << endl;;
        tmpnum = SelectedEvent(counter, arr);
        cout << "\n ���� ���������� �������: ";
        arr[tmpnum].PrintDate();
        cout << endl;
        break;
    case 3:
        // 3) ��������� ������� ����� �������� ����� � ����� ������� (� ����), 
        rezhim3(arr, counter);
        break;
    case 4:
        // 4) ������������ ����� �������, ������� ��������� ������������ ������� �� �������� ��������(� ����) � ������� � � ������� �������.
        // ����� ������� ���� ������� ��������� - �������� ������, ����� � � ���������� ������������
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
    vibor = proverka(1, 2);
    if (vibor == 1)
        arr[counter++] = arr[tmpnum] + tmpdays;
    if (vibor == 2)
        arr[counter++] = arr[tmpnum] - tmpdays;
    system("cls");
    cout << "\n �� ������������ ������� \"" << arr[counter - 1].GetEvent() << "\"\n ����� �������: " << counter << endl << endl;
}
