#include <gtkmm.h>
#include <iostream>

using namespace Gtk;

Window * pWindow;
Entry * num_1, * num_2;
Button * btn_soma;


int main(int argc, char** argv){

	auto app = Application::create(argc, argv, "org.gtkmm.example");
	auto refBuilder = Builder::create();

	refBuilder->add_from_file("glade/soma.glade");
	refBuilder->get_widget( "window", pWindow );

	if ( pWindow ){
		refBuilder->get_widget( "num_1", num_1 );
		refBuilder->get_widget( "num_2", num_2 );
		refBuilder->get_widget( "btn_soma", btn_soma );
	}

	app->run( *pWindow );

	delete pWindow;

	return 0;

//	g++ soma.cpp -o soma.h $(pkg-config gtkmm-3.0 --cflags --libs) -export-dynamic
}
