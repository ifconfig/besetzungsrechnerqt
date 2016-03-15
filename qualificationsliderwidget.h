#ifndef QUALIFICATIONSLIDERWIDGET_H
#define QUALIFICATIONSLIDERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QString>
#include <QList>

#include "qualification.h"


class QualificationSliderWidget : public QWidget
{
  Q_OBJECT
public:
  explicit QualificationSliderWidget(QWidget *parent = 0);
  QualificationSliderWidget(QSharedPointer<Qualification> quali, QWidget *parent = 0);
  QList <QSharedPointer<Qualification> > dependencies();
  bool isDependentOf(const QualificationSliderWidget* masterWidget);
  void setDependency(QualificationSliderWidget* masterWidget);

  QSharedPointer<Qualification> qualification() const;

  QSlider *qualificationSlider() const;

signals:
  void dependencyValueChanged(int value);

public slots:
  void setDependentValue(int value);
  void sliderValueChanged(int value);

private:
  QSharedPointer<Qualification> m_qualification;
  QLabel* m_qualificationNameLabel;
  QSlider* m_qualificationSlider;
  QLabel* m_qualificationSliderPercentage;
  QList <QualificationSliderWidget*> m_dependencyWidgets;
};

#endif // QUALIFICATIONSLIDERWIDGET_H
