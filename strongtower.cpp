#include "strongtower.h"
#include <QTimer>
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPen>
#include <QGraphicsScene>

StrongTower::StrongTower(Level *level_ptr)
{
  level_ptr_ = level_ptr;
  //setting graphics
  setPixmap(QPixmap(":/images/charmander.png"));
  this->setPos(400, 400);

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
  int scaleFactor = 45;

  //scale the points up
  for (size_t i = 0, n = points.size(); i < n; i++) {
    points[i] *= scaleFactor;
  }

  //create a polygon from this
  QPolygonF polygon(points);

  //field, the "this" is there to add the polygon to the scene (its the parent)
  field = new QGraphicsPolygonItem(polygon, this);
  field->setPen(QPen(Qt::darkCyan));

  //changing the position of field
  QPointF center(1.5, 1.5);
  center *= scaleFactor; //this is relative to tower item
  center = mapToScene(center); //maps to the scene coordinates
  QPointF centerTower(x() + 46, y() + 48);
  QLineF ln(center, centerTower);
  field->setPos(ln.dx(), ln.dy());

  //connecting timer to slot
  QTimer *timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(tracking()));
  timer->start(1000);
}

void StrongTower::attackTarget()
{
  Bullet *bull2 = new Bullet();
  bull2->setPixmap(QPixmap(":/images/weak.png"));
  bull2->setPos(x() + 46, y() + 48); //centering the bullet

  //makes it so the path of the bullet is parallel to the line to the target
  QLineF ln(QPointF(x() + 25, y() + 35), attackDest);
  int angle = -1 * ln.angle(); // gives you the angle of the line in counter clockwise so we multiply by -1

  bull2->setRotation(angle);
  level_ptr_->scene_->addItem(bull2);
}


void StrongTower::tracking()
{
  Tower::tracking();
}

