#include "zombies.h"
#include <QPainter>
#include <QApplication>
#include <iostream>

Zombies::Zombies(QWidget *parent)
    : QWidget(parent)
{
  setFocusPolicy(Qt::StrongFocus);
  x = 0,m=0,bad=0;
z=0,q=0,b=0,tscore=0,w=0,f=0,v=0,u=0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  levelUP=false;
  shoot=false;
  attack=false;
  ammoup=false;
  pointsup=false;
  lives=3;
  level=0;
  score=0;
  ammo=100;
  blood=new Blood();
  Guys = new Guy();
  fire=new Fire();
  image.load("b1.png");
  rect = image.rect();
  image2.load("b2.png");
  rect2 = image2.rect();
  image3.load("hell.png");
  rect3 = image3.rect();
  image4.load("start.gif");
  rect4 = image4.rect();
   //rect.moveTo(0,0);

  //bullet[z] = new Bullet();//look
 // tank[q]=new Tank();
  std::cout<<"start";


  for(int a=1;a<100;a++){
      bullet[a] = new Bullet();//look
  }
  for(int a=1;a<100;a++){
      fbullet[a] = new Fire_bullet();//look
      fbullet[a] ->setDestroyed(false);
  }

  for(int a=1;a<100;a++){
      zombie1[a] = new Zombie1();
  }
  for(int a=1;a<100;a++){
      zombie2[a] = new Zombie2();
  }
  for(int a=1;a<100;a++){
      dogs[a] = new Dog();
  }
  for(int a=1;a<100;a++){
      bat[a] = new Bat();
       bat[a] ->setDestroyed(false);
  }
  for(int a=1;a<100;a++){
      reload[a] = new Ammo();
  }
  for(int a=1;a<100;a++){
      health[a] = new Health();
  }
  for(int a=1;a<100;a++){
      x2[a] = new X2();
  }

}

Zombies::~Zombies() {

 delete Guys;
 //delete bullet;
/*
 for (int i=0; i<100; i++) {
 delete bullet[i];
 } for (int i=0; i<100; i++) {
     delete tank[i];
     } for (int i=0; i<100; i++) {
     delete zombie1[i];
     }
 for (int i=0; i<100; i++) {
 delete dogs[i];
 }*/
}

