#include<stdio.h>
#include<graphics.h>

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


int main() {
	initGame();



	getchar();//卡屏
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