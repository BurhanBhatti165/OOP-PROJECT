#include"Grid.h";
 //int Points = 0;
Grid::Grid() {
    height = 20;
    width = 10;
    cellSize = 30;
  //  Points = 0;
}

void Grid::SWAPPER(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Render the grid
void Grid::render(int cells[][10],int &Points,int &Level,int &Lines,time_t &TIME,string PlayerName,sf::RenderWindow& window) {
    
    // Drawing the grid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // Create a rectangle shape for the cell
            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setOutlineThickness(2);
            cell.setOutlineColor(sf::Color::Red);
            cell.setPosition(j * cellSize, i * cellSize);
            cell.setFillColor(sf::Color::Black);

            // Draw the cell
            window.draw(cell);
            if (cells[i][j] == 1) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(sf::Color::White);
                window.draw(cell);
            }
            else if (cells[i][j] == 2) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(sf::Color::Blue);
                window.draw(cell);
            }
            else if (cells[i][j] == 3) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(sf::Color::Cyan);
                window.draw(cell);
            }
            else if (cells[i][j] == 4) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(sf::Color::Yellow);
                window.draw(cell);
            }
            else if (cells[i][j] == 5) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(sf::Color::Green);
                window.draw(cell);
            }
            else if (cells[i][j] == 6) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(sf::Color::Magenta);
                window.draw(cell);
            }
            else if (cells[i][j] == 7) {
                sf::RectangleShape cell(sf::Vector2f(cellSize - 2, cellSize - 2));
                cell.setPosition(j * cellSize, i * cellSize);
                cell.setFillColor(sf::Color::Red);
                window.draw(cell);
            }
        }
    }

    
    // Setting up rectangle parameters
    int rectangleWidth = 130;
    int rectangleHeight = 70;
    
    //Creating a rectangle
    RectangleShape rectangle;
    rectangle.setFillColor(Color::Black);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(Color::White);

    //Drawing rectangle
    for (int i = 60; i <= 450; i += 130) {
        rectangle.setPosition(Vector2f(405, i));                        //Sets position of each individual rectangle in window
        rectangle.setSize(Vector2f(rectangleWidth, rectangleHeight));   //Sets size of each individual rectangle in window
        window.draw(rectangle);
    }

    //Setting up text for rectangles
    string str[4] = { "Player : ","Level # ","Score : ","Lines : " };

    //Setting up text
    Text text;
   // Text Score;
    Font font;
    font.loadFromFile("Fonts/menuFont.ttf");

    text.setFont(font);
    for (int i = 0, j = 62; i < 4 && j <= 452; i++, j += 130) {
        text.setString(str[i]);
        text.setCharacterSize(20);
        text.setPosition(Vector2f(409, j));

        window.draw(text);
    }
    if (Lines > 9 && Level <8) {
        Level += 1;
        float temp = TIME / 10;
        TIME -= temp;
        Lines = 0;
    }
    if (Level == 8 && Lines > 9) {
        TIME = 1;
        Level = 1;
        Lines = 0;
    }

    //Text text;
    text.setString(PlayerName);
     text.setCharacterSize(15);
     text.setPosition(Vector2f(409, 95));
     window.draw(text);

    string LEVEL = to_string(Level);
    text.setString(LEVEL);
    text.setCharacterSize(15);
    text.setPosition(Vector2f(409,225));
    window.draw(text); 
    
    string POINTS = to_string(Points);
    text.setString(POINTS);
    text.setCharacterSize(15);
    text.setPosition(Vector2f(409, 355));
    window.draw(text);

    string LINES = to_string(Lines);
    text.setString(LINES);
    text.setCharacterSize(15);
    text.setPosition(Vector2f(409, 485));
    window.draw(text);

  
 
}

int Grid::getHeight()
{
    return height;
}

int Grid::getWidth()
{
    return width;
}

