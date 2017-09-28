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
 * @copyright Copyright (C) 2017 DigitalGlobe (http://www.digitalglobe.com/)
 */
#include "ImplicitTagRulesJsonWriter.h"

// hoot
#include <hoot/core/util/HootException.h>

namespace hoot
{

ImplicitTagRulesJsonWriter::ImplicitTagRulesJsonWriter(const int minOccurancesAllowed) :
_minOccurancesAllowed(minOccurancesAllowed)
{
}

ImplicitTagRulesJsonWriter::~ImplicitTagRulesJsonWriter()
{
  close();
}

void ImplicitTagRulesJsonWriter::open(const QString output)
{
  close();

  _file.reset(new QFile());
  _file->setFileName(output);
  if (_file->exists() && !_file->remove())
  {
    throw HootException(QObject::tr("Error removing existing %1 for writing.").arg(output));
  }
  if (!_file->open(QIODevice::WriteOnly | QIODevice::Text))
  {
    throw HootException(QObject::tr("Error opening %1 for writing.").arg(output));
  }
  LOG_DEBUG("Opened: " << output << ".");
}

void ImplicitTagRulesJsonWriter::write(
  const QMap<QString, QMap<QString, long> >& /*tokensToKvpsWithCounts*/)
{

}

void ImplicitTagRulesJsonWriter::close()
{
  if (_file.get())
  {
    _file->close();
    _file.reset();
  }
}

}