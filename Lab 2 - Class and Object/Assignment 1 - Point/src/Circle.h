#ifndef CIRCLE_H
#define CIRCLE_H

class Point {
private:
	int coord_x, coord_y;

public:
	Point(int coord_x, int coord_y);
	~Point();
	[[nodiscard]] int getX() const;
	[[nodiscard]] int getY() const;
	[[nodiscard]] double distance(const Point& other) const;
};

struct CircleParams {
        int center_x;
        int center_y;
        int radius;
};

class Circle {
private:
	Point center;
	int radius;
public:
	explicit Circle(const CircleParams& parameter);
	~Circle();
	[[nodiscard]] Point getCenter() const;
	[[nodiscard]] int getRadius() const;
};

#endif