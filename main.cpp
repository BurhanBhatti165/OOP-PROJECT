#include"J.h"
#include"L.h"
#include"I.h"
#include"O.h"
#include"S.h"
#include"Z.h"
#include"T.h"
#include<ctime>
#include<string>
void SWAPPING(int ScoreArr[], string NameArr[], int index) {
    for (int i = 4; i >index; i--) {
       
            ScoreArr[i] = ScoreArr[i-1];
            NameArr[i] = NameArr[i-1];
        
    }
}
bool CheckDown(int cells[][10], shapes* s) {
  
    for (int i = 3; i > 0; i--) {
        for (int j = 3; j > 0; j--) {
            if (s->getShapeArr(i, j) > 0) {
                if (s->getPosiX() + i + 1 < s->getHeight() && s->getPosiY() + j < s->getWidth()) {
                    if (cells[s->getPosiX() + i + 1][s->getPosiY() + j] > 0)      //checking for terimone down collision
                        return true;
                }
            }
        }
    }
    return false;
}
void SetCell(int cells[][10], shapes* s) {
    for (int k = 0, i = 0; k < 4; k++)
        cells[s->getIndexStore(k, i)][s->getIndexStore(k, i + 1)] = s->getShapeNo();
}
void MoveDown(int cells[][10],shapes* s,Grid obj,RenderWindow& window,int Points,int &Lines,int&Level,time_t &TIME,string PlayerName) {
    if (s->getPosiX() < 19) {
        if (!CheckDown(cells, s)) {
            window.clear(Color::Black);
            obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
            
            s->moveDown(window);
            window.display();
        }
        else {
            
            window.clear(Color::Black);
            obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
            s->setNewTetrimone(true);
            s->draw(window, s->getPosiX(), s->getPosiY());
            s->setNewTetrimone(false);
            SetCell(cells, s);
        }
    }
}
bool CellsFull(int cells[][10],shapes* s) {
    int DefaultPosiX = 0, DefaultPosiY = 3;
    int TempIndexStore[4][2];
    int TempIndexStoreX = 0, TempIndexStoreY = 0;
    for (int i = 0, k = DefaultPosiX; i < 4; i++,k++) {
        for (int j = 0, l = DefaultPosiY; j < 4; j++, l++) {
            if (s->getShapeArr(i, j) > 0) {
                if (TempIndexStoreY == 0) {
                    TempIndexStore[TempIndexStoreX][TempIndexStoreY] = k;
                    TempIndexStoreY++;
                }
                if (TempIndexStoreY == 1) {
                    TempIndexStore[TempIndexStoreX][TempIndexStoreY] = l;
                    TempIndexStoreX++;
                    TempIndexStoreY = 0;
                }
            }
        }
    }
    if (cells[TempIndexStore[0][0]][TempIndexStore[0][1]] > 0 || cells[TempIndexStore[1][0]][TempIndexStore[1][1]] > 0 ||
        cells[TempIndexStore[2][0]][TempIndexStore[2][1]] > 0 || cells[TempIndexStore[3][0]][TempIndexStore[3][1]] > 0)
        return true;
    else
        return false;
}
void SetCellLine(int cells[][10],Grid obj, shapes* s, int ClearingIndex,int &Points,int&Level,int&Lines) {
    for (int i = ClearingIndex, j = 0; j < s->getWidth(); j++) {
        cells[i][j] = 0;
    }
    for (int i = ClearingIndex; i > 0; i--) {
        for (int j = 0; j < s->getWidth(); j++) {
            cells[i][j] = cells[i - 1][j];
        }
    }
    for (int i = 0, j = 0; j < s->getWidth(); j++) {
        cells[i][j] = 0;
    }
    
    Points+=100;
    Lines += 1;

}
void LineClearing(int cells[][10],Grid obj,shapes*s,int &Points,int&Level,int &Lines) {
    bool Clear = false;
    for (int i = s->getHeight()-1; i >=0; i--) {
        for (int j = 0; j < s->getWidth(); j++) {
            if (cells[i][j] > 0)
                Clear = true;
            else {
                Clear = false;
                break;
            }
        }
        if (!Clear)
            continue;
        if (Clear) {
            SetCellLine(cells,obj, s, i,Points,Level,Lines);
            i++;
        }
    }
}



