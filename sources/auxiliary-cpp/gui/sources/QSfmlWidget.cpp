/**
 * \proj Библиотека вспомогательных компонентов С++ (auxiliary-cpp)
 * \file Файл исходного кода QSfmlWidget.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/gui/QSfmlWidget.h>

namespace Auxiliary::Gui
{
  QSfmlWidget::QSfmlWidget(QWidget* parent):
    QWidget {parent}
  {
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_OpaquePaintEvent);
    setAttribute(Qt::WA_NoSystemBackground);
    setAttribute(Qt::WA_PaintUnclipped);

    setFocusPolicy(Qt::StrongFocus);

#ifdef Q_WS_X11
    XFlush(QX11Info::display());
#endif

    m_window.create(static_cast<sf::WindowHandle>(winId()));

    m_clock.restart();
    m_updateTimer.setInterval(0);
    m_updateTimer.callOnTimeout(this, &QSfmlWidget::exec);
    m_updateTimer.start();
  }

  QSfmlWidget::~QSfmlWidget() = default;

  QPaintEngine* QSfmlWidget::paintEngine() const
  {
    return nullptr;
  }

  void QSfmlWidget::enterEvent(QEnterEvent*)
  {
    setFocus();
  }

  void QSfmlWidget::resizeEvent(QResizeEvent* event)
  {
    m_window.create(static_cast<sf::WindowHandle>(winId()));
  }

  void QSfmlWidget::exec()
  {
    float deltaTime = m_clock.getElapsedTime().asSeconds();
    m_clock.restart();

    sf::Event event;
    while (m_window.pollEvent(event))
    {
      processEvent(event);
    }

    processInput(deltaTime);
    update(deltaTime);

    m_window.clear(sf::Color::Black);
    draw();
    m_window.display();
  }
} // namespace Auxiliary::Gui
