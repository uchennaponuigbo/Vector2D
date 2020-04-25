#pragma once
template<typename var>
class Vector2D
{
//public:
//	typedef VectSize unsigned int;
private:
	int arrSize;
	int rSize;
	int cSize;
	//int capacity;
	var **Arr;
public:
	//CONSTRUCTORS
	Vector2D();
	Vector2D(int row, int colm);
	Vector2D(const Vector2D&);
	~Vector2D();

	//ACCESSORS
	int size() const;
	int rowSize() const;
	int columnSize() const;
	bool isEmpty() const;

	//GENERAL FUNCTIONS AND OVERLOADING OPERATORS
	var &at(int i, int j);
	//overload [] operator... somehow...
};

template<typename var>
Vector2D<var>::Vector2D()
{
	rSize = cSize = arrSize = 5;

	Arr = new var*[arrSize];
	for (int i = 0; i < arrSize; i++)
		Arr[i] = new var[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		for (int j = 0; j < arrSize; j++)
			Arr[i][j] = var();
	}

	arrSize *= arrSize;
}

template<typename var>
Vector2D<var>::Vector2D(int row, int colm)
{
	Arr = new var*[row];
	for (int i = 0; i < row; i++)
		Arr[i] = new var[colm];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < colm; j++)
			Arr[i][j] = var();
	}

	//Arr = { {NULL}, {NULL} };

	if (row == 0)
	{
		arrSize = colm;
		cSize = colm;
		rSize = 0;
	}
		
	else if (colm == 0)
	{
		arrSize = row;
		rSize = row;
		cSize = 0;
	}	
	else
	{
		arrSize = row * colm;
		rSize = row;
		cSize = colm;
	}
		
}

template<typename var>
Vector2D<var>::Vector2D(const Vector2D<var>& v)
{
	arrSize = v.arrSize;
	rSize = v.rSize;
	cSize = v.cSize;
}

template<typename var>
Vector2D<var>::~Vector2D()
{
	delete[] Arr;
}

template<typename var>
int Vector2D<var>::size() const
{
	return arrSize;
}

template<typename var>
int Vector2D<var>::rowSize() const
{
	return rSize;
}

template<typename var>
int Vector2D<var>::columnSize() const
{
	return cSize;
}

template<typename var>
bool Vector2D<var>::isEmpty() const
{
	return arrSize == 0;
}

template<typename var>
var& Vector2D<var>::at(int i, int j)
{
	if ((i < 0 || i > rSize) &&
		(j < 0 || j > cSize))
		throw std::out_of_range("Out of Range Error!");
	return Arr[i][j];
}