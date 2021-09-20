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
//struct HE_vert;//����
//struct HE_face;//��
//struct HE_edge;//��
//
//struct HE_vert {
//	//�������ά����
//	float x;
//	float y;
//	float z;
//	//�Ըõ�Ϊ��ʼ��İ��֮һ
//	HE_edge* edge;  // one of the half-edges emantating from the vertex
//};
//
//struct HE_face {
//	//����һ���ָ��ƽ��İ��
//	HE_edge* edge;  // one of the half-edges bordering the face
//};
//
//struct HE_edge {//������ݽṹ
//	int id;//��ߵı��
//	HE_vert* vert;   //�ð�ߵ��յ�
//	HE_edge* pair;   //��ñ���Ե���һ�����
//	HE_face* face;   //�ñ߶�Ӧ����
//	HE_edge* next;   //��һ�����
//};
//
//class HE_off {
//private:
//	int vert_cnts, face_cnts, edge_cnts;
//	map<pair<int, int>, HE_edge*> edge_map; //�������Ӧ��һ���ߣ�pair���ǵ�����
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
//		//����������������������ߵ�����
//		this->HE_verts = new HE_vert[this->vert_cnts];//��һ�����������С�Ķ���ṹ������
//
//		//glBegin(GL_POINTS);
//		//��ʼ���涥��λ����Ϣ
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
//		this->HE_faces = new HE_face[this->face_cnts];//��һ����������С����ṹ������
//		this->HE_edges = new HE_edge[this->face_cnts * 5];//��һ���屶��������С�ı߽ṹ������
//
//		for (int i = 0; i < face_cnts; i++) {
//			int n;
//			int k[10];//��ÿ���߶�Ӧ�ĵ�����
//			fin >> n;//ÿһ�����Ӧ�ĵ�/��ߵ�����
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
//				(this->HE_edges + i * n + j)->face = (this->HE_faces + i);//�����߶�Ӧ����һ����
//				(this->HE_edges + i * n + j)->vert = (this->HE_verts + k[t]);//�����߶�Ӧ��ĩ�˽ڵ�
//				(this->HE_edges + i * n + j)->next = (this->HE_edges + i * n + t);//�����������������һ�����
//				(this->HE_edges + i * n + j)->id = i * n + j;//������ߵ���ţ��±꣩
//
//				this->edge_map[make_pair(k[j], k[t])] = (this->HE_edges + i * n + j);
//				//<�ڵ�[j],�ڵ�[j+1]> ��Ӧ ���[j]
//				auto iter = edge_map.find(make_pair(k[t], k[j]));
//				//�ұ�����߶�Ӧ����һ�����
//				if (iter != edge_map.end()) {
//					//����ҵ��ˣ����ڱ�����ߵĽṹ���д�����һ���ߵ�ָ��
//					(this->HE_edges + i * n + j)->pair = iter->second;
//					iter->second->pair = (this->HE_edges + i * n + j);
//				}
//
//				(this->HE_faces + i)->edge = (this->HE_edges + i * n + j);
//				//��i����ķָ��������������
//				// cout << "j: " << j << ", i*n+j:" << i*n+j << " k[j]:" << k[j] << ",k[t]:" << k[t] << endl;
//				(this->HE_verts + k[j])->edge = (this->HE_edges + i * n + j);
//				//�Ե�k[j]����Ϊ���ı��ǵڣ�i * n + j������
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
//		//���õ�Ĵ�С
//		glPointSize(7);
//		//����ƽ������
//		glEnable(GL_POINT_SMOOTH);
//		glHint(GL_POINT_SMOOTH, GL_NICEST);
//
//		glBegin(GL_POINTS);
//		//ָ���ĵ㣬������ɫ
//		glColor3f(0, 255, 0);
//		glVertex3f(a, b, c);
//		glEnd();
//
//		HE_edge* edge = (this->HE_verts + choose)->edge;
//
//		do {
//			glBegin(GL_POINTS);
//			//���ڵĵ㣬���ɺ�ɫ
//			glColor3f(255, 0, 0);
//			glVertex3f(edge->vert->x, edge->vert->y, edge->vert->z);
//			glEnd();
//
//			glBegin(GL_LINE_LOOP);
//			//glLineWidth(3.0f);
//			//���ڵıߣ�������ɫ
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
//	ArcBall->setBounds((GLfloat)w, (GLfloat)h); //1. ���ô��ڱ߽�
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
//	glTranslatef(ArcBall->rightPan, ArcBall->upPan, 0);//1. �ƶ�
//	glScalef(ArcBall->zoomRate, ArcBall->zoomRate, ArcBall->zoomRate);//2. ����
//	glMultMatrixf(ArcBall->Transform.M);                        //3. ��ת
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
//	cout << "����������������ڼ����㣩�����õ��Ϊ��ɫ���õ����ӵı߱�Ϊ��ɫ����õ������Ķ����Ϊ��ɫ��"<<endl;
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
