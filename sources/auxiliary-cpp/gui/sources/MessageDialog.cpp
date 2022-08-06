/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Файл исходного кода MessageDialog.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include "ui_MessageDialog.h"
#include <auxiliary-cpp/gui/MessageDialog.h>

namespace Auxiliary::Gui
{
  MessageDialog::MessageDialog(QWidget* parent):
    QDialog {parent},
    m_ui {std::make_unique<Ui::MessageDialog>()}
  {
    m_ui->setupUi(this);
  }

  MessageDialog::~MessageDialog() = default;
} // namespace Auxiliary::Gui
