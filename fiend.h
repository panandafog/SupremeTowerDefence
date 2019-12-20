#ifndef FIEND_H
#define FIEND_H
#include <QGraphicsPolygonItem>
#include <QObject> //for handling signals and slots
#include <QList> //just like a c++ list, but you can use stream operator to insert things (list<<element)
#include <QPointF> //for points, f version is floating point, additional member functions (e.g. return angle)
#include <QThread>
#include <QtCore>
#include <QGraphicsObject>
#include "enemy.h"
#include "level.h"

class Fiend: public Enemy
{
  Q_OBJECT

public:
  Fiend(Level *level_ptr = nullptr); //always include the line in constructor, allows classes to have a parent, other programmers can give this a parent (or you)

public slots:
  void move_forward();

};
#endif // FIEND_H
