#include "lib.h"

void Active_Win()
{
	system("MODE CON COLS=45 LINES=19");


Start:
	system("cls");


	cout << "Chọn phiên bản Windows 10 bạn muốn kích hoạt : " << endl;
	cout << "1.  Home" << endl;
	cout << "2.  Home N" << endl;
	cout << "3.  Home Single Language" << endl;
	cout << "4.  Home Country Specific" << endl;
	cout << "5.  Professional" << endl;
	cout << "6.  Professional N" << endl;
	cout << "7.  Education" << endl;
	cout << "8.  Education N" << endl;
	cout << "9.  Enterprise" << endl;
	cout << "10. Enterprise N" << endl;

	int WindowsKey;
	cout << "Windows 10 : ";
	cin >> WindowsKey;

	if (WindowsKey < 0 || WindowsKey > 10) 
		goto Start;


	string WindowsKeyChoice, WindowsName;
	string Home = "TX9XD-98N7V-6WMQ6-BX7FG-H8Q99";
	string HomeN = "3KHY7-WNT83-DGQKR-F7HPR-844BM";
	string HomeSL = "7HNRX-D7KGG-3K4RQ-4WPJ4-YTDFH";
	string HomeCS = "PVMJN-6DFY6-9CCP6-7BKTT-D3WVR";
	string Pro = "W269N-WFGWX-YVC9B-4J6C9-T83GX";
	string ProN = "MH37W-N47XK-V7XM9-C7227-GCQG9";
	string Edu = "NW6C2-QMPVW-D7KKK-3GKT6-VCFB2";
	string EduN = "2WH4N-8QGBV-H22JP-CT43Q-MDWWJ";
	string Ent = "NPPR9-FWDCX-D2C8J-H872K-2YT43";
	string EntN = "DPH2V-TTNVB-4X9Q3-TJR4H-KHJW4";

	switch (WindowsKey) 
	{
		case 1: 
			WindowsKeyChoice = Home; WindowsName = "Home"; 
			break;
		case 2: 
			WindowsKeyChoice = HomeN; WindowsName = "Home N"; 
			break;
		case 3: 
			WindowsKeyChoice = HomeSL; WindowsName = "Home SL"; 
			break;
		case 4: 
			WindowsKeyChoice = HomeCS; WindowsName = "Home CS"; 
			break;
		case 5: 
			WindowsKeyChoice = Pro; WindowsName = "Pro"; 
			break;
		case 6: 
			WindowsKeyChoice = ProN; WindowsName = "Pro N"; 
			break;
		case 7: 
			WindowsKeyChoice = Edu; WindowsName = "Edu"; 
			break;
		case 8: 
			WindowsKeyChoice = EduN; WindowsName = "Edu N"; 
			break;
		case 9: 
			WindowsKeyChoice = Ent; WindowsName = "Ent"; 
			break;
		case 10: 
			WindowsKeyChoice = EntN; WindowsName = "Ent N"; 
			break;
		default: exit(1); break;
	}

	
	clrscr();
	cout << "Đang kích hoạt Windows 10 " << WindowsName << endl << endl;

	cout << "Đang nhập khóa vào hệ thống" << endl << endl;
	system(("slmgr /ipk" + WindowsKeyChoice).c_str());

	
	cout << "Đang kết nối với máy chủ kích hoạt" << endl << endl;
	system("runas /user:Administrator@domain slmgr /skms kms8.msguides.com");

	
	cout << "Bắt đầu kích hoạt Windows" << endl;
	system("slmgr /ato");

	
	clrscr();
	cout << "Kích hoạt thành công Windows 10 " << WindowsName << "!" << endl;
}