void Zombies::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  if (gameOver) {
    QFont font("Courier", 15, QFont::DemiBold);
 //   QFont font2("Courier", 15, QFont::DemiBold);

    QFontMetrics fm(font);
  //  QFontMetrics fm2(font);

    int textWidth = fm.width("Game Over");

      //  int textWidth2 = fm2.width("You died");


    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/4, h/2));
    painter.drawText(-textWidth/2, 0, "Game Over");
 //   painter.translate(QPoint(w/4, h/2));
   // painter.drawText(-textWidth2, 0, "You died");
  }
  else if(gameWon) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Victory");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/4, h/2));
    painter.drawText(-textWidth/2, 0, "Level Up!");
    startGame();
  }
  else {
      if(level==0)
      painter.drawImage(rect4,image4);
      if(level==1)
      painter.drawImage(rect,image);
      if(level==2)
         painter.drawImage(rect2,image2);
      if(level>=3)
            painter.drawImage(rect3,image3);
      //printf("painting ");
  //  painter.drawImage(ball->getRect(),
    //    ball->getImage());
       if(level>0)
    painter.drawImage(Guys->getRect(),
        Guys->getImage());
    //painter.drawImage(tank[q]->getRect(),
    //    tank[q]->getImage());
   // painter.drawImage(tank[q]->getRect2(),
    //    tank[q]->getImage2());
 //   if(shoot==true)
  //  {
     //  std::cout<<"print b";
       //shoot=false;
    //    if (z==1){  painter.drawImage(bullet[z]->getRect(),
    //                                  bullet[z]->getImage());}

   if (f>=1 &&level>=2&&shoot==true){//std::cout<<"1 ";
for (int i=1; i<=f; i++) {
if (!bullet[i]->isDestroyed()){
      painter.drawImage(fbullet[i]->getRect(),
       fbullet[i]->getImage());
//std::cout<<"YOOYOYOY";
}
if(bullet[i]->isDestroyed()){
  painter.drawImage(fire->getRect(),fire->getImage());
}
  }
    }
 //  if (level==2&&r>=1)
   if(healthup)
   {//std::cout<<"1 ";
 for (int i=1; i<=h; i++) {
if (!health[i]->isDestroyed())
       painter.drawImage(health[i]->getRect(),
        health[i]->getImage());
   }}
   if(ammoup)
   {//std::cout<<"1 ";
 for (int i=1; i<=r; i++) {
if (!reload[i]->isDestroyed())
       painter.drawImage(reload[i]->getRect(),
        reload[i]->getImage());
   }}
   if(pointsup)
   {//std::cout<<"1 ";
 for (int i=1; i<=u; i++) {
if (!x2[i]->isDestroyed())
       painter.drawImage(x2[i]->getRect(),
        x2[i]->getImage());
   }}

    if (z>=1&&shoot==true&&level<2){//std::cout<<"1 ";
  for (int i=1; i<=z; i++) {
if (!bullet[i]->isDestroyed())
        painter.drawImage(bullet[i]->getRect(),
         bullet[i]->getImage());

    }
      }
      if (q>=1&&attack==true){//std::cout<<"1 ";
  for (int i=1; i<=q; i++) {
if (!zombie1[i]->isDestroyed())
        painter.drawImage(zombie1[i]->getRect(),
         zombie1[i]->getImage());
if(zombie1[i]->isDestroyed()&&level<2){
    painter.drawImage(blood->getRect(),blood->getImage());
  }
    }
      }if(b>=1){
      for (int i=1; i<=b; i++) {
    if (!zombie2[i]->isDestroyed())
            painter.drawImage(zombie2[i]->getRect(),
             zombie2[i]->getImage());
        }}
      if(w>=1){
            for (int i=1; i<=w; i++) {
          if (!dogs[i]->isDestroyed())
                  painter.drawImage(dogs[i]->getRect(),
                   dogs[i]->getImage());

              }}
      if(v>=1){
            for (int i=1; i<=v; i++) {
          if (!bat[i]->isDestroyed())
                  painter.drawImage(bat[i]->getRect(),
                   bat[i]->getImage());

              }}
   // }
    //for (int i=0; i<30; i++) {
   //     if (!bricks[i]->isDestroyed())
     //     painter.drawImage(bricks[i]->getRect(),
        //      bricks[i]->getImage());
 //  }
  }
}

void Zombies::timerEvent(QTimerEvent *event)
{ //printf("timerEvent\n");

  //if(shoot==true){
  //if (z==1){  }
//if (z>=1){bullet[z]->shoot(lives);}
   if (z>=1){
for (int i=1; i<=z; i++) {
  //  std::cout<<"i: "<<i<<"z "<<z;
bullet[i]->shoot(lives);
//fire->shoot(lives);
//std::cout<<"2 ";
shoot=true;
  }}
   if (f>=1){
   for (int i=1; i<=f; i++) {
   fbullet[i]->shoot(lives);
 //  std::cout<<"TEST";
   }}

  // if(level==2&&r>=0)
   if(ammoup)
   {
       for (int i=1; i<=r; i++) {
       reload[i]->shoot(lives);
       }
   }
   if(healthup)
   {
       for (int i=1; i<=h; i++) {
       health[i]->shoot(lives);
       }
   }
   if(pointsup)
   {
       for (int i=1; i<=h; i++) {
       x2[i]->shoot(lives);
       }
   }
if (q>=1){
for (int i=1; i<=q; i++) {
//  std::cout<<"i: "<<i<<"z "<<z;
zombie1[i]->shoot(lives);
//std::cout<<"2 ";
attack=true;
}
//  }
 // bullet[1]->shoot(lives);
 // z++;
  }
for(int i=1; i<=b;i++)
    zombie2[i]->shoot(lives);
for(int i=1; i<=w;i++)
    dogs[i]->shoot(lives);
for(int i=1; i<=v;i++)
    bat[i]->shoot(lives);
//rect.moveTo(0,0);
  //tank[q]->shoot(lives);
//  tank[q]->shoot2(lives);

// tank[q]->move(50);
//    tank[q]->shoot2(x);
  checkCollision();
  repaint();
}

