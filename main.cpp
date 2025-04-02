#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")

int flag = 0;//��Ǻ����
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
	outtextxy(510, 60, "���1������");
	outtextxy(510, 100, "���2������");
}

int judge(int Mapx, int Mapy) {
	int temp = 2 - flag % 2;
	//�ж����Ƿ�������һ��
	for (int i = Mapx , j = Mapy-4; j<= Mapy;j++) {
		if (j >= 1 && j < 16 &&temp==ChessMap[i][j] && temp == ChessMap[i][j + 1] && temp == ChessMap[i][j + 2] && temp == ChessMap[i][j + 3] && temp == ChessMap[i][j + 4]) {
			return 1;
		}
	}
	//�ж����Ƿ�������һ��
	for (int i = Mapx-4, j = Mapy ; i<= Mapx; i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i+1][j ] && temp == ChessMap[i+2][j ] && temp == ChessMap[i+3][j] && temp == ChessMap[i+4][j]) {
			return 1;
		}
	}
	//��б��
	for (int i = Mapx - 4, j = Mapy - 4; j <= Mapy, i <= Mapx; j++, i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j + 1] && temp == ChessMap[i + 2][j + 2] && temp == ChessMap[i + 3][j + 3] && temp == ChessMap[i + 4][j + 4]) {
			return 1;
		}
	}
	//��б��
	for (int i = Mapx - 4, j = Mapy + 4; j >= Mapy ,i <= Mapx; j--, i++) {
		if (i >= 1 && i < 16 && temp == ChessMap[i][j] && temp == ChessMap[i + 1][j - 1] && temp == ChessMap[i + 2][j - 2] && temp == ChessMap[i + 3][j - 3] && temp == ChessMap[i + 4][j - 4]) {
			return 1;
		}
	}

	return 0;
}

void playGame() {
	int cx = 0, cy = 0;//���ӵ�����
	int Mapx=0, Mapy=0;//��¼��������
	MOUSEMSG Msg;
	HWND hwnd = GetHWnd();//��ȡ���ھ��

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
		//��������
		if (Msg.uMsg == WM_LBUTTONDOWN) {

			if (ChessMap[Mapx][Mapy] != 0) {
				MessageBox(hwnd, "������������", MB_OK);
				continue;
			}

			if (flag % 2 == 0) {
				setfillcolor(BLACK);
				solidcircle(cx, cy, 9);
				ChessMap[Mapx][Mapy] = 1;//��ɫ���ӱ��Ϊ1
			}
			else {
				setfillcolor(WHITE);
				solidcircle(cx, cy, 9);
				ChessMap[Mapx][Mapy] = 2;//��ɫ���ӱ��Ϊ2
			}
			flag++;
		}
		
		if (judge(Mapx,Mapy)) {
			if (1 == flag % 2) {
				MessageBox(hwnd, "���1������ʤ��", "Game Over", MB_OK);
				return;
			}
			else {
				MessageBox(hwnd, "���2������ʤ��", "Game Over", MB_OK);
				return;
			}
		}

	}

}
int main() {
	initGame();
	

	setfillcolor(WHITE);
	playGame();
	

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