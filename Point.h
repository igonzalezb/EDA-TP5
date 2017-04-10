#ifndef POINT_H
#define POINT_H

#include <cstdint>

class Point
{
  private:
	uint32_t x;
	uint32_t y;

  public:
	Point(uint32_t _x=0, uint32_t _y=0);	//punto por default = (0,0)

	uint32_t getX();	//getters
	uint32_t getY();

	void setX(uint32_t _x);	//setters (cualquier valor es valido)
	void setY(uint32_t _y);
};

#endif //POINT_H

