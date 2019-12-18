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
    QTimer * moveTimer = new QTimer(this);
    connect(moveTimer,SIGNAL(timeout()),this, SLOT(move()));//connects a certain signal to a certain slot
    moveTimer->start(50); //every 50ms the move function will be executed

    maxRange = 100;
    distanceTravelled = 0;

}

//THE MOVE FUNCTION
void bullet::move()
{
   double stepSize = 60;
   double theta = rotation(); //degrees

   double dy = stepSize*sin(qDegreesToRadians(theta));
   double dx = stepSize*cos(qDegreesToRadians(theta));

   setPos(x()+dx, y()+dy);
}

double bullet::getMaxRange()
{
    return maxRange;
}

double bullet::getDistanceTravelled()
{
    return distanceTravelled;
}

void bullet::setMaxRange(double range)
{
    maxRange = range;
}

void bullet::setDistanceTravelled(double distance)
{
    distanceTravelled = distance;
}
