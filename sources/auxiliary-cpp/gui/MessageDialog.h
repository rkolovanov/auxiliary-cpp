/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл MessageDialog.h
 * \brief Класс MessageDialog
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_GUI_MESSAGEDIALOG_H
#define SOURCES_AUXILIARY_CPP_GUI_MESSAGEDIALOG_H

#include <QDialog>
#include <memory>

namespace Ui
{
  class MessageDialog;
} // namespace Ui

namespace Auxiliary::Gui
{
  class MessageDialog: public QDialog
  {
  Q_OBJECT

  public:
    explicit MessageDialog(QWidget* parent = nullptr);

    ~MessageDialog() override;

  private:
    const std::unique_ptr<Ui::MessageDialog> m_ui;
  }; // class MessageDialog
} // namespace Auxiliary::Gui

#endif // SOURCES_AUXILIARY_CPP_GUI_MESSAGEDIALOG_H
