//============================================================================
// Name        : hello-world.cpp
// Author      : Sergio Andrade
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;

int main() {


	return 0;
}

/* Additional types
 	 wchart_t <- used to store unicode character, extends character memory space to 4
*/

/* Basic floating point numbers manipulation and data types
	cout << "/============== Now working with float: ==============\\" << endl;
	float f1 = 123.456789;
	cout << "How big is a float? " << sizeof(f1) << " bytes." << endl;
	cout << "Fixed notation? " << fixed << f1 << endl;
	cout << "Scientific notation? " << scientific << f1 << endl;
	cout << "Fixed with precision of 20? " << setprecision(20) << fixed << f1 << endl;

	cout << "/============== Now working with double: ==============\\" << endl;
	double d1 = 123.456789;
	cout << "How big is a double? " << sizeof(d1) << " bytes." << endl;
	cout << "Fixed notation? " << fixed << d1 << endl;
	cout << "Scientific notation? " << scientific << d1 << endl;
	cout << "Fixed with precision of 20? " << setprecision(20) << fixed << d1 << endl;

	cout << "/============== Now working with long double: ==============\\" << endl;
	long double ld1 = 123.123456789987654321;
	cout << "How big is a long double? " << sizeof(ld1) << " bytes." << endl;
	cout << "Fixed notation? " << fixed << ld1 << endl;
	cout << "Scientific notation? " << scientific << ld1 << endl;
	cout << "Fixed with precision of 20? " << setprecision(20) << fixed << ld1 << endl;

	cout << "/============== Trying to compare floats: ==============\\" << endl;
	float f1 = 1.11;
	float f2 = 1.11;

	// This will output "Equals"
	if (f1 == f2) {
		cout << "Equals" << endl;
	} else {
		cout << "Not equals" << endl;
	}
	// Whereas this, will output "Not equals"
	if (f1 == 1.11) {
		cout << "Equals" << endl;
	} else {
		cout << "Not equals" << endl;
	}
*/

/* Basic array declaration
	string food[] = {"pasta", "pizza", "burger", "sushi", "lasagna"};
	int arr[8] = {}; // this initialices arr with a 0 in each position
	// class arr[n] = {}; <- this initialices a arr of length n with the default value for class
*/

/* Basic input/output flow
	cout << "This text is going into a line without break" << flush;
	cout << "What would you like to eat? " << endl;
	string answer;
	getline(cin, answer); // As the name says, it captures the whole line from the stream
	cout << "Got it, you want: " << answer << endl;
	int cant;
	cout << "How many portions would you like?" << endl;
	cin >> cant;  // Only takes the first word from the stream
	cout << "So, it would be " << cant << " portions of " << answer << endl;
*/

/* Basic integer manipulation, this can't be done without #include <cmath>
  	double a = 34;
	double b = 56.7;
	double c = 95.45;
	double d = 87.23;

	double minVal = min(a, b); // Only works for a pair of numbers
	cout << "We can find the minimum of two numbers using min(number1, number2) function: " << minVal << endl;
	double maxVal = max(c, d); // Only works for a pair of numbers
	cout << "We also have the opposite function max(number1, number2): " << maxVal << endl;

	cout << "/===================================================================================/ " << endl;

	double mult = (a + b) / c * d + d;
	cout << "We can take a decimal number, " << mult << " and take its floor(number): " << floor(mult) << endl;
	cout << "Or, take its ceil(number) " << ceil(mult) << endl;
	cout << "Or just round(number) it " << round(mult) << endl;

	cout << "/===================================================================================/ " << endl;
	double pot = pow(a, 3);
	cout << "We can calculate powers: pow(a,3) = " << pot << endl;
	double sq = sqrt(a);
	cout << "We can take its square root: sqrt(a) = " << sq << endl;
*/


/*	Basic string manipulation
 	string output = "Hello World, from Sergio!";
	cout << output << endl; // prints Hello World, from Sergio!
	int outputLength = output.size();
	cout << "Those are " << outputLength << " letters!" << endl;
	cout << "You can have up to " << output.max_size() << " characters in a string!" << endl;

	int index = output.find("from", 0); // find(string to_search, int search_start_location)
	cout << "The word you are looking for start at index: " << index << endl;

	cout << "You can use array notation '[]' to edit strings like so: " << endl;
	output[0] = 'B';
	cout << output << endl;

	output.clear(); // After using clear the variable empties
 */
