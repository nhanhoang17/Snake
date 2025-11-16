#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameover ;
const int rong = 20;
const int  cao = 20;
int x, y, fruitx,fruity,score;
int tailX[100], tailY[100];
int nTail;
enum edirection {stop=0,left,right,up,down};
edirection dir;

void setup() {
	gameover = false;
	dir = stop;
	x = rong / 2;
	y = cao / 2;
	fruitx = rand() % rong;
	fruity = rand() % cao;





}
void draw() {
system("cls");


    for (int i = 0; i < rong+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < cao; i++) {
        for (int j = 0; j < rong; j++) {
            if (j == 0) cout << "#"; // biên trái

            if (i == y && j == x)
                cout << "O"; // đầu rắn
            else if (i == fruity && j == fruitx)
                cout << "*"; // thức ăn
            else
                {
                    bool print = false;
                    for (int k=0; k<nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            cout << "o";
                            print = true;
                        }
                    }
                    if (!print) cout << " ";
                }

            if (j == rong - 1) cout << "#"; // biên phải
        }
        cout << endl;
    }

    for (int i = 0; i < rong+2; i++)
        cout << "#";
    cout << endl;

    cout << "Score: " << score << endl;

}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i=1; i<nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case edirection::left:
        x--;
        break;
    case edirection::right:
        x++;
        break;
    case edirection::up:
        y--;
        break;
    case edirection::down:
        y++;
        break;
    default:
        break;
    }

    if (x>rong || x<0 || y>cao || y<0)  gameover = true;
    for (int i=0; i<nTail; i++)
    {
        if (tailX[i]==x && tailY[i]==y)
            gameover = true;
    }

    if (x == fruitx && y == fruity)
    {

        score += 10;
        fruitx = rand() % rong;
        fruity = rand() % cao;
        nTail++;
    }

}

void input() {
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = edirection::left;
            break;
        case 'd':
            dir = edirection::right;
            break;
        case 'w':
            dir = edirection::up;
            break;
        case 's':
            dir = edirection::down;
            break;
        case 'x':
            gameover = true;
            break;
        }
    }
}

int main()
{
	setup();
	while (!gameover) {
		draw();
		input();
		logic();
		Sleep(136);

	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
