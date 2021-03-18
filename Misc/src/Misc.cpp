//============================================================================
// Name        : Misc.cpp
// Author      : Sergio AndradeSergio Andrade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

// .h header file
class Test {
public:
	// as it is a const, it must be initialized here
	static int const MAX = 127;

private:
	int id;
	static int count;

public:
	Test(): id(count++) {}
	static void showInfo() { // can only access static members
		cout << "Count: " << count << endl;
	}
	int getId() { return id; }
};

// .cpp normally initialices static variables
int Test::count = 0;

int main() {
	//========= Here we work on shifting to construct colors
	cout << Test::MAX << endl;
	Test::showInfo();

	Test t1;
	cout << "t1 id: " << t1.getId() << endl;
	t1.showInfo();

	Test t2;
	cout << "t2 id: " << t2.getId() << endl;
	t2.showInfo();

	cout << endl << "============================" << endl << endl;
	//======== Now we alanyze the shift of a created color
	int color = 0x123456FF;
	// the lone & operator performs a comparison bit by bit, we can use this to se values from each sction of the color
	int red = color & 0xFF000000;

	cout << "RED: " << setfill('0') << setw(8) << hex << red << endl;

	int green = color & 0x00FF0000;

	cout << "GREEN: " << setfill('0') << setw(8) << hex << green << endl;

	int blue = color & 0x0000FF00;

	cout << "BLUE: " << setfill('0') << setw(8) << hex << blue << endl;

	int alpha = color & 0x000000FF;

	cout << "ALPHA: " << setfill('0') << setw(8) << hex << alpha << endl;

	return 0;
}
