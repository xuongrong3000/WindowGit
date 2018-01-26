#include "GL/freeglut.h"
#include <iostream>

using namespace std;

// góc xoay của camera 
float angle = 0.0f;

// hướng nhìn của camera 
float lx = 0.0f, lz = -1.0f;

// toạ độ X và Z của camera 
float x = 0.0f, z = 5.0f;

// Biến toàn cục xác định các sự kiện chuột 
float deltaAngle = 0.0f;
float deltaMove = 0;
int xOrigin = -1;


// Hàm vẽ các đối tượng.
void draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Xoá ảnh trong buffer trước khi vẽ  //

														//////////////////////////
														// A Thiết lập ánh sáng //
														//////////////////////////

	GLfloat Lt0diff[] = { 1.0,1.0,1.0,1.0 };  // 1. Giá trị màu của ánh sáng (RGBA) - ánh sáng trắng (đục)									
	GLfloat Lt0pos[] = { 1.0f, 1.0f, 5.0f, 1.0f }; // 2. Vị trí của nguồn sáng

	glLightfv(GL_LIGHT0, GL_DIFFUSE, Lt0diff);
	glLightfv(GL_LIGHT0, GL_POSITION, Lt0pos);

	///////////////////////////////////////////////////////////
	// B Thiết lập chất liệu, màu sắc cho các vật thể cần vẽ   //
	///////////////////////////////////////////////////////////

	GLfloat diffColors[4] = { 0.5, 0.5, 0.9, 1.0 }; // Thiết lập màu khuyết tán,
	GLfloat specColor[] = { 1.0, 1.0, 1.0, 1.0 };  // màu phản xạ gương(specular color)
	GLfloat shininess[] = { 100.0 }; //  độ lấp lánh (shininess)
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, diffColors);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specColor);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, shininess);

	/////////////////////////////
	// C Vẽ vật thể 2D hoặc 3D //
	/////////////////////////////
	glutSolidTeapot(1.0); // Hàm vẽ ấm trà 
	glutSwapBuffers(); //chuyển đổi buffer và xuất ra màn hình
}



void initialize()
{
	glEnable(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //kích hoạt bộ đệm màu sắc, bộ đệm thông tin chiều sâu
	glEnable(GL_DEPTH_TEST);   // Kích hoạt chế độ Depth testing
	glEnable(GL_LIGHTING);     // Kích hoạt chế độ (tính toán) ánh sáng
	glEnable(GL_LIGHT0);       // Kích hoạt nguồn sáng #0

	glClearColor(0.2, 0.2, 0.2, 1.0); //Cài đặt giá trị màu nền

}

void setupViewPort() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.0, 1.0, 100.0); //(degree fov, uniform aspect ratio, near, far)

	glMatrixMode(GL_MODELVIEW);  // Sử dụng ma trận ModelView - tương tác với vị trí vật thể
	glLoadIdentity();              // Khởi tạo ma trận đơn vị (identity) hoặc xoá ma trận hiện hành thành ma trận đơn vị
	gluLookAt(0.0, 0.0, 5.0,  // Thiết lập vị trí camera [0,0,5], 
		0.0, 0.0, 0.0,		  // hướng nhìn về [0,0,0],
		0.0, 1.0, 0.0);       // với vector hướng lên là [0,1,0] (hướng nhìn đứng là theo toạ độ y (hướng lên trên).

}

// Hàm xử lý khi thay đổi kích thước cửa sổ w, h - chiều rộng và cao của cửa sổ tính trên pixel.
void reshapeFunc(int w, int h)
{

	if (w > h) {
		glViewport((w - h) / 2, 0, h, h);
	}
	else {
		glViewport(0, (h - w) / 2, w, w);
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, 1.0, 1.0, 100.0); //(degree fov, uniform aspect ratio, near, far)
	glMatrixMode(GL_MODELVIEW);
}

