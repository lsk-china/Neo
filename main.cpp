#include "mainwindow.h"
#include <QApplication>

#include "plugin/pluginloader.h"

int main(int argc, char* argv[])
{
  auto test = std::make_shared<Container>();
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}