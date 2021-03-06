// hidewindow.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <string>
#include <stdint.h>
#include <iostream>
#include <cstdio>

using namespace std;
int main(int argc, char *argv[])
{       
    char *pstrBuf[256];
    int nBuf = 0; 
    char* pstrToken;

	if (argc != 3) 
    {
		MessageBoxA(NULL, "参数不对，需要输入窗口类名", "Error", MB_OK);
	}

	else
    {
        pstrToken = strtok(argv[2], ",");
        while(pstrToken != NULL)
        {
            pstrBuf[nBuf++] = pstrToken; 
            pstrToken = strtok(NULL,  ",");
        }
        while(nBuf--)
        {
	        HWND a=::FindWindowA(pstrBuf[nBuf], NULL);
            std::string arg1str(argv[1]);
	        if (a == NULL)
	        {
		        MessageBoxA(NULL,"无法找到窗口句柄","Error", MB_OK);
		        return 0;
	        }
            else if(arg1str.compare("-h") == 0) 
            {
            ::ShowWindow(a,SW_HIDE);
        
            }
            else if (arg1str.compare("-t") == 0)
            {
            ::SetWindowPos(a,HWND_NOTOPMOST,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
            }
            else
            {
                MessageBoxA(NULL,"错误指令参数","Error", MB_OK);
		        return 0;
            }
        }
	    
    }
    return 0;
}

