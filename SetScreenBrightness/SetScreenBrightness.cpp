// SetScreenBrightness.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int brightness = 1;
	if (argc < 2){
		wcout << "�������� 0-200��";
		cin >> brightness;
	} else {
		char ** argn = allocate_argn(argc, argv);
		brightness = atoi((char*)argn[1]);
	}
	if (brightness < 0){
		brightness = 0;
	}
	if (brightness > 200){
		brightness = 200;
	}
	cout << "�������ȣ�" << brightness << endl;
	int err = SetBrightness(brightness);

	return 0;
}

