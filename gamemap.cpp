#include "gamemap.h"
#include <QPixmap>
#include <QPixmap>
#include <QTimer>
#include <qmath.h>

Map::Map(Level *level_ptr)
{
  setPixmap(QPixmap(":/images/realmap.png"));
  level_ptr_ = level_ptr;
}
