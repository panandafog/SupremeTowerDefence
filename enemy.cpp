#include "enemy.h"
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QTimer>
#include <qmath.h>
#include <QDebug>
#include <QThread>
#include <QtCore>
#include <QPolygonF>
#include <QPointF>
#include <QPainter>
Enemy::Enemy(Level *level_ptr)
{
  level_ptr_ = level_ptr;
}

int Enemy::getPointIndex()
{
  return pointIndex_;
};

int Enemy::getStepSize()
{
  return stepSize_;
};

double Enemy::getHealth()
{
  return health_;
};

void Enemy::setPointIndex(int pointIndex)
{
  pointIndex_ = pointIndex;
};

void Enemy::setStepSize(int stepSize)
{
  stepSize_ = stepSize;
};

void Enemy::setHealth(double health)
{
  health_ = health;
};

void Enemy::rotateToPoint(QPointF p)
{
  QLineF ln(pos(), p);
  setRotation(-1 * ln.angle());
}

void Enemy::move_forward()
{
  // if close to dest, rotate to next dest
  QLineF ln(pos(), destination_);

  if (ln.length() < 5) {
    pointIndex_++;

    if (pointIndex_ >= points_.size()) {
      // qDebug()<<"Damn bukiki, back at it again with the barakis!";
      return;
    }

    destination_ = points_[pointIndex_];
    rotateToPoint(destination_);
  }

  // move enemy forward at current angle

  double theta = rotation(); // degrees

  double dy = stepSize_ * qSin(qDegreesToRadians(theta));
  double dx = stepSize_ * qCos(qDegreesToRadians(theta));

  setPos(x() + dx, y() + dy);
}
