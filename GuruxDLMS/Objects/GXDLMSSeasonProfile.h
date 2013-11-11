//
// --------------------------------------------------------------------------
//  Gurux Ltd
// 
//
//
// Filename:        $HeadURL$
//
// Version:         $Revision$,
//                  $Date$
//                  $Author$
//
// Copyright (c) Gurux Ltd
//
//---------------------------------------------------------------------------
//
//  DESCRIPTION
//
// This file is a part of Gurux Device Framework.
//
// Gurux Device Framework is Open Source software; you can redistribute it
// and/or modify it under the terms of the GNU General Public License 
// as published by the Free Software Foundation; version 2 of the License.
// Gurux Device Framework is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of 
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
// See the GNU General Public License for more details.
//
// More information of Gurux products: http://www.gurux.org
//
// This code is licensed under the GNU General Public License v2. 
// Full text may be retrieved at http://www.gnu.org/licenses/gpl-2.0.txt
//---------------------------------------------------------------------------

#pragma once

#include "../GXDateTime.h"

class CGXDLMSSeasonProfile
{
	basic_string<char> m_Name;
    CGXDateTime m_Start;  
    basic_string<char> m_WeekName;
    
public:
    /** 
     Constructor.
    */
    CGXDLMSSeasonProfile()
    {

    }

    /** 
     Constructor.
    */
    CGXDLMSSeasonProfile(basic_string<char> name, CGXDateTime start, basic_string<char> weekName)
    {
        SetName(name);
        SetStart(start);
        SetWeekName(weekName);
    }

    /** 
     Name of season profile.
    */
    basic_string<char> GetName()
    {
        return m_Name;
    }
    void SetName(basic_string<char> value)
    {
        m_Name = value;
    }

    /** 
     Season Profile start time.
    */    
    CGXDateTime GetStart()
    {
        return m_Start;
    }
    void SetStart(CGXDateTime value)
    {
        m_Start = value;
    }

    /** 
     Week name of season profile.
    */    
    basic_string<char> GetWeekName()
    {
        return m_WeekName;
    }
    void SetWeekName(basic_string<char> value)
    {
        m_WeekName = value;
    }
};