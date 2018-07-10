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

#ifndef ERESMAMAINWINDOW_H
#define ERESMAMAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class EresmaCanvas;

namespace Ui {
class EresmaMainWindow;
}

class EresmaMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EresmaMainWindow(QWidget *parent = 0);
    ~EresmaMainWindow();

private slots:
    void open();
    void save();
    void print();
    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void about();
    void aboutQt();

    void contextMenuEvent(QContextMenuEvent *event);

private:
    void createActions();
    void createMenus();

    EresmaCanvas *_canvas;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QAction *openAct;
    QAction *saveAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    Ui::EresmaMainWindow *ui;
};

#endif // ERESMAMAINWINDOW_H
