#include "Point.h"


Point :: Point(uint32_t _x, uint32_t _y)
{
	x = _x;	//inicializa ambas coordenadas con los valores recibidos (o 0 por defecto)
	y = _y;
}	

uint32_t Point :: getX()
{
	return x;
}

uint32_t Point :: getY()
{
	return y;
}

void Point :: setX(uint32_t _x)
{
	x = _x;
}

void Point :: setY(uint32_t _y)
{
	y = _y;
}

