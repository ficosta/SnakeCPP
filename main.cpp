#include <iostream>
#include <conio.h>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;
bool gameOver;
const int widht =20;
const int height = 20;

int snakeX, snakeY, fruitX, fruitY, score;

enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    snakeX = widht / 2;
    snakeY = height / 2;

    fruitX = rand() % widht;
    fruitY = rand() % height;

}
void Draw()
{
    #ifdef _WIN32
    system("cls");
    #endif

    #ifdef linux
    system("clear");
    #endif
    cout<<"####################"<<'\n'; // Linha superior

    for (int screenY = 0; screenY < height; screenY++)
    {
        for (int screenX = 0; screenX < widht; screenX++)
        {
            if(screenX == 0 || screenX == widht-1)
                cout<<"#";
            else
                if (screenX==snakeX && screenY==snakeY)
                {
                    cout<<"O";
                }
                else if(screenX==fruitX && screenY==fruitY)
                {
                        cout<<"F";
                }
                else
                {
                cout<<" ";
                }
        }
        cout<<'\n';
    }



    cout<<"####################"<<'\n'; // Linha inferior
    cout<<"Score: "<< score <<'\n' <<endl;



}
void Input()
{
    if(_kbhit())
    {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'X':
            gameOver = true;
            break;
        default:
            break;
        }
    }
}
void Logic()
{
    switch (dir) {
    case LEFT:
        snakeX--;
        break;
    case RIGHT:
        snakeX++;
        break;
    case UP:
        snakeY--;
        break;
    case DOWN:
        snakeY++;
        break;
    }
    if(snakeX == fruitX && snakeY==fruitY){
        score+=10;
        fruitX = rand() % widht;
        fruitY = rand() % height;
    }
    if(snakeX> widht-2 || snakeX< 0 || snakeY > height-1 || snakeY < 0)
    {
        gameOver=true;
    }
}

int main()
{
    Setup();
    while(!gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(100);
    }
    return 0;
}
