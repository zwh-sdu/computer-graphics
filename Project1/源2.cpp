/*
#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<gl/glut.h>
using namespace std;


void DDALine(int x1, int y1, int x2, int y2) {
	int step;
	int x0 = 400, y0 = 300;
	float x, y, dx, dy;
	if (abs(x2-x1) >= abs(y1-y2))
		step = abs(x2-x1);
	else
		step = abs(y2-y1);
	dx = float(1.0 * (x2-x1) / step);                        //让结果为浮点数
	dy = float(1.0 * (y2-y1) / step);
	x = x1;
	y = y1;
	putpixel((x + x0), (y0 - y), RED);                      //画第一个点

	Sleep(50);
	for (int i = 0; i < step; i++) {
		x = x + dx;
		y = y + dy;
		putpixel((x + x0), (y0 - int(y + 0.5)), RED);
	
		Sleep(50);                                          //两个点间隔50毫秒
	}
}

void BresenhamLine(int x1, int y1, int x2, int y2) {
	int dx=x2-x1, dy=y2-y1, e, x, y;
	int x0 = 400, y0 = 300;
	int ux = dx > 0 ? 1 : -1;
	int uy = dy > 0 ? 1 : -1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	x = x1;
	y = y1;
	if (abs(dx) > abs(dy)) {
		e = -dx;
		while (x != x2 + ux) {
			putpixel(x0 + x, y0 - y, RED);
			e += 2*dy;
			if (e > 0) {
				if (y != y2) {
					y += uy;
				}
				e = e - 2*dx;
			}
			x += ux;
		}
	}
	else {
		e = -dy;
		while (y != y2 + uy) {
			putpixel(x0 + x, y0 - y, RED);
			e += 2 * dx;
			if (e > 0) {
				if (x != x2) {
					x += ux;
				}
				e = e - 2 * dy;
			}
			y += uy;
		}
	}
}

void cirpot(int x0, int y0, int x, int y) {

	putpixel(x0 + x, y0 - y, RED);
	putpixel(x0 + x, y0 + y, RED);
	putpixel(x0 - x, y0 - y, RED);
	putpixel(x0 - x, y0 + y, RED); 
	putpixel(x0 + y, y0 + x, RED); 
	putpixel(x0 + y, y0 - x, RED);
	putpixel(x0 - y, y0 - x, RED);
	putpixel(x0 - y, y0 + x, RED);
}

void B_circle(int x1, int y1, double r) {
	int x=0, y=int(r), e=1-int(r);
	int x0 = 400, y0 = 300;
	cirpot(x0+x1, y0-y1, x, y);
	while (x < y) {
		if (e < 0) {
			e += 2 * x + 3;
		}
		else {
			e += 2 * (x - y) + 5;
			y--;
		}
		x++;
		cirpot(x0+x1, y0-y1, x, y);
		Sleep(50);
	}
}


int main() {
	int x1, x2, y1, y2;
	int x0 = 400, y0 = 300;
	//cout << "请输入两个整数点的坐标(x1,y1),(x2,y2)" << endl;
	//cin >> x1 >> y1 >> x2 >> y2;
	initgraph(x0 * 2, y0 * 2);		        //初始化图形窗口大小
	line(0, y0, x0 * 2, y0);			//坐标轴X
	line(x0, 0, x0, y0 * 2);			//坐标轴Y
	DDALine(x1, y1, x2, y2);                       //DDA画线算法
	//BresenhamLine(x1, y1, x2, y2);

	//B_circle(0, 0, 80);

	_getch();                               //等待一个任意输入结束
	closegraph();                           //关闭图形窗口
	return 0;
}
*/