#include <QApplication>
#include "graphicus-03.h"

int main(int argc, char** argv)
{
	// Un affichage de debug a été créé pour valider le fonctionnement de 
	// graphicus. Il affiche dans la console les opérations effectuées.

	QApplication app(argc, argv);
	Graphicus03 gui("le goat");
	return app.exec();
}