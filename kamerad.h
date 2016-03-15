#ifndef KAMERAD_H
#define KAMERAD_H

#include <QList>
#include "qualification.h"

class Kamerad
{
public:
    Kamerad();

private:
	int m_id;

	// qualifications
	QList <Qualification> m_qualifications;

	// emergency case attributes
	int m_arrivalTime;
	int m_readdiness;

	// setting algorithm neccessary
	int m_cost;
	int m_weight;

};

#endif // KAMERAD_H
