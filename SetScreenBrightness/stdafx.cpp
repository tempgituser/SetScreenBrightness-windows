// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// SetScreenBrightness.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO:  �� STDAFX.H ��
// �����κ�����ĸ���ͷ�ļ����������ڴ��ļ�������

int SetBrightness(int brightness)
{
	void * lpGamma = NULL;
	int iArrayValue;
	WORD gMap[3][256] = { 0 };
	lpGamma = &gMap;
	HDC hdc = ::GetDC(NULL);
	if (NULL == hdc)
		return -1;
	for (int i = 0; i < 256; i++)
	{
		iArrayValue = i * (brightness + 128);
		if (iArrayValue > 65535)
			iArrayValue = 65535;
		gMap[0][i] =
			gMap[1][i] =
			gMap[2][i] = (WORD)iArrayValue;
	}
	if (FALSE == SetDeviceGammaRamp(hdc, lpGamma))
		return -2;
	return 0;
}
int wstrlen(_TCHAR * wstr)
{
	int l_idx = 0;
	while (((char*)wstr)[l_idx] != 0) l_idx += 2;
	return l_idx;
}
char * wstrdup(_TCHAR * wSrc)
{
	int l_idx = 0;
	int l_len = wstrlen(wSrc);
	char * l_nstr = (char*)malloc(l_len);
	if (l_nstr) {
		do {
			l_nstr[l_idx] = (char)wSrc[l_idx];
			l_idx++;
		} while ((char)wSrc[l_idx] != 0);
	}
	l_nstr[l_idx] = 0;
	return l_nstr;
}
char ** allocate_argn(int argc, _TCHAR* argv[])
{
	char ** l_argn = (char **)malloc(argc * sizeof(char*));
	for (int idx = 0; idx<argc; idx++) {
		l_argn[idx] = wstrdup(argv[idx]);
	}
	return l_argn;
}