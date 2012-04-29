#include "guy.h"
#include <iostream>

Guy::Guy()
{
  image.load("guygun.gif");

  rect = image.rect();
//  image.load("/Users/scienceguy75/breakout-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/bullet.png");

 // bullet=image.b();
  resetState();
}

Guy::~Guy()
{
 std::cout << ("Guy deleted\n");
}

void Guy::moveUp(int left)
{//std::cout << (left);
  if (rect.left() >= 2)
    {rect.moveTo(3, left);
x--;}
}

void Guy::moveDown(int right)
{
//std::cout << (right)<<(" ");
  if (rect.right() <= 300)
    rect.moveTo(3,right );
x++;
}

void Guy::Shoot(int press)
{
    //std::cout <<"Bang";
   // for(int x=5;x<30; x++)
    //rect.translate(x,50 );
  //if (rect.right() <= 300)
    //rect.moveTo(15,right );
//x++;
}

void Guy::resetState()
{
  rect.moveTo(3, 300);
}

QRect Guy::getRect()
{
  return rect;
}

QImage & Guy::getImage()
{
  return image;
}
