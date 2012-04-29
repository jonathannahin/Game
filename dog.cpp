#include "dog.h"
#include <iostream>
//#include "enemy.h"
Dogs::Dogs()
{

  xdir = 1;
  ydir = -1;

  image.load("/Users/scienceguy75/breakout-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/Dogs.gif");

  rect = image.rect();
  resetState();
}

Dogs::~Dogs() {
  std::cout << ("Dogs deleted\n");
}

void Dogs::move(int pos){
    rect.moveTo(500,pos);
//std::cout<<"pos"<<pos;
}
void Dogs::shoot(int pos)
{
    rect.translate(-1,0 );

}



void Dogs::resetState()
{
  rect.moveTo(500, 305);

}


void Dogs::setXDir(int x)
{
  xdir = x;
}

void Dogs::setYDir(int y)
{
  ydir = y;
}

int Dogs::getXDir()
{
  return xdir;
}

int Dogs::getYDir()
{
  return ydir;
}

QRect Dogs::getRect()
{
  return rect;
}

QImage & Dogs::getImage()
{
  return image;
}

bool Dogs::isDestroyed()
{
  return destroyed;
}

void Dogs::setDestroyed(bool destr)
{
  destroyed = destr;
}

