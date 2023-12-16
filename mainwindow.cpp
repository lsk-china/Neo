#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
{
  // 设置MainWindow大小
  this->setFixedSize(QSize(1024,720));
  // 设置menuBar
  menuBar = new QMenuBar(this);
  this->setMenuBar(menuBar);

  menuBar->addMenu(fileMenu);
  menuBar->addMenu(editMenu);
  menuBar->addMenu(viewMenu);
  menuBar->addMenu(gotoMenu);
  menuBar->addMenu(searchMenu);
  menuBar->addMenu(toolMenu);
  menuBar->addMenu(helpMenu);

  // 设置fileMenu下拉菜单布局
  fileMenu->addActions({newFileAction});
  fileMenu->addActions({openFileAction,openFolderAction});
  fileMenu->addSeparator();
  fileMenu->addActions({saveFileAction,saveAsFileAction});
  fileMenu->addSeparator();
  fileMenu->addActions({closeFileAction, closeAllFileAction, closeFolderAction});
  fileMenu->addSeparator();
  fileMenu->addActions({exitAction});

  // 设置tabWidget
  tabWidget = new QTabWidget(this);
  tabWidget->setTabsClosable(true);
  tabWidget->setMovable(true);

  // 设置平铺与主窗口中
  this->setCentralWidget(tabWidget);

  // 添加tab
  tabWidget->addTab(new QWidget,"untitled");
}

MainWindow::~MainWindow() {}
