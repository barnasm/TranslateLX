#include "clipboardService.h"

ClipboardService::ClipboardService(MainWindow* mw)
{
  Gtk::Clipboard::get(GDK_SELECTION_PRIMARY)->
    signal_owner_change().connect(sigc::mem_fun(mw, &MainWindow::clipboardOwnerChange));

  //clutter_click_action_new ();  
}

