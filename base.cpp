                                  /*参数传递时的内存分配与graphics.h不兼容，改用存储到文件进行二级传递*/
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<easyx.h>
#include<Windows.h>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<io.h>
#include <direct.h>
#include<locale.h>

//全局定义
int Done = 0;//黑夜模式判断
int Max = 0;//欢迎提示判断
int Nt = 0;//新增事件计数
int state[16];//记录完成状态

int Q = 0;//均为绘图时的变量
int W = 0;
int E = 0;
int R = 0;
int T = 0;
int Y = 0;
int N = 0;
int M = 0;
int Info = 0;

FILE* fp;//文件操作（Myaccount.txt)  用户密码
FILE* fp1;//文件操作（Data.txt)      用户数据
FILE* fp2;//文件操作（Name.txt)      用户姓名
FILE* fp3;//文件操作（State.txt)     完成状态

wchar_t s[128];//宽字符集下的用户输入数据
wchar_t e[128];                                  /* 关于宽窄字符集参见 https://blog.csdn.net/jaj2003/article/details/109802900 */
wchar_t g[128];

// 创建顺序表
typedef struct Node
{
	
	wchar_t data1[16][128];
	wchar_t data2[16][128];
	wchar_t goal[16][128];
	wchar_t state[16][128];
	
}Sqlist;


//声明                            /*函数声明的作用简而言之就是为了让编译器认识这些自定义函数，不声明的可能会出现编译不通过或者多个页面间无法跳转的问题*/
void DataSave();
void FileCreate(void);
void CreateFolder(void);
void Draw(void);
void Stupage(void);
void Teapage(void);
void Stuname(void);
void Title(void);
void StateSave();
void New();
void Look(void);
void Submit(void);
void Help(void);
void About(void);
void Did(void);
void UND(void);
void InfoGet();
void InfoOut();
int main();

void StateSave()
{
	fp3 = fopen("D:\\TimePlan\\State.txt", "w");
	for (int i = 1; i < 16; i++)
	{
		fprintf(fp3, "%d\n", state[i]);
	}
	fclose(fp3);
}

void InfoGet()                 /*获取用户输入的内容*/
{
	InputBox(s, 128, L"请输入起始时间");
	outtextxy(40, Info, s);
	InputBox(e, 128, L"请输入结束时间");
	outtextxy(107, Info, e);
	InputBox(g, 128, L"请输入内容");
	outtextxy(233, Info, g);
}

void DataSave()                /*将用户输入的数据写入到Data.txt*/
{
	fputws(s, fp1); fputws(L"\n", fp1);
	fputws(e, fp1); fputws(L"\n", fp1);
	fputws(g, fp1); fputws(L"\n", fp1);
}

//新建日程
void New()
{
	setlocale(LC_ALL, "");            /*对于宽字符来说，无论输出到哪里，都要设置unicode区域，否则会导致运行时编码转换失败，会发现输出乱码*/
	settextcolor(WHITE);
	settextstyle(30, 0, L"楷体");
	fp1 = fopen("D:\\TimePlan\\Data.txt", "w");
	fclose(fp1);
	fp1 = fopen("D:\\TimePlan\\Data.txt", "a+");
	if (Nt == 0) 
	{
		Info = 110;InfoGet();DataSave();
	}
	if (Nt == 1)
	{
		Info = 160;InfoGet();DataSave();
	}
	if (Nt == 2)
	{
		Info = 210;InfoGet();DataSave();
	}
	if (Nt == 3)
	{
		Info = 260; InfoGet(); DataSave();
	}
	if (Nt == 4)
	{
		Info = 310; InfoGet(); DataSave();
	}
	if (Nt == 5)
	{
		Info = 360; InfoGet(); DataSave();
	}
	if (Nt == 6)
	{
		Info = 410; InfoGet(); DataSave();
	}
	if (Nt == 7)
	{
		Info = 460; InfoGet(); DataSave();
	}
	if (Nt == 8)
	{
		Info = 510; InfoGet(); DataSave();
	}
	if (Nt == 9)
	{
		Info = 560; InfoGet(); DataSave();
	}
	if (Nt == 10)
	{
		Info = 610; InfoGet(); DataSave();
	}
	if (Nt == 11)
	{
		Info = 660; InfoGet(); DataSave();
	}
	if (Nt == 12)
	{
		Info = 710; InfoGet(); DataSave();
	}
	if (Nt == 13)
	{
		Info = 760; InfoGet(); DataSave();
	}
	if (Nt == 14)
	{
		Info = 810; InfoGet(); DataSave();
	}
	if (Nt > 14)
	{
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"15个日程都不够你写呀？那我也无能为力了。", L"提示", MB_OK);
	}
	
}

//查看日程
void Look()
{
	if (Nt == 0)
	{
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"请先新建日程！", L"提示", MB_OK);
	}
	else
	{
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"您的日程看起来一切正常。", L"提示", MB_OK);
	}
}

//提交日程
void Submit()
{
	if (Nt == 0)
	{
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"请先新建日程！", L"提示", MB_OK);
	}
	else
	{   
		StateSave();
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"您的日程已经提交，请等待管理员审核。", L"提示", MB_OK);
	}
	
}

//帮助
void Help()
{
	ShellExecuteA(0, "open", "https://www.baidu.com/", 0, 0, 1);
}
//关于
void About()
{
	HWND hwnd = GetHWnd();
	MessageBox(hwnd, L"GaolNiu开发小组版权所有！最后编辑于2022年5月21日。", L"关于", MB_OK);
}

