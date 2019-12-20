#include <QGraphicsScene>
#include "enemy.h"
#include <QGraphicsView>
#include "level.h"
#include <QThread>
#include <QTimer>
#include <QtCore>
#include "level.h"
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

Level::Level(): QGraphicsView()
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

  Map *realMap = new Map(this);
  scene_->addItem(realMap);

  Fiend *hoodrat = new Fiend(this);
  scene_->addItem(hoodrat);

  Megasav *enemy2 = new Megasav(this);
  scene_->addItem(enemy2);

  Savage *enemy3 = new Savage(this);
  scene_->addItem(enemy3);

  WeakTower *weak = new WeakTower(this);
  scene_->addItem(weak);

  WeakTower *weak1 = new WeakTower(this);
  weak1->setPos(50, 50);
  scene_->addItem(weak1);

  MedTower *med = new MedTower(this);
  med->setPos(400, 100);
  scene_->addItem(med);

  StrongTower *strong = new StrongTower(this);
  strong->setPos(300, 200);
  scene_->addItem(strong);

  Nexus *home = new Nexus(this);
  home->setPos(720, 62);
  scene_->addItem(home);

  Nexus *home2 = new Nexus(this);
  home2->setPos(720, 215);
  scene_->addItem(home2);
}

void Level::mousePressEvent(QMouseEvent *event)
{
  //create bullet
  //bullet * bull1 = new bullet();
  //bull1->setPos(event->pos());
  //bull1->setRotation(40);
  //scene->addItem(bull1);

  //make an enemy
  Savage *enemy1 = new Savage();
  scene_->addItem(enemy1);
}
