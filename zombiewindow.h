#ifndef zombiewindow_H
#define zombiewindow_H
#include <QtGui>
#include <QFrame>
#include <QWidget>
#include "zombies.h"

 class QLCDNumber;
 class QLabel;
 class QPushButton;

 class Zombies;

 class ZombiesWindow : public QWidget
 {
     Q_OBJECT

 public:
     ZombiesWindow();

 private:
     QLabel *createLabel(const QString &text);
     Zombies *board;
     QLCDNumber *scoreLcd;
     QLCDNumber *livesLcd;
     QLCDNumber *ammoLcd;
     QLCDNumber * levelLcd;
     QPushButton *startButton;
     QPushButton *quitButton;
     QPushButton *pauseButton ;
     //QPushButton

 };

 #endif