//KEYS
void Zombies::keyPressEvent(QKeyEvent *event)
{   //printf("%c",event->key());

    switch (event->key()) {
    case Qt::Key_Up:
    {
         //printf("left\n");
         int x = Guys->getRect().y();
        for (int i=1; i<=10; i++)
          {Guys->moveUp(x--);
      //  bullet[z]->move(x);
        }
        break;
       }
    case Qt::Key_Down:
    {
          //printf("right\n");
          int x = Guys->getRect().y();
          for (int i=1; i<=10; i++)
            Guys->moveDown(x++);
       //   level();

        }
        break;
    case Qt::Key_P:
        {//printf( "start pause");
          pauseGame();
        }
        break;
    case Qt::Key_Space:
    { //printf( "start space");
          //startGame();
        ammo--;
        if(ammo==0)
    stopGame();
       // bullet[z] = new Bullet();
        int t = Guys->getRect().y();

  //  if(level<2){
        z++;
        bullet[z]->move(t);
    //}
       // if(level>=2){
        f++;
            fbullet[f]->move(t);//}

        if(shoot==true){
            int x=Guys->getRect().y();

            if (m % 2==0){
        q++;
        //if(m==0)
         zombie1[q]->move(x);}
      }

        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Zombies::startGame()
{
  //printf("started\n");
  if (!gameStarted) {
   // ball->resetState();
    Guys->resetState();
    //bullet->resetState();
    if(level==0)
{ level++;}

   // for (int i=0; i<100; i++) {
     // bullet[i]->setDestroyed(FALSE);
   //}
    gameOver = FALSE;
    gameWon = FALSE;
    gameStarted = TRUE;
    emit scoreChanged(score);
    emit livesChanged(lives);
    emit ammoChanged(ammo-2);
    emit levelChanged( level);

    timerId = startTimer(20);

  }
}void Zombies::levels()
{
  //printf("started\n");
    if(level==2&&levelUP==true){
     killTimer(timerId);
 std::cout<<"levelupsssss";
    timerId = startTimer(10);}
    else{levelUP=true;}
   // level++;

}


void Zombies::pauseGame()
{ //printf( "start pause");
  if (paused & gameStarted) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId);
   }
}

void Zombies::stopGame()
{
  killTimer(timerId);
  gameOver = TRUE;
  gameStarted = FALSE;
  score=0;
  lives=0;
}

void Zombies::victory()
{
  killTimer(timerId);
  gameWon = TRUE;
  lives++;
  gameStarted = FALSE;
}

void Zombies::checkCollision()
{

m++;
//std::cout<<m<<" ";
  //if (ball->getRect().left() <5)
   // stopGame();
int ran = rand() % 10 + 1;
int ran2 = rand() % 10 + 2;
int ran3 = rand() % 10 + 3;
if(m%100==0){//q++;
    b++;
    zombie2[b]->move(ran*15);
    if(level>=2){
        w++;
    dogs[w]->move(ran2*20+50);}
    if(level>=3){
        v++;
    bat[v]->move(ran*20+60);}
    //if(level==2)
    if(m==200)
    {
        r++;
        reload[r]->move(ran2*20+20);
        ammoup=true;
    }

    if(m==700)
    {
        h++;
        health[h]->move(ran2*20+60);
        healthup=true;
    }
    if(m==900)
    {
        u++;
        x2[u]->move(ran3*20+80);
        pointsup=true;
    }
}

if(ammoup){
//int x = Guys->getRect().y();
//std::cout<<x<<"y:";
//int y=reload[r]->getRect().y();
//std::cout<<y<<" ";
//for(int i=1;i<r;i++){
if((reload[r]->getRect()).intersects(Guys->getRect())){

if (!reload[r]->isDestroyed())
   {  reload[r]->setDestroyed(TRUE);
        ammoup=false;
        ammo++;
}
}}//}
if(healthup){
if((health[h]->getRect()).intersects(Guys->getRect())){

if (!health[h]->isDestroyed())
   {  health[h]->setDestroyed(TRUE);
        healthup=false;
        lives++;
}
}}
if(pointsup){
if((x2[u]->getRect()).intersects(Guys->getRect())){

if (!x2[u]->isDestroyed())
   {  x2[u]->setDestroyed(TRUE);
        pointsup=false;
        score=score*2;
       // lives++;
}
}}
//  for (int i=0, j=0; i<30; i++) {
  //  if (bricks[i]->isDestroyed()) {
  //    j++;
      //std::cout <<"destroyed" << std::endl;
  //  }

   // if (j==30)
   //   victory();
   // score=j;
 // }

//TANKS
 /* if(shoot==true){
      int x=Guys->getRect().y();
  q++;
  //if(m==0)
   tank[q]->move(x+q*2);
   //tank[q]->shoot(x);
}*/
  //if((tank[q]->getRect()).intersects(paddle->getRect())){
  //  std::cout<<"SHIT";
  //   score--;
// }
  //if(m>1){
//tank[q]->move(m*2);
//tank[q]->shoot(x);
 // }
  //m++;
//if(level<2){
bool check =false;
  for(int i=1;i<100;i++){
      if(check==false){
for(int t=1;t<100;t++){
 if((zombie1[i]->getRect()).intersects(bullet[t]->getRect())){
 if (!bullet[t]->isDestroyed()&&(!zombie1[i]->isDestroyed()))
    {  bullet[t]->setDestroyed(TRUE);
//std::cout<<i<<"bullet"<<t;
     // if(!tank[i]->isDestroyed())

tscore++;
      score++;
      zombie1[i]->setDestroyed(TRUE);
      check=true;//}
      int x = zombie1[i]->getRect().x();
      int y = zombie1[i]->getRect().y();
      fire->move(x,y);
       blood->move(x+1,y);
 }}}}}

  bool check2 =false;
    for(int i=1;i<100;i++){
        if(check2==false){
  for(int t=1;t<100;t++){
   if((zombie2[i]->getRect()).intersects(bullet[t]->getRect())){
   if (!bullet[t]->isDestroyed()&&(!zombie2[i]->isDestroyed()))
      {bullet[t]->setDestroyed(TRUE);
//  std::cout<<i<<"bullet"<<t;
       // if(!tank[i]->isDestroyed())
        score++;
        tscore++;
 //  std::cout<<"HIT"<<score;
        zombie2[i]->setDestroyed(TRUE);
        check2=true;//}
        int x = zombie2[i]->getRect().x();
        int y = zombie2[i]->getRect().y();
        fire->move(x,y);
       blood->move(x+2,y);
  }}}}}
    bool check3 =false;
      for(int i=1;i<100;i++){
          if(check3==false){
    for(int t=1;t<100;t++){
     if((dogs[i]->getRect()).intersects(bullet[t]->getRect())){
     if (!bullet[t]->isDestroyed()&&(!dogs[i]->isDestroyed()))
        {bullet[t]->setDestroyed(TRUE);
   // std::cout<<i<<"bullet"<<t;
         // if(!tank[i]->isDestroyed())
          score++;
          tscore++;
          dogs[i]->setDestroyed(TRUE);
          check3=true;//}

          int x = dogs[i]->getRect().x();
           int y = dogs[i]->getRect().y();
          fire->move(x,y);
            blood->move(x+3,y);
    }}}}}
      bool check4 =false;
        for(int i=1;i<100;i++){
            if(check4==false){
      for(int t=1;t<100;t++){
       if((bat[i]->getRect()).intersects(bullet[t]->getRect())){
       if (!bullet[t]->isDestroyed()&&(!bat[i]->isDestroyed()))
          {bullet[t]->setDestroyed(TRUE);
     // std::cout<<i<<"bullet"<<t;
           // if(!tank[i]->isDestroyed())
            score++;
            tscore++;
            bat[i]->setDestroyed(TRUE);
            check4=true;//}

            int x = bat[i]->getRect().x();
             int y = bat[i]->getRect().y();
            fire->move(x,y);
              blood->move(x+3,y);
      }}}}}

 /*   // if(level>=2){
      bool check4 =false;
        for(int i=1;i<100;i++){
            if(check4==false){
      for(int t=1;t<100;t++){
       if((zombie1[i]->getRect()).intersects(fbullet[t]->getRect())){
       if (!fbullet[t]->isDestroyed()&&(!zombie1[i]->isDestroyed()))
          {  fbullet[t]->setDestroyed(TRUE);
      //std::cout<<i<<"bullet"<<t;
           // if(!tank[i]->isDestroyed())
      //tscore++;
            score++;
      // std::cout<<"HIT"<<score;
            zombie1[i]->setDestroyed(TRUE);
            check4=true;//}
       }}}}}
//}

         check2 =false;
          for(int i=1;i<100;i++){
              if(check==false){
        for(int t=1;t<100;t++){
         if((zombie2[i]->getRect()).intersects(fbullet[t]->getRect())){
         if (!fbullet[t]->isDestroyed()&&(!zombie2[i]->isDestroyed()))
            {fbullet[t]->setDestroyed(TRUE);
      //  std::cout<<i<<"bullet"<<t;
             // if(!tank[i]->isDestroyed())
              score++;
              tscore++;
         std::cout<<"HIT"<<score;
              zombie2[i]->setDestroyed(TRUE);
              check2=true;//}
        }}}}}
           check3 =false;
            for(int i=1;i<100;i++){
                if(check==false){
          for(int t=1;t<100;t++){
           if((dogs[i]->getRect()).intersects(fbullet[t]->getRect())){
           if (!fbullet[t]->isDestroyed()&&(!dogs[i]->isDestroyed()))
              {fbullet[t]->setDestroyed(TRUE);
         // std::cout<<i<<"bullet"<<t;
               // if(!tank[i]->isDestroyed())
                score++;
                tscore++;
           std::cout<<"HIT"<<score;
                dogs[i]->setDestroyed(TRUE);
                check3=true;//}
          }}}}}

*/

//LIVES
l1=false;
    for(int i=1;i<100;i++){
        if(l1==false){
            if(i!=bad){
    int zombpos2= zombie2[i]->getRect().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!zombie2[i]->isDestroyed())&&zombpos2>0){
       // std::cout<<"zombpos!!!!!!!!!!!!!!"<<zombpos2;
l1=true;
l2=true;
    bad=i;
    lives--;
    }
        }}}
    l1=false;

        for(int i=1;i<100;i++){
            if(l1==false){
                if(i!=bad){
        int zombpos2= dogs[i]->getRect().left();
       // std::cout<<zombpos2<<" ";
        if (zombpos2<10&&(!dogs[i]->isDestroyed())&&zombpos2>0){
        //    std::cout<<"zombpos!!!!!!!!!!!!!!"<<zombpos2;
    l1=true;
    l2=true;
        bad=i;
        lives--;
        }
            }}}
        for(int i=1;i<100;i++){
            if(l1==false){
                if(i!=bad){
        int zombpos2= zombie1[i]->getRect().left();
       // std::cout<<zombpos2<<" ";
        if (zombpos2<10&&(!zombie1[i]->isDestroyed())&&zombpos2>0){
    l1=true;
    l2=true;
        bad=i;
        lives--;
        }
            }}}
        for(int i=1;i<100;i++){
            if(l1==false){
                if(i!=bad){
        int zombpos2= bat[i]->getRect().left();
       // std::cout<<zombpos2<<" ";
        if (zombpos2<10&&(!bat[i]->isDestroyed())&&zombpos2>0){
    l1=true;
    l2=true;
        bad=i;
        lives--;
        }
            }}}



    /*

    for(int i=1;i<100;i++){
        if(l2==true){
            if(i!=bad){
    int zombpos2= zombie1[i]->getRect().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!zombie1[i]->isDestroyed())){
        std::cout<<"zombpos!!!!!!!!!!!!!!";
l2=false;
l3=true;
    bad=i;
    lives--;}
        }}}
    for(int i=1;i<100;i++){
        if(l3==true){
            if(i!=bad){
    int zombpos2= zombie1[i]->getRect().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!zombie1[i]->isDestroyed())){
        std::cout<<"333zombpos!!!!!!!!!!!!!!";
    l3=false;
    bad=i;
    lives--;
    stopGame();}
        }}}

    for(int i=1;i<100;i++){
        if(two==false){
            if(i!=bad){
    int zombpos2= zombie1[i]->getRect().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!zombie1[i]->isDestroyed())){
        std::cout<<"zombpos!!!!!!!!!!!!!!";
two=true;
three=true;
    bad=i;
    lives--;}
        }}}

    for(int i=1;i<100;i++){
        if(three==true){
            if(i!=bad){
    int zombpos2= zombie1[i]->getRect().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!zombie1[i]->isDestroyed())){
        std::cout<<"zombpos!!!!!!!!!!!!!!";
three=false;
four=true;
    bad=i;
    lives--;}
        }}}
    for(int i=1;i<100;i++){
        if(four==true){
            if(i!=bad){
    int zombpos2= zombie1[i]->getRect().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!zombie1[i]->isDestroyed())){
        std::cout<<"333zombpos!!!!!!!!!!!!!!";
    four=false;
    bad=i;
    lives--;
   // stopGame();
    }
        }}}*/
