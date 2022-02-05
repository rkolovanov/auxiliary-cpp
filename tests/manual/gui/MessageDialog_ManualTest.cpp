/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода MessageDialog_ManualTest.cpp
 * \brief Тесты класса MessageDialog
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary/gui/MessageDialog.h>
#include <QCoreApplication>

using namespace Auxiliary::Gui;

int main(int argc, char** argv)
{
  QCoreApplication app(argc, argv);

  MessageDialog messageDialog;
  messageDialog.show();

  return QCoreApplication::exec();
}
