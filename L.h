#pragma once
#include"Shapes.h"
class L :public shapes {

	//int SHAPEarr[4][4];
	int Degree0[4][4];
	int Degree90[4][4];
	int Degree180[4][4];
	int Degree270[4][4];


public:

	L();
	int count = 0;
	bool Compare(int[][4]);
	void defaultPosi(RenderWindow&);
	void draw(RenderWindow&, int, int);
	void moveLeft(RenderWindow&);
	void moveRight(RenderWindow&);
	void moveDown(RenderWindow&);

	void rotate90();
	void rotate(RenderWindow&);
};
