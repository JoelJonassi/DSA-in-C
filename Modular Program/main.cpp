#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct _rectangle {
	int length;
	int breath;

} Rectangle;

void initialize(Rectangle* r, int length, int breath) {
	r->length = length;
	r->breath = breath;
}

int area(Rectangle r) {
	return r.length * r.breath;
}

int perimeter(Rectangle r) {
	int p;
	p = 2 * (r.length + r.breath);
	return p;
}

int main() {
	Rectangle r = { 0,0 };

	initialize(&r, 10, 4);

	int a = area(r);
	int p = perimeter(r);

	return 0;
}
