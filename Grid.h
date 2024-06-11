
#include<iostream>
#include<string>
#include<fstream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

//#ifndef GLOBALS_H
//#define GLOBALS_H
//
//extern int Points;
//
//#endif // GLOBALS_H
//int cells[20][10] = {
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0, 
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//                   0,0,0,0,0,0,0,0,0,0,
//};


class Grid {
   
protected:
    int width;
    int height;
    int cellSize;
public:
    Grid();
    void SWAPPER(int&, int&);
  
    void render(int cells[][10], int& Points,int&Level,int&Lines,time_t &TIME,string PlayerName, sf::RenderWindow& window);

    int getHeight();
    int getWidth();
    //int getPoints();
    //void setPoints(int);
};