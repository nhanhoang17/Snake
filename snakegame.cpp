

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
	score = 0;




}
void draw() {
	system("cls");
	for (int i = 0; i < rong; i++)
		cout << "#";
	cout << endl;

	
	for (int i = 0; i < cao; i++) {
		cout << "#" ;
		for (int j = 1; j < rong-1; j++) {
			cout << " ";
		}
		cout << "#" << endl;

	}

	for (int i=0; i < rong; i++) {
		cout << "#";
	}

}
void logic() {

}
void input() {

}
int main()
{
	/*setup();
	while (!gameover) {
		draw();
		logic();

	}*/
	draw();
}

