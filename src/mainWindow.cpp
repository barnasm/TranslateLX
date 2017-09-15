#include "mainWindow.h"

MainWindow::MainWindow(DictionaryInterface* di): di(di)
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
  //boxCentral.add(buttonPronunciationVoice);
  //boxCentral.add(comboLangFrom);
  //boxCentral.add(buttonSwapLanguages);
  //boxCentral.add(comboLangTo);
  gridCentral.attach(comboLangFrom, 0, 0, 2, 1);
  gridCentral.attach(comboLangTo,   0, 1, 2, 1);
  gridCentral.attach(buttonSwapLanguages, 2, 0, 1, 2);
  boxCentral.add(gridCentral);


  
  textTranslation.set_size_request(200, 20);
  textPronunciation.set_size_request(200, 20);
  textTranslation.set_cursor_visible(false);
  // textTranslation.set_vscroll_policy(Gtk::ScrollablePolicy::SCROLL_MINIMUM);
  // textPronunciation.set_vscroll_policy(Gtk::ScrollablePolicy::SCROLL_NATURAL);
  textTranslation.set_editable(false);
  textPronunciation.set_editable(false);

  Glib::RefPtr<Gtk::TextChildAnchor> refAnchor =
    textPronunciation.get_buffer()->create_child_anchor(textPronunciation.get_buffer()->begin());
  textPronunciation.add_child_at_anchor(buttonPronunciationVoice, refAnchor);
  
  buttonPrev.set_label("◀");
  buttonNext.set_label("▶");
  buttonPronunciationVoice.set_label("♬");
  buttonSwapLanguages.set_label("⤸");

  buttonPrev.signal_clicked().connect( sigc::bind<Gtk::Button*>( sigc::mem_fun(*this, &MainWindow::onButtonClicked), &buttonPrev) );
  buttonNext.signal_clicked().connect( sigc::bind<Gtk::Button*>( sigc::mem_fun(*this, &MainWindow::onButtonClicked), &buttonNext) );
  buttonPronunciationVoice.signal_clicked().
    connect(sigc::mem_fun(*this, &MainWindow::onButtonPronunciationVoice));
  buttonSwapLanguages.signal_clicked().
    connect( sigc::bind<Gtk::Widget*>( sigc::mem_fun(*this, &MainWindow::onLanguageChange), &buttonSwapLanguages) );
  comboLangFrom.signal_changed().connect(sigc::bind<Gtk::Widget*>(sigc::mem_fun(*this, &MainWindow::onLanguageChange), &comboLangFrom));
  comboLangTo.  signal_changed().connect(sigc::bind<Gtk::Widget*>(sigc::mem_fun(*this, &MainWindow::onLanguageChange), &comboLangTo));
  insertLanguagesToCombos();
  
  show_all();
  // window = new QWidget;
    //     window->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::Drawer);

    //     window->setMinimumSize(*windowSizeMin);
    //     window->setMaximumSize(*windowSizeMax);
    //     window->setFixedSize(*windowSizeMin);
    //     setWindowPosition(QCursor::pos());
}

void MainWindow::onButtonClicked(Gtk::Button* b){
  if(b == &buttonPrev)
    --elem;
  else if(b == &buttonNext)
    ++elem;

  setTextVeiws();
}
void MainWindow::setTextVeiws(){  
    textTranslation.get_buffer()->
      set_text(di->getTranslation().empty()? "Not found": di->getTranslation() [elem % (di->getTranslation().size())]); 

    textPronunciation.get_buffer()->
      erase(++textPronunciation.get_buffer()->begin(), textPronunciation.get_buffer()->end());
    textPronunciation.get_buffer()->
      insert(++textPronunciation.get_buffer()->begin(),
    	     di->getPronunciation().empty()?"Not found":di->getPronunciation()[elem % (di->getPronunciation().size())]);
    //set_text(di->getPronunciation().empty()?"Not found":di->getPronunciation()[elem % (di->getPronunciation().size())]);
}

void MainWindow::onButtonPronunciationVoice(){
  if(di->getPronunciationVoiceAddr().empty())
    return;
  
  std::cout << "play\n";

  GstElement *pipeline;
  GstBus *bus;
  GstMessage *msg;

   /* Build the pipeline */
  std::string addr = "playbin uri="+ di->baseAddr +di->getPronunciationVoiceAddr()[0];
  pipeline = gst_parse_launch (addr.c_str(), NULL);

  /* Start playing */
  gst_element_set_state (pipeline, GST_STATE_PLAYING);

  /* Wait until error or EOS */
  bus = gst_element_get_bus (pipeline);
  msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

  /* Free resources */
  if (msg != NULL)
    gst_message_unref (msg);
  gst_object_unref (bus);
  gst_element_set_state (pipeline, GST_STATE_NULL);
  gst_object_unref (pipeline);
}

void MainWindow::clipboardOwnerChange(GdkEventOwnerChange*)
{
  auto clipboard = Gtk::Clipboard::get(GDK_SELECTION_PRIMARY);
  std::string sel = clipboard->wait_for_text();
  di->getTranslation(sel);
  di->getPronunciation(sel);
  di->getPronunciationVoiceAddr(sel);

  std::cout << "\twait for text: " << sel << std::endl;
  for(auto a: di->getTranslation())
    std::cout << a << std::endl;

  elem = 0;
  setTextVeiws();
}

void MainWindow::onLanguageChange(Gtk::Widget* combo){
  std::cout << "changed\n";
  if(combo == &comboLangFrom){
    di->langFromShort = di->getLanguageList()[((Gtk::ComboBoxText*)combo)->get_active_text()];
  }else if(combo == &comboLangTo){
    di->langToShort = di->getLanguageList()[((Gtk::ComboBoxText*)combo)->get_active_text()];
  }else if(combo == &buttonSwapLanguages){
    auto tmp = comboLangFrom.get_active_row_number();
    comboLangFrom.set_active(comboLangTo.get_active_row_number());
    comboLangTo.set_active(tmp);
  }
}

void MainWindow::insertLanguagesToCombos(){
  for(auto a: di->getLanguageList()){
    comboLangTo  .append(a.first);
    comboLangFrom.append(a.first);
  }
  comboLangFrom.set_active_text("English");
  comboLangTo.  set_active_text("Polish");
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
