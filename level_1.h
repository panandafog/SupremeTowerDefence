#ifndef LEVEL_1_H
#define LEVEL_1_H

#include "level.h"

class Level_1: public Level
{
public:
  Level_1();

private:
  void mousePressEvent(QMouseEvent *event);
};

#endif // LEVEL_1_H
