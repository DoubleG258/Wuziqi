#include<stdio.h>
#include<graphics.h>

int main() {
	initgraph(600, 500);//�������δ���
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

	getchar();//����
	closegraph();//�رմ���
	return 0;
}