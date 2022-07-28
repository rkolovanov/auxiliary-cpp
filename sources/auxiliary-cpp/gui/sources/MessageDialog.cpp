/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода MessageDialog.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <ui_MessageDialog.h>
#include <auxiliary-cpp/gui/MessageDialog.h>

namespace Auxiliary
{
  namespace Gui
  {
    MessageDialog::MessageDialog(QWidget* parent):
      m_ui{std::make_unique<Ui::MessageDialog>()}
    {
    }

    MessageDialog::~MessageDialog() = default;
  } // namespace Gui
} // namespace Auxiliary
