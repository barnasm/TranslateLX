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
#include <languageInfo.h>
*/
class MainWindow
{
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

    void setWindow();
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
    MainWindow();
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
