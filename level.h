#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QMouseEvent>

class Level: public QGraphicsView
{
public:
  Level();
  QGraphicsScene *scene_;

private:
  void mousePressEvent(QMouseEvent *event);
};


#endif // GAME_H
