#include <iostream>
using namespace std;
#include "Thuvien.h"
#include "Menu.h"

void ChayChuongTrinh()
{
    int menu, soMenu = 5;
    int n = 0;
    do
    {
        menu = ChonMenu(soMenu);
        XuLyMenu(menu, n);
        system("PAUSE");
    } while (menu > 0);
}

int main()
{
    ChayChuongTrinh();
    return 0;
}
