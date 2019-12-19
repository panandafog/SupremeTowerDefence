#ifndef MEDTOWER_H
#define MEDTOWER_H
#include "QTimer"
#include "bullet.h"
#include "tower.h"
#include "game.h"

class medtower: public tower
{
  Q_OBJECT
public:
  medtower(QGraphicsItem *parent = 0);
  void  attackTarget();
private slots:
  void tracking();
};
#endif // MEDTOWER_H
