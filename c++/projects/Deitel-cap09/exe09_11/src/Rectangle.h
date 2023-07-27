class Rectangle
{
public:
	Rectangle(int=1, int=1);
	int perimeter();
	int area();
private:
	int length;
	int width;
	void setLength(int);
	void setWidth(int);
	int getLength();
	int getWidth();
	void setRectangle(int,int);
};
