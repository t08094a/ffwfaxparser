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

#include "OperationResource.h"

OperationResource::OperationResource()
{
    // nop
}

OperationResource::OperationResource (const OperationResource& other)
{

}

OperationResource::~OperationResource()
{
    requestedEquipment.clear();
}

OperationResource& OperationResource::operator= (const OperationResource& other)
{

}

bool OperationResource::operator== (const OperationResource& other) const
{
    return true; // todo
}

string OperationResource::GetFullName()
{
    return fullName;
}

void OperationResource::SetFullName(const string name)
{
    fullName = name;
}

const boost::posix_time::ptime OperationResource::GetTimestamp() const
{
    return timestamp;
}

void OperationResource::SetTimestamp(const boost::posix_time::ptime timestamp)
{
    this->timestamp = timestamp;
}

const vector<string>& OperationResource::GetRequestedEquipment() const
{
    return requestedEquipment;
}

void OperationResource::AddRequestedEquipment(string equipment)
{
    requestedEquipment.push_back(equipment);
}