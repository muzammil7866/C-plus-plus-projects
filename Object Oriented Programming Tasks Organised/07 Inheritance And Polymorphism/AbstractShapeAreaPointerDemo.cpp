#include <iostream>
using namespace std;
class Shape {
public:
virtual double area() const = 0;
};
class Rectangle : public Shape {
public:
	Rectangle(double width, double height) : m_width(width), m_height(height) {}
double area() const { return m_width * m_height; }
private:
double m_width;
double m_height;
};
class Circle : public Shape {


public:
	Circle(double radius) : m_radius(radius) {}
double area() const { return 3.14159 * m_radius * m_radius; }
private:
double m_radius;
};
int main() {
Shape* shapes[2];
shapes[0] = new Rectangle(2.0, 3.0);
shapes[1] = new Circle(1.5);
for (int i = 0; i < 2; i++) {
	std::cout << "Area of shape " << i << ": " << shapes[i]->area() << std::endl;
}
return 0;
}
