#include "megasav.h"
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QThread>
#include <QtCore>
#include <QPolygonF>
#include <QPointF>
#include <QPainter>
#include "enemy.h"

Megasav::Megasav(Level *level_ptr)
{
  level_ptr_ = level_ptr;
  // set graphics
  QPolygonF poly3;
  poly3 << QPointF(0, 0)
        << QPointF(10, 10)
        << QPointF(15, 25)
        << QPointF(0, 35)
        << QPointF(-15, 25)
        << QPointF(-15, 15);

  (this)->setPolygon(poly3);
  (this)->setPen(QPen(Qt::Dense2Pattern));
  (this)->setBrush(QBrush(Qt::Dense2Pattern));

  //HEALTH BAR!!!
  health_ = 200;
  stepSize_ = 6; //speed


  // set points
  points_ << QPointF(110, 80) << QPointF(110, 355) << QPointF(340, 355) << QPointF(340, 234) << QPointF(800, 234); // move down-right then right
  pointIndex_ = 0;
  destination_ = points_[0];
  rotateToPoint(destination_);

  // connect timer to move_forward
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(move_forward()));
  timer->start(150);
}

void Megasav::move_forward()
{
  Enemy::move_forward();
}