bool CheckRotatedTetrimoneCollision(int cells[][10], shapes* s) {
    if (!(s->getShapeArr(0, 1) && s->getShapeArr(0, 2) && s->getShapeArr(1, 1) && s->getShapeArr(1, 2))) {  //this if is for O shape so that it may not rotate
        s->rotate90();

        bool CheckCollision = false;
        for (int i = 0, k = s->getPosiX(); i < 4; i++, k++) {
            for (int j = 0, l = s->getPosiY(); j < 4; j++, l++) {
                if (s->getShapeArr(i, j) > 0 && CheckCollision == false)
                {
                    if (cells[k][l] > 0)
                        CheckCollision = true;
                }
            }
        }

        int TEMP[4][4];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                TEMP[i][j] = 0;
            }
        }

        //copying data as a rotated array
        for (int i = 3, k = 0; i >= 0 && k < 4; i--, k++) {		//i is column of ShapeArr and k is row of Temp array
            for (int j = 0, l = 0; j < 4 && l < 4; j++, l++) {		//j is row of ShapeArr and l is column of Temp array
                TEMP[k][l] = s->getShapeArr(j, i);
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                s->setShapeArr(i, j, TEMP[i][j]);
            }
        }
        return CheckCollision;
    }
    return false;
}

bool CheckLeft(int cells[][10], shapes* s) {


   
    for (int j = 0; j <4; j++) {
        for (int i = 0; i <4; i++) {
            if (s->getShapeArr(i, j) > 0) {
                if (s->getPosiX() + i < s->getHeight() && s->getPosiY() + j - 1 < s->getWidth()) {
                    if (cells[s->getPosiX() + i][s->getPosiY() + j - 1] > 0)                           //checking for terimone left collision
                        return true;
                }
            }
        }
    }
    return false;

}
bool CheckRight(int cells[][10], shapes* s) {


  
    for (int j = 3; j >0; j--) {
        for (int i = 0; i <4; i++) {
            if (s->getShapeArr(i, j) > 0) {
                if (s->getPosiX() + i < s->getHeight() && s->getPosiY() + j+1 < s->getWidth()) {
                    if (cells[s->getPosiX() + i ][s->getPosiY() + j+1] > 0)                           //checking for terimone right collision
                        return true;
                }
            }
        }

    }
    return false;

}