//用户类型的判断
void userpage()
{
	HWND hwnd = GetHWnd();
	int wet = MessageBox(hwnd, L"学生端登录请点击确定，教师端登录请点击取消。", L"提示", MB_OKCANCEL);
	if (wet == IDOK)
	{
		Stupage();
	}
	if(wet == IDCANCEL)
	{
	    
		Teapage();
	}
}

//标题
void Title()
{
	wchar_t str[] = { L"今天的日程" };
		settextcolor(WHITE);
		settextstyle(30, 0, L"楷体");
		outtextxy(640, 10, str);
}
//绘制学生页面
void Draw(void)
{
	fillroundrect(10, 70, 150, 100, 10, 10);
	outtextxy(46, 78, L"时间（小时）");
	roundrect(10, 110, 150, 140, 10, 10);
	roundrect(10, 160, 150, 190, 10, 10);
	roundrect(10, 210, 150, 240, 10, 10);
	roundrect(10, 260, 150, 290, 10, 10);
	roundrect(10, 310, 150, 340, 10, 10);
	roundrect(10, 360, 150, 390, 10, 10);
	roundrect(10, 410, 150, 440, 10, 10);
	roundrect(10, 460, 150, 490, 10, 10);
	roundrect(10, 510, 150, 540, 10, 10);
	roundrect(10, 560, 150, 590, 10, 10);
	roundrect(10, 610, 150, 640, 10, 10);
	roundrect(10, 660, 150, 690, 10, 10);
	roundrect(10, 710, 150, 740, 10, 10);
	roundrect(10, 760, 150, 790, 10, 10);
	roundrect(10, 810, 150, 840, 10, 10);
	settextcolor(RGB(0,245,255));
	outtextxy(75, 120, L"到");
	outtextxy(75, 170, L"到");
	outtextxy(75, 220, L"到");
	outtextxy(75, 270, L"到");
	outtextxy(75, 320, L"到");
	outtextxy(75, 370, L"到");
	outtextxy(75, 420, L"到");
	outtextxy(75, 470, L"到");
	outtextxy(75, 520, L"到");
	outtextxy(75, 570, L"到");
	outtextxy(75, 620, L"到");
	outtextxy(75, 670, L"到");
	outtextxy(75, 720, L"到");
	outtextxy(75, 770, L"到");
	outtextxy(75, 820, L"到");
	fillroundrect(230, 70, 930, 100, 10, 10);
	settextcolor(BLACK);
	outtextxy(545, 78, L"目标");
	roundrect(230, 110, 930, 140, 10, 10);
	roundrect(230, 160, 930, 190, 10, 10);
	roundrect(230, 210, 930, 240, 10, 10);
	roundrect(230, 260, 930, 290, 10, 10);
	roundrect(230, 310, 930, 340, 10, 10);
	roundrect(230, 360, 930, 390, 10, 10);
	roundrect(230, 410, 930, 440, 10, 10);
	roundrect(230, 460, 930, 490, 10, 10);
	roundrect(230, 510, 930, 540, 10, 10);
	roundrect(230, 560, 930, 590, 10, 10);
	roundrect(230, 610, 930, 640, 10, 10);
	roundrect(230, 660, 930, 690, 10, 10);
	roundrect(230, 710, 930, 740, 10, 10);
	roundrect(230, 760, 930, 790, 10, 10);
	roundrect(230, 810, 930, 840, 10, 10);

	fillroundrect(1000, 70, 1200, 100, 10, 10);
	outtextxy(1065, 78, L"完成状态");
	roundrect(1000, 110, 1090, 140, 10, 10);
	roundrect(1110, 110, 1200, 140, 10, 10);
	roundrect(1000, 160, 1090, 190, 10, 10);
	roundrect(1110, 160, 1200, 190, 10, 10);
	roundrect(1000, 210, 1090, 240, 10, 10);
	roundrect(1110, 210, 1200, 240, 10, 10);
	roundrect(1000, 260, 1090, 290, 10, 10);
	roundrect(1110, 260, 1200, 290, 10, 10);
	roundrect(1000, 310, 1090, 340, 10, 10);
	roundrect(1110, 310, 1200, 340, 10, 10);
	roundrect(1000, 360, 1090, 390, 10, 10);
	roundrect(1110, 360, 1200, 390, 10, 10);
	roundrect(1000, 410, 1090, 440, 10, 10);
	roundrect(1110, 410, 1200, 440, 10, 10);
	roundrect(1000, 460, 1090, 490, 10, 10);
	roundrect(1110, 460, 1200, 490, 10, 10);
	roundrect(1000, 510, 1090, 540, 10, 10);
	roundrect(1110, 510, 1200, 540, 10, 10);
	roundrect(1000, 560, 1090, 590, 10, 10);
	roundrect(1110, 560, 1200, 590, 10, 10);
	roundrect(1000, 610, 1090, 640, 10, 10);
	roundrect(1110, 610, 1200, 640, 10, 10);
	roundrect(1000, 660, 1090, 690, 10, 10);
	roundrect(1110, 660, 1200, 690, 10, 10);
	roundrect(1000, 710, 1090, 740, 10, 10);
	roundrect(1110, 710, 1200, 740, 10, 10);
	roundrect(1000, 760, 1090, 790, 10, 10);
	roundrect(1110, 760, 1200, 790, 10, 10);
	roundrect(1000, 810, 1090, 840, 10, 10);
	roundrect(1110, 810, 1200, 840, 10, 10);
	outtextxy(1040, 118, L"是");
	outtextxy(1148, 118, L"否");
	outtextxy(1040, 168, L"是");
	outtextxy(1148, 168, L"否");
	outtextxy(1040, 218, L"是");
	outtextxy(1148, 218, L"否");
	outtextxy(1040, 268, L"是");
	outtextxy(1148, 268, L"否");
	outtextxy(1040, 318, L"是");
	outtextxy(1148, 318, L"否");
	outtextxy(1040, 368, L"是");
	outtextxy(1148, 368, L"否");
	outtextxy(1040, 418, L"是");
	outtextxy(1148, 418, L"否");
	outtextxy(1040, 468, L"是");
	outtextxy(1148, 468, L"否");
	outtextxy(1040, 518, L"是");
	outtextxy(1148, 518, L"否");
	outtextxy(1040, 568, L"是");
	outtextxy(1148, 568, L"否");
	outtextxy(1040, 618, L"是");
	outtextxy(1148, 618, L"否");
	outtextxy(1040, 668, L"是");
	outtextxy(1148, 668, L"否");
	outtextxy(1040, 718, L"是");
	outtextxy(1148, 718, L"否");
	outtextxy(1040, 768, L"是");
	outtextxy(1148, 768, L"否");
	outtextxy(1040, 818, L"是");
	outtextxy(1148, 818, L"否");
}

