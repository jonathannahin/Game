#include <QtGui>
#include <QDesktopWidget>
#include <QApplication>
#include "zombies.h"
#include "zombiewindow.h"
// QLineEdit { background: yellow };
ZombiesWindow::ZombiesWindow()
{
    board = new Zombies(this);

    scoreLcd = new QLCDNumber(5);
    scoreLcd->setSegmentStyle(QLCDNumber::Filled);
    livesLcd = new QLCDNumber(2);
    livesLcd->setSegmentStyle(QLCDNumber::Filled);
    levelLcd = new QLCDNumber(2);
    levelLcd->setSegmentStyle(QLCDNumber::Filled);
    ammoLcd = new QLCDNumber(2);
    ammoLcd->setSegmentStyle(QLCDNumber::Filled);

    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);

    connect(startButton, SIGNAL(clicked()), board, SLOT(startGame()));
    connect(quitButton , SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(board, SIGNAL(scoreChanged(int)), scoreLcd, SLOT(display(int)));
    connect(board, SIGNAL(livesChanged(int)), livesLcd, SLOT(display(int)));
    connect(board, SIGNAL(ammoChanged(int)), ammoLcd, SLOT(display(int)));
    connect(board, SIGNAL(levelChanged(int)), levelLcd, SLOT(display(int)));

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(createLabel(tr("LIVES")), 0, 1);
    layout->addWidget(livesLcd, 2, 1);
    layout->addWidget(startButton, 1, 1);
    layout->addWidget(board, 0, 0, 10, 0 );
    layout->addWidget(createLabel(tr("AMMO")), 3, 1);
    layout->addWidget(ammoLcd, 4, 1);
    layout->addWidget(createLabel(tr("LEVEL")), 5, 1);
    layout->addWidget(levelLcd, 6, 1);
    layout->addWidget(createLabel(tr("SCORE")), 7, 1);
    layout->addWidget(scoreLcd, 8, 1);
    layout->addWidget(quitButton, 9, 1);
   // layout->addWidget(pauseButton, 6, 1);
    setLayout(layout);
//SIZE OF GAME SPACE
    setWindowTitle(tr("Zombie Attack!"));
    resize(1000, 500);
}


void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 1000;
  int HEIGHT = 500;


  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);
  widget.setFixedSize(WIDTH, HEIGHT);
}

QLabel *ZombiesWindow::createLabel(const QString &text)
{
    QLabel *lbl = new QLabel(text);
    lbl->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return lbl;
}
