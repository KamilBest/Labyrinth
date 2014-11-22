#include <iostream>
#include <windows.h>
#include <conio.h>
#include <time.h>


using namespace std;
char board[10][10];
int x=0, y=0;

enum FIELDS
{
    FLD_EMPTY='.',
    FLD_WALL='X',
    FLD_PLAYER='@',
};

enum GAMESTATE
{
    GS_START,
    GS_END,
};
void set_fields()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            board[i][j] = FLD_EMPTY;
        }
    }
}

void draw_board()
{
    cout << string(5, '\n');
    for(int i=0; i<12; i++)
        cout<<" X";
    cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        if (i != 0)
            cout << endl;
        if (i != 10)
            cout << " " << "X";

        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                cout << "|";
            cout << board[i][j] << "|";
        }
    }
    cout<<endl;

    for(int i=0; i<12; i++)
        cout<<" X";
}


int main()
{
    GAMESTATE game_state;
    game_state=GS_START;
    set_fields();
    draw_board();
    board[x][y]=FLD_PLAYER;
    char kierunek;
    system("cls");
//RYSOWANIE SCIAN

    for(int i=0; i<5; i++)
        board[i][1]=FLD_WALL;

//////////////
    do
    {
        draw_board();
        cout<<endl<<"Podaj kierunek:"<<endl;
        kierunek=getch();
        if(kierunek=='s')
        {

            if((x+1>9)or(board[x+1][y]==FLD_WALL))
            {
                cout<<"SCIANA!";
                Sleep(300);
            }
            else
            {
                x++;

                board[x-1][y]=FLD_EMPTY;
                board[x][y]=FLD_PLAYER;
            }
        }
        else if(kierunek=='d')
        {

            if((y+1>9)or(board[x][y+1]==FLD_WALL))
            {
                cout<<"SCIANA!";
                Sleep(300);
            }

            else
            {
                y++;

                board[x][y-1]=FLD_EMPTY;
                board[x][y]=FLD_PLAYER;
            }
        }
        else if(kierunek=='a')
        {
            if((y-1<0)or(board[x][y-1]==FLD_WALL))
            {
                cout<<"SCIANA!";
                Sleep(300);
            }

            else
            {
                y--;

                board[x][y+1]=FLD_EMPTY;
                board[x][y]=FLD_PLAYER;
            }
        }
        else if(kierunek=='w')
        {

            if((x-1<0)or(board[x-1][y]==FLD_WALL))
            {
                cout<<"SCIANA!";
                Sleep(300);
            }
            else
            {
                x--;

                board[x+1][y]=FLD_EMPTY;
                board[x][y]=FLD_PLAYER;
            }
        }

        system("cls");
    }
    while(game_state!=GS_END);
    return 0;
}
