#ifndef TOWER_H
#define TOWER_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QObject>


class tower: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  tower(QGraphicsItem *parent = 0);
  double distanceTo(QGraphicsItem *items);
  virtual void attackTarget();
  QGraphicsPolygonItem *field;
  QPointF attackDest; //this is the point that the tower will attack periodically
  bool hasTarget;
protected slots:
  void tracking();
  void tracking1();
};
#endif // TOWER_H
