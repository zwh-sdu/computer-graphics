//#include<bits/stdc++.h>
//#include<glut.h>
//using namespace std;
//
//int w = 500, h = 500;
//int minx, maxx, miny, maxy;
//
//struct Point2D {
//	int x;
//	int y;
//	int num;
//};
//
//Point2D p;
//vector<Point2D> poi;
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
//	glMatrixMode(GL_MODELVIEW);
//}
//vector<Point2D> poly[2];
//
//bool checkin(vector<Point2D> poly, int x, int y) {	//�����Ƿ���ͼ����
//	bool flag = false;
//	int size = poly.size();
//	for (int i = 0, j = size - 1; i < size; j = i, i++)
//	{
//		int x1 = poly[i].x;
//		int y1 = poly[i].y;
//		int x2 = poly[j].x;
//		int y2 = poly[j].y;
//
//		// �������ζ����غ�
//		if ((x1 == x && y1 == y) || (x2 == x && y2 == y))
//		{
//			//return 'on'; // ����������
//			return false;
//		}
//
//		// �ж��߶����˵��Ƿ�����������
//		if ((y1 < y && y2 >= y) || (y1 >= y && y2 < y)) // ֻ��һ��ȡ�Ⱥţ������߾�������ζ���ʱ��ֻ��һ��
//		{
//			// �߶��������� Y ������ͬ�ĵ�� X ����
//			double crossX = (y - y1) * (x2 - x1) / (y2 - y1) + x1;  // y=kx+b�任��x=(y-b)/k ����k=(y2-y1)/(x2-x1)
//
//			// ���ڶ���εı���
//			if (crossX == x)
//			{
//				//return 'on'; // ����������
//				return false;
//			}
//
//			// �����ߴ�������εı߽磬ÿ����һ��flag��ֵ�任һ��
//			if (crossX > x)
//			{
//				flag = !flag;  // ����������Ϊtrue��ż����Ϊfalse
//			}
//		}
//	}
//
//	// ���ߴ�������α߽�Ĵ���Ϊ����ʱ���ڶ������
//	//return flag ? 'in' : 'out'; // ���������ڻ���
//	return flag ? true : false;
//}
//
//int i,j,k;
//int a[2] = { 2,1 }, b[2] = { 3,2 }, c[2] = { 1,4 }, d[2] = { 2,2 };
//
//int cd() {	//�������
//	return -(a[k] * i + b[k] * j + d[k]) / c[k];
//}
//
//void zbuffer() {
//	int depth;
//
//	for (i = 0; i <= 500; i++) {
//		for (j = 0; j <= 500; j++) {	//��Ļ��ÿһ�����ص�
//
//			int indexp = 0;
//			int zb = -0x3f3f3f3f;
//			for(k=0;k<2;k++){	//����ͼ��
//				if (checkin(poly[k], i, j)) {	//�����i��j������ͼ����
//					depth = cd();
//					if (depth > zb) {
//						zb = depth;
//						indexp = k;
//					}
//				}
//			}
//			if (zb == -0x3f3f3f3f) {
//				continue;
//			}
//			else {
//				poi.push_back({ i,j,indexp });
//			}
//
//		}
//	}
//}
//double co[6];
//void line(Point2D p0, Point2D p1)
//{
//	if (p0.num == 0) {
//		co[0] = 0.6;
//		co[1] = 0;
//		co[2] = 0;
//		co[3] = 0.5;
//		co[4] = 0;
//		co[5] = 0;
//	}
//	else {
//		co[0] = 0;
//		co[1] = 0.6;
//		co[2] = 0;
//		co[3] = 0;
//		co[4] = 0.5;
//		co[5] = 0;
//	}
//	Point2D p, temp;
//	int dx = p1.x - p0.x;
//	int dy = p1.y - p0.y;
//	double k = (dy * 1.00) / (dx * 1.00);//����б��
//	if (dx == 0)//����
//	{
//		if (dy < 0)//������Ϸ�������
//		{
//			temp = p0;
//			p0 = p1;
//			p1 = temp;
//		}
//		for (p = p0; p.y < p1.y; p.y++)//���ƶ�����->y,������p1
//		{
//			if (p0.num == 0) {
//				glColor3f(1, 0, 0);
//			}
//			else {
//				glColor3f(0, 1, 0);
//			}
//			glVertex2f(p.x, p.y);
//		}
//	}
//
//	else
//	{
//
//		double e = 0.00;//����
//
//		if (k >= 0 && k <= 1)
//		{
//			if (dx < 0)//p1����࣬����
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0������
//
//			for (p = p0; p.x < p1.x; p.x++)//���ƶ�����->x,������p1
//			{
//				glColor3f(co[0],co[1],co[2]);
//				glVertex2f(p.x, p.y+1);
//				glColor3f(co[3],co[4],co[5]);//��ͬ����ֵ
//				glVertex2f(p.x, p.y);
//				e += k;
//
//				if (e >= 1.0)
//				{
//					p.y++;
//					e -= 1;
//				}
//			}
//		}
//		else if (k > 1)
//		{
//			if (dy < 0)//p1����࣬����
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0���·�
//
//			for (p = p0; p.y < p1.y; p.y++)//���ƶ�����->y,������p1
//			{
//				glColor3f(co[3],co[4],co[5]);
//				glVertex2f(p.x, p.y);
//				glColor3f(co[0],co[1],co[2]);
//				glVertex2f(p.x+1, p.y);
//				e += 1.00 / (k * 1.00);
//
//				if (e >= 1.0)
//				{
//					p.x++;
//					e -= 1;
//				}
//			}
//		}
//		else if (k >= -1 && k < 0)
//		{
//			e = 0.00;
//			if (dx < 0)//p1�����ϣ�����
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0������
//
//			for (p = p0; p.x < p1.x; p.x++)//���ƶ�����->x,������p1
//			{
//				glColor3f(co[0],co[1],co[2]);
//				glVertex2f(p.x, p.y);
//				glColor3f(co[3],co[4],co[5]);//����e�Ǹ���
//				glVertex2f(p.x, p.y - 1);
//				e += k;
//
//				if (e <= -1.0)
//				{
//					p.y--;
//					e += 1.0;
//				}
//			}
//		}
//
//		else if (k < -1)
//		{
//			if (dy > 0)//p1���Ϸ�������
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0����
//			for (p = p0; p.y > p1.y; p.y--)//���ƶ�����->y,������p1
//			{
//				glColor3f(co[0],co[1],co[2]);
//				glVertex2f(p.x, p.y);
//				glColor3f(co[3],co[4],co[5]);
//				glVertex2f(p.x + 1, p.y);
//				e += -1.0 / (k * 1.0);
//
//				if (e >= 1.0)
//				{
//					p.x++;
//					e -= 1;
//				}
//			}
//		}
//
//	}
//}
//
//void display()
//{	
//	glBegin(GL_POINTS);
//	glClear(GL_COLOR_BUFFER_BIT);
//	for (int i = 0; i < poi.size(); i++) {
//		if (poi[i].num == 0) {
//			glColor3f(1, 0, 0);
//		}
//		if (poi[i].num == 1) {
//			glColor3f(0, 1, 0);
//		}
//		glVertex2d(poi[i].x, poi[i].y);
//	}
//	//line(poly[0][0], poly[0][1]);
//	line(poly[0][1], poly[0][2]);
//	line(poly[0][0], poly[0][2]);
//	line(poly[1][0], poly[1][1]);
//	line(poly[1][1], poly[1][2]);
//	line(poly[1][0], poly[1][2]);
//	//line({ 0,0,1 }, { 200,500,1 });
//	glEnd();
//	glFlush();
//}
//
//void add() {
//	p.x = 100;
//	p.y = 100;
//	p.num = 0;
//	poly[0].push_back(p);
//	p.x = 400;
//	p.y = 100;
//	p.num = 0;
//	poly[0].push_back(p);
//	p.x = 250;
//	p.y = 450;
//	p.num = 0;
//	poly[0].push_back(p);
//	p.x = 150;
//	p.y = 80;
//	p.num = 1;
//	poly[1].push_back(p);
//	p.x = 300;
//	p.y = 80;
//	p.num = 1;
//	poly[1].push_back(p);
//	p.x = 200;
//	p.y = 250;
//	p.num = 1;
//	poly[1].push_back(p);
//}
//
//int main(int argc, char** argv) {
//
//	add();
//	// ��ʼ����ʾģʽ
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// ��ʼ������
//	glutInitWindowSize(w, h);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("ʵ����");
//
//	init();
//	zbuffer();
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	
//	// ��ʼ��ѭ������
//	glutMainLoop();
//	return 0;
//}