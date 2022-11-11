#define _CRT_SECURE_NO_WARNINGS 
#include <string>
#include <windows.h>                			//GetAsyncKeyState所需头文件
#include <iostream>
#include <graphics.h>


#pragma comment (lib, "Winmm.lib")//导入Winmm.lib库
//using namespace std;


int main()
{
	// 初始化图形窗口
	initgraph(1024, 720);
	MOUSEMSG m;
	loadimage(0, _T("abc1.jpg"));
	TCHAR c[]=_T("功德值：");
	
	TCHAR d = _T('0');
	TCHAR s[] = _T("功德+1");
	int x = 800;
	int y = 300;
	loadimage(0, _T("abc1.jpg"), 1024, 720);
	settextstyle(32, 0, s);

	while (1)
	{
		m = GetMouseMsg();

		if (m.mkLButton)
		{
			outtextxy(32, 50, d);
			outtextxy(32, 24, c);
			if (y <= 0)
			{
				y = 240;
			}
			PlaySound(_T("木鱼.wav"), NULL, NULL);
			outtextxy(x, y-=10, s);
			Sleep(300);
			cleardevice();
			//Resize(NULL,480,320);
			loadimage(0, _T("abc1.jpg"),1024,720);

			outtextxy(32,50, d);
			outtextxy(32, 24, c);
			d++;
			FlushMouseMsgBuffer();
			if (m.mkRButton)
			{
				break;
			}
		}
		
		
	}
	system("pause");

	// 关闭图形窗口
	closegraph();
	return 0;
}


