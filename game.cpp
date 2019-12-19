#include <QGraphicsScene>
#include "enemy.h"
#include <QGraphicsView>
#include "game.h"
#include <QThread>
#include <QTimer>
#include <QtCore>
#include "savage.h"
#include "megasav.h"
#include "tower.h"
#include "bullet.h"
#include "weaktower.h"
#include "strongtower.h"
#include "medtower.h"
#include "fiend.h"
#include "gamemap.h"
#include "nexus.h"
#include "QDebug"

Game::Game(): QGraphicsView()
{
  //create a scene
  scene_ = new QGraphicsScene(this);
  scene_->setSceneRect(0, 0, 800, 600);

  //set the scene
  setScene(scene_);

  //alter window
  setFixedSize(800, 600);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  gameMap *realMap = new gameMap();
  scene_->addItem(realMap);

  fiend *hoodrat = new fiend();
  scene_->addItem(hoodrat);

  megasav *enemy2 = new megasav();
  scene_->addItem(enemy2);

  savage *enemy3 = new savage();
  scene_->addItem(enemy3);

  weaktower *weak = new weaktower();
  scene_->addItem(weak);

  weaktower *weak1 = new weaktower();
  weak1->setPos(50, 50);
  scene_->addItem(weak1);

  medtower *med = new medtower();
  med->setPos(400, 100);
  scene_->addItem(med);

  strongtower *strong = new strongtower();
  strong->setPos(300, 200);
  scene_->addItem(strong);

  nexus *home = new nexus();
  home->setPos(720, 62);
  scene_->addItem(home);

  nexus *home2 = new nexus();
  home2->setPos(720, 215);
  scene_->addItem(home2);

}

void Game::mousePressEvent(QMouseEvent *event)
{
  //create bullet
  //bullet * bull1 = new bullet();
  //bull1->setPos(event->pos());
  //bull1->setRotation(40);
  //scene->addItem(bull1);

  //make an enemy
  savage *enemy1 = new savage();
  scene_->addItem(enemy1);
}
