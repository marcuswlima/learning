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
	int getLength() const;
	int getWidth() const;
	void setRectangle(int,int);
};
