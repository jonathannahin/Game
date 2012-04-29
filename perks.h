#ifndef PERKS_H
#define PERKS_H
#include <QImage>
#include <QRect>
class Perks
{

  public:
    Perks();
    ~Perks();

  public:
    void move(int);//Move Perk
    void resetState();//Restart State
    void moveBottom(int);//Moves Perks from left to right
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void shoot(int);
    void shoot2(int);
    void shoot3(int);

    bool isDestroyed();//Check if destroyed
    void setDestroyed(bool);//Set if destroyed

    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect();//get location of image
    QImage & getImage();//get image

  //  void paintEvent(QPaintEvent *event);
   // void timerEvent(QTimerEvent *event);

  protected:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool stuck;
    bool destroyed;
    QImage image,image2,image3;
    QRect rect,rect2,rect3;

};

class Ammo: public Perks
{

  public:
Ammo(){image.load("ammo.gif");
      rect = image.rect();};

  public:
  //  void move(int pos){
    void move(int pos){rect.moveTo(500,pos); };
    void resetState(){  rect.moveTo(500, 305);};
    void shoot(int){rect.translate(-1,0 );};
    bool isDestroyed(){return destroyed;};
    void setDestroyed(bool destr){destroyed = destr;};

    void setXDir(int a){
    xdir=a;
    };
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect(){return rect;};
    QImage & getImage(){return image;};


};
class Health: public Perks
{

  public:
Health(){image.load("redcross.gif");
      rect = image.rect();};

  public:
  //  void move(int pos){
    void move(int pos){rect.moveTo(500,pos); };
    void resetState(){  rect.moveTo(500, 305);};
    void shoot(int){rect.translate(-1,0 );};
    bool isDestroyed(){return destroyed;};
    void setDestroyed(bool destr){destroyed = destr;};

    void setXDir(int a){
    xdir=a;
    };
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect(){return rect;};
    QImage & getImage(){return image;};


};
class X2: public Perks
{

  public:
X2(){image.load("x2.gif");
      rect = image.rect();};

  public:
  //  void move(int pos){
    void move(int pos){rect.moveTo(500,pos); };
    void resetState(){  rect.moveTo(500, 305);};
    void shoot(int){rect.translate(-1,0 );};
    bool isDestroyed(){return destroyed;};
    void setDestroyed(bool destr){destroyed = destr;};

    void setXDir(int a){
    xdir=a;
    };
    void setYDir(int);
    int getXDir();
    int getYDir();
    QRect getRect(){return rect;};
    QImage & getImage(){return image;};


};
#endif // PERKS_H
