#include "Perks.h"
#include <iostream>

Perks::Perks()
{

  xdir = 1;
  ydir = -1;

  resetState();

}

Perks::~Perks() {
  std::cout << ("Perks deleted\n");
}

void Perks::move(int pos){
   // rect3.moveTo(600,pos);
   // rect2.moveTo(500,pos);
  //  rect.moveTo(500,pos);
//std::cout<<"pos"<<pos;
}
void Perks::shoot(int pos)
{ //printf("automove %d %d", xdir, ydir);
   // std::cout<<pos;
   // for (int i=0; i<=; i++){
   // rect2.moveTo(550,pos);

   // rect.translate(-1,0 );
//}
 //   std::cout<<"shoot";
}
void Perks::shoot2(int pos)
{// rect2.translate(-1,0 );
}
void Perks::shoot3(int pos)
{// rect3.translate(-1,0 );
}

void Perks::resetState()
{
  //rect.moveTo(500, 305);
  //rect2.moveTo(500, 305);
  rect3.moveTo(500, 305);

}

void Perks::moveBottom(int bottom)
{
  rect.moveBottom(bottom);
}

void Perks::moveTop(int top)
{
  rect.moveTop(top);
}

void Perks::moveLeft(int left)
{
  rect.moveLeft(left);
}

void Perks::moveRight(int right)
{
  rect.moveRight(right);
}

void Perks::setXDir(int x)
{
  xdir = x;
}

void Perks::setYDir(int y)
{
  ydir = y;
}

int Perks::getXDir()
{
  return xdir;
}

int Perks::getYDir()
{
  return ydir;
}

bool Perks::isDestroyed()
{
  return destroyed;
}

void Perks::setDestroyed(bool destr)
{
  destroyed = destr;
}

