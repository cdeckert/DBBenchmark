/*
 * LogWriter.h
 *
 */

#ifndef DBTESTING_SRC_LOGWRITER_H_
#define DBTESTING_SRC_LOGWRITER_H_
#include "ATest.h"
//
namespace DBTest
{

class LogWriter : public ATest
{
public:
	LogWriter();
	virtual ~LogWriter();
	void testAlgorithm() override;
};

} /* namespace DBTest */

#endif /* DBTESTING_SRC_LOGWRITER_H_ */
