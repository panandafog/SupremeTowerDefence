#include "tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPen>
#include <QGraphicsScene>
#include <QTimer>
#include "bullet.h"
#include "level.h"
#include "enemy.h"

Tower::Tower(Level *level_ptr)
{
  level_ptr_ = level_ptr;
}

double Tower::distanceTo(QGraphicsItem *items)
{
  //make a line between the tower and item and then determine it's size
  QLineF ln(pos(), items->pos());
  return ln.length();
}

void Tower::attackTarget()
{

}

void Tower::tracking()
{
  //get a list of all the items collinding with the field
  QList<QGraphicsItem *> Items = field->collidingItems();

  //the field always has 1 colliding item (the tower), so if the list has 1 object, no enemies
  if (Items.size() == 1) {
    hasTarget = false;
    return;
  }

  double closest = 400;
  QPointF closestPt = QPointF(0, 0);

  //now we assuming that the enemy in inside the field
  for (size_t i = 0, n = Items.size(); i < n; i++) {

    //need to dynamic cast to see if object inside is an enemy
    Enemy *enem = dynamic_cast<Enemy *>(Items[i]);

    if (enem) {
      //this evaluates to true if the dynamic cast is in fact successful, if not then: NULL_PTR
      double thisDist = distanceTo(enem);

      if (thisDist < closest) {
        closest = thisDist;
        closestPt = Items[i]->pos();
        hasTarget = true;
      }

      attackDest = closestPt;
      attackTarget();
    }
  }
}

void Tower::tracking1()
{
  int okayhi = 1;
}
