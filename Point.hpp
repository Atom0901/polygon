class Point{
private:
	float x, y;
public:
	Point(double x0 = 0, double y0 = 0) : x(x0), y(y0)
	{
	}
	Point(const Point & old) : x(old.getX()), y(old.getY()){}
	Point(Point && old) : x(old.x), y(old.y){}
	void setX(float _x){x = _x;}
	void setY(float _y){y = _y;}
	float getX() const {return x;}
	float getY() const {return y;}
};