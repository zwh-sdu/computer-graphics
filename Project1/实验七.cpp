//#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
//#include <string.h>
//#include <time.h>
//#include <GL/glut.h>
//#include <iostream>
//#include <fstream>
//#include <stdlib.h>
//#include <map>
//#include "arcball.h"
//using namespace std;
//
//int choose = 0;
//
//struct HE_vert;//顶点
//struct HE_face;//面
//struct HE_edge;//边
//
//struct HE_vert {
//	//顶点的三维坐标
//	float x;
//	float y;
//	float z;
//	//以该点为起始点的半边之一
//	HE_edge* edge;  // one of the half-edges emantating from the vertex
//};
//
//struct HE_face {
//	//其中一个分割该平面的半边
//	HE_edge* edge;  // one of the half-edges bordering the face
//};
//
//struct HE_edge {//半边数据结构
//	int id;//半边的标号
//	HE_vert* vert;   //该半边的终点
//	HE_edge* pair;   //与该边相对的另一条半边
//	HE_face* face;   //该边对应的面
//	HE_edge* next;   //下一条半边
//};
//
//class HE_off {
//private:
//	int vert_cnts, face_cnts, edge_cnts;
//	map<pair<int, int>, HE_edge*> edge_map; //两个点对应着一条边，pair中是点的序号
//	HE_vert* HE_verts;
//	HE_face* HE_faces;
//	HE_edge* HE_edges;
//public:
//	HE_off() {}
//	~HE_off() {
//		delete HE_verts;
//		delete HE_faces;
//		delete HE_edges;
//	}
//
//
//	void read_off() {
//		char theOff[233] = "cube.off";
//		// cin >> theOff;
//		ifstream fin(theOff);
//		if (!fin.is_open()) {
//			puts("Error opening file.");
//			exit(1);
//		}
//		string isOff;
//		do {
//			fin >> isOff;
//		} while (isOff[0] == '#');
//		if (isOff != "OFF") {
//			puts("This is not a .off file.");
//			exit(1);
//		}
//
//		fin >> this->vert_cnts >> this->face_cnts >> this->edge_cnts;
//		//读入点的数量，面的数量，边的数量
//		this->HE_verts = new HE_vert[this->vert_cnts];//开一个点的数量大小的顶点结构体数组
//
//		//glBegin(GL_POINTS);
//		//开始储存顶点位置信息
//		for (int i = 0; i < vert_cnts; i++) {
//			float a, b, c;
//			fin >> a >> b >> c;
//			(this->HE_verts + i)->x = a, (this->HE_verts + i)->y = b, (this->HE_verts + i)->z = c;
//			//cout << a << b << c << endl;
//			//glVertex3d(a, b, c);
//		}
//		//glEnd();
//
//
//		this->HE_faces = new HE_face[this->face_cnts];//开一个面数量大小的面结构体数组
//		this->HE_edges = new HE_edge[this->face_cnts * 5];//开一个五倍面数量大小的边结构体数组
//
//		for (int i = 0; i < face_cnts; i++) {
//			int n;
//			int k[10];//存每个边对应的点的序号
//			fin >> n;//每一个面对应的点/半边的数量
//
//			//cout << "face_point: ";
//			for (int j = 0; j < n; j++) {
//				fin >> k[j];
//			}
//
//			//glBegin(GL_POLYGON);
//			glBegin(GL_LINE_LOOP);
//			for (int j = 0; j < n; j++) {
//				int t = (j + 1) % n;
//
//				(this->HE_edges + i * n + j)->face = (this->HE_faces + i);//这个半边对应的哪一个面
//				(this->HE_edges + i * n + j)->vert = (this->HE_verts + k[t]);//这个半边对应的末端节点
//				(this->HE_edges + i * n + j)->next = (this->HE_edges + i * n + t);//与这条半边相连的下一条半边
//				(this->HE_edges + i * n + j)->id = i * n + j;//这条半边的序号（下标）
//
//				this->edge_map[make_pair(k[j], k[t])] = (this->HE_edges + i * n + j);
//				//<节点[j],节点[j+1]> 对应 半边[j]
//				auto iter = edge_map.find(make_pair(k[t], k[j]));
//				//找本条半边对应的另一条半边
//				if (iter != edge_map.end()) {
//					//如果找到了，就在本条半边的结构体中储存另一半半边的指针
//					(this->HE_edges + i * n + j)->pair = iter->second;
//					iter->second->pair = (this->HE_edges + i * n + j);
//				}
//
//				(this->HE_faces + i)->edge = (this->HE_edges + i * n + j);
//				//第i个面的分割边是现在这个半边
//				// cout << "j: " << j << ", i*n+j:" << i*n+j << " k[j]:" << k[j] << ",k[t]:" << k[t] << endl;
//				(this->HE_verts + k[j])->edge = (this->HE_edges + i * n + j);
//				//以第k[j]个点为起点的边是第（i * n + j）个边
//				float a, b, c;
//				a = (this->HE_verts + k[j])->x;
//				b = (this->HE_verts + k[j])->y;
//				c = (this->HE_verts + k[j])->z;
//
//				//glBegin(GL_POINT);
//				glVertex3f(a, b, c);
//				//cout << k << " ";
//			}
//			glEnd();
//			//cout << endl;
//		}
//	}
//
//	void drawpoint() {
//		float a, b, c;
//		a = (this->HE_verts + choose)->x;
//		b = (this->HE_verts + choose)->y;
//		c = (this->HE_verts + choose)->z;
//
//		//设置点的大小
//		glPointSize(7);
//		//进行平滑处理　
//		glEnable(GL_POINT_SMOOTH);
//		glHint(GL_POINT_SMOOTH, GL_NICEST);
//
//		glBegin(GL_POINTS);
//		//指定的点，换成绿色
//		glColor3f(0, 255, 0);
//		glVertex3f(a, b, c);
//		glEnd();
//
//		HE_edge* edge = (this->HE_verts + choose)->edge;
//
//		do {
//			glBegin(GL_POINTS);
//			//相邻的点，换成红色
//			glColor3f(255, 0, 0);
//			glVertex3f(edge->vert->x, edge->vert->y, edge->vert->z);
//			glEnd();
//
//			glBegin(GL_LINE_LOOP);
//			//glLineWidth(3.0f);
//			//相邻的边，换成蓝色
//			glColor4ub(0, 0, 255, 255);
//			glColor3f(0, 0, 255);
//			glVertex3f(a, b, c);
//			glVertex3f(edge->vert->x, edge->vert->y, edge->vert->z);
//			glEnd();
//
//			edge = edge->pair->next;
//		} while (edge != (this->HE_verts + choose)->edge);
//
//	}
//};
//
//ArcBallT arcBall(600.0f, 400.0f);
//ArcBallT* ArcBall = &arcBall;// new ArcBallT(600.0f,400.0f);//&arcBall;
//
//void reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1, 1, -1, 1, 1.5, 20);
//	glMatrixMode(GL_MODELVIEW);
//	//ball
//	ArcBall->setBounds((GLfloat)w, (GLfloat)h); //1. 设置窗口边界
//}
//void init() {
//	glClearColor(0, 0, 0, 0);
//	glShadeModel(GL_FLAT);
//}
//
//
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//	glLoadIdentity();
//	gluLookAt(0.0, 0.0, 5.0,
//		0.0, 0.0, 0.0,
//		0.0, 1.0, 0.0);
//	glScalef(1.0, 2.0, 1.0);
//
//	//glPushMatrix();
//	glTranslatef(ArcBall->rightPan, ArcBall->upPan, 0);//1. 移动
//	glScalef(ArcBall->zoomRate, ArcBall->zoomRate, ArcBall->zoomRate);//2. 缩放
//	glMultMatrixf(ArcBall->Transform.M);                        //3. 旋转
//	//glutWireCube(1.0);
//
//	/*glBegin(GL_POLYGON);*/
//
//
//	HE_off myoff;
//	myoff.read_off();
//	myoff.drawpoint();
//
//	glFlush();
//}
////移动
//void move(int x, int y)
//{
//	ArcBall->MousePt.s.X = x;
//	ArcBall->MousePt.s.Y = y;
//	ArcBall->upstate();
//	glutPostRedisplay();
//}
////点击
//void mouse(int button, int state, int x, int y)
//{
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
//		ArcBall->isClicked = true;
//		move(x, y);
//	}
//	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//		ArcBall->isClicked = false;
//	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
//		ArcBall->isRClicked = true;
//		move(x, y);
//	}
//	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
//		ArcBall->isRClicked = false;
//	else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP)
//		ArcBall->isRClicked = false;
//	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
//		ArcBall->isMClicked = true;
//		move(x, y);
//	}
//	else if (button == GLUT_MIDDLE_BUTTON && state == GLUT_UP)
//		ArcBall->isMClicked = false;
//	ArcBall->upstate();
//	glutPostRedisplay();
//
//
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(640, 480);
//	//glutCreateWindow("TEST_Arcball");
//	glutCreateWindow("MY_OFF");
//
//	cout << "给出顶点的索引（第几个点），将该点变为绿色，该点连接的边变为蓝色，与该点相连的顶点变为红色："<<endl;
//	cin >> choose;
//
//	init();
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//
//	glutMouseFunc(mouse);
//	glutMotionFunc(move);
//
//	glutMainLoop();
//
//	return 0;
//}
