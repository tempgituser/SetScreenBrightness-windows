// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

#include <windows.h>
#include <iostream>
int SetBrightness(int brightness);
int wstrlen(_TCHAR * wstr);
char * wstrdup(_TCHAR * wSrc);
char ** allocate_argn(int argc, _TCHAR* argv[]);