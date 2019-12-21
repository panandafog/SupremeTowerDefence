#include "level.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QThread>
#include <QTimer>
#include <QtCore>
#include <QDebug>
#include "enemy.h"
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

Level::Level(): QGraphicsView()
{

}

