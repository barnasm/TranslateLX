//#include <QtCore/QCoreApplication>
//#include "clipboard.h"

#include <gtk/gtk.h>
#include "mainWindow.h"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[]){
  
  /*
  auto const start_pos = file.tellg();
  file.ignore(std::numeric_limits<std::streamsize>::max());
  auto const char_count = file.gcount();
  file.seekg(start_pos);
  auto s = std::string(char_count, char{});
  // or std::vector<char>(char_count);
  // or you can use unsigned char or signed char
  file.read(&s[0], s.size());
  std::cout << s;
  */
  
  //QApplication a(argc, argv);
  
  //MainWindow *window = new MainWindow;
  //WindowControl *windowControl = new WindowControl(window);
  //windowControl->start();
  //Clipboard clipboard(window); clipboard.activeSignal(); //clipboard.setClipboard(clipboard.getClipboard());
  
  return 0;
}
