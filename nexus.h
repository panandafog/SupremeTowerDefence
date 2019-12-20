#ifndef NEXUS_H
#define NEXUS_H
#include "tower.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include "level.h"

class Nexus: public Tower
{
public:
  int life_;
  Nexus(Level *level_ptr = nullptr);

private slots:
  void tracking1();
};

#endif // NEXUS_H
