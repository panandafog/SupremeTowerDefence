#ifndef WEAKTOWER_H
#define WEAKTOWER_H
#include "QTimer"
#include "bullet.h"
#include "tower.h"
#include "game.h"

class weaktower: public tower
{
    Q_OBJECT
public:
    weaktower(QGraphicsItem * parent=0);
    void  attackTarget();
public slots:
    void tracking();

};

#endif // WEAKTOWER_H
