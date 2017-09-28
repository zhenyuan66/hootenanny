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
#ifndef POIIMPLICITTAGRULESDERIVER_H
#define POIIMPLICITTAGRULESDERIVER_H

// hoot


// Qt
#include <QString>
#include <QMultiMap>

namespace hoot
{

class Tags;

/**
 *
 */
class PoiImplicitTagRulesDeriver
{

public:

  PoiImplicitTagRulesDeriver();

  void writeRules(const QString input, const QString output, const int minOccurancesAllowed = 1,
                  const QStringList typeKeys = QStringList());

private:

//  //#1
//  QMultiMap<QString, QStringList> _kvpCountsByToken;

//  //#2
//  QMap<QString, QStringList> _tokenToKvps;
//  QMap<QString, QStringList> _kvpToTokens;
//  QMap<QString, int> _tokenKvpToCount;

  //#3
  //QList<ImplicitTagRulePtr> _rules;
  //QMap<QString, ImplicitTagRulePtr> _tokensToRules;
  //QMap<QString, ImplicitTagRulePtr> _kvpsToRules;
  QMap<QString, long> _wordKvpToCount;
  QMap<QString, QMap<QString, long> > _tokensToKvpsWithCounts;

  int _minOccurancesAllowed;

  //void _updateForNewToken(const QString token, const QString kvp);
  void _updateForNewToken2(const QString token, const QString kvp);
  //QList<ImplicitTagRulePtr> _tokenKvpsToRules();
  QString _getMostSpecificPoiKvp(const Tags& tags) const;
  void _removeKvpsBelowOccuranceThreshold();
};

}

#endif // POIIMPLICITTAGRULESDERIVER_H