//完成封装
void Did()
{
	IMAGE done;//roundrect(1000, 110, 1090, 140, 10, 10);是
	loadimage(&done, L"C:\\Users\\LEGION\\Desktop\\Datas\\done.jpg", 88, 28, true);
	putimage(Q, W, &done);
	IMAGE err;
	loadimage(&err, L"C:\\Users\\LEGION\\Desktop\\Datas\\err.jpg", 88, 28, true);
	putimage(E+1, R+1, &err);
	roundrect(E, R, T, Y, 10, 10);
	settextstyle(18, 0, L"宋体");	
	outtextxy(N, M, L"否");
	
}
//未完成封装
void UND()
{
	IMAGE done;//roundrect(1110, 110, 1200, 140, 10, 10);否
	loadimage(&done, L"C:\\Users\\LEGION\\Desktop\\Datas\\done.jpg", 88, 28, true);
	putimage(Q, W, &done);
	IMAGE err;
	loadimage(&err, L"C:\\Users\\LEGION\\Desktop\\Datas\\err.jpg", 88, 28, true);
	putimage(E+1, R+1, &err);
	roundrect(E, R, T, Y, 10, 10);
	settextstyle(18, 0, L"宋体");
	outtextxy(N, M, L"是");
}

//学生页面
void Stupage(void)
{
	initgraph(1280, 900);
	if (Done % 2 == 0) 
	{
		setbkcolor(RGB(70, 130, 180));
	}
	else
	{
		setbkcolor(RGB(112, 128, 144));
	}
	setbkmode(TRANSPARENT);
	cleardevice();
	settextcolor(BLACK);
	Draw();
	Title();
	Stuname();
	fillroundrect(1200,10,1260,30,10,10);
	settextcolor(BLACK);
	settextstyle(20, 0, L"楷体");
	outtextxy(1208, 11, L"返回");
	
	fillroundrect(10, 10, 110, 30, 10, 10);
	outtextxy(18, 11, L"新建日程");

	fillroundrect(10, 40, 110, 60, 10, 10);
	outtextxy(18, 41, L"查看日程");

	fillroundrect(120, 10, 220, 30, 10, 10);
	outtextxy(128, 11, L"提交日程");

	fillroundrect(230, 10, 330, 30, 10, 10);
	outtextxy(260, 11, L"帮助");

	fillroundrect(340, 10, 440, 30, 10, 10);
	outtextxy(370, 11, L"关于");
	
	ExMessage msg;
	while (1) 
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.x >= 1200 && msg.x <= 1260 && msg.y >= 10 && msg.y <= 30)
			{
				setlinecolor(RED); roundrect(1200, 10, 1260, 30, 10, 10);
			}
			else  setlinecolor(WHITE); roundrect(1200, 10, 1260, 30, 10, 10);
			if (msg.x >= 10 && msg.x <= 110 && msg.y >= 10 && msg.y <= 30)
			{
				setlinecolor(RED); roundrect(10, 10, 110, 30, 10, 10);
			}
			else  setlinecolor(WHITE); roundrect(10, 10, 110, 30, 10, 10);
			if (msg.x >= 10 && msg.x <= 110 && msg.y >= 40 && msg.y <= 60)
			{
				setlinecolor(RED); roundrect(10, 40, 110, 60, 10, 10);
			}
			else  setlinecolor(WHITE); roundrect(10, 40, 110, 60, 10, 10);
			if (msg.x >= 120 && msg.x <= 220 && msg.y >= 10 && msg.y <= 30)
			{
				setlinecolor(RED); roundrect(120, 10, 220, 30, 10, 10);
			}
			else  setlinecolor(WHITE); roundrect(120, 10, 220, 30, 10, 10);
			if (msg.x >= 230 && msg.x <= 330 && msg.y >= 10 && msg.y <= 30)
			{
				setlinecolor(RED); roundrect(230, 10, 330, 30, 10, 10);
			}
			else  setlinecolor(WHITE); roundrect(230, 10, 330, 30, 10, 10);
			if (msg.x >= 340 && msg.x <= 440 && msg.y >= 10 && msg.y <= 30)
			{
				setlinecolor(RED); roundrect(340, 10, 440, 30, 10, 10);
			}
			else  setlinecolor(WHITE); roundrect(340, 10, 440, 30, 10, 10);
			
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1200 && msg.x <= 1260 && msg.y >= 10 && msg.y <= 30)
				{
					main();
				}
				//roundrect(1000, 110, 1090, 140, 10, 10);是                            /*从460到669负责完成状态的选定和保存*/
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 110 && msg.y <= 140)
				{
					Q = 1001; W = 111; E = 1110; R = 110; T = 1200; Y = 140;
					N = 1148; M = 118;
					Did(); state[1] = 1;         /*将完成状态存到state数组里，1代表完成，0代表未完成*/
				}
				//roundrect(1110, 110, 1200, 140, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 110 && msg.y <= 140)
				{
					Q = 1111; W = 111; E = 1000; R = 110; T = 1090; Y = 140;
					N = 1040; M = 118;
					UND(); state[1] = 0;
				}
				//roundrect(1000, 160, 1090, 190, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 160 && msg.y <= 190)
				{
					Q = 1001; W = 161; E = 1110; R = 160; T = 1200; Y = 190;
					N = 1148; M = 168;
					Did(); state[2] = 1;
				}
				//roundrect(1110, 160, 1200, 190, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 160 && msg.y <= 190)
				{
					Q = 1111; W = 161; E = 1000; R = 160; T = 1090; Y = 190;
					N = 1040; M = 168;
					UND(); state[2] = 0;
				}
				//roundrect(1000, 210, 1090, 240, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 210 && msg.y <= 240)
				{
					Q = 1001; W = 211; E = 1110; R = 210; T = 1200; Y = 240;
					N = 1148; M = 218;
					Did(); state[3] = 1;
				}
				//roundrect(1110, 210, 1200, 240, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 210 && msg.y <= 240)
				{
					Q = 1111; W = 211; E = 1000; R = 210; T = 1090; Y = 240;
					N = 1040; M = 218;
					UND(); state[3] = 0;
				}
				//roundrect(1000, 260, 1090, 290, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 260 && msg.y <= 290)
				{
					Q = 1001; W = 261; E = 1110; R = 260; T = 1200; Y = 290;
					N = 1148; M = 268;
					Did(); state[4] = 1;
				}
				//roundrect(1110, 260, 1200, 290, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 260 && msg.y <= 290)
				{
					Q = 1111; W = 261; E = 1000; R = 260; T = 1090; Y = 290;
					N = 1040; M = 268;
					UND(); state[4] = 0;
				}
				//roundrect(1000, 310, 1090, 340, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 310 && msg.y <= 340)
				{
					Q = 1001; W = 311; E = 1110; R = 310; T = 1200; Y = 340;
					N = 1148; M = 318;
					Did(); state[5] = 1;
				}
				//roundrect(1110, 310, 1200, 340, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 310 && msg.y <= 340)
				{
					Q = 1111; W = 311; E = 1000; R = 310; T = 1090; Y = 340;
					N = 1040; M = 318;
					UND(); state[5] = 0;
				}
				//roundrect(1000, 360, 1090, 390, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 360 && msg.y <= 390)
				{
					Q = 1001; W = 361; E = 1110; R = 360; T = 1200; Y = 390;
					N = 1148; M = 368;
					Did(); state[6] = 1;
				}
				//roundrect(1110, 360, 1200, 390, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 360 && msg.y <= 390)
				{
					Q = 1111; W = 361; E = 1000; R = 360; T = 1090; Y = 390;
					N = 1040; M = 368;
					UND(); state[6] = 0;
				}
				//roundrect(1000, 410, 1090, 440, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 410 && msg.y <= 440)
				{
					Q = 1001; W = 411; E = 1110; R = 410; T = 1200; Y = 440;
					N = 1148; M = 418;
					Did(); state[7] = 1;
				}
				//roundrect(1110, 410, 1200, 440, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 410 && msg.y <= 440)
				{
					Q = 1111; W = 411; E = 1000; R = 410; T = 1090; Y = 440;
					N = 1040; M = 418;
					UND(); state[7] = 0;
				} 
				//roundrect(1000, 460, 1090, 490, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 460 && msg.y <= 490)
				{
					Q = 1001; W = 461; E = 1110; R = 460; T = 1200; Y = 490;
					N = 1148; M = 468;
					Did(); state[8] = 1;
				}
				//roundrect(1110, 460, 1200, 490, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 460 && msg.y <= 490)
				{
					Q = 1111; W = 461; E = 1000; R = 460; T = 1090; Y = 490;
					N = 1040; M = 468;
					UND(); state[8] = 0;
				}
				//roundrect(1000, 510, 1090, 540, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 510 && msg.y <= 540)
				{
					Q = 1001; W = 511; E = 1110; R = 510; T = 1200; Y = 540;
					N = 1148; M = 518;
					Did(); state[9] = 1;
				}
				//roundrect(1110, 510, 1200, 540, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 510 && msg.y <= 540)
				{
					Q = 1111; W = 511; E = 1000; R = 510; T = 1090; Y = 540;
					N = 1040; M = 518;
					UND(); state[9] = 0;
				}
				//roundrect(1000, 560, 1090, 590, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 560 && msg.y <= 590)
				{
					Q = 1001; W = 561; E = 1110; R = 560; T = 1200; Y = 590;
					N = 1148; M = 568;
					Did(); state[10] = 1;
				}
				//roundrect(1110, 560, 1200, 590, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 560 && msg.y <= 590)
				{
					Q = 1111; W = 561; E = 1000; R = 560; T = 1090; Y = 590;
					N = 1040; M = 568;
					UND(); state[10] = 0;
				}
				//roundrect(1000, 610, 1090, 640, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 610 && msg.y <= 640)
				{
					Q = 1001; W = 611; E = 1110; R = 610; T = 1200; Y = 640;
					N = 1148; M = 618;
					Did(); state[11] = 1;
				}
				//roundrect(1110, 610, 1200, 640, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 610 && msg.y <= 640)
				{
					Q = 1111; W = 611; E = 1000; R = 610; T = 1090; Y = 640;
					N = 1040; M = 618;
					UND(); state[11] = 0;
				}
				//roundrect(1000, 660, 1090, 690, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 660 && msg.y <= 690)
				{
					Q = 1001; W = 661; E = 1110; R = 660; T = 1200; Y = 690;
					N = 1148; M = 668;
					Did(); state[12] = 1;
				}
				//roundrect(1110, 660, 1200, 690, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 660 && msg.y <= 690)
				{
					Q = 1111; W = 661; E = 1000; R = 660; T = 1090; Y = 690;
					N = 1040; M = 668;
					UND(); state[12] = 0;
				}
				//roundrect(1000, 710, 1090, 740, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 710 && msg.y <= 740)
				{
					Q = 1001; W = 711; E = 1110; R = 710; T = 1200; Y = 740;
					N = 1148; M = 718;
					Did(); state[13] = 1;
				}
				//roundrect(1110, 710, 1200, 740, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 710 && msg.y <= 740)
				{
					Q = 1111; W = 711; E = 1000; R = 710; T = 1090; Y = 740;
					N = 1040; M = 718;
					UND(); state[13] = 0;
				}
				//roundrect(1000, 760, 1090, 790, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 760 && msg.y <= 790)
				{
					Q = 1001; W = 761; E = 1110; R = 760; T = 1200; Y = 790;
					N = 1148; M = 768;
					Did(); state[14] = 1;
				}
				//roundrect(1110, 760, 1200, 790, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 760 && msg.y <= 790)
				{
					Q = 1111; W = 761; E = 1000; R = 760; T = 1090; Y = 790;
					N = 1040; M = 768;
					UND(); state[14] = 0;
				}
				//roundrect(1000, 810, 1090, 840, 10, 10);是
				if (msg.x >= 1000 && msg.x <= 1090 && msg.y >= 810 && msg.y <= 840)
				{
					Q = 1001; W = 811; E = 1110; R = 810; T = 1200; Y = 840;
					N = 1148; M = 818;
					Did(); state[15] = 1;
				}
				//roundrect(1110, 810, 1200, 840, 10, 10);否
				if (msg.x >= 1110 && msg.x <= 1200 && msg.y >= 810 && msg.y <= 840)
				{
					Q = 1111; W = 811; E = 1000; R = 810; T = 1090; Y = 840;
					N = 1040; M = 818;
					UND(); state[15] = 0;
				}
				//5个页面按钮的点击
				if (msg.x >= 10 && msg.x <= 110 && msg.y >= 10 && msg.y <= 30)
				{
					New(); Nt++;
				}
				if (msg.x >= 10 && msg.x <= 110 && msg.y >= 40 && msg.y <= 60)
				{
					Look();
				}
				if (msg.x >= 120 && msg.x <= 220 && msg.y >= 10 && msg.y <= 30)
				{
					Submit();
				}
				if (msg.x >= 230 && msg.x <= 330 && msg.y >= 10 && msg.y <= 30)
				{
					Help();
				}
				if (msg.x >= 340 && msg.x <= 440 && msg.y >= 10 && msg.y <= 30)
				{
					About();
				}
				break;
			}
		}
	}
}
//学生姓名输入
void Stuname()
{
	setlocale(LC_ALL, "");
	fp2 = fopen("D:\\TimePlan\\Name.txt", "w");
	fclose(fp2);
	fp2 = fopen("D:\\TimePlan\\Name.txt", "a+");
	wchar_t s[15]{};
	InputBox(s, 15, L"请输入你的姓名");
		settextcolor(WHITE);
		settextstyle(30, 0, L"楷体");
		outtextxy(550, 10, s);
		fputws(s, fp2);
		fclose(fp2);
}

