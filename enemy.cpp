#include "enemy.h"
#include <iostream>

Enemy::Enemy()
{

  xdir = 1;
  ydir = -1;

  //image.load("/Users/scienceguy75/breakout-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/zombie.gif");
//image2.load("/Users/scienceguy75/breakout-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/zombie2.gif");
//image3.load("/Users/scienceguy75/breakout-build-desktop-Desktop_Qt_4_8_1_for_GCC__Qt_SDK__Debug/dog.gif");
//  rect = image.rect();
  //rect2=image2.rect();
 // rect3=image3.rect();

  resetState();

}

Enemy::~Enemy() {
  std::cout << ("Enemy deleted\n");
}

void Enemy::move(int pos){
   // rect3.moveTo(600,pos);
   // rect2.moveTo(500,pos);
  //  rect.moveTo(500,pos);
//std::cout<<"pos"<<pos;
}
void Enemy::shoot(int pos)
{ //printf("automove %d %d", xdir, ydir);
   // std::cout<<pos;
   // for (int i=0; i<=; i++){
   // rect2.moveTo(550,pos);

   // rect.translate(-1,0 );
//}
 //   std::cout<<"shoot";
}
void Enemy::shoot2(int pos)
{// rect2.translate(-1,0 );
}
void Enemy::shoot3(int pos)
{// rect3.translate(-1,0 );
}

void Enemy::resetState()
{
  //rect.moveTo(500, 305);
  //rect2.moveTo(500, 305);
  rect3.moveTo(500, 305);

}

void Enemy::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Enemy::moveTop(int top)
{
  rect.moveTop(top);
}

void Enemy::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Enemy::moveRight(int right)
{
  rect.moveRight(right);
}

void Enemy::setXDir(int x)
{
  xdir = x;
}

void Enemy::setYDir(int y)
{
  ydir = y;
}

int Enemy::getXDir()
{
  return xdir;
}

int Enemy::getYDir()
{
  return ydir;
}


QRect Enemy::getRect2()
{
  return rect2;
}

QImage & Enemy::getImage2()
{
  return image2;
}
QRect Enemy::getRect3()
{
  return rect3;
}
QImage & Enemy::getImage3()
{
  return image3;
}
bool Enemy::isDestroyed()
{
  return destroyed;
}

void Enemy::setDestroyed(bool destr)
{
  destroyed = destr;
}

