/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл StorageCategory.h
 * \brief Класс StorageCategory
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef StorageCategory_H_03F19D7A_AC52_4F39_B8F1_DA4E9C852359
#define StorageCategory_H_03F19D7A_AC52_4F39_B8F1_DA4E9C852359

#include <QStringList>
#include <memory>

namespace Auxiliary
{
  namespace Common
  {
    using StringListPointer = std::shared_ptr<QStringList>;

    class StorageCategory
    {
    public:
      explicit StorageCategory(const QChar& separator = '|');
      explicit StorageCategory(const QString& topicsString, const QChar& separator = '|');

      void appendTopic(const QString& topicName);
      StorageCategory getChildCategory() const;
      QChar getSeparator() const;
      QString toString() const;

    private:
      explicit StorageCategory(StringListPointer topics, const QChar& separator = '|');

      QChar m_separator;
      StringListPointer m_topics;
    }; // class StorageCategory
  } // namespace Common
} // namespace Auxiliary

#endif // StorageCategory_H_03F19D7A_AC52_4F39_B8F1_DA4E9C852359

/*** End of file StorageCategory.h ***/
