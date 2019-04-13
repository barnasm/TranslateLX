#ifndef MAINWINDOW_H
#define MAINWINDOW_H
/*
#include <unistd.h>
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QDesktopWidget>
#include <QPlainTextEdit>
#include <contentofwebpage.h>

#include <QSystemTrayIcon>
#include <QMenu>
#include <QIcon>

#include <QWidgetAction>
#include <QCheckBox>
#include <QComboBox>
*/
#include "dictionaryInterface.h"
#include <gtkmm/window.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/entry.h>
#include <gtkmm/box.h>
#include <gtkmm/grid.h>
#include <gtkmm/button.h>
#include <gtkmm/scrollbar.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/spinner.h>
#include <thread>
#include <memory>
#include <gst/gst.h>

class MainWindow : public Gtk::Window
{
private:
  size_t elem = 0;
  DictionaryInterface* di;
  std::unique_ptr<std::thread> thr;
  
  Gtk::HBox boxPrimary;
  Gtk::VBox boxCentral;
  Gtk::Grid gridCentral;
  Gtk::ScrolledWindow scrolledwindowTranslation;
  Gtk::ScrolledWindow scrolledwindowPronunciation;
  Gtk::Entry textTranslation; //this field also shows youMean content if no translation found
  Gtk::Entry textPronunciation;
  Gtk::Button buttonPrev;
  Gtk::Button buttonNext;
  Gtk::Button buttonPronunciationVoice;
  Gtk::Button buttonSwapLanguages;
  Gtk::ComboBoxText comboLangFrom;
  Gtk::ComboBoxText comboLangTo;
  Gtk::Spinner spinner;
  void setWindow();
  void setTextVeiws();

  /*
private:
    QSize *bottonSizeMax  = new QSize(21, 1000);
    QSize *windowSizeMin  = new QSize(170, 32);
    QSize *windowSizeMax  = new QSize(QApplication::desktop()->screenGeometry().width() * 0.5, 500);


    QWidget *window;

    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;

    QPushButton *buttonPrev;
    QPushButton *buttonNext;

    QPushButton* button;

    void setWidgets();
    void setLayout();

    void setTray();

    void emitClick();

    ContentOfWebpage *contentOfWebpage;
    LanguageInfo *languageInfo;
    QPlainTextEdit *textEdit;

    void createActions();
    QComboBox *comboBox1;
    QComboBox *comboBox2;
    QWidgetAction *comboBoxAction1;
    QWidgetAction *comboBoxAction2;
    QCheckBox *checkBox;
    QWidgetAction *checkBoxAction;
    QAction *actionQuit;
  */
public:
  MainWindow(DictionaryInterface*);
  virtual ~MainWindow(){};
  void onNotificationFromThread();

//signals handlers
  void clipboardOwnerChange(GdkEventOwnerChange*);
private:
  void onButtonClicked(Gtk::Button*);
  void onButtonPronunciationVoice();
  void onLanguageChange(Gtk::Widget*);
  void insertLanguagesToCombos();
  /*
  void setWindowPosition(QPoint pos);
    void windowShow();
    void windowHide();
    void getPreparedData (ContentOfWebpage *content);
    void getLanguagesList(LanguageInfo *languages);
    bool cursorOverMainWindow();
    bool isReady();


public slots:
    void buttonClicked();
    void check();
*/
};

#endif // MAINWINDOW_H
