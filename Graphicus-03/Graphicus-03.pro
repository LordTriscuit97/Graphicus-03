TEMPLATE     = vcapp
TARGET       = Graphicus-03
CONFIG      += warn_on qt debug windows console
HEADERS     += graphicus-03.h vecteur.h vecteur.cpp canevas.h couche.h forme.h rectangle.h cercle.h carre.h 
SOURCES     += graphicus-03.cpp canevas.cpp couche.cpp forme.cpp rectangle.cpp cercle.cpp carre.cpp main.cpp
INCLUDEPATH += ..\GraphicusGUI
LIBS        += ..\GraphicusGUI/graphicusGUI.lib
QT          += widgets
