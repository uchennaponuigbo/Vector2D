#pragma once
template<typename var>
class Vector2D
{
private:
	int n;
	var **Arr;
public:
	Vector2D();
	Vector2D(int r, int c);
	Vector2D(const Vector2D&);
	~Vector2D();
};

template<typename var>
Vector2D<var>::Vector2D()
{
	n = 0;
}

template<typename var>
Vector2D<var>::Vector2D(int r, int c)
{

	n = r * c;
}

template<typename var>
Vector2D<var>::Vector2D(const Vector2D<var>& v)
{
	
}

template<typename var>
Vector2D<var>::~Vector2D()
{
	delete[] Arr;
}
