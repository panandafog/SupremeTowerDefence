#ifndef BULLET_H
#define BULLET_H
#include <QObject>
#include <QGraphicsPixmapItem>

class Bullet: public QObject, public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Bullet(double maxRange = 100, double step = 60);

public slots:
  void move(); //a Qtimer will make this member function fire periodically
  double getMaxRange();
  double getDistanceTravelled();
  double getStep();
  void setMaxRange(double range);
  void setDistanceTravelled(double distance);
  void setStep(double step);

protected:
  double maxRange_;
  double distanceTravelled_;
  double step_;
};
#endif // BULLET_H
