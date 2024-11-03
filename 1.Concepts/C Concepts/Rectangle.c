#include "Rectangle.h"

int main() {
	
	Rectangle r;

	initialize(&r, 10, 5);
	area(r);
	changeLength(&r, 20);
}
