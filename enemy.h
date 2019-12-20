#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPolygonItem>
#include <QObject> //for handling signals and slots
#include <QList> //just like a c++ list, but you can use stream operator to insert things (list<<element)
#include <QPointF> //for points, f version is floating point, additional member functions (e.g. return angle)
#include <QThread>
#include <QtCore>
#include <QPolygonF>
#include "level.h"

class enemy: public QObject, public QGraphicsPolygonItem
{

  Q_OBJECT //need to include QOBJECT macro

public:
  enemy(Level *level_ptr = nullptr); //always include the line in constructor, allows classes to have a parent, other programmers can give this a parent (or you)
  void rotateToPoint(QPointF p); //will take a point and get enemy to face that point

  int getPointIndex();
  int getStepSize();
  double getHealth();

  void setPointIndex(int);
  void setStepSize(int);
  void setHealth(double);

public slots:
  void move_forward();//slots are connected to Qtimer, this allows enemy to move forward periodically

protected:
  QList<QPointF> points_; //list of points
  QPointF destination_; //point to travel towards
  int pointIndex_; //which point are we at in list of points
  int stepSize_;

  double health_;
  QPolygonF poly2_;

  Level *level_ptr_;
};

#endif // ENEMY_H
