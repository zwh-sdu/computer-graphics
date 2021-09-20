//#include <GL/glut.h>  
//#include <iostream>
//#include <stdio.h>  
//#include <stdlib.h>
//#include <math.h> 
//#include <assert.h>
//#include <string.h>
//#include<vector>
//#include <fstream>
//#include "arcball.h"
//
//using namespace std;
//
//#define PI 3.1415926536
//int choose = 0;
//
//typedef struct Vertex//����ṹ
//{
//	float x, y, z;//���������
//}Vertex;
//
//typedef struct Face//��ṹ
//{
//	int num;//�ߵ����
//	int order[3];//һ�����Ӧ��������������
//}Face;
//
//typedef struct HalfEdge//��߽ṹ
//{
//	int origin;//��ʼ��������
//	struct HalfEdge* next;//��һ����ߵ�ָ��
//	struct HalfEdge* opposite;//��Եİ�ߵ�ָ��
//	int theface;//��Ӧ��������
//}HalfEdge;
//
//vector<Vertex> vertex;//������еĶ���
//vector<Face> face;//������е���
//vector<HalfEdge*> edge;//������еİ��
//int e_num;
//int n_node, n_face, n_edge;
//int width = 800;
//int height = 800;
//
//int readoff()
//{
//	char theoff[233] = "bunny.off";
//	ifstream fin(theoff);
//	if (!fin.is_open()) {
//		puts("error opening file.");
//		exit(1);
//	}
//	string isoff;
//	do {
//		fin >> isoff;
//	} while (isoff[0] == '#');
//	if (isoff != "OFF") {
//		puts("this is not a .off file.");
//		exit(1);
//	}
//	fin >> n_node >> n_face >> n_edge;
//	//�������㣬�����棬������
//
//	for (int i = 0; i < n_node; i++)
//	{
//		Vertex ver;
//		fin >> ver.x >> ver.y >> ver.z;
//		vertex.push_back(ver);
//	}
//	for (int i = 0; i < n_face; i++)
//	{
//		Face f;
//		fin >> f.num >> f.order[0] >> f.order[1] >> f.order[2];
//		face.push_back(f);
//	}
//}
//
//void initEdge()//���ɰ�ߴ���vector
//{
//	int** map = new int* [n_node];
//	for (int i = 0; i < n_node; i++) {
//		map[i] = new int[n_node];
//	}
//	//��ʼ��һ����ά���飬map[i][j]����˼�Ǵӵ�i�����㵽��j������ıߵ���ţ������ڱߵĻ��͵���-1
//	for (int i = 0; i < n_node; i++)
//	{
//		for (int j = 0; j < n_node; j++)
//		{
//			map[i][j] = -1;
//		}
//	}
//	e_num = 0;//�ߵ����
//	//��Ϊֻ����������������һ����һ����Ӧ�����������������
//	for (int i = 0; i < n_face; i++)
//	{
//		HalfEdge* edge1 = new HalfEdge();
//		HalfEdge* edge2 = new HalfEdge();
//		HalfEdge* edge3 = new HalfEdge();
//
//		edge1->origin = face[i].order[0];
//		edge2->origin = face[i].order[1];
//		edge3->origin = face[i].order[2];
//
//		edge1->next = edge2;
//		edge2->next = edge3;
//		edge3->next = edge1;
//
//		HalfEdge* temp = new HalfEdge();
//		if (map[face[i].order[1]][face[i].order[0]] != -1)//�����������Ѿ��ɶԱ���
//		{
//			temp = edge[map[face[i].order[1]][face[i].order[0]]];
//			edge1->opposite = temp;
//			temp->opposite = edge1;
//		}
//		else//������߻�û�жԱ�
//		{
//			edge1->opposite = NULL;
//			map[face[i].order[0]][face[i].order[1]] = e_num;
//		}
//		e_num++;
//		if (map[face[i].order[2]][face[i].order[1]] != -1)
//		{
//			temp = edge[map[face[i].order[2]][face[i].order[1]]];
//			edge2->opposite = temp;
//			temp->opposite = edge2;
//		}
//		else
//		{
//			edge2->opposite = NULL;
//			map[face[i].order[1]][face[i].order[2]] = e_num;
//		}
//		e_num++;
//		if (map[face[i].order[0]][face[i].order[2]] != -1)
//		{
//			temp = edge[map[face[i].order[0]][face[i].order[2]]];
//			edge3->opposite = temp;
//			temp->opposite = edge3;
//		}
//		else
//		{
//			edge3->opposite = NULL;
//			map[face[i].order[2]][face[i].order[0]] = e_num;
//		}
//		e_num++;
//
//		edge1->theface = i;
//		edge2->theface = i;
//		edge3->theface = i;
//
//		edge.push_back(edge1);
//		edge.push_back(edge2);
//		edge.push_back(edge3);
//	}
//	n_edge = edge.size();
//}
//
//HalfEdge* findonedge(int point)//�ҵ��Ӹö��������һ�����
//{
//	for (int k = 0; k < n_edge; k++)
//	{
//		if (edge[k]->origin == point)
//			return edge[k];
//	}
//	return NULL;
//}
//
//void subdivide()//ϸ��
//{
//	vector<Vertex> vertex2;//�µĶ���
//	vector<Face> face2;//�µ���
//	vector<HalfEdge*> edge2;//�µİ��
//	HalfEdge* he = new HalfEdge();
//	int n;
//	float p_sumx, p_sumy, p_sumz;
//	float px, py, pz;
//	float beta;
//	cout << "ϸ�ֿ�ʼ" << endl;
//	for (int i = 0; i < n_node; i++)//�ɵ����
//	{
//		//����ÿһ�����㣬�����������б������Ļ�
//		he = findonedge(i);
//
//		if (he != NULL)
//		{
//			n = 0;
//			p_sumx = 0;
//			p_sumy = 0;
//			p_sumz = 0;
//			HalfEdge* e = new HalfEdge();
//			e = he->next;
//			int p0 = e->origin;
//			//������i�����������ж��㣬p_sum��¼��Щ���������֮��
//			while (e->next->origin != p0)
//			{
//				n++;
//				p_sumx += vertex[e->next->origin].x;
//				p_sumy += vertex[e->next->origin].y;
//				p_sumz += vertex[e->next->origin].z;
//				HalfEdge* te = new HalfEdge();
//				te = e->next->opposite;
//				e = te->next;
//			}
//			n++;
//			p_sumx += vertex[p0].x;
//			p_sumy += vertex[p0].y;
//			p_sumz += vertex[p0].z;
//			beta = 1 / (double)n * (0.625 - pow(0.375 + 0.25 * cos(2 * PI / n), 2));
//			//p�Ǹ�����i���������ж��������������µ�i���������
//			px = (1 - n * beta) * vertex[i].x + beta * p_sumx;
//			py = (1 - n * beta) * vertex[i].y + beta * p_sumy;
//			pz = (1 - n * beta) * vertex[i].z + beta * p_sumz;
//
//			Vertex v;
//			v.x = px;
//			v.y = py;
//			v.z = pz;
//			vertex2.push_back(v);
//		}
//	}
//	//��ʱ����ֵǮ���ڵĶ������������ϣ�����Ҫ�����µĶ���
//	int** map1 = new int* [n_node];
//	for (int i = 0; i < n_node; i++) {
//		map1[i] = new int[n_node];
//	}
//	for (int i = 0; i < n_node; i++) {
//		for (int j = 0; j < n_node; j++) {
//			map1[i][j] = 0;
//		}
//	}
//
//	float qx, qy, qz;
//	//����ÿһ�����
//	for (int i = 0; i < n_edge; i++)//�µ�����
//	{
//		if (!map1[edge[i]->origin][edge[i]->next->origin])//���������
//		{
//			int p = edge[i]->origin;//�����ߵ���ʼ����
//			int pi = edge[i]->next->origin;//�����ߵ��յ�
//			int pi1 = edge[i]->next->next->origin;//����һ������
//			int pi0 = edge[i]->opposite->next->next->origin;//����һ�ߵ���һ������
//			//��������������һ���µĶ���
//			qx = 0.375 * (vertex[p].x + vertex[pi].x) + 0.125 * (vertex[pi1].x + vertex[pi0].x);
//			qy = 0.375 * (vertex[p].y + vertex[pi].y) + 0.125 * (vertex[pi1].y + vertex[pi0].y);
//			qz = 0.375 * (vertex[p].z + vertex[pi].z) + 0.125 * (vertex[pi1].z + vertex[pi0].z);
//
//			Vertex v;
//			v.x = qx;
//			v.y = qy;
//			v.z = qz;
//			vertex2.push_back(v);
//
//			map1[edge[i]->origin][edge[i]->next->origin] = vertex2.size() - 1;
//			map1[edge[i]->next->origin][edge[i]->origin] = vertex2.size() - 1;
//		}
//	}
//	for (int i = 0; i < n_face; i++)//����
//	{
//		int a, b, c, d, e, f;
//		//a,b,c��֮ǰ�Ķ��㣬d,e,f�Ǹղ������ɵĶ���
//		a = face[i].order[0];
//		b = face[i].order[1];
//		c = face[i].order[2];
//		d = map1[a][b];
//		e = map1[b][c];
//		f = map1[a][c];
//
//		Face f2;
//		f2.num = 3;
//
//		f2.order[0] = a;
//		f2.order[1] = d;
//		f2.order[2] = f;
//		face2.push_back(f2);
//
//		f2.order[0] = d;
//		f2.order[1] = b;
//		f2.order[2] = e;
//		face2.push_back(f2);
//
//		f2.order[0] = d;
//		f2.order[1] = e;
//		f2.order[2] = f;
//		face2.push_back(f2);
//
//		f2.order[0] = f;
//		f2.order[1] = e;
//		f2.order[2] = c;
//		face2.push_back(f2);
//	}
//
//	n_face = face2.size();
//	n_node = vertex2.size();
//
//	int** map2 = new int* [n_node];
//	for (int i = 0; i < n_node; i++) {
//		map2[i] = new int[n_node];
//	}
//	for (int i = 0; i < n_node; i++)
//	{
//		for (int j = 0; j < n_node; j++)
//		{
//			map2[i][j] = -1;
//		}
//	}
//	e_num = 0;
//	for (int i = 0; i < n_face; i++)//�±�
//	{
//		HalfEdge* edge4 = new HalfEdge();
//		HalfEdge* edge5 = new HalfEdge();
//		HalfEdge* edge6 = new HalfEdge();
//
//		edge4->origin = face2[i].order[0];
//		edge5->origin = face2[i].order[1];
//		edge6->origin = face2[i].order[2];
//
//		edge4->next = edge5;
//		edge5->next = edge6;
//		edge6->next = edge4;
//
//		HalfEdge* temp = new HalfEdge();
//		if (map2[face2[i].order[1]][face2[i].order[0]] != -1)
//		{
//			temp = edge2[map2[face2[i].order[1]][face2[i].order[0]]];
//			edge4->opposite = temp;
//			temp->opposite = edge4;
//		}
//		else
//		{
//			edge4->opposite = NULL;
//			map2[face2[i].order[0]][face2[i].order[1]] = e_num;
//		}
//		e_num++;
//		if (map2[face2[i].order[2]][face2[i].order[1]] != -1)
//		{
//			temp = edge2[map2[face2[i].order[2]][face2[i].order[1]]];
//			edge5->opposite = temp;
//			temp->opposite = edge5;
//		}
//		else
//		{
//			edge5->opposite = NULL;
//			map2[face2[i].order[1]][face2[i].order[2]] = e_num;
//		}
//		e_num++;
//		if (map2[face2[i].order[0]][face2[i].order[2]] != -1)
//		{
//			temp = edge2[map2[face2[i].order[0]][face2[i].order[2]]];
//			edge6->opposite = temp;
//			temp->opposite = edge6;
//		}
//		else
//		{
//			edge6->opposite = NULL;
//			map2[face2[i].order[2]][face2[i].order[0]] = e_num;
//		}
//		e_num++;
//
//		edge4->theface = i;
//		edge5->theface = i;
//		edge6->theface = i;
//
//		edge2.push_back(edge4);
//		edge2.push_back(edge5);
//		edge2.push_back(edge6);
//	}
//	n_edge = edge2.size();
//
//	vertex.assign(vertex2.begin(), vertex2.end());
//
//	face.assign(face2.begin(), face2.end());
//
//	edge.assign(edge2.begin(), edge2.end());
//
//	cout << "ϸ�����" << endl;
//
//
//}
//
//ArcBallT arcBall(600.0f, 400.0f);
//ArcBallT* ArcBall = &arcBall;// new ArcBallT(600.0f,400.0f);//&arcBall;
//
//void display()
//{
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glColor3f(1.0, 1.0, 1.0);
//	glLoadIdentity();
//	gluLookAt(0.0, 0.0, 5.0,
//		0.0, 0.0, 0.0,
//		0.0, 1.0, 0.0);
//	glScalef(1.0, 2.0, 1.0);
//
//	//glPushMatrix();
//	glTranslatef(ArcBall->rightPan, ArcBall->upPan, 0);//1. �ƶ�
//	glScalef(ArcBall->zoomRate, ArcBall->zoomRate, ArcBall->zoomRate);//2. ����
//	glMultMatrixf(ArcBall->Transform.M);                        //3. ��ת
//
//
//	for (int i = 0; i < n_face; i++)
//	{	
//		glBegin(GL_LINE_STRIP);
//		glVertex3f(vertex[face[i].order[0]].x, vertex[face[i].order[0]].y, vertex[face[i].order[0]].z);
//		glVertex3f(vertex[face[i].order[1]].x, vertex[face[i].order[1]].y, vertex[face[i].order[1]].z);
//		glVertex3f(vertex[face[i].order[2]].x, vertex[face[i].order[2]].y, vertex[face[i].order[2]].z);
//		glVertex3f(vertex[face[i].order[0]].x, vertex[face[i].order[0]].y, vertex[face[i].order[0]].z);
//		glEnd();
//	}
//	float a, b, c;
//	a = vertex[choose].x;
//	b = vertex[choose].y;
//	c = vertex[choose].z;
//
//	//���õ�Ĵ�С
//	glPointSize(7);
//	//����ƽ������
//	glEnable(GL_POINT_SMOOTH);
//	glHint(GL_POINT_SMOOTH, GL_NICEST);
//
//	glBegin(GL_POINTS);
//	//ָ���ĵ㣬������ɫ
//	glColor3f(0, 255, 0);
//	glVertex3f(a, b, c);
//	glEnd();
//
//	HalfEdge* edge = findonedge(choose);
//
//	do {
//		glBegin(GL_POINTS);
//		//���ڵĵ㣬���ɺ�ɫ
//		glColor3f(255, 0, 0);
//		glVertex3f(vertex[edge->origin].x, vertex[edge->origin].y, vertex[edge->origin].z);
//		glEnd();
//
//		glBegin(GL_LINE_LOOP);
//		//glLineWidth(3.0f);
//		//���ڵıߣ�������ɫ
//		glColor4ub(0, 0, 255, 255);
//		glColor3f(0, 0, 255);
//		glVertex3f(a, b, c);
//		glVertex3f(vertex[edge->opposite->origin].x, vertex[edge->opposite->origin].y, vertex[edge->opposite->origin].z);
//		glEnd();
//
//		edge = edge->opposite->next;
//	} while (edge != findonedge(choose));
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//	switch (key)
//	{
//	case 'w':
//		subdivide();
//		break;
//	}
//	glutPostRedisplay();
//}
//
//void reshape(int w, int h) {
//	//�����ӿڴ�С
//	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//	//ͶӰ��ʾ
//	glMatrixMode(GL_PROJECTION);
//	//����ԭ������Ļ����
//	glLoadIdentity();
//	//����ģ���Ӿ�
//	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
////�ƶ�
//void move(int x, int y)
//{
//	ArcBall->MousePt.s.X = x;
//	ArcBall->MousePt.s.Y = y;
//	ArcBall->upstate();
//	glutPostRedisplay();
//}
////���
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
//}
//
//int main(int argc, char** argv)
//{
//	cout << "����������������ڼ����㣩�����õ��Ϊ��ɫ���õ����ӵı߱�Ϊ��ɫ����õ������Ķ����Ϊ��ɫ��" << endl;
//	cin >> choose;
//	readoff();
//	initEdge();
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(width, height);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("loop");
//	glutReshapeFunc(reshape);
//	glutDisplayFunc(display);
//	glutIdleFunc(display);
//	glutMouseFunc(mouse);
//	glutMotionFunc(move);
//	glutKeyboardFunc(keyboard);
//	glutMainLoop();
//	return 0;
//}