#ifndef POSITION_H
#define POSITION_H

#include <QString>
#include <QList>
#include <QJsonObject>
#include <QJsonArray>
#include <QSharedPointer>

/**
 * This is the Qualification of a comrad. This class holds all attributes and Pointers to generate the dependency tree.
 * @brief The Qualification class
 * @author Georg Heyne
 * @date 06.04.2016
 */
class Qualification
{
public:
  Qualification();
  Qualification(QJsonObject qualiObj);

  /**
   * @brief getter for m_qualiName
   * @return m_qualiName
   */
  QString qualiName() const;

  /**
   * @brief getter for m_qualiShortName
   * @return m_qualiShortName
   */
  QString qualiShortName() const;

  /**
   * @brief getter for m_defaultValue
   * @return m_defaultValue
   */
  int defaultValue() const;

  /**
   * @brief sets the qualification dependency
   * @param dependency - Qualification that this quali is dependent from
   */
  void setDependency(const QSharedPointer<Qualification> &dependency);

  /**
   * @brief getter for m_depShortName
   * @return m_depShortName
   */
  QString depShortName() const;

  /**
   * @brief getter for the list of dependent qualifications
   * @return m_dependecyFrom
   */
  QHash<QString, QSharedPointer<Qualification> > getDependecyFrom() const;

  /**
   * @brief adds a dependent qualification to this qualification
   * @param dependentQualification - Qualification
   */
  void addDependencyFrom(QSharedPointer<Qualification> dependentQualification);

private:
  /**
   * @brief name of this quallification. Used in the GUI.
   */
  QString m_qualiName;

  /**
   * @brief short name of this qualification. Mostly used as key in Lists
   */
  QString m_qualiShortName;

  /**
   * set in QualificationList::getAndSetDependencies()
   * @brief pointer to the dependency of this qualification
   */
  QSharedPointer<Qualification> m_dependency;

  /**
   * filled in QualificationList::getAndSetDependencies()
   * @brief List of dependent qualifications, where this quali is the dependency.
   */
  QHash<QString, QSharedPointer<Qualification> > m_dependecyFrom;

  /**
   * @brief short name of the dependency. Mostly two to four characters long.
   */
  QString m_depShortName;

  /**
   * @brief ID given from the database. In case of generating out of the config file this id is set zero.
   */
  int m_qualiID;

  /**
   * @brief Default value for the percentage of the qualification in the test db generator
   */
  int m_defaultValue;

};

#endif // POSITION_H