bool RandObj(int cells[][10],shapes*& s, RenderWindow& window) {
    srand(time(0));
    int randObj = rand() % 7 + 1;
    delete[]s;
    if (randObj == 1) {
        s = new I;
        s->setShapeNo(1);
    }
    else if (randObj == 2) {
        s = new J;
        s->setShapeNo(2);
    }
    else if (randObj == 3) {
        s = new L;
        s->setShapeNo(3);
    }
    else if (randObj == 4) {
        s = new O;
        s->setShapeNo(4);
    }
    else if (randObj == 5) {
        s = new S;
        s->setShapeNo(5);
    }
    else if (randObj == 6) {
        s = new T;
        s->setShapeNo(6);
    }
    else {
        s = new Z;
        s->setShapeNo(7);
    }

    if (!CellsFull(cells, s))
    {
        s->defaultPosi(window);
        window.display();
        return false;
    }
    else
        return true;
}
void run(int cells[][10],int &Points,int &Level,int&Lines,time_t& TIME,string& PlayerName) {


    RenderWindow window(VideoMode(600, 600), "Tatris");
    window.clear();

    cout << "Enter Player Name " << endl;
    getline(cin, PlayerName);
    Grid obj;
    obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);

    shapes* s = new I;
   /*  int PreviousShape[4][4];
   for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            PreviousShape[i][j] = s->getShapeArr(i, j);
        }
    }*/
    s->setShapeNo(1);
    s->defaultPosi(window);
    window.display();

    Clock time;
   
    while (window.isOpen()) {
        
        static float TimePassed = time.getElapsedTime().asSeconds();
        if (time.getElapsedTime().asSeconds() - TimePassed >= TIME) {
            TimePassed = time.getElapsedTime().asSeconds();
            MoveDown(cells, s, obj, window,Points,Lines,Level,TIME,PlayerName);
        }
        Event e;
        while (window.pollEvent(e)) {

            // Enter the main game loop               

            if (e.type == Event::Closed)
                window.close();
            else if (Keyboard::isKeyPressed(Keyboard::Left)) {

                if (s->getPosiX() < 19)
                {
                    if (!CheckLeft(cells, s)) {
                        window.clear(Color::Black);
                        obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                        s->moveLeft(window);
                        window.display();
                    }
                }
                else {
                    SetCell(cells, s);

                    LineClearing(cells,obj, s,Points,Level,Lines);
                    window.clear(Color::Black);
                    obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                    window.display();
                    if (RandObj(cells, s, window))
                        return;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Right)) {

                if (s->getPosiX() < 19)
                {
                    if (!CheckRight(cells, s)) {
                        window.clear(Color::Black);
                        obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                        s->moveRight(window);
                        window.display();
                    }
                }
                else {
                    SetCell(cells, s);
                    LineClearing(cells, obj, s,Points,Level,Lines);
                    window.clear(Color::Black);
                    obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                    window.display();
                    if (RandObj(cells, s, window))
                        return;

                }
            }
            else  if (Keyboard::isKeyPressed(Keyboard::Down)) {

                if (s->getPosiX() < 19)
                {
                    if (!CheckDown(cells, s)) {
                        window.clear(Color::Black);
                        obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                        s->moveDown(window);
                        window.display();
                   

                    }
                    else {
                        window.clear(Color::Black);
                        obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                        s->setNewTetrimone(true);
                        s->draw(window, s->getPosiX(), s->getPosiY());
                        s->setNewTetrimone(false);
                        SetCell(cells, s);
                        window.clear(Color::Black);
                        LineClearing(cells, obj, s,Points,Level,Lines);

                        obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                        window.display();
                        if (RandObj(cells, s, window))
                            return;
                    }

                }
                else {
                    SetCell(cells, s); window.clear(Color::Black);
                    LineClearing(cells, obj, s,Points,Level,Lines);

                    obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                    window.display();
                    if (RandObj(cells, s, window))
                        return;
                }
            }
            else if (Keyboard::isKeyPressed(Keyboard::Up))
            {
                if (!CheckRotatedTetrimoneCollision(cells, s)) {
                    if (s->getPosiX() < 19)
                    {

                        window.clear(Color::Black);
                        obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                        s->rotate(window);
                        window.display();
                    }
                    else {
                        SetCell(cells, s);
                        LineClearing(cells, obj, s,Points,Level,Lines);
                        window.clear(Color::Black);
                        obj.render(cells, Points,Level,Lines,TIME,PlayerName,window);
                        window.display();
                        if (RandObj(cells, s, window))
                            return;
                    }
                }
            }
        }
        
    }
}
int main() {

    int cells[20][10] = { 0 };


    int Points = 0;
    int Level = 1;
    int Lines = 0;
    time_t time = 1;
    string PlayerName = " ";

    run(cells,Points,Level,Lines,time,PlayerName);

    int ScoreArr[5];
    string NameArr[5];

    ifstream fin;
    fin.open("Score.txt");
    for (int i = 0; i < 5; i++) {
        fin >> ScoreArr[i];
    }
    fin.close();

    ifstream fin1("Name.txt");
    for (int i = 0; i < 5; i++) {
        fin1 >> NameArr[i];
    }
    fin1.close();  

    if (Points >= ScoreArr[0]) {           //highest
        SWAPPING(ScoreArr, NameArr, 0);
        ScoreArr[0] = Points;
        NameArr[0] = PlayerName;
    }
    else if (Points >= ScoreArr[1]) {      //second highest
        SWAPPING(ScoreArr, NameArr, 1);
        ScoreArr[1] = Points;
        NameArr[1] = PlayerName;
    }
    else if (Points >= ScoreArr[2]) {      //third highest
        SWAPPING(ScoreArr, NameArr, 2);
        ScoreArr[2] = Points;
        NameArr[2] = PlayerName;
    }
    else if (Points >= ScoreArr[3]) {      //fourth highest
        SWAPPING(ScoreArr, NameArr, 3);
        ScoreArr[3] = Points;
        NameArr[3] = PlayerName;
    }
    else if (Points >= ScoreArr[4]) {      //last highest
        ScoreArr[4] = Points;
        NameArr[4] = PlayerName;
    }
   

    ofstream fout;
    fout.open("Score.txt");
    for (int i = 0; i < 5; i++) {
        fout << ScoreArr[i] << " ";
    }
    fout.close();

    ofstream fout1;
    fout1.open("Name.txt");
    for (int i = 0; i < 5; i++) {
        fout1 << NameArr[i] << endl;
    }
    fout1.close();

    cout << endl;
    cout << "\t\t\tHigh Score" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\t\t     " << NameArr[i] << "\t  " << ScoreArr[i] << endl;
   }

    getchar();
}