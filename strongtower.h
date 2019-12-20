#ifndef STRONGTOWER_H
#define STRONGTOWER_H
#include "QTimer"
#include "bullet.h"
#include "tower.h"
#include "level.h"

class StrongTower: public Tower
{
  Q_OBJECT

public:
  StrongTower(Level *level_ptr = nullptr);
  void  attackTarget();

private slots:
  void tracking();
};
#endif // STRONGTOWER_H
