#ifndef DEMO_H
#define DEMO_H

#include "level.h"

class Demo: public Level
{
public:
  Demo();

private:
  void mousePressEvent(QMouseEvent *event);
};

#endif // DEMO_H
