#pragma once
#include"Grid.h"
class shapes:public Grid {
protected:
	int ShapeNo;
	int PosiX;
	int PosiY;
	bool NewTetrimone=false;
	int IndexStored[4][2];
protected:
	int SHAPEarr[4][4];
public:
	shapes()
	{
		ShapeNo = 0;
		PosiX = 0; 
		PosiY = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				SHAPEarr[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				IndexStored[i][j] = 0;
			}
		}
	}
	int getShapeArr(int i, int j) { return SHAPEarr[i][j]; }
	void setShapeArr(int i, int j, int n) { SHAPEarr[i][j] = n; }
	bool getNewTertimone() { return NewTetrimone; }
	void setNewTetrimone(bool i) { NewTetrimone = i; }
	int getPosiX() { return PosiX; }
	void setPosiX(int n) {  PosiX=n; }
	int getPosiY() { return PosiY; }
	int getIndexStore(int i, int j) { return IndexStored[i][j]; }
	void setShapeNo(int n) { ShapeNo = n; }
	int getShapeNo() { return ShapeNo; }
	virtual void defaultPosi( RenderWindow&) = 0;
	virtual void draw(RenderWindow&, int, int) = 0;
	virtual void moveLeft( RenderWindow&) = 0;
	virtual void moveRight( RenderWindow&) = 0;
	virtual void moveDown(RenderWindow&) = 0;
	virtual void rotate90()=0;
	virtual void rotate( RenderWindow&) = 0;
	bool leftRotatedTetrimoneCollision(RenderWindow& window) {
		bool Collision = false;
		for (int i = 3, k = PosiY + 3; i >= 0 && k >= PosiY; i--, k--) {
			for (int j = 0, l = PosiX; j < 4 && l < PosiX + 4; j++, l++) {
				
			}
		}
	}
	//virtual void RotatedTetrimoneCollision()=0;
	/*bool CheckDown(int PosiX, int PosY) {
		
	}*/
	
};