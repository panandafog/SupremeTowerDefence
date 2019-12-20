#ifndef NEXUS_H
#define NEXUS_H
#include "tower.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include "level.h"

class nexus: public tower
{
public:
  nexus(Level *level_ptr = nullptr);
  int life_;
private slots:
  void tracking1();
};

#endif // NEXUS_H
