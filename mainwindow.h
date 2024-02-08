#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

#include "editor/editorobject.h"
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
  // File
  QAction* newFileAction = new QAction(tr("New"));
  QAction* saveFileAction = new QAction(tr("Save"));
  QAction* saveAsFileAction = new QAction(tr("Save As"));
  QAction* openFileAction = new QAction(tr("Open"));
  QAction* openFolderAction = new QAction(tr("Open Folder"));
  QAction* closeFileAction = new QAction(tr("Close File"));
  QAction* closeFolderAction = new QAction(tr("Close Folder"));
  QAction* closeAllFileAction = new QAction(tr("Close All Files"));
  QAction* exitAction = new QAction(tr("Exit"));

  // Edit
  QAction* undoAction = new QAction(tr("Undo"));
  QAction* rewriteAction = new QAction(tr("Rewrite"));
  QAction* cutAction = new QAction(tr("Cut"));
  QAction* copyAction = new QAction(tr("Copy"));
  QAction* pasteAction = new QAction(tr("Paste"));
  QAction* selectAllAction = new QAction(tr("Select All"));
  QAction* findAction = new QAction(tr("Find"));
  QAction* findAllAction = new QAction(tr("Find All"));
  QAction* findNextAction = new QAction(tr("Find Next"));
  QAction* findPreviousAction = new QAction(tr("Find Previous"));
  QAction* replaceAction = new QAction(tr("Replace"));


  // Help
  QAction* documentAction = new QAction(tr("Document"));
  QAction* websiteAction = new QAction(tr("Website"));
  QAction* feedBackAction = new QAction(tr("Feedback"));
  QAction* aboutAction = new QAction(tr("About"));

  EditorManager* editorManager = new EditorManager();

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
};
#endif // MAINWINDOW_H
