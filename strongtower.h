#ifndef STRONGTOWER_H
#define STRONGTOWER_H
#include "QTimer"
#include "bullet.h"
#include "tower.h"
#include "level.h"

class strongtower: public tower
{
  Q_OBJECT
public:
  strongtower(Level *level_ptr = nullptr);
  void  attackTarget();
private slots:
  void tracking();
};
#endif // STRONGTOWER_H