// Hàm Xử lý sự kiện bàn phím 
void keyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Phím Escape  (Esc)
		exit(0);
		break;
	case 'c':
		//////////////////////
		//    Bài tập 2		//
		// Thêm code xử lý  //
		//////////////////////
		cout << "chua xu ly phim nay: " << key << "." << endl;
		break;
	default:
		cout << "chua xu ly phim nay: " << key << "." << endl;
	}
	// refresh màn hình (vẽ lại khi có thay đổi)
	glutPostRedisplay();
}

// Hàm xử lý sự kiện các phím đặc biệt
void specialFunc(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		//////////////////////
		//    Bài tập 3  	//
		// Thêm code xử lý  //
		//////////////////////
		cout << "Phim dac biet: mui ten len" << endl;
		break;
	case GLUT_KEY_DOWN:
		cout << "Phim dac biet: mui ten xuong" << endl;
		// Thêm code xử lý
		break;
	case GLUT_KEY_LEFT:
		// Thêm code xử lý
		cout << "Phim dac biet: mui ten qua trai" << endl;
		break;
	case GLUT_KEY_RIGHT:
		// Thêm code xử lý
		cout << "Phim dac biet: mui ten qua phai" << endl;
		break;
	}
	// refresh màn hình (vẽ lại khi có thay đổi)
	glutPostRedisplay();
}

void mouseButton(int button, int state, int x, int y) {// (phím chuột, trạng thái chuột, toạ độ x, toạ độ y)

	if (button == GLUT_LEFT_BUTTON) { //Chuột trái
									  //////////////////////
									  //    Bài tập 4  	//
									  // Thêm code xử lý  //
									  //////////////////////
		angle += deltaAngle;
		xOrigin = -1;

		if (state == GLUT_UP) { //Nhả chuột

		}
		else {// vẫn đang giữ chuột 
			xOrigin = x;
		}
	}
}

void mouseMove(int x, int y) { // (toạ độ x, toạ độ y) khi di chuyển chuột
							   //////////////////////
							   //    Bài tập 5  	//
							   // Thêm code xử lý  //
							   //////////////////////
	if (xOrigin >= 0) {
		deltaAngle = (x - xOrigin) * 0.001f;
		// cập nhật góc nhìn của camera hoặc của người nhìn
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}


int main(int argc, char** argv)
{
	///////////////////////////////////////////////////
	// Các hàm khởi tạo cửa sổ và thiết lập mặc định //
	///////////////////////////////////////////////////
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); //Thiết lập chế độ hiển thị hình ảnh
	glutInitWindowPosition(60, 60); // Thiết lập vị trí cửa sổ chính của chương trình
	glutInitWindowSize(360, 360);   // Thiết lập kích thước cửa sổ chính 
	glutCreateWindow("DHNC Lab0"); //Tạo cửa sổ với tiêu đề DHNC Lab0

	initialize(); //Khởi tạo các trạng thái vẽ toàn cục 
	setupViewPort(); //thiết lập camera, khung nhìn, góc nhìn ...
					 //glutReshapeFunc(reshapeFunc);   // Đăng ký hàm xử lý khi thay đổi kích thước cửa sổ

					 ///////////////////////////////////////////////////////////////////////////////////
					 // Đăng ký các hàm callback (xử lý sự kiện chuột, bàn phím, thay đổi cửa sổ ...  //
					 ///////////////////////////////////////////////////////////////////////////////////

	glutKeyboardFunc(keyboardFunc); // Xử lý các kí tự ascii thông thường từ bàn phím
	glutSpecialFunc(specialFunc);   // Xử lý các kí tự đặc biệt từ bàn phím

	glutMouseFunc(mouseButton);  //Xử lý các sự kiện bấm chuột
	glutMotionFunc(mouseMove);	 //Xử lý các sự kiện di chuyển chuột

								 ///////////////////
								 // Hàm vẽ chính  //
								 ///////////////////
	glutDisplayFunc(draw);     // Đăng ký hàm vẽ đối tượng

	glutMainLoop(); 	// Khởi tạo vòng lặp chính, hàm glutMainLoop không bao giờ kết thúc trừ khi có sự kiện thoát.

	return 0;
}