//在D:创建TimePlan文件夹
void CreateFolder(void)
{
	int a=_wchdir(L"D:\\");
	int b=_wmkdir(L"TimePlan");
	int c=_wchdir(L"D:\\TimePlan");
}

//密码核验
void Passwd()
{
	wchar_t Pass[20];
	wchar_t Userpass[20];
	if ((fp = fopen("D:\\TimePlan\\Myaccount.txt", "r")) == NULL)//如果未发现用户文件
	{
		FileCreate();//新建密码文件
		fp = fopen("D:\\TimePlan\\Myaccount.txt", "w");
		HWND Eu = GetHWnd();
		MessageBox(Eu, L"首次使用，请先创建密码。", L"提示", MB_OK);
		InputBox(Pass, 20, L"创建密码");
		for (int i = 0; i <= 19; i++)//对密码进行简单加密
		{
			Pass[i] = Pass[i] + 1;
		}
		fputws(Pass,fp);//写入密码
		fclose(fp);
		main();
	}
	else
	{
		fp = fopen("D:\\TimePlan\\Myaccount.txt", "r");
		fgetws(Pass, 20, fp);
		for (int i = 0; i <= 19; i++)//解密
		{
			Pass[i] = Pass[i] - 1;
		}
		InputBox(Userpass, 20, L"输入密码");
		if (wcscmp(Userpass,Pass) == 0)//比对用户密码和输入值
		{
			HWND Et = GetHWnd();
			MessageBox(Et, L"登录成功", L"提示", MB_OK);
		}
		else
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"密码错误", L"提示", MB_OK);
			main();
		}
	}
	fclose(fp);
}

