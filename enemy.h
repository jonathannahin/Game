#ifndef ENEMY_H
#define ENEMY_H
#include <QImage>
#include <QRect>

class Enemy
{

  public:
    Enemy();
    ~Enemy();

  public:
    void move(int);//Move Enemy
    void resetState();//Restart State
    void moveBottom(int);//Moves enemy from left to right
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
    QImage & getImage();
    QRect getRect2();
    QImage & getImage2();//get image
    QRect getRect3();
    QImage & getImage3();

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

class Dog: public Enemy
{

  public:
Dog(){image.load("dog.gif");
      rect = image.rect();};

  public:
  //  void move(int pos){
    void move(int pos){rect.moveTo(500,pos);};
    void resetState(){  rect.moveTo(500, 305);};
    void shoot(int){rect.translate(-1,0 );};
    bool isDestroyed(){return destroyed;};
    void setDestroyed(bool destr){destroyed = destr;};

    void setXDir(int a){
    xdir=a;
    };
    void setYDir(int){

    };
    int getXDir();
    int getYDir();
    QRect getRect(){
   return rect;
    };
    QImage & getImage(){

       return image;
    };
};
    class Zombie1: public Enemy
    {

      public:
    Zombie1(){image.load("zombie.gif");
          rect = image.rect();};

      public:
      //  void move(int pos){
        void move(int pos){rect.moveTo(500,pos);};
        void resetState(){  rect.moveTo(500, 305);};
        void shoot(int){rect.translate(-1,0 );};
        bool isDestroyed(){return destroyed;};
        void setDestroyed(bool destr){destroyed = destr;};

        void setXDir(int a){
        xdir=a;
        };

        QRect getRect(){
       return rect;
        };
        QImage & getImage(){

           return image;
        };


};
    class Zombie2: public Enemy
    {

      public:
    Zombie2(){image.load("zombie2.gif");
          rect = image.rect();};

      public:
      //  void move(int pos){
        void move(int pos){rect.moveTo(500,pos);};
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

    class Bat: public Enemy
    {

      public:
    Bat(){image.load("firebat.gif");
          rect = image.rect();};

      public:
      //  void move(int pos){
        void move(int pos){rect.moveTo(500,pos);};
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

    class Fire: public Enemy
    {

      public:
    Fire(){image.load("fire.gif");
          rect = image.rect();};

      public:
      //  void move(int pos){
        void move(int pos,int x){rect.moveTo(pos,x);
                          };
        void resetState(){  rect.moveTo(300, 305);};
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
    class Blood: public Enemy
    {

      public:
    Blood(){image.load("blood1.gif");
          rect = image.rect();};

      public:
      //  void move(int pos){
        void move(int pos,int x){rect.moveTo(pos,x);
                          };
        void resetState(){  rect.moveTo(300, 305);};
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

#endif
