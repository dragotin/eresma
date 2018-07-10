# Eresma - an Experimental lightweight Viewer for the Eressea PBEM

This is a skeleton for a Qt based, cross platform ready viewer for
Eressa, and maybe similar games:

![Eresma Skeleton](images/eresma_alpha.png?raw=true "Eresma Skeleton Screenshot")

The goal of this project could be that players start the client, provide
their credentials, and the software loads their current report automatically
and they can work on their orders, which are uploaded once they're finished.

That is a long way to go, nothing of that is here.

The repository just contains a few classes and files:

### main.cpp

This is where the who thing starts. It instanciates an Application
object and a EresmaMainWindow and starts the app.

### EresmaMainWindow

This class builds up all the application specifics such as a menu etc.
It also creates an EresmaCanvas and puts it as the main widget of the
application.

### EresmaCanvas

The main gui components are created here and arranged in the main view
of the application, such as the region tree, the map and more.

The classes are connected here via signals and slots to react on events
and process user interaction.

### RegionTree

A treeview to display all the Eressea regions and units in it.

### Region

The data class that contains information about a single region.

### HexMap

The QGraphicsView based map view. It scales nicely (300*400 regions)
selects single regions on click already.

### RegionGraphicsItem

The implementation of a single graphics item on the HexMap.

### ItemInfo

The class to display details about the selected item such as a region
or a unit.

### OrderEditor

A very simply text input field to collect the orders for a certain, selected
unit.




Klaas Freitag <klaas@volle-kraft-voraus.de>

