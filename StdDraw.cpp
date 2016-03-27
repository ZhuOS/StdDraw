#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<unistd.h>
#include<string>
#include<string.h>
#include "StdDraw.h"
using namespace std;

//int nums[]={1,2,3,4,5,6,7,8,9,10,'\0'};

//char flagArray[11]={0,0,1,0,1,0,1,0,0,0};

//StdDraw<int> sdraw(nums);
StdDraw<int> sdraw;
// 显示函数

void Display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);
	static int times = 0;
	std::cout<<"times: "<<times++<<std::endl;
    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);


	sdraw.Draw();
 
    glutSwapBuffers();
}
void Update(int value)
{
	cout<<value<<endl;
}
void initOpenGL(int argc, char **argv){
	
	// 初始化OpenGL
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );

    // 设置界面大小，增加的范围用来显示边界
    glutInitWindowSize( WINDOW_WIDTH+100, WINDOW_HEIGHT+100);

    // 设置显示界面的位置
    glutInitWindowPosition( 50, 50 );

    // 创建游戏界面
    glutCreateWindow( "SortTraceView" );

    // 初始化界面背景色
    glClearColor( 0.0, 0.0, 0.0, 0.0 ) ;
    glMatrixMode(GL_MODELVIEW) ;  
    glLoadIdentity(); 
    gluOrtho2D(-50, (GLdouble)WINDOW_WIDTH+50, -50, (GLdouble)WINDOW_HEIGHT+50 );
    //srand(time(NULL));
	// 注册显示和键盘处理函数

    //glutKeyboardFunc(HandleKeyPress);

    // 设置Timer和更新函数
    glutTimerFunc(500,Update,0);
}
template<typename T>
int compare(T val1, T val2)
{
	return val1 < val2? -1: (val1 > val2? 1: 0);
}

template<typename T>
void exch(T a[],int index1, int index2)
{
	T temp = a[index1];
	a[index1] = a[index2];
	a[index2] = temp;
}
template<typename Type>
void sort(Type a[],int lo, int hi, bool colorArray[])
{
	usleep(10000);//10ms
	if(hi <= lo) return;
	int lt = lo, i = lo+1, gt = hi;
	Type v = a[lo];
	while(i <= gt)
	{
		
		int cmp = compare(a[i], v);
		if(cmp < 0) {
			colorArray[lt] = 1;
			colorArray[i]  = 1;
			exch(a, lt++, i++);
			sdraw.setColorArray(colorArray);
			//colorArray[lt-1] = 0;
			//colorArray[i-1] = 0;
		}
		else if(cmp > 0){
			colorArray[i]  = 1;
			colorArray[gt] = 1;
			exch(a, i, gt--);
			sdraw.setColorArray(colorArray);
			//colorArray[i] = 0;
			//colorArray[gt+1] = 0;
		}
		else i++;
		//std::cout<<i<<std::endl;
		glutPostRedisplay();
			
	}
	sort(a, lo, lt-1,colorArray);
	sort(a, gt+1, hi,colorArray);
}
int main(int argc, char **argv)
{
	initOpenGL(argc, argv);
    glutDisplayFunc(Display);
	//

	int nums[]={1,10,4,2,7,18,14,3,17,15};
	int size =sizeof(nums)/sizeof(int); 
 	bool flagArray[size];
	memset(flagArray, 0, size);
 	StdDraw<int> sd(nums, size);	
	sdraw = sd;
	
	sort(nums,0,9,flagArray);
    // 进入主循环
    glutMainLoop();
	return 0;
}
