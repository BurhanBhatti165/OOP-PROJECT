#pragma once
#include"Shapes.h"
class O:public shapes {

	//int SHAPEarr[4][4];

public:

	O();
	void draw(RenderWindow&, int, int);
	void defaultPosi( RenderWindow&);
	void moveLeft( RenderWindow&);
	void moveRight( RenderWindow&);
	void moveDown( RenderWindow&);
	void rotate( RenderWindow&);
	void rotate90(){}
};