void InfoOut()
{
	int Line=0;//行数计数
	wchar_t Info[100];//行数获取时的字符缓冲区
	setlocale(LC_ALL, "");
	Sqlist *L;
    L = (Sqlist *)malloc(sizeof(Sqlist));
	wchar_t str[128]{};
	if ((fp1 = fopen("D:\\TimePlan\\Data.txt", "r")) == NULL)
	{
		HWND Er = GetHWnd();
		MessageBox(Er, L"用户数据读取失败！", L"提示", MB_OK);
	}
	for (int i = 1; i < 16; i++)         /*负责将通过文件进行二级传递的用户数据复制到结构体Node中*/
	{
		fgetws(str, 128, fp1);           //读取Data.txt的第i行数据
		wcscpy(L->data1[i], str);        //将该数据写入L->data1[i]
		fgetws(str, 128, fp1);
		wcscpy(L->data2[i], str);
		fgetws(str, 128, fp1);
		wcscpy(L->goal[i], str);
	}
	//获取fp1内容的行数
	while (fgetws(Info, 100, fp1) != NULL)
	{
		Line++;
	}
	printf("%d\n", Line);
	fclose(fp1);
	if ((fp3 = fopen("D:\\TimePlan\\State.txt", "r")) == NULL)
	{
		HWND Er = GetHWnd();
		MessageBox(Er, L"状态数据读取失败！", L"提示", MB_OK);
	}
	for (int i = 1; i < 16; i++)
	{
		fgetws(str, 128, fp3);
		wcscpy(L->state[i], str);
	}
	fclose(fp3);
	int j = 1;                          /*负责将结构体中的数据输出到Teapage(教师页面)*/
    for (int i = 190; i <= 780; i += 40)
	{
		  outtextxy(110, i, L->data1[j]);
		  outtextxy(230, i, L->data2[j]);
		  outtextxy(310, i, L->goal[j]);
		  outtextxy(1078, i, L->state[j]);
		  j += 1;
	}
}

