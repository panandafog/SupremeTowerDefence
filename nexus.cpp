#include <QPixmap>
#include "nexus.h"
#include "tower.h"
#include "game.h"
#include "QTimer"
#include "QPen"
#include "QPointF"
#include "QDebug"
#include "enemy.h"
#include "savage.h"
extern Game *game;  //global variable

nexus::nexus(QGraphicsItem *parent)
{
  //setting graphics
  setPixmap(QPixmap(":/images/nexus.png"));
  this->setPos(200, 400);

  //points for field (1.5.1.5) is the center
  QVector<QPointF> points;
  points << QPointF(1, 0)
         << QPointF(2, 0)
         << QPointF(3, 1)
         << QPointF(3, 2)
         << QPointF(2, 3)
         << QPointF(1, 3)
         << QPointF(0, 2)
         << QPointF(0, 1);
  int scaleFactor = 30;

  //scale the points up
  for (size_t i = 0, n = points.size(); i < n; i++) {
    points[i] *= scaleFactor;
  }

  //create a polygon from this
  QPolygonF polygon(points);

  //field, the "this" is there to add the polygon to the scene (its the parent)
  field = new QGraphicsPolygonItem(polygon, this);
  field->setPen(QPen(Qt::darkBlue));

  //changing the position of field
  QPointF center(1.5, 1.5);
  center *= scaleFactor; //this is relative to tower item
  center = mapToScene(center); //maps to the scene coordinates
  QPointF centerTower(x() + 38, y() + 36);
  QLineF ln(center, centerTower);
  field->setPos(ln.dx(), ln.dy());

  //connecting timer to slot
  QTimer *timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(tracking1()));
  timer->start(1000);

  life_ = 100;
}

void nexus::tracking1()
{
  //get a list of all the items collinding with the field
  QList<QGraphicsItem *> Items = field->collidingItems();

  //the field always has 1 colliding item (the tower), so if the list has 1 object, no enemies
  if (Items.size() == 1) {
    hasTarget = false;
    return;
  }

  //now we assuming that the enemy in inside the field
  for (size_t i = 0, n = Items.size(); i < n; i++) {

    //need to dynamic cast to see if object inside is an enemy
    enemy *enem = dynamic_cast<enemy *>(Items[i]);

    if (enem) {
      //this evaluates to true if the dynamic cast is in fact successful, if not then: NULL_PTR

      qDebug() << "hey"; //ISSUE HERE NOT SURE WHY THIS ISN'T WORKING

    }
  }
}
