#ifndef VECTOR2_H_
#define VECTOR2_H_

#include <math.h>

template <class T>
class Vector2
{
public:

	Vector2();
	Vector2(T, T);

	T magnitude();
	void scale(T);
	Vector2<T>* add(Vector2<T>);
	Vector2<T>* makeUnit();

    T x;
    T y;
          
};

template <class T>
Vector2<T>::Vector2()
{

}

template <class T>
Vector2<T>::Vector2(T x, T y)
{
    this->x = x;
    this->y = y;
}

template <class T>
T Vector2<T>::magnitude()//TODO explanation needed
{
	return (T)sqrt((x * x) + (y * y));
}

template <class T>
void Vector2<T>::scale(T scale)//TODO explanation needed
{
	x *= scale;
	y *= scale;
}

template <class T>
Vector2<T>* Vector2<T>::add(Vector2<T> other)
{
	x += other.x;
	y += other.y;

	return this;
}

template <class T>
Vector2<T>* Vector2<T>::makeUnit()//TODO explanation needed
{
	float m = magnitude();
	if (m != 0)
	{
		x /= m;
		y /= m;
	}

	return this;
}

#endif
