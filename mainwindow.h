#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include "editor/editormanager.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
  // MenuBar
  QMenuBar* menuBar;
  QTabWidget* tabWidget;

  // 定义QMenu
  QMenu* fileMenu = new QMenu(tr("File")+"(&F)");
  QMenu* editMenu = new QMenu(tr("Edit")+"(&E)");
  QMenu* viewMenu = new QMenu(tr("View")+"(&V)");
  QMenu* gotoMenu = new QMenu(tr("Goto")+"(&G)");
  QMenu* searchMenu = new QMenu(tr("Search")+"(&S)");
  QMenu* toolMenu = new QMenu(tr("Tool")+"(&T)");
  QMenu* helpMenu = new QMenu(tr("Help")+"(&H)");

  // 定义QAction
  QAction* newFileAction = new QAction(tr("New"));
  QAction* saveFileAction = new QAction(tr("Save"));
  QAction* saveAsFileAction = new QAction(tr("Save As"));
  QAction* openFileAction = new QAction(tr("Open"));
  QAction* openFolderAction = new QAction(tr("Open Folder"));
  QAction* closeFileAction = new QAction(tr("Close File"));
  QAction* closeFolderAction = new QAction(tr("Close Folder"));
  QAction* closeAllFileAction = new QAction(tr("Close All Files"));
  QAction* exitAction = new QAction(tr("Exit"));

  EditorManager* editorManager = new EditorManager();

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
};
#endif // MAINWINDOW_H
