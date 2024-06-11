#include "O.h"

O::O()
{
	int temp = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			temp = i * 4 + j;
			if (temp == 1 || temp == 2 || temp ==  5|| temp == 6)
				SHAPEarr[i][j] = 4;
			else
				SHAPEarr[i][j] = 0;
		}
	}
	PosiX = 0;
	PosiY = 0;
}
void O::draw(RenderWindow& window, int PosiX, int PosiY)
{
	int IndexStoreX = 0, IndexStoreY = 0;
	for (int i = 0, k = PosiX; i < 4; i++, k++) {
		for (int j = 0, l = PosiY; j < 4; j++, l++) {
			if (SHAPEarr[i][j] == 4)
			{
				RectangleShape J1(Vector2f(this->cellSize - 2, this->cellSize - 2));
				J1.setPosition(Vector2f(l * this->cellSize, k * this->cellSize));
				J1.setFillColor(Color::Yellow);
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
					ShapeNo = SHAPEarr[i][j];
				}
			}
		}
	}
}
void O::defaultPosi( RenderWindow& window)
{
	PosiX = 0, PosiY = 3;

	cout << endl;
	for (int i = 0, k = PosiX; i < 4; i++, k++) {
		for (int j = 0, l = PosiY; j < 4; j++, l++) {
			if (SHAPEarr[i][j] == 4)
			{
				RectangleShape J1(Vector2f(this->cellSize - 2, this->cellSize - 2));
				J1.setPosition(Vector2f(l * this->cellSize, k * this->cellSize));
				J1.setFillColor(Color::Yellow);
				window.draw(J1);
			}
		}
	}
}

void O::moveLeft(RenderWindow& window)
{
	if (PosiX >= 18) {
		draw(window, 18, PosiY);
	}
	else {
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
void O::moveRight(RenderWindow& window)
{

	if (PosiX >= 18) {
		draw(window, 18, PosiY);
	}
	else {
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
void O::moveDown(RenderWindow& window)
{
	if (PosiX >= 18) {
		NewTetrimone = true;
		draw(window, 18, PosiY);
		NewTetrimone = false;
		PosiX = 19;
	}
	if (PosiX < 18) {
		draw(window, PosiX + 1, PosiY);
		PosiX += 1;
	}
}
void O::rotate(RenderWindow& window) {
	draw(window, PosiX, PosiY);
}