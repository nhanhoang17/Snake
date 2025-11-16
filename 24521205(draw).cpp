

#include <iostream>
using namespace std;
bool gameover ;
const int rong = 20;
const int  cao = 20;
int x, y, fruitx,fruity,score;
enum edirection {stop=0,left,right,up,down};
edirection dir;

void setup() {
	gameover = false;
	dir = stop;
	x = rong / 2;
	y = cao / 2;
	fruitx = rand() % rong;
	fruity = rand() % cao;
	fruity = rand() % 2;




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
                cout << " "; // khoảng trống

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

}
void input() {

}
int main()
{
	setup();
	while (!gameover) {
		draw();
		logic();

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
