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

#include "GXDLMSImageActivateInfo.h"
#include <sstream> 

/**
 * Constructor.
 */
CGXDLMSImageActivateInfo::CGXDLMSImageActivateInfo()
{
    
}

/**
 * Constructor.
 */
CGXDLMSImageActivateInfo::CGXDLMSImageActivateInfo(long size, string identification, string signature)
{
    m_Size = size;
    m_Identification = identification;
    m_Signature = signature;
}

 /** 
  *  Image_size is the size of the Image(s) to be activated. 
  *  Expressed in octets;
*/
long CGXDLMSImageActivateInfo::GetSize()
{
    return m_Size;
}
void CGXDLMSImageActivateInfo::SetSize(long value)
{
    m_Size = value;
}

 /** 
  * Image identification is the identification of the Image(s)
  * to be activated, and may contain information like
  * manufacturer, device type, version information, etc.
*/
string CGXDLMSImageActivateInfo::GetIdentification()
{
    return m_Identification;
}
void CGXDLMSImageActivateInfo::SetIdentification(string value)
{
    m_Identification = value;
}

 /** 
  * Image signature is the signature of the Image(s) to be activated.
*/
string CGXDLMSImageActivateInfo::GetSignature()
{
    return m_Signature;
}
void CGXDLMSImageActivateInfo::SetSignature(string value)
{
    m_Signature = value;
}

string CGXDLMSImageActivateInfo::ToString()
{
	std::stringstream sb;	
	sb << m_Identification.c_str();
	sb << " ";
	sb << m_Signature.c_str();
	sb << " ";
	sb << m_Size;
	return sb.str();
}