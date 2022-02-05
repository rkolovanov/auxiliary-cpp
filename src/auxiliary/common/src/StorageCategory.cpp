/**
 * \proj Библиотека вспомогательных решений С++ (auxiliary-cpp)
 * \file Файл исходного кода StorageCategory.cpp
 *
 * Copyright (c) 2022 Rodion Kolovanov
 */

#include <auxiliary/common/StorageCategory.h>

namespace
{
  using Auxiliary::Common::StringListPointer;

  StringListPointer parseTopicsList(const QString& topicsString, const QChar& separator)
  {
    StringListPointer topics = std::make_shared<QStringList>();
    const auto splittedTopicsString = topicsString.split(separator);

    topics->reserve(splittedTopicsString.size());

    for (const auto& topicName : splittedTopicsString)
    {
      if (!topicName.isEmpty())
      {
        topics->append(topicName);
      }
    }

    return topics;
  }
} // anonymous namespace

namespace Auxiliary
{
  namespace Common
  {
    StorageCategory::StorageCategory(const QChar& separator):
      m_separator{separator},
      m_topics{std::make_shared<QStringList>()}
    {}

    StorageCategory::StorageCategory(const QString& topicsString, const QChar& separator):
      m_separator{separator},
      m_topics{parseTopicsList(topicsString, separator)}
    {}

    StorageCategory::StorageCategory(StringListPointer topics, const QChar& separator):
      m_topics{std::move(topics)},
      m_separator{separator}
    {}

    void StorageCategory::appendTopic(const QString& topicName)
    {
      m_topics->append(topicName);
    }

    StorageCategory StorageCategory::getChildCategory() const
    {
      if(m_topics->size() < 2)
      {
        return StorageCategory{m_separator};
      }

      const auto childTopics = std::make_shared<QStringList>(*m_topics);

      childTopics->removeLast();

      return StorageCategory{childTopics, m_separator};
    }

    QChar StorageCategory::getSeparator() const
    {
      return m_separator;
    }

    QString StorageCategory::toString() const
    {
      if (m_topics->empty())
      {
        return {};
      }
      return m_topics->join(m_separator);
    }
  } // namespace Common
} // namespace Auxiliary
