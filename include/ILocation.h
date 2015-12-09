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

#ifndef ILOCATION_H
#define ILOCATION_H

#include <string>
#include <iostream>
#include "IPrintable.h"

using namespace std;

class ILocation : public IPrintable
{
public:
    virtual ~ILocation() {}
    
    /**
     * @brief Gets the location name.
     * @return
     */
    virtual string GetLocation() = 0;
    
    /**
     * @brief Gets the zip code of the city.
     * @return
     */
    virtual string GetZipCode() = 0;
    
    /**
     * @brief Gets the city name.
     * @return
     */
    virtual string GetCity() = 0;
    
    /**
     * @brief Gets the street. May contain the street number.
     * @return
     */
    virtual string GetStreet() = 0;
    
    /**
     * @brief Gets the street number. May be contained within the street.
     * @return
     */
    virtual string GetStreetNumber() = 0;
    
    /**
     * @brief Gets a description of the "Intersection" (if provided by alarmsource).
     * @return
     */
    virtual string GetIntersection() = 0;
    
    /**
     * @brief Gets the latitude of the location (if provided by alarmsource).
     * @return
     */
    virtual string GetGeoLatitude() = 0;
    
    /**
     * @brief Gets the longitude of the location (if provided by alarmsource).
     * @return
     */
    virtual string GetGeoLongitude() = 0;
    
    /**
     * @brief Gets the name of the property (company, site, house etc.).
     * @return
     */
    virtual string GetProperty() = 0;
    
    /**
     * @brief Gets whether or not this instance represents a meaningful geographic location.
     *        This takes only ZipCode, City and Street into account.
     * @return
     */
    virtual bool IsMeaningful() = 0;
    
    /**
     * @brief Gets whether or not there are meaningful values for the geo
     *        coordinates (latitude and longitude) defined.
     * @return
     */
    virtual bool HasGeoCoordinates() = 0;

    /**
     * @brief Returns a string describing the property location like:
     *        "[[Street] [StreetNumber]], [ZipCode] [City]".
     * @return
     */
    virtual string ToString() const = 0;
    
    friend ostream& operator<< (ostream& out, const ILocation& location)
    {
        out << location.ToString();
        
        return out;
    }
};

#endif // ILOCATION_H
