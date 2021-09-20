//#include<cstdio>
//#include<iostream>
//#include<graphics.h>
//#include<conio.h>
//#include<ctime>
//#include<glut.h>
//using namespace std;
//
//const int bs = 6;
//
//typedef struct ET {
//	float x, dx, ymax;
//	struct ET* next;
//}AET,NET;
//
//struct point
//{
//	float x, y;
//}polypoint[bs] = { 300,200,400,150,400,400,300,500,200,400,200,150 };
//
//int ymax = 0;
//int ymin = 2000;
//
////ʱ����ʱ����
//void delay(int time)
//{
//	clock_t   now = clock();
//
//	while (clock() - now < time);
//}
//
//int main() {
//	initgraph(600, 600);
//	int i;
//	//�ҵ������y�ķ�Χ
//	for (i = 0; i < bs; i++) {
//		if (polypoint[i].y > ymax) {
//			ymax = polypoint[i].y;
//		}
//		if (polypoint[i].y < ymin) {
//			ymin = polypoint[i].y;
//		}
//	}
//	//��ʼ��AET
//	AET* pAET = new AET;
//	pAET->next = NULL;
//
//	//��ʼ��NET
//	NET* pNET[1024];
//	for (i = ymin; i <= ymax; i++) {
//		pNET[i] = new NET;
//		pNET[i]->next = NULL;
//	}
//
//	//����NET
//	for (i = ymin; i <= ymax; i++) {
//		for (int j = 0; j < bs; j++) {
//			if (polypoint[j].y == i) {
//				if (polypoint[(j - 1 + bs) % bs].y > polypoint[j].y) {
//					NET* p = new NET;
//					p->x = polypoint[j].x;
//					p->ymax = polypoint[(j - 1 + bs) % bs].y;
//					p->dx = (polypoint[(j - 1 + bs) % bs].x - polypoint[j].x) / (polypoint[(j - 1 + bs) % bs].y - polypoint[j].y);
//					p->next = pNET[i]->next;
//					pNET[i] ->next = p;
//				}
//				if (polypoint[(j + 1 + bs) % bs].y > polypoint[j].y) {
//					NET* p = new NET;
//					p->x = polypoint[j].x;
//					p->ymax = polypoint[(j + 1 + bs) % bs].y;
//					p->dx = (polypoint[(j + 1 + bs) % bs].x - polypoint[j].x)/(polypoint[(j + 1 + bs) % bs].y - polypoint[j].y);
//					p->next = pNET[i]->next;
//					pNET[i]->next = p;
//				}
//			}
//
//		}
//	}
//
//	//����������AET
//	for (int i = ymin; i <= ymax; i++) {
//		//�����µĽ���x������AET
//		NET* p = pAET->next;
//		while (p != NULL) {
//			p->x = p->x + p->dx;
//			p = p->next;
//		}
//		//���º��AET����
//		AET* w = pAET;
//		p = pAET->next;
//		w->next = NULL;
//
//		while (p != NULL) {
//			while (w->next != NULL && p->x >= w->next->x) {
//				w = w->next;
//			}
//			NET* s = p->next;
//			p->next = w->next;
//			w->next = p;
//			p = s;
//			w = pAET;
//		}
//
//		//ɾ��ymax==i�Ľ��
//		AET* q = pAET;
//		p = q->next;
//		while (p != NULL) {
//			if (p->ymax == i) {
//				q->next = p->next;
//				delete p;
//				p = q->next;
//			}
//			else {
//				q = q->next;
//				p = p->next;
//			}
//		}
//
//		//��NET�е��µ����AET,���ò��뷨��Xֵ��������
//		p = pNET[i]->next;
//		q = pAET;
//		while (p != NULL) {
//			while (q->next != NULL && p->x >= q->next->x) {
//				q = q->next;
//			}
//			NET* s = p->next;
//			p->next = q->next;
//			q->next = p;
//			p = s;
//			q = pAET;
//		}
//
//		//���
//		p = pAET->next;
//		while (p != NULL && p->next != NULL) {
//			for (int j = p->x; j <= p->next->x; j++) {
//				putpixel(j, i, RGB(255, 0, 0));
//				//delay(1);
//			}
//			//delay(1);
//			p = p->next->next;
//		}
//
//
//	}
//	_getch();
//	closegraph();
//	return 0;
//}