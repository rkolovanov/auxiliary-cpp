/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Заголовочный файл StorageCategory.h
 * \brief Класс StorageCategory
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#ifndef AUXILIARY_COMMON_STORAGE_CATEGORY_H
#define AUXILIARY_COMMON_STORAGE_CATEGORY_H

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
    };
  } // namespace Common
} // namespace Auxiliary

#endif // AUXILIARY_COMMON_STORAGE_CATEGORY_H
