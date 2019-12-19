#include "savage.h"
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

savage::savage(QGraphicsItem *parent){
    // set graphics
    QPolygonF poly;
    poly << QPointF(0,0)
         << QPointF(30,0)
         << QPointF(30,30)
         << QPointF(0,30);

   (this)->setPolygon(poly);
   (this)->setPen(QPen(Qt::darkCyan));
   (this)->setBrush(QBrush(Qt::darkCyan));

    //HEALTH BAR!!!
    health_ = 150;
    stepSize_ = 7;

    // set points
    points_ << QPointF(97,82) << QPointF(790,82); // move down-right then right
    pointIndex_ = 0;
    destination_ = points_[0];
    rotateToPoint(destination_);

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);

}

void savage::move_forward()
{
    enemy::move_forward();

}
