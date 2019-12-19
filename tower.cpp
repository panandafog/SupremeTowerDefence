#include "tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPen>
#include <QGraphicsScene>
#include "bullet.h"
#include "game.h"
#include <QTimer>
#include "enemy.h"


extern Game *game;  //global variable

tower::tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

}

double tower::distanceTo(QGraphicsItem *items)
{
  //make a line between the tower and item and then determine it's size
  QLineF ln(pos(), items->pos());
  return ln.length();
}

void tower::attackTarget()
{


}

void tower::tracking()
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
    enemy *enem = dynamic_cast<enemy *>(Items[i]);

    if (enem) { //this evaluates to true if the dynamic cast is in fact successful, if not then: NULL_PTR
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

void tower::tracking1()
{
  int okayhi = 1;
}
