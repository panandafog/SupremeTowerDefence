#ifndef MEGASAV_H
#define MEGASAV_H
#include <QGraphicsPolygonItem>
#include <QObject> //for handling signals and slots
#include <QList> //just like a c++ list, but you can use stream operator to insert things (list<<element)
#include <QPointF> //for points, f version is floating point, additional member functions (e.g. return angle)
#include <QThread>
#include <QtCore>
#include "enemy.h"
#include "level.h"

class megasav: public enemy
{
  Q_OBJECT //need to include QOBJECT macro

public:
  megasav(Level *level_ptr = nullptr); //always include the line in constructor, allows classes to have a parent, other programmers can give this a parent (or you)

private slots:
  void move_forward();
};
#endif // MEGASAV_H
