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

#ifndef OPERATIONRESOURCE_H
#define OPERATIONRESOURCE_H

#include <string>
#include <vector>
#include <boost/date_time/posix_time/ptime.hpp>

using namespace std;

/**
 * @brief Represents a resource, which was was requested by the call center.
 */
class OperationResource
{
private:
    vector<string> requestedEquipment;
    string fullName;
    boost::posix_time::ptime timestamp;
public:
    OperationResource();
    OperationResource ( const OperationResource& other );
    ~OperationResource();
    OperationResource& operator= ( const OperationResource& other );
    bool operator== ( const OperationResource& other ) const;
    
    /**
     * @brief Gets the name of the resource. Usually this represents a vehicle.
     * @return
     */
    string GetFullName();

    /**
     * @brief Sets the name of the resource. Usually this represents a vehicle.
     * @param name
     */
    void SetFullName(const string name);

    /**
     * @brief Gets the timestamp of the request. May be empty.
     * @return
     */
    const boost::posix_time::ptime GetTimestamp() const;

    /**
     * @brief Sets the timestamp of the request. May be empty.
     * @param timestamp
     */
    void SetTimestamp(const boost::posix_time::ptime timestamp);

    /**
     * @brief Gets any equipment that is explicitely requested. May be empty.
     * @return
     */
    const vector<string>& GetRequestedEquipment() const;

    void AddRequestedEquipment(string equipment);
};

#endif // OPERATIONRESOURCE_H