#include <QApplication>
#include <QLabel>
#include <QWidget>

int main(int argc, char ** argv ) {

	QApplication app(argc, argv);
	QString title;
	if( argc > 1 ){
		title = argv[1];
		title = "<center>" + title + "</center>";
	}else{
		title = "<center>Meu Primeiro Programa com Qt e C++</center>";
	}
	QLabel hello( title );
	hello.setWindowTitle("Título da janela para meu programa.");
	hello.resize(400, 400);
	hello.show();
	return app.exec();

}
