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


#include <QContextMenuEvent>
#include <QLabel>
#include <QMessageBox>
#include <QMainWindow>

#include "eresmamainwindow.h"
#include "ui_eresmamainwindow.h"

#include "eresmacanvas.h"


EresmaMainWindow::EresmaMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EresmaMainWindow)
{
    ui->setupUi(this); // internal ui setup routine, initializes the UI file
    createActions();
    createMenus();

    _canvas = new EresmaCanvas; // main interaction widget of the whole thing
    setCentralWidget(_canvas);

    setWindowTitle(tr("Eresma - Lightweight Eressea Viewer"));
}

EresmaMainWindow::~EresmaMainWindow()
{
    delete ui;
}

void EresmaMainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}

void EresmaMainWindow::open()
{
    ui->statusBar->showMessage(tr("Invoked <b>File|Open</b>"));
}

void EresmaMainWindow::save()
{
}

void EresmaMainWindow::print()
{
}

void EresmaMainWindow::undo()
{
}

void EresmaMainWindow::redo()
{
}

void EresmaMainWindow::cut()
{
}

void EresmaMainWindow::copy()
{
}

void EresmaMainWindow::paste()
{
}

void EresmaMainWindow::about()
{
    QMessageBox::about(this, tr("About Menu"),
            tr("Eresma is licensed under the GPL, started by Klaas Freitag <klaas@volle-kraft-voraus.de> in July 2018."));
}

void EresmaMainWindow::aboutQt()
{
}

void EresmaMainWindow::createActions()
{

    openAct = new QAction(tr("&Open Orders..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing order file"));
    connect(openAct, &QAction::triggered, this, &EresmaMainWindow::open);

    ui->mainToolBar->addAction(openAct);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the order file to disk"));
    connect(saveAct, &QAction::triggered, this, &EresmaMainWindow::save);

    ui->mainToolBar->addAction(openAct);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the map"));
    connect(printAct, &QAction::triggered, this, &EresmaMainWindow::print);

    ui->mainToolBar->addAction(openAct);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    undoAct = new QAction(tr("&Undo"), this);
    undoAct->setShortcuts(QKeySequence::Undo);
    undoAct->setStatusTip(tr("Undo the last operation"));
    connect(undoAct, &QAction::triggered, this, &EresmaMainWindow::undo);

    redoAct = new QAction(tr("&Redo"), this);
    redoAct->setShortcuts(QKeySequence::Redo);
    redoAct->setStatusTip(tr("Redo the last operation"));
    connect(redoAct, &QAction::triggered, this, &EresmaMainWindow::redo);

    cutAct = new QAction(tr("Cu&t"), this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, &QAction::triggered, this, &EresmaMainWindow::cut);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, this, &EresmaMainWindow::copy);

    pasteAct = new QAction(tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, this, &EresmaMainWindow::paste);

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, &QAction::triggered, this, &EresmaMainWindow::about);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);
    connect(aboutQtAct, &QAction::triggered, this, &EresmaMainWindow::aboutQt);
}

void EresmaMainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
    editMenu->addSeparator();
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);
    editMenu->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}
