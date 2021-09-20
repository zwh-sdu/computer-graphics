#include<stdc++.h>
#include<glut.h>
#include<math.h>
#define N 1000
using namespace std;

int line[N][4], k = 0;
int w = 500, h = 500,mode=0;
int x1, yl, x2, y2;
int x3, y3, r;

void cirpot(int x3, int y3, int x, int y) {

	glVertex2d(x3 + x, y3 - y);
	glVertex2d(x3 + x, y3 + y);
	glVertex2d(x3 - x, y3 - y);
	glVertex2d(x3 - x, y3 + y);
	glVertex2d(x3 + y, y3 + x);
	glVertex2d(x3 + y, y3 - x);
	glVertex2d(x3 - y, y3 - x);
	glVertex2d(x3 - y, y3 + x);
}

void display() {
	if (mode == 2) {					//BresenhamLine
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < k; i++) {
			glBegin(GL_POINTS);
			glColor3f(0, 1, 0);
			x1 = line[i][0];
			yl = line[i][1];
			x2 = line[i][2];
			y2 = line[i][3];
			int dx = x2 - x1, dy = y2 - yl, e, x, y;
			int ux = dx > 0 ? 1 : -1;
			int uy = dy > 0 ? 1 : -1;
			dx = abs(x2 - x1);
			dy = abs(y2 - yl);
			x = x1;
			y = yl;
			if (abs(dx) > abs(dy)) {
				e = -dx;
				while (x != x2 + ux) {
					glVertex2d(x, y);
					e += 2 * dy;
					if (e > 0) {
						if (y != y2) {
							y += uy;
						}
						e = e - 2 * dx;
					}
					x += ux;
				}
			}
			else {
				e = -dy;
				while (y != y2 + uy) {
					glVertex2d(x, y);
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
			glEnd();

		}
		glutSwapBuffers();
	}
	if (mode == 1) {					//DDA
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < k; i++) {
			glBegin(GL_POINTS);
			glColor3f(1, 0, 0);
			int step;
			float x, y, dx, dy;
			x1 = line[i][0];
			yl = line[i][1];
			x2 = line[i][2];
			y2 = line[i][3];

			if (abs(x2 - x1) >= abs(yl - y2))
				step = abs(x2 - x1);
			else
				step = abs(y2 - yl);
			dx = float(1.0 * (x2 - x1) / step);
			dy = float(1.0 * (y2 - yl) / step);
			x = x1;
			y = yl;
			glVertex2d(x, y);

			for (int i = 0; i < step; i++) {
				x = x + dx;
				y = y + dy;
				glVertex2d(x, int(y + 0.5));
				//cout << x <<"  "<< int(y + 0.5) << endl;
			}
			glEnd();

		}
		glutSwapBuffers();
	}
	if (mode == 3) {
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_POINTS);
		glColor3f(0, 0, 1);
		int x = 0, y = int(r), e = 1 - int(r);
		cirpot(x3, y3, x, y);
		while (x < y) {
			if (e < 0) {
				e += 2 * x + 3;
			}
			else {
				e += 2 * (x - y) + 5;
				y--;
			}
			x++;
			cirpot(x3, y3, x, y);
		}
		glEnd();
		glutSwapBuffers();
	}
	glFlush();
}

void mykeyboard(unsigned char key, int x, int y) {
	if (key == '1') {
		mode = 1;
	}
	if (key == '2') {
		mode = 2;
	}
	if (key == '3') {
		mode = 3;
	}
}

void mymouse(int button, int state, int x, int y) {
	 //按下左键，起始坐标
	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
		line[k][0] = x;
		line[k][1] = h - y;
	}
	 //松开左键，结束坐标
	if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
		line[k][2] = x;
		line[k][3] = h - y;
		k++;
		glutPostRedisplay();
	}
	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
		x3 = x;
		y3 = h-y;
	}
	if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
		r = pow((x-x3)*(x-x3) + (h-y-y3)*(h-y-y3), 0.5);
		glutPostRedisplay();
	}
}

void mymotion(int x, int y) {
	line[k][2] = x;
	line[k][3] = h - y;
	r = pow((x - x3) ^ 2 + (h - y - y3) ^ 2, 0.5);
	glutPostRedisplay();
}

void init() {
	glClearColor(0.1, 0.1, 0.4, 0.0);
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);

}

void reshape(int w, int h) {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glViewport(0, 0, w, h);

	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {

	cout << "输入1利用DDA算法画直线\n输入2利用Bresenham算法画直线\n输入3画圆：鼠标右键确定圆心  左键确定半径" << endl;
	 //初始化显示模式
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	 //初始化窗口
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("实验二");

	init();
	glutReshapeFunc(reshape);
	glutDisplayFunc(display);
	glutKeyboardFunc(mykeyboard);
	glutMouseFunc(mymouse);
	glutMotionFunc(mymotion);

	 //开始主循环绘制
	glutMainLoop();
	return 0;
}
