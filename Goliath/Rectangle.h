/*
 * Rectangle.h
 *
 *  Created on: Feb 1, 2012
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Vector2.h"

template <class T>
class Rectangle
{
public:

	Rectangle(T, T, T, T);
	~Rectangle();

	T getTop();
	T getBottom();
	T getLeft();
	T getRight();

	Vector2<T> getTopLeft();
	Vector2<T> getBottomLeft();
	Vector2<T> getBottomRight();
	Vector2<T> getTopRight();

	T getWidth();
	T getHeight();

	void translate(T, T);
	void resize(T, T);

private:

	Vector2<T> mPosition;
	Vector2<T> mDimension;
};

template <class T>
Rectangle<T>::Rectangle(T x, T y, T w, T h)
{
	mPosition.x = x;
	mPosition.y = y;
	mDimension.x = w;
	mDimension.y = h;
}

template <class T>
Rectangle<T>::~Rectangle()
{
}

template <class T>
T Rectangle<T>::getTop()
{
	return mPosition.y + mDimension.y;
}

template <class T>
T Rectangle<T>::getBottom()
{
	return mPosition.y;
}

template <class T>
T Rectangle<T>::getLeft()
{
	return mPosition.x;
}

template <class T>
T Rectangle<T>::getRight()
{
	return mPosition.x + mDimension.x;
}

template <class T>
Vector2<T> Rectangle<T>::getTopLeft()
{
	return Vector2<T>(getLeft(), getTop());
}

template <class T>
Vector2<T> Rectangle<T>::getBottomLeft()
{
	return mPosition;
}

template <class T>
Vector2<T> Rectangle<T>::getBottomRight()
{
	return Vector2<T>(getRight(), getBottom());
}

template <class T>
Vector2<T> Rectangle<T>::getTopRight()
{
	return Vector2<T>(getRight(), getTop());
}

template <class T>
T Rectangle<T>::getWidth()
{
	return mDimension.x;
}

template <class T>
T Rectangle<T>::getHeight()
{
	return mDimension.y;
}

template <class T>
void Rectangle<T>::translate(T x, T y)
{
	mPosition.x = x;
	mPosition.y = y;
}

template <class T>
void Rectangle<T>::resize(T x, T y)
{
	mDimension.x = x;
	mDimension.y = y;
}

#endif /* RECTANGLE_H_ */
