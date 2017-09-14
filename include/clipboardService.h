#pragma once

#include "mainWindow.h"
#include <gtkmm.h>

class ClipboardService
{
public:
  //ClipboardService();
  ClipboardService(MainWindow*);
  ~ClipboardService(){}
//private:  
  //signal handlers
  //void clipboardOwnerChange(GdkEventOwnerChange* event);
};
