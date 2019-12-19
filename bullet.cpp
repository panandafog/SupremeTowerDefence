#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QObject>

bullet::bullet(QGraphicsItem *parent)
{
  //set graphics
  setPixmap(QPixmap(":/images/mixtape.png"));

  //connect a timer
  QTimer *moveTimer = new QTimer(this);
  connect(moveTimer, SIGNAL(timeout()), this, SLOT(move())); //connects a certain signal to a certain slot
  moveTimer->start(50); //every 50ms the move function will be executed

  maxRange_ = 100;
  distanceTravelled_ = 0;

}

//THE MOVE FUNCTION
void bullet::move()
{
  double stepSize = 60;
  double theta = rotation(); //degrees

  double dy = stepSize * sin(qDegreesToRadians(theta));
  double dx = stepSize * cos(qDegreesToRadians(theta));

  setPos(x() + dx, y() + dy);
}

double bullet::getMaxRange()
{
  return maxRange_;
}

double bullet::getDistanceTravelled()
{
  return distanceTravelled_;
}

void bullet::setMaxRange(double range)
{
  maxRange_ = range;
}

void bullet::setDistanceTravelled(double distance)
{
  distanceTravelled_ = distance;
}
