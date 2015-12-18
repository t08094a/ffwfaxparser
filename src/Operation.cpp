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
#include <sstream>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>

Operation::Operation()
    : resources(), id(0), guid(boost::uuids::random_generator()()), timestampIncome(boost::posix_time::second_clock::local_time()), timestamp(timestampIncome),
      einsatzort(), zielort(), keywords()
{
    // nop
}

Operation::Operation (const Operation& other)
{
    id = other.id;
    guid = other.guid;
    timestampIncome = other.timestampIncome;
    timestamp = other.timestamp;
    absender = other.absender;
    termin = other.termin;
    einsatzortZusatz = other.einsatzortZusatz;
    einsatzortPlannummer = other.einsatzortPlannummer;
    einsatzortStation = other.einsatzortStation;
    zielortZusatz = other.zielortZusatz;
    zielortStation = other.zielortStation;
    operationNumber = other.operationNumber;
    einsatzort = other.einsatzort;
    zielort = other.zielort;
    messenger = other.messenger;
    priority = other.priority;
    comment = other.comment;
    keywords = other.keywords;
    resources = other.resources;
}

Operation::~Operation()
{
    // nop
}

Operation& Operation::operator= (const Operation& other)
{
    if (this == &other)
    {
        return *this; // handle self assignment
    }
    
    id = other.id;
    guid = other.guid;
    timestampIncome = other.timestampIncome;
    timestamp = other.timestamp;
    absender = other.absender;
    termin = other.termin;
    einsatzortZusatz = other.einsatzortZusatz;
    einsatzortPlannummer = other.einsatzortPlannummer;
    einsatzortStation = other.einsatzortStation;
    zielortZusatz = other.zielortZusatz;
    zielortStation = other.zielortStation;
    operationNumber = other.operationNumber;
    einsatzort = other.einsatzort;
    zielort = other.zielort;
    messenger = other.messenger;
    priority = other.priority;
    comment = other.comment;
    keywords = other.keywords;
    resources = other.resources;
    
    return *this;
}

bool Operation::operator== (const Operation& other) const
{
    return id == other.id &&
           guid == other.guid &&
           timestampIncome == other.timestampIncome &&
           timestamp == other.timestamp &&
           absender == other.absender &&
           termin == other.termin &&
           einsatzortZusatz == other.einsatzortZusatz &&
           einsatzortPlannummer == other.einsatzortPlannummer &&
           einsatzortStation == other.einsatzortStation &&
           zielortZusatz == other.zielortZusatz &&
           zielortStation == other.zielortStation &&
           operationNumber == other.operationNumber &&
           einsatzort == other.einsatzort && // todo: == pointer copy
           zielort == other.zielort &&       // todo: == pointer copy
           messenger == other.messenger &&
           priority == other.priority &&
           comment == other.comment &&
           keywords == other.keywords &&     // todo: == pointer copy
           resources == other.resources;   // todo: == pointer copy
}

int Operation::GetId() const
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
    resources.push_back(shared_ptr<OperationResource>(resource));
}

const vector<shared_ptr<OperationResource>>& Operation::GetResources() const
{
    return resources;
}

IKeywords& Operation::GetKeywords()
{
    return keywords;
}

OperationKeywords& Operation::GetKeywordsInternal()
{
    return keywords;
}

ILocation& Operation::GetEinsatzort()
{
    return einsatzort;
}

PropertyLocation& Operation::GetEinsatzortInternal()
{
    return einsatzort;
}

ILocation& Operation::GetZielort()
{
    return zielort;
}

PropertyLocation& Operation::GetZielortInternal()
{
    return zielort;
}

string Operation::ToString() const
{
    stringstream ss;
    
    ss << "Operation:" << endl;
    ss << "\t" << "id: " << id << endl;
    ss << "\t" << "guid: " << guid << endl;
    ss << "\t" << "timestampIncome: " << timestampIncome << endl;
    ss << "\t" << "timestamp: " << timestamp << endl;
    ss << "\t" << "absender: " << absender << endl;
    ss << "\t" << "termin: " << termin << endl;
    ss << "\t" << "einsatzort: " << einsatzort.ToString() << endl;
    ss << "\t" << "einsatzortZusatz: " << einsatzortZusatz << endl;
    ss << "\t" << "einsatzortPlannummer: " << einsatzortPlannummer << endl;
    ss << "\t" << "einsatzortStation: " << einsatzortStation << endl;
    ss << "\t" << "operationNumber: " << operationNumber << endl;
    ss << "\t" << "messenger: " << messenger << endl;
    ss << "\t" << "priority: " << priority << endl;
    ss << "\t" << "comment: " << comment << endl;
    ss << "\t" << "keywords: " << keywords.ToString() << endl;
    ss << "\t" << "zielort: " << zielort.ToString() << endl;
    ss << "\t" << "zielortStation: " << zielortStation << endl;
    ss << "\t" << "zielortZusatz: " << zielortZusatz << endl;
    ss << "\t" << "resources: " << endl;
    
    for(auto resource : resources)
    {
        ss << "\t\t" << *resource << endl;
    }
    
    return ss.str();
}
