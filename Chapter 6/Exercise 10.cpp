#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include "std_lib_facilities.h"

/*
exercise 10
*/

/* Pseudocode
input_values; // For example:
calculate;
output_result;
*/

int get_factorial(int x) {
	int fac = 1;
	for (int a = 1; a <= x; ++a)
		fac *= a;
	return fac;
}

int permutation(int a, int b, char c) {
	if (c != 'p' && c != 'c') error("Operation must be 'p' or 'c'");
	if (b >= a || a < 1 || b < 1) error("Bad permutation sizes");

	return get_factorial(a) / get_factorial(a - b);
}

int combination(int a, int b, int p) {
	int result = p / get_factorial(b);
	return result;
}

int main()
try
{
	int a, b;
	char operation;

	cout << "Enter 2 numbers  and first letter of operation with space.\n"
		<< "(combination - c, permutation - p)\n";

	if (!(cin >> a >> b >> operation)) error("Bad input instruction");

	int p = permutation(a, b, operation);

	if (operation == 'p')
		cout << a << "! " << "/" << " (" << a << "-" << b << ")! = " << p << endl;
	else cout << p << " / " << b << "! = " << combination(a, b, p) << endl;

	keep_window_open();
}

catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}