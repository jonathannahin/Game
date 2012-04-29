#ifndef GUY_H
#define GUY_H

#include <QImage>
#include <QRect>

class Guy
{

  public:
    Guy();
    ~Guy();

  public:
    void resetState();
    void moveUp(int);
    void moveDown(int);
    QRect getRect();
    QImage & getImage();
    void Shoot(int);


  private:
    QImage image;
    QRect rect,bullet;
	int x,y;

};

#endif
