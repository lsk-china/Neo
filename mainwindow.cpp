#include "mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent)
{

  // 设置MainWindow大小
  this->setMinimumSize(QSize(1024,720));
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

  // 设置editMenu下拉菜单布局
  editMenu->addActions({undoAction,rewriteAction});
  editMenu->addSeparator();
  editMenu->addActions({cutAction,copyAction,pasteAction,selectAllAction});
  editMenu->addSeparator();
  editMenu->addActions({findAction,findNextAction,findPreviousAction,findAllAction,replaceAction});

  // 设置viewMenu下拉菜单布局

  // 设置helpMenu下拉菜单布局
  helpMenu->addActions({documentAction,websiteAction,feedBackAction});
  helpMenu->addSeparator();
  helpMenu->addActions({aboutAction});

  // 设置tabWidget
  tabWidget = new QTabWidget(this);
  tabWidget->setTabsClosable(true);
  tabWidget->setMovable(true);

  // 设置平铺与主窗口中
  this->setCentralWidget(tabWidget);

  // 添加tab
  tabWidget->addTab(editorManager->getEditor(0)->getEditor(),"untitled");
  editorManager->getEditor(0)->getEditor()->setFocus();
}

MainWindow::~MainWindow() {}
