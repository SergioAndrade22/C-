//============================================================================
// Name        : BitShifting.cpp
// Author      : Sergio AndradeSergio Andrade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	unsigned char red = 0x12;
	unsigned char green = 0x34;
	unsigned char blue = 0x56;
	unsigned char alpha = 0xFF;

	unsigned int color = 0;

	// the << operator shifts the content by x bits to the left, the >> operator work analog
	color += red;
	color <<= 8;

	color += green;
	color <<= 8;

	color += blue;
	color <<= 8;

	color += alpha;

	cout << setfill('0') << setw(8) << hex << color << endl;
	return 0;
}
