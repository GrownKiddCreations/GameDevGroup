/*
 * Rectangle.h
 *
 *  Created on: Feb 1, 2012
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include "Vector2.h"

template<class T>
class Rectangle
{
    public:

        Rectangle();
        Rectangle(T, T, T, T);
        //Rectangle(const Rectangle<T>&);
        ~Rectangle();

        T getTop();
        T getBottom();
        T getLeft();
        T getRight();

        Vector2<T> getTopLeft();
        Vector2<T> getBottomLeft();
        Vector2<T> getBottomRight();
        Vector2<T> getTopRight();

        Vector2<T> getPosition();
        Vector2<T> getDimension();

        T getWidth();
        T getHeight();

        void setX(T);
        void setY(T);
        void setPosition(T, T);

        void setSize(T, T);
        void setWidth(T);
        void setHeight(T);

    private:

        Vector2<T> mPosition;
        Vector2<T> mDimension;
};

template<class T>
Rectangle<T>::Rectangle()
{
    mPosition.x = 0;
    mPosition.y = 0;
    mDimension.x = 0;
    mDimension.y = 0;
}

template<class T>
Rectangle<T>::Rectangle(T x, T y, T w, T h)
{
    mPosition.x = x;
    mPosition.y = y;
    mDimension.x = w;
    mDimension.y = h;
}

/*template <class T>
 Rectangle<T>::Rectangle(const Rectangle<T>& other)
 {
 mPosition.x = other.mPosition.x;
 mPosition.y = other.mPosition.y;
 mDimension.x = other.mDimension.x;
 mDimension.y = other.mDimension.y;
 }*/

template<class T>
Rectangle<T>::~Rectangle()
{
}

template<class T>
T Rectangle<T>::getTop()
{
    return mPosition.y + mDimension.y;
}

template<class T>
T Rectangle<T>::getBottom()
{
    return mPosition.y;
}

template<class T>
T Rectangle<T>::getLeft()
{
    return mPosition.x;
}

template<class T>
T Rectangle<T>::getRight()
{
    return mPosition.x + mDimension.x;
}

template<class T>
Vector2<T> Rectangle<T>::getTopLeft()
{
    return Vector2<T>(getLeft(), getTop());
}

template<class T>
Vector2<T> Rectangle<T>::getBottomLeft()
{
    return mPosition;
}

template<class T>
Vector2<T> Rectangle<T>::getBottomRight()
{
    return Vector2<T>(getRight(), getBottom());
}

template<class T>
Vector2<T> Rectangle<T>::getTopRight()
{
    return Vector2<T>(getRight(), getTop());
}

template<class T>
Vector2<T> Rectangle<T>::getPosition()
{
    return mPosition;
}

template<class T>
Vector2<T> Rectangle<T>::getDimension()
{
    return mDimension;
}

template<class T>
T Rectangle<T>::getWidth()
{
    return mDimension.x;
}

template<class T>
T Rectangle<T>::getHeight()
{
    return mDimension.y;
}

template<class T>
void Rectangle<T>::setX(T x)
{
    mPosition.x = x;
}

template<class T>
void Rectangle<T>::setY(T y)
{
    mPosition.y = y;
}

template<class T>
void Rectangle<T>::setPosition(T x, T y)
{
    mPosition.x = x;
    mPosition.y = y;
}

template<class T>
void Rectangle<T>::setSize(T x, T y)
{
    mDimension.x = x;
    mDimension.y = y;
}

template<class T>
void Rectangle<T>::setWidth(T x)
{
    mDimension.x = x;
}

template<class T>
void Rectangle<T>::setHeight(T y)
{
    mDimension.y = y;
}

#endif /* RECTANGLE_H_ */
