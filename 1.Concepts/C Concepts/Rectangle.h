#pragma once
typedef struct _rectangle {
	int length;
	int breadth;
} Rectangle;

void initialize(Rectangle* r, int l, int b) {
	r->length = l;
	r->breadth = b;
}

int area(Rectangle r) {
	return r.length * r.breadth;
}

void changeLength(Rectangle *r, int l) {
	r->length = l;
}

