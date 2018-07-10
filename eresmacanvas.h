/***************************************************************************
                     Eresma Qt based Eressea Viewer
                             -------------------
    begin                : July 2018
    copyright            : (C) 2018 Klaas Freitag
    email                : klaas@volle-kraft-voraus.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef ERESMACANVAS_H
#define ERESMACANVAS_H

#include <QObject>
#include <QWidget>
#include <QSplitter>
#include <QTreeWidget>

class RegionTree;
class ItemInfo;
class OrderEditor;
class HexMap;

class EresmaCanvas : public QSplitter
{
    Q_OBJECT
public:
    explicit EresmaCanvas(QWidget *parent = nullptr);

signals:

public slots:

private:
    RegionTree  *_regionTree;
    ItemInfo    *_itemInfo;
    OrderEditor *_orderEditor;
    HexMap      *_hexMap;
};

#endif // ERESMACANVAS_H