/*
    for(int i=1;i<100;i++){
        if(as==false){
            if(i!=bad){
    int zombpos2= dogs[i]->getRect3().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!dogs[i]->isDestroyed())){
        std::cout<<"zombpos!!!!!!!!!!!!!!";
as=true;
ad=true;
    bad=i;
    lives--;}
        }}}

    for(int i=1;i<100;i++){
        if(ad==true){
            if(i!=bad){
    int zombpos2= dogs[i]->getRect3().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!dogs[i]->isDestroyed())){
        std::cout<<"zombpos!!!!!!!!!!!!!!";
ad=false;
af=true;
    bad=i;
    lives--;}
        }}}
    for(int i=1;i<100;i++){
        if(af==true){
            if(i!=bad){
    int zombpos2= dogs[i]->getRect3().left();
   // std::cout<<zombpos2<<" ";
    if (zombpos2<10&&(!dogs[i]->isDestroyed())){
        std::cout<<"333zombpos!!!!!!!!!!!!!!";
    af=false;
    bad=i;
    lives--;
    stopGame();}
        }}}
*/
    if(tscore==25){
        std::cout<<"Next Level";
        levels();
        level++;
        //tscore=tscore + score*30;
        tscore=0;
       // ammo=ammo+15;
    }
    if(lives<=0||ammo<=2)
    {stopGame();
        //endGame()
        std::cout<<"GAMEOVER";
    }

  if (!gameOver)
    emit scoreChanged(score*30);
  emit livesChanged(lives);
  emit ammoChanged(ammo-2);
  emit levelChanged(level);

  //if (level==2)
  //   victory();

  //if ((ball->getRect()).intersects(paddle->getRect())) {

    int GuysLPos = Guys->getRect().left();
  //  int ballLPos = ball->getRect().left();
