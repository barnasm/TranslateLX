#include "mainWindow.h"

MainWindow::MainWindow()
{
  //setTray();
  setWindow();
  //setWidgets();
}

void MainWindow::setWindow(){
  add(boxPrimary);
  set_decorated(false);
  set_keep_above(true);
  set_resizable(false);

  boxPrimary.add(buttonPrev);
  boxPrimary.add(boxCentral);
  boxPrimary.add(buttonNext);
 
  boxCentral.add(textTranslation);
  boxCentral.add(textPronunciation);
  boxCentral.add(buttonAudio);
  boxCentral.add(comboLangFrom);
  boxCentral.add(comboLangTo);
  
  textTranslation.set_size_request(200, 20);
  textPronunciation.set_size_request(200, 20);
  // textTranslation.set_vscroll_policy(Gtk::ScrollablePolicy::SCROLL_MINIMUM);
  // textPronunciation.set_vscroll_policy(Gtk::ScrollablePolicy::SCROLL_NATURAL);
  //textTranslation.set_editable(false);
  //textPronunciation.set_editable(false);
  show_all();
  // window = new QWidget;
    //     window->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Drawer);

    //     window->setMinimumSize(*windowSizeMin);
    //     window->setMaximumSize(*windowSizeMax);
    //     window->setFixedSize(*windowSizeMin);
    //     setWindowPosition(QCursor::pos());
}
/*void MainWindow::setWindowPosition(QPoint pos = QCursor::pos()){
    window->move(pos);
}

void MainWindow::setWidgets(){
    buttonPrev = new QPushButton("◀");
        buttonPrev->setMaximumSize(*bottonSizeMax);

    buttonNext = new QPushButton("▶");
        buttonNext->setMaximumSize(*bottonSizeMax);

    textEdit = new QPlainTextEdit;
    setLayout();

    connect(buttonPrev, SIGNAL(clicked()), this, SLOT(buttonClicked()));
    connect(buttonNext, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}
void MainWindow::buttonClicked(){
    textEdit->clear();
    textEdit->moveCursor(QTextCursor::Start);

    if(sender() == buttonPrev){
        textEdit->insertPlainText(contentOfWebpage->getPrev().toStdString().c_str());
    }else if(sender() == buttonNext){
        textEdit->insertPlainText(contentOfWebpage->getNext().toStdString().c_str());
    }
}

void MainWindow::setLayout(){
    QGridLayout *layout = new QGridLayout;

    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    layout->addWidget(buttonPrev, 0, 0);
    layout->addWidget(textEdit,   0, 1);
    layout->addWidget(buttonNext, 0, 2);

    window->setLayout(layout);
}

void MainWindow::createActions()
{
    actionQuit = new QAction(tr("&Quit"), this);
    connect(actionQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    connect(checkBox, SIGNAL(stateChanged(int)), this, SLOT(check()));
}

void MainWindow::check(){
    printf("checkbox %i\n", checkBox->checkState());
}

void MainWindow::setTray(){
    QIcon icon = QIcon("/home/michal/Pulpit/mojeProgramy/translateLx/translateIcon64.png");
    QApplication::setWindowIcon(icon);

    trayMenu = new QMenu;

    checkBox = new QCheckBox(trayMenu);
    checkBox->setText("Turn on");
    checkBoxAction = new QWidgetAction(trayMenu);
    checkBoxAction->setDefaultWidget(checkBox);

    comboBox1 = new QComboBox(trayMenu);
    comboBoxAction1 = new QWidgetAction(trayMenu);
    comboBoxAction1->setDefaultWidget(comboBox1);

    comboBox2 = new QComboBox(trayMenu);
    comboBoxAction2 = new QWidgetAction(trayMenu);
    comboBoxAction2->setDefaultWidget(comboBox2);


    createActions();
    //trayMenu->setTitle("Title");
    //trayMenu->setIcon(icon);
    trayMenu->setToolTip("toot tip");


    trayMenu->addAction(checkBoxAction);
    trayMenu->addAction(comboBoxAction1);
    trayMenu->addAction(comboBoxAction2);
    trayMenu->addSeparator();
    trayMenu->addAction(actionQuit);



    trayIcon = new QSystemTrayIcon;
    trayIcon->setContextMenu(trayMenu);

    trayIcon->setIcon(icon);
    trayIcon->show();

    //trayIcon->showMessage("title", "message", QSystemTrayIcon::Information);
    //buttonNext->setIcon(QIcon("/home/michal/Pulpit/gnome.png"));
}

void MainWindow::windowShow(){
    window->show();
}

void MainWindow::windowHide(){
    window->hide();
}

void MainWindow::getPreparedData(ContentOfWebpage *content){
    contentOfWebpage = content;

    textEdit->clear();
    textEdit->moveCursor(QTextCursor::Start);
    textEdit->insertPlainText(contentOfWebpage->getCurrent().toStdString().c_str());
}

void MainWindow::getLanguagesList(LanguageInfo *languages){
    languageInfo = languages;
    for(int i = 0; i < languageInfo->langList.size(); i++){
        comboBox1->addItem(languageInfo->langList[i]);
        comboBox2->addItem(languageInfo->langList[i]);
    }
}

bool MainWindow::isReady(){
    return window->underMouse();
}

bool MainWindow::cursorOverMainWindow(){
    return window->underMouse();
}

void MainWindow::emitClick(){
    emit buttonClicked();
}
*/
