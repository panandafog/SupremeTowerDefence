#ifndef MEDTOWER_H
#define MEDTOWER_H
#include "QTimer"
#include "bullet.h"
#include "tower.h"
#include "level.h"

class MedTower: public Tower
{
  Q_OBJECT

public:
  MedTower(Level *level_ptr = nullptr);
  void  attackTarget();

private slots:
  void tracking();
};
#endif // MEDTOWER_H
