
#include "all.h"

bool menu()
{
    static Tabulator tab;
    int vibor = -1;
    cout << "\n ������ �� ���������� � ����. ��������, ��� ����� �������:\n\t(1) ������ ������� �������\n\t(2) ������ ������� ����� ����� �������������\n\t(3) ������ ������� ����� ����� �������������\n\t(4) ������ ������� �������������\n\t(5) ������ ������� �������������\n\t(6) ��������� ������������� �������\n\t    � ������ ���������� �������������\n\t(7) ��������� ������������� �������\n\t    � ��������� ��������� ������������� � ����\n\t(0) ����� �� ���������" << endl;
    vibor = proverka(0, 7);
    system("cls");
    switch (vibor)
    {
    case 1:
        rezhim1(tab);
        break;
    case 2:
        rezhim2(tab);
        break;
    case 3:
        rezhim3(tab);
        break;
    case 4:
        rezhim4(tab);
        break;
    case 5:
        rezhim5(tab);
        break;
    case 6:
        rezhim6(tab);
        break;
    case 7:
        rezhim7(tab);
        break;
    case 0:
        system("cls");
        return false;
    default:
        cout << "�������������� ������." << endl;
        return false;
    }
    system("pause");
    system("cls");
    return true;
}

void rezhim1(Tabulator& tab)
{
    cout << "\n �� ������� �������� \"������ ������� �������\"\n\n �������� ��������� �������:" << endl << endl;
    string NameOfFunc[NUMOFFUNC] = { "x", "�����", "�������", "�������", "���������", "��������", "����������", "����������", "������������", "��������������� �����", "��������������� �������", "��������������� �������", "��������������� ���������", "���������", "�����������", "�����������", "�������������", "x � ��������", "x � ����", "���������� ������ �� x", "���������� ������ �� x", "2 � ������� x", "e � ������� x ", "10 � ������� x", "�������� ��������", "����������� ��������", "���������� ��������", "������� ����� �����", "����� ����� �����", "������" };
    for (int i = 1; i < NUMOFFUNC; i++)
    {
        cout << " " << i << ") " << NameOfFunc[i];
        if ((i==4)||(i==8)||(i==12)||(i==16)||(i==20)||(i==23)||(i==26)||(i==29))
            cout << endl << endl;
    }
    cout << " �������� ������ �������: ";
    int tmpnum = proverka(1, NUMOFFUNC);
    tab.SetFunc(tmpnum);
    cout << "�� ������� ������ ������� �������!" << endl;
}

void rezhim2(Tabulator& tab)
{
    int tmpnum = -1;
    cout << "\n �� ������� �������� \"������ ������� ����� ����� �������������\"\n ������� ������ ���������� ����� ������������� (>=2): " << endl;
    tmpnum = proverka(2, INT_MAX);
    tab.SetPoints(tmpnum);
    cout << "\n �� ������� ������ ����� ����� �������������!\n\n";
}

void rezhim3(Tabulator& tab)
{
    cout << "\n �� ������� �������� \"������ ������� ����� ����� �������������\"\n �������� ����� �����: " << tab.GetPoints() << endl;
}

void rezhim4(Tabulator& tab)
{
    double tmp;
    cout << "\n �� ������� �������� \"������ ������� �������������\"\n\n ���� \".\" ������������ � �������� ����������� ��� ������� �������� \n\n ������� �������� ����� ������� �������: ";
    cin >> tmp;
    tab.SetLeftBound(tmp);
    tab.SetRightBound(tmp - 1);
    while (tab.GetLeftBound() > tab.GetRightBound())
    {
        cout << "\n ������� �������� ������ ������� �������: ";
        cleaner();
        cin >> tmp;
        tab.SetRightBound(tmp);
    }
}

void rezhim5(Tabulator& tab)
{
    cout << "\n �� ������� �������� \"������ ������� �������������\"\n �������� ������� �������������: �� " << tab.GetLeftBound() << " �� " << tab.GetRightBound() << endl;
}

void rezhim6(Tabulator& tab)
{
    cout << "\n �� ������� �������� \"��������� ������������� �������\n\t\t      � ������ ���������� �������������\"" << endl;
    double** temp;
    Function* func = tab.GetFunc();
    temp = tab.TabFunc(func);
    cout << endl;
    for (int i = 0; i < tab.GetPoints(); i++)
        cout << " x = " << temp[i][0] << " ; y = " << temp[i][1] << endl;
    for (int i = 0; i < 2; i++)
        delete[]temp[i];
    delete[] temp;
}

void rezhim7(Tabulator& tab)
{
    cout << "\n �� ������� �������� \"��������� ������������� �������\n\t    � ��������� ��������� ������������� � ����\"" << endl;
    char* tmpstr = new char[MAX_SYMB];
    time_t seconds = time(NULL);
    strftime(tmpstr, MAX_SYMB, "tabfunction (%H.%M.%S).txt", localtime(&seconds)); //%H - ����, %M - ������, %S - �������
    Function* func = tab.GetFunc();
    ofstream fout;
    fout.open(tmpstr);
    if (!fout.is_open())
        cout << "\n ������ �������� �����!\n\n";
    else
    {
        double** temp = tab.TabFunc(func);
        fout << endl;
        for (int i = 0; i < tab.GetPoints(); i++)
            fout << " x = " << temp[i][0] << " ; y = " << temp[i][1] << endl;
        for (int i = 0; i < 2; i++)
            delete[]temp[i];
        delete[] temp;
    }
    fout.close();
    cout << "\n ������������� ������� ������ �������!\n ������ ���� ��������� � ����\n \"" << tmpstr << "\",\n ����������� � ����� � ����������.\n\n";
    delete[]tmpstr;
    tmpstr = nullptr;

}
