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

#ifndef OPERATIONKEYWORDS_H
#define OPERATIONKEYWORDS_H

#include <string>
#include <iostream>
#include "IPrintable.h"

using namespace std;

/**
 * @brief Contains the keywords ("stichwörter") for an operation.
 */
class OperationKeywords : public IPrintable
{
private:
    string keyword;
    string emergencyKeyword;
    string b;
    string r;
    string s;
    string t;

public:
    OperationKeywords();
    OperationKeywords ( const OperationKeywords& other );
    ~OperationKeywords();
    OperationKeywords& operator= ( const OperationKeywords& other );
    bool operator== ( const OperationKeywords& other ) const;
    
    friend ostream& operator<< (ostream& out, const OperationKeywords& keywords)
    {
        out << keywords.ToString();
        
        return out;
    }
        
    /**
     * @brief Gets the "Stichwort" (generic keyword), direct or equivalent.
     * @return
     */
    string GetKeyword();

    /**
     * @brief Sets the "Stichwort" (generic keyword), direct or equivalent.
     * @name keyword
     */
    void SetKeyword(const string keyword);

    /**
     * @brief Gets the B/R/S/T/etc. keyword for sources that don't distinguish between them.
     * @return
     */
    string GetEmergencyKeyword();

    /**
     * @brief Sets the B/R/S/T/etc. keyword for sources that don't distinguish between them.
     * @param keyword
     */
    void SetEmergencyKeyword(const string keyword);

    /**
     * @brief Gets the "Stichwort B" (specific keyword), direct or equivalent.
     * @return
     */
    string GetB();

    /**
     * @brief Sets the "Stichwort B" (specific keyword), direct or equivalent.
     * @param b
     */
    void SetB(const string b);

    /**
     * @brief Gets the "Stichwort R" (specific keyword), direct or equivalent.
     * @return
     */
    string GetR();

    /**
     * @brief Sets the "Stichwort R" (specific keyword), direct or equivalent.
     * @param r
     */
    void SetR(const string r);

    /**
     * @brief Gets the "Stichwort S" (specific keyword), direct or equivalent.
     * @return
     */
    string GetS();

    /**
     * @brief Sets the "Stichwort S" (specific keyword), direct or equivalent.
     * @param s
     */
    void SetS(const string s);

    /**
     * @brief Gets the "Stichwort T" (specific keyword), direct or equivalent.
     * @return
     */
    string GetT();

    /**
     * @brief Sets the "Stichwort T" (specific keyword), direct or equivalent.
     * @param t
     */
    void SetT(const string t);

    /**
     * @brief Returns a string that contains all set keywords separated by commas.
     * @return A string that contains all set keywords by commas
     */
    string ToString() const;
};

#endif // OPERATIONKEYWORDS_H
