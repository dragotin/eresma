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

#ifndef ITEMINFO_H
#define ITEMINFO_H

#include <QObject>
#include <QWidget>
#include <QTextBrowser>

class Region;

class ItemInfo : public QTextBrowser
{
    Q_OBJECT

public:
    ItemInfo(QWidget *parent=nullptr);

public slots:
    void slotCurrentRegion(Region *r);
};

#endif // ITEMINFO_H
