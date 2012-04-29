#include "bullet.h"
#include <iostream>

Bullet::Bullet()
{

  xdir = 1;
  ydir = -1;

  image.load("bullet.gif");

  rect = image.rect();
  resetState();

}

Bullet::~Bullet() {
  std::cout << ("Bullet deleted\n");
}

void Bullet::move(int pos){
    rect.moveTo(145,pos+15);

}
void Bullet::shoot(int pos)
{ //printf("automove %d %d", xdir, ydir);
   // std::cout<<pos;
   // for (int i=0; i<=; i++){

    rect.translate(1,0 );
//}
 //   std::cout<<"shoot";


  /*if (rect.left() <= 5) {
    //xdir = 1;
    // std::cout<<"YOOO2";
  }

  if (rect.right() >= 300) {
    xdir = -1;
    //std::cout<<"YOOO";

  }
  if (rect.bottom() >= 400) {
    ydir = -1;
    //std::cout<<"YOOOB";

  }

  if (rect.top() <= 0) {
    ydir = 1;
  }*/
}

void Bullet::resetState()
{
  rect.moveTo(40, 305);
}

void Bullet::setXDir(int x)
{
  xdir = x;
}

void Bullet::setYDir(int y)
{
  ydir = y;
}

int Bullet::getXDir()
{
  return xdir;
}

int Bullet::getYDir()
{
  return ydir;
}

QRect Bullet::getRect()
{
  return rect;
}

QImage & Bullet::getImage()
{
  return image;
}

bool Bullet::isDestroyed()
{
  return destroyed;
}

void Bullet::setDestroyed(bool destr)
{
  destroyed = destr;
}
