#include <gtkmm/application.h>
#include "clipboardService.h"

int main(int argc, char *argv[]){

  auto app = Gtk::Application::create("org.gtkmm.example",
				      Gio::APPLICATION_NON_UNIQUE);

  //app->quit();

  ClipboardService cs;
  app->hold();
  return app->run();
}