//HIT POS
 /*   int first = GuyssLPos + 8;
    int second = GuyssLPos + 16;
    int third = paddleLPos + 24;
    int fourth = paddleLPos + 32;
    //std::cout<<"f: "<<first<<"s: "<<second;

    if (ballLPos < first) {
        std::cout<<"first";

      ball->setXDir(-1);
      ball->setYDir(-1);
    }

    if (ballLPos >= first && ballLPos < second) {
      ball->setXDir(-1);
      ball->setYDir(-1*ball->getYDir());
       std::cout<<"second";
    }

    if (ballLPos >= second && ballLPos < third) {
       ball->setXDir(1);
       ball->setYDir(-1);
       std::cout<<"first"<<first<<"third"<<second<<" "<<third<<" "<<fourth;
    }

    if (ballLPos >= third && ballLPos < fourth) {
       ball->setXDir(1);
       ball->setYDir(-1*ball->getYDir());
      // std::cout<<"forthhhhh"<<second<<" "<<third;

    }

    if (ballLPos > fourth) {
      ball->setXDir(1);
      ball->setYDir(-1);
      //std::cout<<"rrrforthhhhh"<<second<<" "<<third;

    }
  }
//BRICKS
  for (int i=0; i<30; i++) {
    if ((ball->getRect()).intersects(bricks[i]->getRect())) {

      int ballLeft = ball->getRect().left();
      int ballHeight = ball->getRect().height();
      int ballWidth = ball->getRect().width();
      int ballTop = ball->getRect().top();

      QPoint pointRight(ballLeft + ballWidth + 1, ballTop);
      QPoint pointLeft(ballLeft - 1, ballTop);
      QPoint pointTop(ballLeft, ballTop -1);
      QPoint pointBottom(ballLeft, ballTop + ballHeight + 1);

      if (!bricks[i]->isDestroyed()) {
        if(bricks[i]->getRect().contains(pointRight)) {
           ball->setXDir(-1);
        }

        else if(bricks[i]->getRect().contains(pointLeft)) {
           ball->setXDir(1);
        }

        if(bricks[i]->getRect().contains(pointTop)) {
           ball->setYDir(1);
        }

        else if(bricks[i]->getRect().contains(pointBottom)) {
           ball->setYDir(-1);
        }

        bricks[i]->setDestroyed(TRUE);
      }
    }
  }*/

}
