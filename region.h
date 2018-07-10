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

#ifndef REGION_H
#define REGION_H

#include <QString>

class Region
{
public:

    enum Type {
        Unknown,
        Wood,
        Plains,
        Desert,
        Sump,
        Mountains,
        Vulcans,
        Magical
    };

    Region(const QString &name, Type t, int x, int y);

    int _x, _y;

    QString _name;
    Type _type;

};

#endif // REGION_H
