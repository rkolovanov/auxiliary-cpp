/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл MessageDialog.h
 * \brief Класс MessageDialog
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_GUI_MESSAGE_DIALOG_H
#define AUXILIARY_GUI_MESSAGE_DIALOG_H

#include <QtWidgets/QDialog>
#include <memory>

namespace Ui
{
  class MessageDialog;
} // namespace Ui

namespace Auxiliary
{
  namespace Gui
  {
    class MessageDialog: public QDialog
    {
      Q_OBJECT

    public:
      explicit MessageDialog(QWidget* parent = nullptr);
      ~MessageDialog() override;

    private:
      const std::unique_ptr<Ui::MessageDialog> m_ui;
    };
  } // namespace Gui
} // namespace Auxiliary

#endif // AUXILIARY_GUI_MESSAGE_DIALOG_H
