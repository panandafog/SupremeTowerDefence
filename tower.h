#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>
#include "level.h"


class tower: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  tower(Level *level_ptr = nullptr);
  double distanceTo(QGraphicsItem *items);
  virtual void attackTarget();

  QGraphicsPolygonItem *field;
  QPointF attackDest; //this is the point that the tower will attack periodically
  bool hasTarget;
protected slots:
  void tracking();
  void tracking1();
protected:
  Level *level_ptr_;
};
#endif // TOWER_H
