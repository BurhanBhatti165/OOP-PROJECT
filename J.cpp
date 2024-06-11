#include "J.h"

J::J()
{
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {						
			temp = i * 4 + j;
			if (temp == 2 || temp == 6 || temp == 10 || temp == 9)
				SHAPEarr[i][j] = 2;
			else
				SHAPEarr[i][j] = 0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = i * 4 + j;
			if (temp == 2 || temp == 6 || temp == 10 || temp == 9)				/*for 0 degree shape*/
				Degree0[i][j] = 2;
			else
				Degree0[i][j] = 0;
			if (temp == 5 || temp == 9 || temp == 10 || temp == 11)				/*for 90 degree shape*/
				Degree90[i][j] = 2;
			else
				Degree90[i][j] = 0;
			if (temp == 5 || temp == 6 || temp == 9 || temp == 13)				/*for 180 degree shape*/
				Degree180[i][j] = 2;
			else
				Degree180[i][j] = 0;
			if (temp == 4 || temp == 5 || temp == 6 || temp == 10)				/*for 270 degree shape*/
				Degree270[i][j] = 2;
			else
				Degree270[i][j] = 0;
		}
	}
	PosiX = 0;
	PosiY = 0;
}

bool J::Compare(int Temp[][4])
{
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (SHAPEarr[i][j] != Temp[i][j])
				return false;
		}
	}
	return true;
}

void J::defaultPosi(RenderWindow& window)
{
	PosiX = 0, PosiY = 3;
	
	cout << endl;
	for (int i = 0,k=PosiX; i < 4; i++,k++) {
		for (int j = 0,l=PosiY; j < 4; j++,l++) {
			if (SHAPEarr[i][j] == 2)
			{
				RectangleShape J1(Vector2f(this->cellSize - 2, this->cellSize - 2));
				J1.setPosition(Vector2f(l * this->cellSize, k * this->cellSize));
				J1.setFillColor(Color::Blue);
				window.draw(J1);
			}
		}
	}
}

void J::draw(RenderWindow& window, int PosiX, int PosiY)
{
	int IndexStoreX = 0, IndexStoreY = 0;
	for (int i = 0, k = PosiX; i < 4; i++, k++) {
		for (int j = 0, l = PosiY; j < 4; j++, l++) {
			if (SHAPEarr[i][j] == 2)
			{
				RectangleShape J1(Vector2f(this->cellSize - 2, this->cellSize - 2));
				J1.setPosition(Vector2f(l * this->cellSize, k * this->cellSize));
				J1.setFillColor(Color::Blue);
				window.draw(J1);

				if (NewTetrimone) {
					if (IndexStoreY == 0) {
						IndexStored[IndexStoreX][IndexStoreY] = k;
						IndexStoreY++;
					}
					if (IndexStoreY == 1) {
						IndexStored[IndexStoreX][IndexStoreY] = l;
						IndexStoreX++;
						IndexStoreY = 0;
					}
				}	ShapeNo = SHAPEarr[i][j];
			}
		}
	}

}

void J::moveLeft( RenderWindow& window)
{	
	if (Compare(Degree180) && PosiX >= 16) {
		draw(window, 16, PosiY);
	}
	else if (!Compare(Degree180) && PosiX >= 17) {
		draw(window, 17, PosiY);
	}
	else {
		if (Compare(Degree270))
		{
			if (PosiY <= 0) {
				draw(window, PosiX, 0);
				PosiY = 0;
			}
			if (PosiY > 0) {
				draw(window, PosiX, PosiY - 1);
				PosiY -= 1;
			}
		}
		else
		{
			if (PosiY <= -1) {
				draw(window, PosiX, -1);
				PosiY = -1;
			}
			if (PosiY > -1) {
				draw(window, PosiX, PosiY - 1);
				PosiY -= 1;
			}
		}
	}
		
}
void J::moveRight( RenderWindow& window)
{
	if (Compare(Degree180) && PosiX >= 16) {
		draw(window, 16, PosiY);
	}
	else if (!Compare(Degree180) && PosiX >= 17) {
		draw(window, 17, PosiY);
	}
	else {
		if (Compare(Degree90))
		{
			if (PosiY >= 6) {
				draw(window, PosiX, 6);
				PosiY = 6;
			}
			if (PosiY < 6) {
				draw(window, PosiX, PosiY + 1);
				PosiY += 1;
			}
		}
		else
		{
			if (PosiY >= 7) {
				draw(window, PosiX, 7);
				PosiY = 7;
			}
			if (PosiY < 7) {
				draw(window, PosiX, PosiY + 1);
				PosiY += 1;
			}
		}
	}
}

void J::moveDown( RenderWindow& window)
{
	if (Compare(Degree180)) {
		if (PosiX >= 16) {
			NewTetrimone = true;
			draw(window, 16, PosiY);
			NewTetrimone = false;
			PosiX = 19;
		}
		if (PosiX < 16) {
			draw(window, PosiX+1, PosiY);
			PosiX += 1;
		}
	}
	else {
		if (PosiX >= 17) {
			NewTetrimone = true;
			draw(window, 17, PosiY);
			NewTetrimone = false;
			PosiX = 19;
		}
		if (PosiX < 17) {
			draw(window, PosiX + 1, PosiY);
			PosiX += 1;
		}
	}
}



void J::rotate90()
{
	int Temp[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			Temp[i][j] = 0;
		}
	}

	//copying data as a rotated array
	for (int i = 0, k = 0; i < 4 && k < 4; i++, k++) {		//i is column of ShapeArr and k is row of Temp array
		for (int j = 3, l = 0; j >= 0 && l < 4; j--, l++) {		//j is row of ShapeArr and l is column of Temp array
			Temp[k][l] = this->SHAPEarr[j][i];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			this->SHAPEarr[i][j] = Temp[i][j];
		}
	}
}

void J::rotate(RenderWindow& window)
{
	if (Compare(Degree180) && PosiX >= 16) {
		draw(window, 16, PosiY);
	}
	else if (!Compare(Degree180) && PosiX >= 17) {
		draw(window, 17, PosiY);
	}
	else {
		rotate90();

		if (Compare(Degree270) && PosiY <= 0)
		{
			draw(window, PosiX, 0);
			PosiY = 0;
		}
		else if (!Compare(Degree270) && PosiY <= -1)
		{
			draw(window, PosiX, -1);
			PosiY = -1;
		}
		else if (Compare(Degree90) && PosiY >= 6)
		{
			draw(window, PosiX, 6);
			PosiY = 6;
		}
		else if (!Compare(Degree90) && PosiY >= 7) {
			draw(window, PosiX, 7);
			PosiY = 7;
		}
		else {
			draw(window, PosiX, PosiY);
		}
	}
}
