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

megasav::megasav(QGraphicsItem *parent){
    // set graphics
    QPolygonF poly3;
    poly3 << QPointF(0, 0)
         << QPointF(10, 10)
         << QPointF(15,25)
         << QPointF(0,35)
         << QPointF(-15,25)
         << QPointF(-15,15);

    (this)->setPolygon(poly3);
    (this)->setPen(QPen(Qt::Dense2Pattern));
    (this)->setBrush(QBrush(Qt::Dense2Pattern));

    //HEALTH BAR!!!
    health = 200;
    STEP_SIZE = 6; //speed


    // set points
    points << QPointF(110,80) << QPointF(110,355)<<QPointF(340,355)<< QPointF(340,234)<< QPointF(800, 234); // move down-right then right
    point_index = 0;
    destination = points[0];
    rotateToPoint(destination);

    // connect timer to move_forward
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
    timer->start(150);
}

void megasav::move_forward(){
    enemy::move_forward();
}
