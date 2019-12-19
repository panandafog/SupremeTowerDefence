#ifndef NEXUS_H
#define NEXUS_H
#include "tower.h"
#include "QObject"
#include "QGraphicsPixmapItem"

class nexus: public tower
{
public:
    nexus(QGraphicsItem * parent=0);
    int life;
public slots:
    void tracking1();
};

#endif // NEXUS_H
