// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ�;
// ���Ǿ���ʹ�õ��������ĵ�;
// �ض�����Ŀ�İ����ļ�;

#pragma once

#define WIN32_LEAN_AND_MEAN		// �� Windows ͷ�ļ����ų�����ʹ�õ���Ϣ;
// Windows ͷ�ļ�;
#include <windows.h>

#include "StringTool.h"
using namespace StringTool;
#include "INI.h"
#include "format.h"

extern TString g_strDirPath;

// TypeX->TypeY ��������ת���ľ���;
#define TypeToInt(tValue)				(int(tValue))
#define TypeToFloat(tValue)				(float(tValue))
#define TypeToDouble(tValue)			(double(tValue))