void Edit()
{
	wchar_t str[128]{};
	wchar_t str1[128]{};
	setlocale(LC_ALL, "");
	Sqlist *L;
	L = (Sqlist*)malloc(sizeof(Sqlist));
	if ((fp1 = fopen("D:\\TimePlan\\Data.txt", "r")) == NULL)
	{
		HWND Er = GetHWnd();
		MessageBox(Er, L"用户数据读取失败！", L"提示", MB_OK);
	}
	for (int i = 1; i < 16; i++)         /*负责将通过文件进行二级传递的用户数据复制到结构体Node中*/
	{
		fgetws(str, 128, fp1);           //读取Data.txt的第i行数据
		wcscpy(L->data1[i], str);        //将该数据写入L->data1[i]
		fgetws(str, 128, fp1);
		wcscpy(L->data2[i], str);
		fgetws(str, 128, fp1);
		wcscpy(L->goal[i], str);
	}
	fclose(fp1);
	//输入框“输入修改内容”
	InputBox(str1, 128, L"输入修改内容");
	//比对Sqlist中是否存在str,如果存在，输入框“修改为什么？”如果不存在，消息窗口“没有找到需要修改的内容。”
	for (int i = 1; i < 16; i++)
	{
		if (wcscmp(L->data1[i], str1) == 0)
		{
			InputBox(str1, 128, L"修改为什么？");
			wcscpy(L->data1[i], str1);
			break;
		}
		else if (wcscmp(L->data2[i], str1) == 0)
		{
			InputBox(str1, 128, L"修改为什么？");
			wcscpy(L->data2[i], str1);
			break;
		}
		else if (wcscmp(L->goal[i], str1) == 0)
		{
			InputBox(str1, 128, L"修改为什么？");
			wcscpy(L->goal[i], str1);
			break;
		}
		else if (wcscmp(L->state[i], str1) == 0)
		{
			InputBox(str1, 128, L"修改为什么？");
			wcscpy(L->state[i], str1);
			break;
		}
		else if (i == 15)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"没有找到需要修改的内容。", L"提示", MB_OK);
		}
	}
}

