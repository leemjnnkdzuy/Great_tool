#include "lib.h"


void Menu()
{

	clrscr();
	cout << "----------------------------------XIN CHÀO----------------------------------" << endl;
	cout << "----------------------------Tool by LeeMjnnkDzuy----------------------------" << endl;
	cout << "1. Active Windows                                                           " << endl;
	cout << "2. install_SpotyX                                                           " << endl;
	cout << "3.                                                                          " << endl;
	cout << "4.                                                                          " << endl;
}

void Get_Answer(int &option_select)
{
	do
	{
		clrscr();
		Menu();
		cout << "Lựa chọn chức năng : ";
		cin >> option_select;
	} while (option_select < 0 || option_select > 5);

	Sleep(1000);

    switch (option_select) 
    {
    case 1:
        Active_Win();
        break;

    case 2:
		Install_Spotify();
        break;

    case 3:
        ///
        break;

    default:
        ///
        break;
    }
}

