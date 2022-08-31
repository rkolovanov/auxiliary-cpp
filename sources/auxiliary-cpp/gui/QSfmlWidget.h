/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Заголовочный файл QSfmlWidget.h
 * \brief Класс QSfmlWidget
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef SOURCES_AUXILIARY_CPP_GUI_QSFMLWIDGET_H
#define SOURCES_AUXILIARY_CPP_GUI_QSFMLWIDGET_H

#include <QTimer>
#include <QWidget>
#include <SFML/Graphics.hpp>

namespace Auxiliary::Gui
{
  class QSfmlWidget: public QWidget
  {
  public:
    QSfmlWidget(QWidget* parent = nullptr);
    ~QSfmlWidget() override;

    virtual void processEvent(const sf::Event& event) = 0;
    virtual void processInput(float deltaTime) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;

  private slots:
    void exec();

  private:
    QPaintEngine* paintEngine() const override;
    void enterEvent(QEnterEvent*) override;
    void resizeEvent(QResizeEvent* event) override;

  protected:
    sf::RenderWindow m_window;
    sf::Clock m_clock;
    QTimer m_updateTimer;
  }; // class QSfmlWidget
} // namespace Auxiliary::Gui

#endif // SOURCES_AUXILIARY_CPP_GUI_QSFMLWIDGET_H
