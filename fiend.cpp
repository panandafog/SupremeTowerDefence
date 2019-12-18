#include "fiend.h"
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

fiend::fiend(QGraphicsItem *parent)
{
    // set graphics
    poly2 << QPointF(0,0)
         << QPointF(30,0)
         << QPointF(30,30)
         << QPointF(0,30);

    (this)->setPolygon(poly2);
    (this)->setPen(QPen(Qt::darkRed));
    (this)->setBrush(QBrush(Qt::darkRed));

    //HEALTH BAR!!!
    health = 100;
    STEP_SIZE = 6;

    // set points
   points << QPointF(97,82) << QPointF(770,82); // move down-right then right
    point_index = 0;
    destination = points[0];
    rotateToPoint(destination);


    // connect timer to move_forward
   QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void fiend::move_forward()
{
    enemy::move_forward();
}

