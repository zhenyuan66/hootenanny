/*
 * This file is part of Hootenanny.
 *
 * Hootenanny is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * --------------------------------------------------------------------
 *
 * The following copyright notices are generated automatically. If you
 * have a new notice to add, please use the format:
 * " * @copyright Copyright ..."
 * This will properly maintain the copyright information. DigitalGlobe
 * copyrights will be updated automatically.
 *
 * @copyright Copyright (C) 2015, 2016, 2017 DigitalGlobe (http://www.digitalglobe.com/)
 */

#include "RegressionReleaseTestFitnessFunction.h"

// Hoot
#include "RegressionReleaseTestSuite.h"
#include "RegressionReleaseTest.h"

namespace hoot
{

RegressionReleaseTestFitnessFunction::RegressionReleaseTestFitnessFunction() :
AbstractTestFitnessFunction(),
_highestOverallScore(-1.0)
{
  //TODO: make this configurable
  const QString dir = "/home/bwitham/hoot-tests/network-tests.child/release_test.child";
  _testSuite.reset(new RegressionReleaseTestSuite(dir));
  QStringList confs;
  _testSuite->loadDir(dir, confs);
  _testCount = _testSuite->getChildTestCount();
}

void RegressionReleaseTestFitnessFunction::initTest(AbstractTest* test)
{
  RegressionReleaseTest* regressionReleaseTest = dynamic_cast<RegressionReleaseTest*>(test);
  if (_highestOverallScore != -1.0)
  {
    regressionReleaseTest->setMinPassingScore(_highestOverallScore);
  }
}

void RegressionReleaseTestFitnessFunction::afterTestRun(AbstractTest* test)
{
  RegressionReleaseTest* regressionReleaseTest = dynamic_cast<RegressionReleaseTest*>(test);
  if (regressionReleaseTest->getMinPassingScore() > _highestOverallScore)
  {
    _highestOverallScore = regressionReleaseTest->getMinPassingScore();
  }
}

}
