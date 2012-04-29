#ifndef zombies_H
#define zombies_H

#include "enemy.h"
#include "bullet.h"
#include "perks.h"
//#include "dog.h"

#include "guy.h"
#include <QWidget>
#include <QKeyEvent>

class Zombies : public QWidget
{
  Q_OBJECT

  public:
    Zombies(QWidget *parent = 0);
    ~Zombies();

  protected:
    void paintEvent(QPaintEvent *event);//Paints images in game
    void timerEvent(QTimerEvent *event);//times the pace of the game
    void keyPressEvent(QKeyEvent *event);//Checks to see if buttons are pressed and performs actions if they are
    void victory();//Win
    void checkCollision();//Checks collisions of every thing in the game

public slots:
    void startGame();//Starts when the start button is pressed
    void levels();//different reactions at different levels
    void pauseGame();//if p is pressd and the game is paused, also can speed up game after pause
    void stopGame();//Ends the game


signals:
     void scoreChanged(int score);
     void livesChanged(int lives);
     void ammoChanged(int ammo);
    void levelChanged(int level);
  private:
    int x,z,q,m,b,bad,tscore,w,f,r,h,v,u;//Integers to track paint events and places in arrays
    int timerId;//Holds the time, pace of the game
    Bat*bat[100];//Creates an array of zombie bats that come after level three
   Blood *blood;//Creates an instance of blood to show when zombies are hit by regular bullets
    Fire*fire;//Creates on instance of fire to show when things are hit by fire bullets
    Health*health[100];//Creates an array of dogs
    Dog *dogs[100];//Creates an array of dogs
    Guy * Guys;//Creates the guy who shoots bullets
    Ammo * reload[100];//Creates an array of the perk to
    X2*x2[100];//Creates an array of the perk to double your score
    Zombie1*zombie1[100];//Creates an array of the first zombie
    Zombie2*zombie2[100];//Creates an array of the second zombie
    Fire_bullet *fbullet[100];//Creates an array of fire bullets
    Bullet *bullet[100];//Creates an array of bullets

    int lives,ammo,score,level;//Keep track of various game points
    bool gameOver,l1,l2,l3,l4,two,three,four,as,ad,af,ag;//Bools for checking colisions
    bool gameWon;//bool tells if game has been won
    bool gameStarted;//bool that shows game has started
    bool paused,healthup,ammoup;//paused game and showing upgrades to game stats
    bool shoot,attack,levelUP,pointsup;
    QImage image,image2,image3,image4;//Hold the background images for different levels
    QRect rect,rect2,rect3,rect4;

};

#endif
