/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода MessageDialog_ManualTest.cpp
 * \brief Тесты класса MessageDialog
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary-cpp/gui/QSfmlWidget.h>
#include <QApplication>

using namespace Auxiliary::Gui;

namespace
{
  class TestSfmlWidget: public QSfmlWidget
  {
  public:
    void processEvent(const sf::Event&) override
    {}

    void processInput(float deltaTime) override
    {}

    void update(float deltaTime) override
    {}

    void draw() override
    {
      sf::CircleShape circleShape(5);
      circleShape.setFillColor(sf::Color::Red);

      circleShape.setPosition(0, 0);
      m_window.draw(circleShape);
      circleShape.setPosition(0, 500);
      m_window.draw(circleShape);
      circleShape.setPosition(500, 0);
      m_window.draw(circleShape);
      circleShape.setPosition(500, 500);
      m_window.draw(circleShape);
    }
  }; // class TestSfmlWidget
}

int main(int argc, char** argv)
{
  QApplication app(argc, argv);

  TestSfmlWidget sfmlWidget;
  sfmlWidget.show();

  return QCoreApplication::exec();
}
