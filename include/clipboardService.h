#pragma once

#include "mainWindow.h"
#include <gtkmm/clipboard.h>

class ClipboardService
{
public:
  //ClipboardService();
  ClipboardService(MainWindow*);
  ~ClipboardService(){}
};
