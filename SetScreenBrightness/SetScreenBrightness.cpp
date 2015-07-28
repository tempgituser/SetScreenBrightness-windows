// SetScreenBrightness.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int brightness = 1;
	if (argc < 2){
		wcout << "输入亮度 0-200：";
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
	cout << "设置亮度：" << brightness << endl;
	int err = SetBrightness(brightness);

	return 0;
}

