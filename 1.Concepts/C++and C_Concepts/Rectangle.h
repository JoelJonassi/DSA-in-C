#pragma once
class Rectangle
{
	private:
		int length;
		int breadth;
	public:
		void initialize(int l, int b) {
			length = l;
			breadth = b;
		}

		int area() {
			return length * breadth;
		}

		void changeLength(int l) {
			length = l;
		}
};

