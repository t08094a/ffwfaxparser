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

#include "Operation.h"
#include <algorithm>
#include <functional>

// this is a function object to delete a pointer matching our criteria.
struct resource_deleter
{
    void operator()(OperationResource*& e) // important to take pointer by reference!
    {
        delete e;
        e = nullptr;
    }
};

Operation::Operation()
    : resources(), einsatzort(), zielort()
{
    // nop
}

Operation::Operation (const Operation& other)
{
    // now, apply resource_deleter to each element, remove the elements that were deleted,
    // and erase them from the vector
    for_each(resources.begin(), resources.end(), resource_deleter());
    vector<OperationResource*>::iterator new_end = remove(resources.begin(), resources.end(), static_cast<OperationResource*>(NULL));
    resources.erase(new_end, resources.end());
}

Operation::~Operation()
{

}

Operation& Operation::operator= (const Operation& other)
{

}

bool Operation::operator== (const Operation& other) const
{

}

int Operation::GetId()
{
    return id;
}

void Operation::SetId(const int id)
{
    this->id = id;
}

boost::uuids::uuid Operation::GetGuid()
{
    return guid;
}

void Operation::SetGuid(const boost::uuids::uuid guid)
{
    this->guid = guid;
}

boost::posix_time::ptime Operation::GetTimestampIncome()
{
    return timestampIncome;
}

void Operation::SetTimestampIncome(const boost::posix_time::ptime time)
{
    timestampIncome = time;
}

boost::posix_time::ptime Operation::GetTimestamp()
{
    return timestamp;
}

void Operation::SetTimestamp(const boost::posix_time::ptime time)
{
    timestamp = time;
}

string Operation::GetAbsender()
{
    return absender;
}

void Operation::SetAbsender(const string value)
{
    absender = value;
}

string Operation::GetTermin()
{
    return termin;
}

void Operation::SetTermin(const string termin)
{
    this->termin = termin;
}

string Operation::GetEinsatzortZusatz()
{
    return einsatzortZusatz;
}

void Operation::SetEinsatzortZusatz(const string zusatz)
{
    einsatzortZusatz = zusatz;
}

string Operation::GetEinsatzortPlannummer()
{
    return einsatzortPlannummer;
}

void Operation::SetEinsatzortPlannummer(const string plannummer)
{
    einsatzortPlannummer = plannummer;
}

string Operation::GetEinsatzortStation()
{
    return einsatzortStation;
}

void Operation::SetEinsatzortStation(const string station)
{
    einsatzortStation = station;
}

string Operation::GetZielortZusatz()
{
    return zielortZusatz;
}

void Operation::SetZielortZusatz(const string zusatz)
{
    zielortZusatz = zusatz;
}

string Operation::GetZielortStation()
{
    return zielortStation;
}

void Operation::SetZielortStation(const string station)
{
    zielortStation = station;
}

string Operation::GetOperationNumber()
{
    return operationNumber;
}

void Operation::SetOperationNumber(const string number)
{
    operationNumber = number;
}

string Operation::GetMessenger()
{
    return messenger;
}

void Operation::SetMessenger(const string messenger)
{
    this->messenger = messenger;
}

string Operation::GetPriority()
{
    return priority;
}

void Operation::SetPriority(string priority)
{
    this->priority = priority;
}

string Operation::GetComment()
{
    return comment;
}

void Operation::SetComment(const string comment)
{
    this->comment = comment;
}

void Operation::AddResource(OperationResource* resource)
{
    resources.push_back(resource);
}

OperationKeywords& Operation::GetKeywords()
{
    return keywords;
}

PropertyLocation& Operation::GetEinsatzort()
{
    return einsatzort;
}

PropertyLocation& Operation::GetZielort()
{
    return zielort;
}
