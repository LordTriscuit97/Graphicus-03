#include <QApplication>
#include "graphicus-03.h"

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	Graphicus03 gui("le goat");
	return app.exec();
}