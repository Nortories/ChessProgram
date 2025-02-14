/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream>

 /*********************************************
  * POINT
  * A single position.
  *********************************************/
class Point
{
public:
   // constructors
   Point() : x(0.0), y(0.0) {}
   Point(double x, double y);

   // getters
   double getX()       const { return x; }
   double getY()       const { return y; }

   // setters
   void setX(double x) { this->x = x; }
   void setY(double y) { this->y = y; }
   void addX(double dx) { setX(getX() + dx); }
   void addY(double dy) { setY(getY() + dy); }

   // these are member variables, or could be called properties or attributes
private:
   double x;           // horizontal position
   double y;           // vertical position
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Point& pt);
std::istream& operator >> (std::istream& in, Point& pt);


