
#include "all.h"

int proverka(int a, int b)
{
    int vibor = INT_MIN;
    while ((vibor < a) || (vibor > b))
    {
        cin >> vibor;
        if ((vibor < a) || (vibor > b))
        {
            cout << "������� �������� �����. ���������� ������ �����." << endl;
            cleaner();
        }
    }
    return vibor;
}

void cleaner()
{
    while (getchar() != '\n');
    cin.clear();
}
