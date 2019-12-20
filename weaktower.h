#ifndef WEAKTOWER_H
#define WEAKTOWER_H
#include "QTimer"
#include "bullet.h"
#include "tower.h"
#include "level.h"

class WeakTower: public Tower
{
  Q_OBJECT

public:
  WeakTower(Level *level_ptr = nullptr);
  void attackTarget();

private slots:
  void tracking();
};

#endif // WEAKTOWER_H
