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
	outtextxy(510, 60, "���1������");
	outtextxy(510, 100, "���2������");
}


int main() {
	initGame();



	getchar();//����
	closegraph();//�رմ���
	return 0;
}

/*  	initgraph(600, 500,1);//�������δ���
	//����һ���洢ͼƬ�ı���
	IMAGE img;
	// ����ͼƬ
	loadimage(&img, "bk.png");//���ع��������û��ָ�����صı�����Ĭ�ϼ��ص�������
	//��ͼ
	putimage(0, 0, &img);

		��ͼ��
			�������
			��ֵ
			��ʾ���


	//����500 500����  20*20����
setlinecolor(BLACK);
setlinestyle(PS_SOLID, 1);
for (int i = 0; i <= 20; i++) {
	line(0, i * 25, 500, i * 25);
	line(i * 25, 0, i * 25, 500);
}

//��������
// ���ñ�����ɫ��͸��
setbkmode(0);
//����������ɫ
settextcolor(BLACK);
//���������������
outtextxy(510, 60, "���1������");
outtextxy(510, 100, "���2������");


*/