#include <gtkmm/application.h>
#include "mainWindow.h"
#include "clipboardService.h"
//#include <gst/gst.h>

int main(int argc, char *argv[]){

  auto app = Gtk::Application::create("org.gtkmm.TranslateLx",
				      Gio::APPLICATION_NON_UNIQUE);

  //app->quit();

  MainWindow mainWindow;
  ClipboardService cs(mainWindow);
  //app->hold();
   return app->run(mainWindow);
}
