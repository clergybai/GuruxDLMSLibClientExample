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

#include "GXDLMSDayProfile.h"
#include <sstream> 

/** 
 Constructor.
*/
CGXDLMSDayProfile::CGXDLMSDayProfile()
{
	m_DayId = 0;
}

/** 
 Constructor.
*/
CGXDLMSDayProfile::CGXDLMSDayProfile(int dayId, vector<CGXDLMSDayProfileAction> schedules)
{
    SetDayId(dayId);
    SetDaySchedules(schedules);
}

/** 
 User defined identifier, identifying the currentday_profile.
*/
int CGXDLMSDayProfile::GetDayId()
{
    return m_DayId;
}
void CGXDLMSDayProfile::SetDayId(int value)
{
    m_DayId = value;
}

vector<CGXDLMSDayProfileAction>& CGXDLMSDayProfile::GetDaySchedules()
{
    return m_DaySchedules;
}
void CGXDLMSDayProfile::SetDaySchedules(vector<CGXDLMSDayProfileAction>& value)
{
    m_DaySchedules = value;
}

string CGXDLMSDayProfile::ToString()
{
	std::stringstream sb;
	sb << m_DayId;	
	for(vector<CGXDLMSDayProfileAction>::iterator it = m_DaySchedules.begin(); it != m_DaySchedules.end(); ++it)
    {
        sb << " ";
		sb << it->ToString().c_str();
    }
	return sb.str();

}