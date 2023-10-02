#include <iostream>
using namespace std;

class Rectangle{
public:
	Rectangle();
	Rectangle(double set_width, double set_height);
	void set_width(double new_width);
	void set_height(double new_height);
	double get_width();
	double get_height();
	double getArea();
	double getPerimeter();
private:
	double width;
	double height;
};
Rectangle::Rectangle(){
	width = 1;
	height =1;
}
Rectangle::Rectangle(double set_width, double set_height){
	width = set_width;
	height = set_height;
}

void Rectangle::set_width(double new_width){
	width = new_width;
}
void Rectangle::set_height(double new_height){
	height = new_height;
}
double Rectangle::get_width(){
	return width;
}
double Rectangle::get_height(){
	return height;
}
double Rectangle::getArea(){
	return width*height;
}
double Rectangle::getPerimeter(){
	return (width+height)*2;
}

int main(){
	Rectangle rec1(4,20);
	Rectangle rec2(3.5,35.9);
	cout << rec1.get_width() << '\t' << rec1.get_height() << '\t'
	  << rec1.getArea() << '\t' << rec1.getPerimeter() << endl;
	  
	cout << rec2.get_width() << '\t' << rec2.get_height() << '\t'
      << rec2.getArea() << '\t' << rec2.getPerimeter() << endl;
	return 0;
}