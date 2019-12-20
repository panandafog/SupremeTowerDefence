#ifndef GAMEMAP_H
#define GAMEMAP_H
#include <QGraphicsPixmapItem>
#include "level.h"

class gameMap: public QGraphicsPixmapItem
{

public:
  gameMap(/*QGraphicsItem *parent = 0*/ Level *level_ptr = nullptr);
protected:
  Level *level_ptr_;
};
#endif // GAMEMAP_H
