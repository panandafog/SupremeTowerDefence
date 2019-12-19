#ifndef STRONGTOWER_H
#define STRONGTOWER_H
#include "QTimer"
#include "bullet.h"
#include "tower.h"
#include "game.h"

class strongtower: public tower
{
  Q_OBJECT
public:
  strongtower(QGraphicsItem *parent = 0);
  void  attackTarget();
private slots:
  void tracking();
};
#endif // STRONGTOWER_H
