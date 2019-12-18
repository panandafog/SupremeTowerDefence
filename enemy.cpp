#include "enemy.h"
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
enemy::enemy(QGraphicsItem *parent){




}



void enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1 * ln.angle());
}

void enemy::move_forward(){
    // if close to dest, rotate to next dest
    QLineF ln(pos(),destination);
    if (ln.length() < 5){
        point_index++;
        if (point_index>=points.size()){
           // qDebug()<<"Damn bukiki, back at it again with the barakis!";
            return;
        }
        destination = points[point_index];
        rotateToPoint(destination);
    }

    // move enemy forward at current angle

    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);
}
