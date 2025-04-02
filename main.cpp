#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

int flag = 0;//标记黑与白
int ChessMap[20][20] = {0};

void initGame() {
	initgraph(600, 500);
	loadimage(NULL, "bk.png");
	setlinecolor(BLACK);
	for (int i = 0; i <= 20; i++) {
		line(0, 25 * i, 500, 25 * i);
		line(25 * i, 0, 25 * i, 500);
	}

	setbkmode(0);
	settextcolor(BLACK);
	outtextxy(510, 60, "玩家1：黑棋");
	outtextxy(510, 100, "玩家2：白棋");
}

int judge(int Mapx, int Mapy) {
	int temp = 2 - flag % 2;
	//判定横是否链接在一起
	for (int i = Mapx , j = Mapy-4; j<= Mapy;j++) {
		if (j >= 1 && j < 16 &&temp==ChessMap[i][j] && temp == ChessMap[i][j + 1] && temp == ChessMap[i][j + 2] && temp == ChessMap[i][j + 3] && temp == ChessMap[i][j + 4]) {
			return 1;
		}
	}
	//判断竖是否连接在一起
	for (int i = Mapx-4, j = Mapy ; i<= Mapx; i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i+1][j ] && temp == ChessMap[i+2][j ] && temp == ChessMap[i+3][j] && temp == ChessMap[i+4][j]) {
			return 1;
		}
	}
	//左斜线
	for (int i = Mapx - 4, j = Mapy - 4; j <= Mapy, i <= Mapx; j++, i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j + 1] && temp == ChessMap[i + 2][j + 2] && temp == ChessMap[i + 3][j + 3] && temp == ChessMap[i + 4][j + 4]) {
			return 1;
		}
	}
	//右斜线
	for (int i = Mapx - 4, j = Mapy + 4; j >= Mapy ,i <= Mapx; j--, i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j - 1] && temp == ChessMap[i + 2][j - 2] && temp == ChessMap[i + 3][j - 3] && temp == ChessMap[i + 4][j - 4]) {
			return 1;
		}
	}

	return 0;
}

void playGame() {
	int cx = 0, cy = 0;//棋子的坐标
	int Mapx=0, Mapy=0;//记录棋盘坐标
	MOUSEMSG Msg;
	HWND hwnd = GetHWnd();//获取窗口句柄

	while (1) {
		Msg = GetMouseMsg();
		for (int i = 1; i < 20; i++) {
			for (int j = 1; j < 20; j++) {
				if (abs(Msg.x - j * 25) < 12 && abs(Msg.y - i * 25) < 12) {
					cx = j * 25;
					cy = i * 25;
					Mapx = i;
					Mapy = j;
				}
			}
		}
		printf("cx=%d,cy=%d\n", cx, cy);
		//绘制棋子
		if (Msg.uMsg == WM_LBUTTONDOWN) {

			if (ChessMap[Mapx][Mapy] != 0) {
				MessageBox(hwnd, "这里有棋子了", MB_OK);
				continue;
			}

			if (flag % 2 == 0) {
				setfillcolor(BLACK);
				solidcircle(cx, cy, 9);
				ChessMap[Mapx][Mapy] = 1;//黑色棋子标记为1
			}
			else {
				setfillcolor(WHITE);
				solidcircle(cx, cy, 9);
				ChessMap[Mapx][Mapy] = 2;//白色棋子标记为2
			}
			flag++;
		}
		
		if (judge(Mapx,Mapy)) {
			if (1 == flag % 2) {
				MessageBox(hwnd, "玩家1：黑棋胜利", "Game Over", MB_OK);
				return;
			}
			else {
				MessageBox(hwnd, "玩家2：白棋胜利", "Game Over", MB_OK);
				return;
			}
		}

	}

}
int main() {
	initGame();
	

	setfillcolor(WHITE);
	playGame();
	

	closegraph();//关闭窗口
	return 0;
}

/*  	initgraph(600, 500,1);//创建矩形窗口
	//定义一个存储图片的变量
	IMAGE img;
	// 加载图片
	loadimage(&img, "bk.png");//加载过程中如果没有指定加载的变量，默认加载到界面上
	//贴图
	putimage(0, 0, &img);

		贴图：
			定义变量
			赋值
			显示输出


	//绘制500 500棋盘  20*20格子
setlinecolor(BLACK);
setlinestyle(PS_SOLID, 1);
for (int i = 0; i <= 20; i++) {
	line(0, i * 25, 500, i * 25);
	line(i * 25, 0, i * 25, 500);
}

//插入文字
// 设置背景颜色，透明
setbkmode(0);
//设置文字颜色
settextcolor(BLACK);
//根据坐标插入文字
outtextxy(510, 60, "玩家1：黑棋");
outtextxy(510, 100, "玩家2：白棋");


*/