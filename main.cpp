#include<stdio.h>
#include<graphics.h>

int main() {
	initgraph(600, 500);//创建矩形窗口
	//定义一个存储图片的变量
	IMAGE img;
	// 加载图片
	loadimage(&img, "bk.png");//加载过程中如果没有指定加载的变量，默认加载到界面上
	//贴图
	putimage(0, 0, &img);
	/*
		贴图：
			定义变量
			赋值
			显示输出
	*/

	getchar();//卡屏
	closegraph();//关闭窗口
	return 0;
}