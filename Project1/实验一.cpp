//#include<stdc++.h>
//#include<gl/glut.h>
//
//double dx=0, dy=0, oldx, oldy;
//int w = 500, h = 500;
//int mode=0;
//double dxt, dyt, dxc, dyc, anglezt=0,anglezc=0;
//
////��ʼ������
//void init() {
//	glClearColor(0.1, 0.1, 0.4, 0.0);
//	glShadeModel(GL_SMOOTH);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, w, 0, h);
//
//}
//
//void display() {
//	int n = 1000;
//	GLfloat r = 50;
//	GLfloat pi = acos(-1);
//
//	glClear(GL_COLOR_BUFFER_BIT);
//
////����������
//	if (mode == 1) {
//		dxt = dx;
//		dyt = dy;
//	}
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(dxt, dyt, 0);
//	glRotatef(anglezt, 0, 0, 1);
//
//	glBegin(GL_TRIANGLES);
//	glColor3f(1, 0, 0);
//	glVertex2f(-69.282, -40);
//	glColor3f(0, 1, 0);
//	glVertex2f(0, 69.282);
//	glColor3f(0, 0, 1);
//	glVertex2f(69.282, -40);
//	glEnd();
//
//	glPopMatrix();
//	//����Բ��
//	if (mode == 2) {
//		dxc = dx;
//		dyc = dy;
//	}
//	glPushMatrix();
//	glLoadIdentity();
//	glTranslatef(dxc, dyc, 0);
//	glRotatef(anglezc, 0, 0, 1);
//
//	glBegin(GL_POLYGON);
//	glColor3f(0.3, 0.3, 0.3);
//	for (int i = 0; i < n; i++) {
//		if (i == 500) {
//			glColor3f(0.8, 0.8, 0.8);
//		}
//		glVertex2f(r * cos(2 * pi / n * i), r * sin(2 * pi / n * i));
//	}
//	glEnd();
//	glPopMatrix();
//
//	glFlush();
//}
//
// //���ڴ�С�仯�ص�����
//void reshape(int w, int h) {
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(0, w, 0, h);
//	glViewport(0, 0, w, h);
//
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void mymouse(int x, int y, int button, int state)
//{
//	if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON) {
//		oldx = x;
//		oldy = h-y;
//	}
//}
//
//void mymotion(int x, int y)
//{
//	y = h - y;
//	dx += x - oldx;
//	dy += y - oldy;
//
//	GLfloat deltax = x-oldx;
//	GLfloat deltay = y-oldy;
//	if (mode == 3) {
//		anglezt += deltay;
//	}
//	if (mode == 4) {
//		anglezc += deltay;
//	}
//	glutPostRedisplay();
//
//	oldx = x;
//	oldy = y;
//}
//
//void mykeyboard(unsigned char key, int x, int y)
//{
//	if (key == '1') {
//		mode = 1;
//	}
//	if (key == '2'){
//		mode = 2;
//	}
//	if (key == '3') {
//		mode = 3;
//	}
//	if (key == '4') {
//		mode = 4;
//	}
//	
//}
//
//int main(int argc, char** argv) {
//	std::cout << "����1�ƶ�������\n����2�ƶ�Բ��\n����3��ת������\n����4��תԲ��\n" << std::endl;
//	 //��ʼ����ʾģʽ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB);
//
//	 //��ʼ������
//	glutInitWindowSize(w, h);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("ʵ��һ");
//
//	init();
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	glutKeyboardFunc(mykeyboard);
//	glutMouseFunc(mymouse);
//	glutMotionFunc(mymotion);
//
//	// ��ʼ��ѭ������
//	glutMainLoop();
//	return 0;
//}
