#include<stdio.h>
#include<graphics.h>

int main() {
	initgraph(600, 500,1);//�������δ���
	//����һ���洢ͼƬ�ı���
	IMAGE img;
	// ����ͼƬ
	loadimage(&img, "bk.png");//���ع��������û��ָ�����صı�����Ĭ�ϼ��ص�������
	//��ͼ
	putimage(0, 0, &img);
	/*
		��ͼ��
			�������
			��ֵ
			��ʾ���
	*/

	//����500 500����  20*20����
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	for (int i = 0; i <= 20; i++) {
		line(0, i*25, 500, i*25);
		line(i * 25, 0, i * 25, 500);
	}







	getchar();//����
	closegraph();//�رմ���
	return 0;
}