/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2015  Jochen Fähnlein <jochen.faehnlein@ff-ipsheim.de>
 *
 * This program is free software: you can redistribute it and/or modify
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
 */

#ifndef IOPERATION_H
#define IOPERATION_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/uuid/uuid.hpp>

class IOperation
{
public:
    virtual int GetId() = 0;
    virtual void SetId(int id) = 0;
    virtual boost::uuids::uuid GetGuid() = 0;
    virtual void SetGuid(boost::uuids::uuid guid) = 0;
    virtual boost::posix_time::ptime GetTimestampIncome() = 0;
    virtual void SetTimestampIncome(boost::posix_time::ptime time) = 0;
    virtual boost::posix_time::ptime GetTimestamp() = 0;
    virtual void SetTimestamp(boost::posix_time::ptime time) = 0;
};

#endif // IOPERATION_H