void Search()
{
	wchar_t str[128]{};
	wchar_t str1[128]{};
	setlocale(LC_ALL, "");
	Sqlist *L;
	L = (Sqlist*)malloc(sizeof(Sqlist));
	if ((fp1 = fopen("D:\\TimePlan\\Data.txt", "r")) == NULL)
	{
		HWND Er = GetHWnd();
		MessageBox(Er, L"用户数据读取失败！", L"提示", MB_OK);
	}
	for (int i = 1; i < 16; i++)         /*负责将通过文件进行二级传递的用户数据复制到结构体Node中*/
	{
		fgetws(str, 128, fp1);           //读取Data.txt的第i行数据
		wcscpy(L->data1[i], str);        //将该数据写入L->data1[i]
		fgetws(str, 128, fp1);
		wcscpy(L->data2[i], str);
		fgetws(str, 128, fp1);
		wcscpy(L->goal[i], str);
	}
	fclose(fp1);
	//输入框“输入查找内容”
	InputBox(str1, 128, L"输入查找内容");
	//比对Sqlist中是否存在str,如果存在，输出框“找到了！”如果不存在，HWND“没有找到需要查找的内容。”
	for (int i = 1; i < 16; i++)
	{
		if (wcscmp(L->data1[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"找到了！", L"提示", MB_OK);
			break;
		}
		else if (wcscmp(L->data2[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"找到了！", L"提示", MB_OK);
			break;
		}
		else if (wcscmp(L->goal[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"找到了！", L"提示", MB_OK);
			break;
		}
		else if (wcscmp(L->state[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"找到了！", L"提示", MB_OK);
			break;
		}
		else if (i == 15)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"没有找到需要查找的内容。", L"提示", MB_OK);
		}
	}
}

void Delete()
{
	//删除顺序表中的某一项
	wchar_t str[128]{};
	wchar_t str1[128]{};
	setlocale(LC_ALL, "");
	Sqlist *L;
	L = (Sqlist*)malloc(sizeof(Sqlist));
	if ((fp1 = fopen("D:\\TimePlan\\Data.txt", "r")) == NULL)
	{
		HWND Er = GetHWnd();
		MessageBox(Er, L"用户数据读取失败！", L"提示", MB_OK);
	}
	for (int i = 1; i < 16; i++)         /*负责将通过文件进行二级传递的用户数据复制到结构体Node中*/
	{
		fgetws(str, 128, fp1);           //读取Data.txt的第i行数据
		wcscpy(L->data1[i], str);        //将该数据写入L->data1[i]
		fgetws(str, 128, fp1);
		wcscpy(L->data2[i], str);
		fgetws(str, 128, fp1);
		wcscpy(L->goal[i], str);
	}
	fclose(fp1);
	//输入框“输入删除内容”
	InputBox(str1, 128, L"输入删除内容");
	//比对Sqlist中是否存在str,如果存在，输出框“已删除！”如果不存在，HWND“没有找到需要删除的内容。”
	for (int i = 1; i < 16; i++)
	{
		if (wcscmp(L->data1[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"已删除！", L"提示", MB_OK);
			break;
		}
		else if (wcscmp(L->data2[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"已删除！", L"提示", MB_OK);
			break;
		}
		else if (wcscmp(L->goal[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"已删除！", L"提示", MB_OK);
			break;
		}
		else if (wcscmp(L->state[i], str1) == 0)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"已删除！", L"提示", MB_OK);
			break;
		}
		else if (i == 15)
		{
			HWND Er = GetHWnd();
			MessageBox(Er, L"没有找到需要删除的内容。", L"提示", MB_OK);
		}
	}
}

//教师页面
void Teapage()
{
	Passwd();                          /*密码校验*/
	initgraph(1600, 900);
	cleardevice();
	wchar_t Name[20]{};                /*从843到846负责获取Name.txt的内容并复制到Name[20]*/
	fp2 = fopen("D:\\TimePlan\\Name.txt", "r");
	fgetws(Name, 20, fp2);
	fclose(fp2);
	IMAGE back;
	loadimage(&back, L"C:\\Users\\LEGION\\Desktop\\Datas\\Tb.jpg", 1600, 900, true);
	putimage(0, 0, &back);
	IMAGE Data;
	loadimage(&Data, L"C:\\Users\\LEGION\\Desktop\\Datas\\Data.png", 1100, 750, true);
	putimage(50, 50, &Data);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, L"黑体");
	outtextxy(480, 85, Name);
	InfoOut();
	ExMessage msg;
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))
		{
			if (msg.x >= 1483 && msg.x <= 1555 && msg.y >= 39 && msg.y <= 111)    /*从822到846负责按钮交互性（鼠标移动到按钮区域按钮边缘颜色变化）*/
			{
				setlinecolor(WHITE); circle(1519, 75, 36);//返回
			}
			else  setlinecolor(RED); circle(1519, 75, 36);
			if (msg.x >= 1378 && msg.x <= 1450 && msg.y >= 39 && msg.y <= 111)
			{
				setlinecolor(WHITE); circle(1414, 75, 36);//编辑
			}
			else  setlinecolor(RED); circle(1414, 75, 36);
			if (msg.x >= 1273 && msg.x <= 1345 && msg.y >= 39 && msg.y <= 111)
			{
				setlinecolor(WHITE); circle(1309, 75, 36);//删除
			}
			else  setlinecolor(RED); circle(1309, 75, 36);
			if (msg.x >= 1273 && msg.x <= 1345 && msg.y >= 143 && msg.y <= 215)
			{
				setlinecolor(WHITE); circle(1309, 179, 36);//搜索
			}
			else  setlinecolor(RED); circle(1309, 179, 36);
			if (msg.x >= 1378 && msg.x <= 1555 && msg.y >= 143 && msg.y <= 215)
			{
				setlinecolor(WHITE); roundrect(1378, 143, 1555, 215, 90, 90);//彩蛋
			}
			else  setlinecolor(RED); roundrect(1378, 143, 1555, 215, 90, 90);

			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
				if (msg.x >= 1483 && msg.x <= 1555 && msg.y >= 39 && msg.y <= 111)
				{
					main();//返回
				}
				if (msg.x >= 1378 && msg.x <= 1555 && msg.y >= 143 && msg.y <= 215)
				{
					Teapage();
				}
				if (msg.x >= 1378 && msg.x <= 1450 && msg.y >= 39 && msg.y <= 111)
				{
					//对顺序表的内容修改
					Edit();
				}
				if (msg.x >= 1273 && msg.x <= 1345 && msg.y >= 39 && msg.y <= 111)
				{
					//删除
					Delete();
				}
				if (msg.x >= 1273 && msg.x <= 1345 && msg.y >= 143 && msg.y <= 215)
				{
					//搜索
					Search();
				}
			}
		}
	}
}

