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
//bool checkin(vector<Point2D> poly, int x, int y) {	//检查点是否在图形中
//	bool flag = false;
//	int size = poly.size();
//	for (int i = 0, j = size - 1; i < size; j = i, i++)
//	{
//		int x1 = poly[i].x;
//		int y1 = poly[i].y;
//		int x2 = poly[j].x;
//		int y2 = poly[j].y;
//
//		// 点与多边形顶点重合
//		if ((x1 == x && y1 == y) || (x2 == x && y2 == y))
//		{
//			//return 'on'; // 点在轮廓上
//			return false;
//		}
//
//		// 判断线段两端点是否在射线两侧
//		if ((y1 < y && y2 >= y) || (y1 >= y && y2 < y)) // 只有一边取等号，当射线经过多边形顶点时，只计一次
//		{
//			// 线段上与射线 Y 坐标相同的点的 X 坐标
//			double crossX = (y - y1) * (x2 - x1) / (y2 - y1) + x1;  // y=kx+b变换成x=(y-b)/k 其中k=(y2-y1)/(x2-x1)
//
//			// 点在多边形的边上
//			if (crossX == x)
//			{
//				//return 'on'; // 点在轮廓上
//				return false;
//			}
//
//			// 右射线穿过多边形的边界，每穿过一次flag的值变换一次
//			if (crossX > x)
//			{
//				flag = !flag;  // 穿过奇数次为true，偶数次为false
//			}
//		}
//	}
//
//	// 射线穿过多边形边界的次数为奇数时点在多边形内
//	//return flag ? 'in' : 'out'; // 点在轮廓内或外
//	return flag ? true : false;
//}
//
//int i,j,k;
//int a[2] = { 2,1 }, b[2] = { 3,2 }, c[2] = { 1,4 }, d[2] = { 2,2 };
//
//int cd() {	//计算深度
//	return -(a[k] * i + b[k] * j + d[k]) / c[k];
//}
//
//void zbuffer() {
//	int depth;
//
//	for (i = 0; i <= 500; i++) {
//		for (j = 0; j <= 500; j++) {	//屏幕上每一个像素点
//
//			int indexp = 0;
//			int zb = -0x3f3f3f3f;
//			for(k=0;k<2;k++){	//两个图形
//				if (checkin(poly[k], i, j)) {	//如果（i，j）点在图形中
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
//	double k = (dy * 1.00) / (dx * 1.00);//计算斜率
//	if (dx == 0)//垂线
//	{
//		if (dy < 0)//起点在上方，调换
//		{
//			temp = p0;
//			p0 = p1;
//			p1 = temp;
//		}
//		for (p = p0; p.y < p1.y; p.y++)//主移动方向->y,不包括p1
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
//		double e = 0.00;//增量
//
//		if (k >= 0 && k <= 1)
//		{
//			if (dx < 0)//p1在左侧，调换
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0在左下
//
//			for (p = p0; p.x < p1.x; p.x++)//主移动方向->x,不包括p1
//			{
//				glColor3f(co[0],co[1],co[2]);
//				glVertex2f(p.x, p.y+1);
//				glColor3f(co[3],co[4],co[5]);//不同亮度值
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
//			if (dy < 0)//p1在左侧，调换
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0在下方
//
//			for (p = p0; p.y < p1.y; p.y++)//主移动方向->y,不包括p1
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
//			if (dx < 0)//p1在左上，调换
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0在左上
//
//			for (p = p0; p.x < p1.x; p.x++)//主移动方向->x,不包括p1
//			{
//				glColor3f(co[0],co[1],co[2]);
//				glVertex2f(p.x, p.y);
//				glColor3f(co[3],co[4],co[5]);//这里e是负数
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
//			if (dy > 0)//p1在上方，调换
//			{
//				temp = p0;
//				p0 = p1;
//				p1 = temp;
//			}//p0在上
//			for (p = p0; p.y > p1.y; p.y--)//主移动方向->y,不包括p1
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
//	// 初始化显示模式
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//
//	// 初始化窗口
//	glutInitWindowSize(w, h);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("实验五");
//
//	init();
//	zbuffer();
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	
//	// 开始主循环绘制
//	glutMainLoop();
//	return 0;
//}