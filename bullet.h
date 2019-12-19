#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>

class bullet: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  bullet(QGraphicsItem *parent = 0);

public slots:
  void move(); //a Qtimer will make this member function fire periodically
  double getMaxRange();
  double getDistanceTravelled();
  void setMaxRange(double range);
  void setDistanceTravelled(double distance);
protected:
  double maxRange_;
  double distanceTravelled_;

};
#endif // BULLET_H