//黑夜模式
void settings(void)
{
	if (Done % 2 == 0)
	{
		IMAGE bkdark;
		loadimage(&bkdark, L"C:\\Users\\LEGION\\Desktop\\Datas\\bkdark.jpg", 1080, 640, true);
		putimage(0, 0, &bkdark);
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"黑夜模式打开啦！", L"提示", MB_OKCANCEL);
	}
	else
	{
		IMAGE bklight;
		loadimage(&bklight, L"C:\\Users\\LEGION\\Desktop\\Datas\\back.jpg", 1080, 640, true);
		putimage(0, 0, &bklight);
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"黑夜模式关闭啦！", L"提示", MB_OKCANCEL);
	}
}

void FileCreate(void)//文件创建(Myaccount.txt)
{
	fp = fopen("D:\\TimePlan\\Myaccount.txt", "w");         /*以写入模式打开Myaccount.txt*/
/*                                                                                                 文件的读写模式
	  "r"	以“只读”方式打开文件。只允许读取，不允许写入。文件必须存在，否则打开失败。
      "w"	以“写入”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
      "a"	以“追加”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
      "r+"	以“读写”方式打开文件。既可以读取也可以写入，也就是随意更新文件。文件必须存在，否则打开失败。
      "w+"	以“写入/更新”方式打开文件，相当于w和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
      "a+"	以“追加/更新”方式打开文件，相当于a和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
*/
	fclose(fp);
}

int main( )
{
	CreateFolder();          /*TimePlan文件夹的创建*/
	if (_waccess(L"D:\\TimePlan", 0) != 0)          //判断TimePlan文件夹是否成功生成
	{
		HWND hwnd = GetHWnd();
		MessageBox(hwnd, L"Error!", L"Error", MB_OK);
	}
	initgraph(1080, 640);         /*创建窗口*/
	setbkcolor(BLACK);             /*设置背景颜色*/
	settextcolor(BLACK);			/*设置字体颜色*/
	cleardevice();                  /*清屏*/
	setbkmode(TRANSPARENT);         /*设置背景透明*/
	IMAGE back;                     /*背景图片的定义*/
	loadimage(&back, L"C:\\Users\\LEGION\\Desktop\\Datas\\back.jpg", 1080, 640, true);        /*背景图片的加载*/
	putimage(0, 0, &back);          /*背景图片的显示*/
	GetHWnd();                       /*获取窗口句柄*/
	if (Max == 0)    /*这个判断用来检测main()页面的打开次数，防止用户在返回主页面时重复收到"欢迎使用"的通知*/
	{
		HWND hwnd = GetHWnd();         /*获取窗口句柄*/
		MessageBox(hwnd, L"欢迎使用！", L"提示", MB_OK);       /*提示用户*/
		Max++;
	}
	ExMessage msg;                /*鼠标消息的定义*/
	while (1)
	{
		if (peekmessage(&msg, EM_MOUSE))        
		{
			//范围变色
			if (msg.x >= 85 && msg.x <= 260 && msg.y >= 360 && msg.y <= 415)
			{
				setlinecolor(RED); roundrect(82, 370, 273, 424, 50, 50);
			}
			  else  setlinecolor(WHITE);roundrect(82, 370, 273, 424, 50, 50);
			
			if (msg.x >= 85 && msg.x <= 260 && msg.y >= 510 && msg.y <= 565)
			{
				setlinecolor(RED); roundrect(82, 520, 273, 576, 50, 50);
			}
			  else  setlinecolor(WHITE); roundrect(82, 520, 273, 576, 50, 50);
			//按钮点击
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:              /*如果鼠标左键被按下*/
				if (msg.x >= 85 && msg.x <= 260 && msg.y >= 360 && msg.y <= 415)
				{
					userpage();               /*用户类型判断*/
				}
				if (msg.x >= 85 && msg.x <= 260 && msg.y >= 510 && msg.y <= 565)
				{
				    exit(5418);               /*退出按钮*/
				}
				if (msg.x >= 963 && msg.x <= 1025 && msg.y >= 30 && msg.y <= 95)
				{
					settings(); Done++;  
				}
			}
		}
	}
}
