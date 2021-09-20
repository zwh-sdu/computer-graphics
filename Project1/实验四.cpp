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
////时间延时函数
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
//	//找到多边形y的范围
//	for (i = 0; i < bs; i++) {
//		if (polypoint[i].y > ymax) {
//			ymax = polypoint[i].y;
//		}
//		if (polypoint[i].y < ymin) {
//			ymin = polypoint[i].y;
//		}
//	}
//	//初始化AET
//	AET* pAET = new AET;
//	pAET->next = NULL;
//
//	//初始化NET
//	NET* pNET[1024];
//	for (i = ymin; i <= ymax; i++) {
//		pNET[i] = new NET;
//		pNET[i]->next = NULL;
//	}
//
//	//建立NET
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
//	//建立并更新AET
//	for (int i = ymin; i <= ymax; i++) {
//		//计算新的交点x，更新AET
//		NET* p = pAET->next;
//		while (p != NULL) {
//			p->x = p->x + p->dx;
//			p = p->next;
//		}
//		//更新后对AET排序
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
//		//删除ymax==i的结点
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
//		//将NET中的新点加入AET,并用插入法按X值递增排序
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
//		//填充
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