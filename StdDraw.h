//StdDraw.h
#ifndef COMMON_H
#define COMMON_H
#include <GL/glut.h>
#include<iostream>
//显示界面的大小
#define WINDOW_WIDTH	500
#define WINDOW_HEIGHT	500
//方块大小
#define BLOCK_WIDTH	    2
#define BLOCK_HEIGHT	19
#define BLOCK_SPACING	1
//界面容纳方块数量
#define BLOCK_NUM_X	WINDOW_WIDTH/(BLOCK_WIDTH+BLOCK_SPACING)
#define BLOCK_NUM_Y	WINDOW_HEIGHT/(BLOCK_HEIGHT+BLOCK_SPACING)



template<typename T>
class Block{
public:
	Block(){}
	~Block(){}
void Draw(int posX, int posY, T value, bool colorChoice)
    {
		X = posX*(BLOCK_WIDTH+BLOCK_SPACING);
		Y = posY*(BLOCK_HEIGHT+BLOCK_SPACING);
		vl = value;
		glBegin(GL_QUADS);
		colorChoice? glColor3d(1,0,0): glColor3d(0,1,0);
		glVertex3f(X, Y, 0);
    	glVertex3f(X+BLOCK_WIDTH, Y, 0);
    	glVertex3f(X+BLOCK_WIDTH, Y+vl, 0);
    	glVertex3f(X, Y+vl, 0);
		glEnd();
	}
private:
	int X, Y;
    T vl;
	
};

template<typename T>
class StdDraw{
public:
	StdDraw(){}
	StdDraw(T p[], int n){
		size = n;
		colorArray = new bool[size];
		array = p;
	}
	~StdDraw(){
		//delete [] array;
      // delete [] colorArray;
	}
	void setColorArray(bool array[]){	colorArray = array;    }
    
	//void setPos(int pos_x, int pos_y){	X = pos_x*100; Y = pos_y;	}

	void Draw(){
		std::cout<<"Y: "<<Y<<std::endl;	
		Block<T> blk;
		for(int i = 0; i < size; i++)
			blk.Draw(X+i, Y, array[i], colorArray[i]);
		Y--;
		if(Y < 0){
			Y = 25;
			X = 100;
		}	
	}

private:
	int size;
	static int X,Y;
	T *array;
    bool *colorArray;
	//Block<T> blk;
};
template<typename T>
int StdDraw<T>::X = 0;
template<typename T>
int StdDraw<T>::Y = 25;
#endif
