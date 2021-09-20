//#include<stdc++.h>
//#include<iostream>
//#include<cstdio>
//#include<glut.h>
//#include<math.h>
//#define N 1000
//using namespace std;
//
//int line[N][4], k = 0;
//int oldx=0, oldy=0, dxp=0, dyp=0;
//int w = 600, h = 600;
//
//void init() {
//	glClearColor(0.1, 0.1, 0.4, 0.0);
//	glShadeModel(GL_FLAT);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0,w,0,h);
//}
//
//void reshape(int w, int h) {
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, w, 0, h);
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//int mode = 1;
//void mymouse(int button, int state, int x, int y) {
//	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
//		line[k][0] = x;
//		line[k][1] = h - y;
//		mode = 1;
//	}
//	if (state == GLUT_UP && button == GLUT_LEFT_BUTTON) {
//		line[k][2] = x;
//		line[k][3] = h - y;
//		k++;
//		glutPostRedisplay();
//	}
//	if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON) {
//		oldx = x;
//		oldy = h - y;
//		mode = 2;
//	}
//}
//
//void mymotion(int x, int y) {
//	if (mode == 2) {
//		y = h - y;
//		dxp += x - oldx;
//		dyp += y - oldy;
//		glutPostRedisplay();
//		oldx = x;
//		oldy = y;
//	}
//
//	
//}
//
//bool check(float p, float q, float &u1, float &u2) {
//	float u;
//	if (p > 0) {
//		u = q / p;
//		if (u < u1) {
//			return false;
//		}
//		else if (u < u2) {
//			u2 = u;
//		}
//	}
//	else if (p < 0) {
//		u = q / p;
//		if (u > u2) {
//			return false;
//		}
//		else if (u > u1) {
//			u1 = u;
//		}
//	}
//	else {
//		if (q < 0) {
//			return false;
//		}
//	}
//	return true;
//}
//
//void clip(float xleft, float xright, float ybottom, float ytop, float x1, float y1, float x2, float y2) {
//	float u1 = 0, u2 = 1;
//	float dx = x2 - x1, dy = y2 - y1;
//	float x3=x1, y3=y1, x4=x2, y4=y2;
//	if (check(-dx, x1 - xleft, u1, u2)) {
//		if (check(dx, xright - x1, u1, u2)) {
//			dy = y2 - y1;
//			if (check(-dy, y1-ybottom, u1, u2)) {
//				if (check(dy, ytop - y1, u1, u2)) {
//					if (u2 < 1) {
//						x4 = x1 + u2 * dx;
//						y4 = y1 + u2 * dy;
//					}
//					if (u1 > 0) {
//						x3 = x1 + u1 * dx;
//						y3 = y1 + u1 * dy;
//					}
//
//					glBegin(GL_LINE_STRIP);
//					glClear(GL_COLOR_BUFFER_BIT);
//					glColor3f(1, 0, 0);
//					glVertex2f(x1, y1);
//					glVertex2f(x3, y3);
//					glColor3f(0, 1, 0);
//					glVertex2d(x4, y4);
//					glColor3f(1, 0, 0);
//					glVertex2f(x2, y2);
//					glEnd();
//					return;
//				}
//			}
//		}
//	}
//	glBegin(GL_LINE_STRIP);
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(1, 0, 0);
//	glVertex2f(x1, y1);
//	glVertex2f(x2, y2);
//	glEnd();
//}
//
//void display() {
//	glClear(GL_COLOR_BUFFER_BIT);
//	//绘制裁剪矩形
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(dxp, dyp, 0);
//	glBegin(GL_LINE_STRIP);
//	glColor3f(0.1,0.1,0.9);
//	glVertex2d(-150, -150);
//	glVertex2d(-150, 150);
//	glVertex2d(150, 150);
//	glVertex2d(150, -150);
//	glVertex2d(-150, -150);
//	glEnd();
//	glPopMatrix();
//
//	//绘制直线
//	for (int i = 0; i < k; i++) {
//		clip(-150 + dxp, 150 + dxp, -150 + dyp, 150 + dyp, line[i][0], line[i][1], line[i][2], line[i][3]);
//	}
//	glFlush();
//}
//
//int main(int argc, char** argv) {
//
//	// 初始化显示模式
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// 初始化窗口
//	glutInitWindowSize(w, h);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("实验三");
//
//	init();
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	glutMouseFunc(mymouse);
//	glutMotionFunc(mymotion);
//
//	// 开始主循环绘制
//	glutMainLoop();
//	return 0;
//}
//
//
//
//
