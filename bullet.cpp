#include "bullet.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QObject>

Bullet::Bullet(double maxRange, double step):
  distanceTravelled_(0),
  maxRange_(maxRange),
  step_(step)
{
  //set graphics
  setPixmap(QPixmap(":/images/mixtape.png"));

  //connect a timer
  QTimer *moveTimer = new QTimer(this);
  connect(moveTimer, SIGNAL(timeout()), this, SLOT(move())); //connects a certain signal to a certain slot
  moveTimer->start(50); //every 50ms the move function will be executed

}

void Bullet::move()
{
  double theta = rotation(); //degrees

  double dy = step_ * sin(qDegreesToRadians(theta));
  double dx = step_ * cos(qDegreesToRadians(theta));

  setPos(x() + dx, y() + dy);
}

double Bullet::getMaxRange()
{
  return maxRange_;
}

double Bullet::getDistanceTravelled()
{
  return distanceTravelled_;
}

double Bullet::getStep()
{
  return step_;
}

void Bullet::setMaxRange(double range)
{
  maxRange_ = range;
}

void Bullet::setDistanceTravelled(double distance)
{
  distanceTravelled_ = distance;
}

void Bullet::setStep(double step)
{
  step_ = step;
}
