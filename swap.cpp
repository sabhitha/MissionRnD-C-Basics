/*
OVERVIEW: Write a function which takes two numbers as input and swaps those two numbers.
E.g.: int a = 1, b = 2; after swap(a, b) call value of "a" should be 2 and value of "b" should be 1.

INPUTS:  Two integer pointers a, b.

OUTPUT:  Swap the values of a, b.

ERROR CASES:

NOTES:
*/

void swap(int *a, int *b)
{
	if (a == 0 && b == 0)
		return;
	else{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
	}
}