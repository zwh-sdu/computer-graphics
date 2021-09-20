//#include<bits/stdc++.h>
//#include<gl/glut.h>
//using namespace std;
//
//const int w = 600, h = 600;
//int flag, k = 3, mode;
//struct point
//{
//	int x, y;
//};
//
//vector<point> control, control0, out;
//void init() {
//	glClearColor(0.1, 0.1, 0.4, 0.0);
//	glShadeModel(GL_SMOOTH);
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
//
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void byt()
//{
//	out.clear();
//	int num = control.size() - 1;
//
//	double t[9999];
//	for (int i = 0; i <= k - 1; i++)
//		t[i] = 0;
//	for (int i = k; i < num + 1; i++)
//		t[i] = t[i - 1] + 1.0 / (num + 1 - k + 1);
//	for (int i = num + 1; i <= num + k; i++)
//		t[i] = 1;
//
//	for (int j = k - 1; j <= num; j++)//j为区间的末端点
//	{
//		for (double u = t[j]; u <= t[j + 1]; u += 0.001 / num)
//		{
//			for (int r = 1; r <= k - 1; r++)//递推k-1层
//			{
//				for (int i = j; i >= j - k + r + 1; i--)//由递推公式得，需要倒着来，i和i-1存在i中；；bezier为j和j+1存在j中
//				{
//					double x1 = u - t[i];
//					double x2 = t[i + k - r] - t[i];
//					double y1 = t[i + k - r] - u;
//					double y2 = t[i + k - r] - t[i];
//
//					double temp1, temp2;
//					if (x1 == 0 && x2 == 0)
//						temp1 = 0;
//					else
//						temp1 = x1 / x2;
//					if (y1 == 0 && y2 == 0)
//						temp2 = 0;
//					else
//						temp2 = y1 / y2;
//
//					if (r == 1)//第一轮必须是输入的那几个控制点
//					{
//						control0[i].x = control[i].x * temp1 + control[i - 1].x * temp2;
//						control0[i].y = control[i].y * temp1 + control[i - 1].y * temp2;
//						continue;
//					}
//					else
//					{
//						control0[i].x = control0[i].x * temp1 + control0[i - 1].x * temp2;
//						control0[i].y = control0[i].y * temp1 + control0[i - 1].y * temp2;
//					}
//				}
//			}
//			out.push_back(control0[j]);//递推的最后一层的点，即为求得的点
//		}
//	}
//}
//
//void bezier()
//{
//	out.clear();	//最后要输出bezier曲线上的点
//	int num = control.size();
//	for (double t = 0; t <= 1; t += 0.005 / num) {	//Bezier的de Casteljau递推算法
//		for (int i = 1; i < num; i++) {
//			for (int j = 0; j < num - i; j++) {
//				if (i == 1) {
//					control0[j].x = (1 - t) * control[j].x + t * control[j + 1].x;
//					control0[j].y = (1 - t) * control[j].y + t * control[j + 1].y;
//				}
//				else {
//					control0[j].x = (1 - t) * control0[j].x + t * control0[j + 1].x;
//					control0[j].y = (1 - t) * control0[j].y + t * control0[j + 1].y;
//				}
//			}
//		}
//		out.push_back(control0[0]);
//	}
//}
//
//int zuijin(int x, int y) {
//	int ans = -1;
//	double minx = 0x3f3f3f3f;
//	for (int i = 0; i < control.size(); i++) {
//		double temp = sqrt(pow(x - control[i].x, 2) + pow(y - control[i].y, 2));
//		if (temp < minx && temp < 30) {
//			minx = temp;
//			ans = i;
//		}
//	}
//	return ans;
//}
//
//void mymouse(int button, int state, int x, int y) {
//	if (flag == 1) {	//插入点
//		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//			point temp = { x,h - y };
//			control.push_back(temp);
//			control0 = control;
//			if (mode == 1) bezier();
//			else byt();
//			glutPostRedisplay();
//		}
//	}
//	if (flag == 2) {	//删除点
//		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//			int dp = zuijin(x, h - y);	//找到离鼠标点击最近的点
//			if (dp == -1) {
//				return;
//			}
//			control.erase(control.begin() + dp);
//			control0 = control;
//			if (mode == 1) bezier();
//			else byt();
//			glutPostRedisplay();
//		}
//	}
//}
//
//void mymotion(int x, int y) {
//	int dp = zuijin(x, h - y);
//	if (dp == -1) {
//		return;
//	}
//	if (flag == 3) {
//		control[dp].x = x;
//		control[dp].y = h - y;
//		control0 = control;
//		if (mode == 1) bezier();
//		else byt();
//		glutPostRedisplay();
//	}
//}
//
//void mykeyboard(unsigned char key, int x, int y)
//{
//	if (key == '1') {
//		flag = 1;
//	}
//	if (key == '2'){
//		flag = 2;
//	}
//	if (key == '3') {
//		flag = 3;
//	}
//	if (key == '4') {
//		exit(0);
//	}
//}
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//	glPointSize(10.0f);
//	glBegin(GL_POINTS);
//	glColor3b(0, 0, 1);
//	for (int i = 0; i < control.size(); i++) {
//		glVertex2f(control[i].x, control[i].y);
//	}
//	glEnd();
//	glBegin(GL_LINE_STRIP);
//	glColor3f(1, 0, 0);
//	for (int i = 0; i < control.size(); i++) {
//		glVertex2f(control[i].x, control[i].y);
//	}
//	glEnd();
//	glBegin(GL_LINE_STRIP);
//	glColor3f(0, 1, 0);
//	for (int i = 0; i < out.size(); i++) {
//		glVertex2f(out[i].x, out[i].y);
//	}
//	glEnd();
//	glFlush();
//}
//
//int main(int argc, char** argv)
//{
//	cout << "输入1绘制Bezier曲线\n输入2绘制B样条曲线" << endl;
//	cin >> mode;
//	if (mode == 2) {
//		cout << "输入B样条的阶数k，默认k=3" << endl;
//		cin >> k;
//	}
//	cout << "输入1插入控制点\n输入2删除控制点\n输入3移动控制点\n输入4结束绘制" << endl;
//	//初始化显示模式
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	// 初始化窗口
//	glutInitWindowSize(w, h);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("实验六");
//	init();
//
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	glutMouseFunc(mymouse);
//	glutMotionFunc(mymotion);
//	glutKeyboardFunc(mykeyboard);
//	// 开始主循环绘制
//	glutMainLoop();
//	return 0;
//}