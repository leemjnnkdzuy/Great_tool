#include "lib.h"


void Menu()
{

	clrscr();
	cout << "----------------------------------XIN CHÀO----------------------------------" << endl;
	cout << "----------------------------Tool by LeeMjnnkDzuy----------------------------" << endl;
	cout << "1. Active Windows                                                           " << endl;
	cout << "2.                                                                          " << endl;
	cout << "3.                                                                          " << endl;
	cout << "4.                                                                          " << endl;
}

void Get_Answer(int &option_select)
{
	cout << "Lựa chọn chức năng : ";
	cin >> option_select;
    Sleep(1000);

    switch (option_select) 
    {
    case 1:
        Active_Win();
        break;

    case 2:
        ///
        break;

    case 3:
        ///
        break;

    default:
        ///
        break;
    }
}

