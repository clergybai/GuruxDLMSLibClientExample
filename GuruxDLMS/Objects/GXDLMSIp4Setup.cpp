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

#include "GXDLMSIp4Setup.h"
#include "../GXDLMSClient.h"
#include <sstream> 

//Constructor.
CGXDLMSIp4Setup::CGXDLMSIp4Setup() : CGXDLMSObject(OBJECT_TYPE_IP4_SETUP)
{
}

//SN Constructor.
CGXDLMSIp4Setup::CGXDLMSIp4Setup(unsigned short sn) : CGXDLMSObject(OBJECT_TYPE_IP4_SETUP, sn)
{

}

//LN Constructor.
CGXDLMSIp4Setup::CGXDLMSIp4Setup(basic_string<char> ln) : CGXDLMSObject(OBJECT_TYPE_IP4_SETUP, ln)
{

}

string& CGXDLMSIp4Setup::GetDataLinkLayerReference()
{
    return m_DataLinkLayerReference;
}
void CGXDLMSIp4Setup::SetDataLinkLayerReference(string value)
{
    m_DataLinkLayerReference = value;
}

unsigned long CGXDLMSIp4Setup::GetIPAddress()
{
    return m_IPAddress;
}

void CGXDLMSIp4Setup::SetIPAddress(unsigned long value)
{
    m_IPAddress = value;
}

vector<unsigned long>& CGXDLMSIp4Setup::GetMulticastIPAddress()
{
    return m_MulticastIPAddress;
}

vector<CGXDLMSIp4SetupIpOption>& CGXDLMSIp4Setup::GetIPOptions()
{
    return m_IPOptions;
}
void CGXDLMSIp4Setup::SetIPOptions(vector<CGXDLMSIp4SetupIpOption> value)
{
    m_IPOptions = value;
}

unsigned long CGXDLMSIp4Setup::GetSubnetMask()
{
    return m_SubnetMask;
}

void CGXDLMSIp4Setup::SetSubnetMask(unsigned long value)
{
    m_SubnetMask = value;
}

unsigned long CGXDLMSIp4Setup::GetGatewayIPAddress()
{
    return m_GatewayIPAddress;
}
void CGXDLMSIp4Setup::SetGatewayIPAddress(unsigned long value)
{
    m_GatewayIPAddress = value;
}

bool CGXDLMSIp4Setup::GetUseDHCP()
{
    return m_UseDHCP;
}
void CGXDLMSIp4Setup::SetUseDHCP(bool value)
{
    m_UseDHCP = value;
}

unsigned long CGXDLMSIp4Setup::GetPrimaryDNSAddress()
{
    return m_PrimaryDNSAddress;
}
void CGXDLMSIp4Setup::SetPrimaryDNSAddress(unsigned long value)
{
    m_PrimaryDNSAddress = value;
}

unsigned long CGXDLMSIp4Setup::GetSecondaryDNSAddress()
{
    return m_SecondaryDNSAddress;
}

void CGXDLMSIp4Setup::SetSecondaryDNSAddress(unsigned long value)
{
    m_SecondaryDNSAddress = value;
}

// Returns amount of attributes.
int CGXDLMSIp4Setup::GetAttributeCount()
{
	return 10;
}

// Returns amount of methods.
int CGXDLMSIp4Setup::GetMethodCount()
{
	return 3;
}

void CGXDLMSIp4Setup::GetValues(vector<string>& values)
{
	values.clear();
	string ln;
	GetLogicalName(ln);
	values.push_back(ln);
	//CGXDLMSVariant().ToString()
	values.push_back(m_DataLinkLayerReference);
	values.push_back(CGXDLMSVariant(m_IPAddress).ToString());
	std::stringstream sb;
	sb << '[';
	bool empty = true;
	for(vector<unsigned long>::iterator it = m_MulticastIPAddress.begin(); it != m_MulticastIPAddress.end(); ++it)
	{
		if (!empty)
		{
			sb << ", ";
		}
		empty = false;
		string str = CGXDLMSVariant(*it).ToString();
		sb.write(str.c_str(), str.size());
	}
	sb << ']';
	values.push_back(sb.str());		

	//Clear str.
	sb.str(std::string());		
	sb << '[';
	empty = true;
	for(vector<CGXDLMSIp4SetupIpOption>::iterator it = m_IPOptions.begin(); it != m_IPOptions.end(); ++it)
	{
		if (!empty)
		{
			sb << ", ";
		}
		empty = false;
		string str = it->ToString();
		sb.write(str.c_str(), str.size());
	}
	sb << ']';
	values.push_back(sb.str());	
	
	values.push_back(CGXDLMSVariant(m_SubnetMask).ToString());
	values.push_back(CGXDLMSVariant(m_GatewayIPAddress).ToString());
	values.push_back(CGXDLMSVariant(m_UseDHCP).ToString());
	values.push_back(CGXDLMSVariant(m_PrimaryDNSAddress).ToString());
	values.push_back(CGXDLMSVariant(m_SecondaryDNSAddress).ToString());	
}

void CGXDLMSIp4Setup::GetAttributeIndexToRead(vector<int>& attributes)
{
	//LN is static and read only once.
	if (CGXOBISTemplate::IsLogicalNameEmpty(m_LN))
    {
        attributes.push_back(1);
    }
	//DataLinkLayerReference
    if (!IsRead(2))
    {
        attributes.push_back(2);
    }
    //IPAddress
    if (CanRead(3))
    {
        attributes.push_back(3);
    }
    //MulticastIPAddress
    if (CanRead(4))
    {
        attributes.push_back(4);
    }
    //IPOptions
    if (CanRead(5))
    {
        attributes.push_back(5);
    }
    //SubnetMask
    if (CanRead(6))
    {
        attributes.push_back(6);
    }
    //GatewayIPAddress
    if (CanRead(7))
    {
        attributes.push_back(7);
    }
    //UseDHCP
    if (!IsRead(8))
    {
        attributes.push_back(8);
    }
    //PrimaryDNSAddress
    if (CanRead(9))
    {
        attributes.push_back(9);
    }
    //SecondaryDNSAddress
    if (CanRead(10))
    {
        attributes.push_back(10);
    }
}

int CGXDLMSIp4Setup::GetDataType(int index, DLMS_DATA_TYPE& type)
{
	if (index == 1)
	{
		type = DLMS_DATA_TYPE_OCTET_STRING;			
	}
    else if (index == 2)
    {
        type = DLMS_DATA_TYPE_OCTET_STRING;
    }
    else if (index == 3)
    {
        type = DLMS_DATA_TYPE_UINT16;
    }
    else if (index == 4)
    {
        type = DLMS_DATA_TYPE_ARRAY;
    }
    else if (index == 5)
    {
        type = DLMS_DATA_TYPE_ARRAY;
    }
    else if (index == 6)
    {
        type = DLMS_DATA_TYPE_UINT32;
    }
    else if (index == 7)
    {
        type = DLMS_DATA_TYPE_UINT32;
    }
    else if (index == 8)
    {
        type = DLMS_DATA_TYPE_BOOLEAN;
    }
    else if (index == 9)
    {
        type = DLMS_DATA_TYPE_UINT32;
    }
    else if (index == 10)
    {
        type = DLMS_DATA_TYPE_UINT32;
    }
	else
	{
		return ERROR_CODES_INVALID_PARAMETER;
	}
	return ERROR_CODES_OK;
}

// Returns value of given attribute.
int CGXDLMSIp4Setup::GetValue(int index, unsigned char* parameters, int length, CGXDLMSVariant& value)
{
	if (index == 1)
	{
		GXHelpers::AddRange(value.byteArr, m_LN, 6);
		value.vt = DLMS_DATA_TYPE_OCTET_STRING;
		return ERROR_CODES_OK;
	}
    if (index == 2)
    {
        value = m_DataLinkLayerReference;
    }
    if (index == 3)
    {
        value = m_IPAddress;
    }
    if (index == 4)
    {
		vector<unsigned char> data;
        data.push_back(DLMS_DATA_TYPE_ARRAY);
        CGXOBISTemplate::SetObjectCount(m_MulticastIPAddress.size(), data);
		int ret;
		for(vector<unsigned long>::iterator it = m_MulticastIPAddress.begin(); it != m_MulticastIPAddress.end(); ++it)            
        {
			if ((ret = CGXOBISTemplate::SetData(data, DLMS_DATA_TYPE_UINT32, *it)) != 0)
			{
				return ret;
			}
        }
        value = data;
		return ERROR_CODES_OK;
    }
    if (index == 5)
    {
        vector<unsigned char> data;
        data.push_back(DLMS_DATA_TYPE_ARRAY);
        CGXOBISTemplate::SetObjectCount(m_IPOptions.size(), data);
		int ret;
		for(vector<CGXDLMSIp4SetupIpOption>::iterator it = m_IPOptions.begin(); it != m_IPOptions.end(); ++it)            
        {
            data.push_back(DLMS_DATA_TYPE_STRUCTURE);
            data.push_back(3);
            if ((ret = CGXOBISTemplate::SetData(data, DLMS_DATA_TYPE_UINT8, it->GetType())) != 0 ||
				(ret = CGXOBISTemplate::SetData(data, DLMS_DATA_TYPE_UINT8, it->GetLength())) != 0 ||
				(ret = CGXOBISTemplate::SetData(data, DLMS_DATA_TYPE_OCTET_STRING, it->GetData())) != 0)
			{
				return ret;
			}
        }
        value = data;
		return ERROR_CODES_OK;
    }
    if (index == 6)
    {
        value = m_SubnetMask;
    }
    if (index == 7)
    {
        value = m_GatewayIPAddress;
    }
    if (index == 8)
    {
        value = m_UseDHCP;
    }
    if (index == 9)
    {
        value = m_PrimaryDNSAddress;
    }
    if (index == 10)
    {
        value = m_SecondaryDNSAddress;
    }
	return ERROR_CODES_INVALID_PARAMETER;
}

// Set value of given attribute.
int CGXDLMSIp4Setup::SetValue(int index, CGXDLMSVariant& value)
{
	if (index == 1)
	{			
		if (value.vt != DLMS_DATA_TYPE_OCTET_STRING || value.GetSize() != 6)
		{
			return ERROR_CODES_INVALID_PARAMETER;
		}
		memcpy(m_LN, &value.byteArr[0], 6);		
	}
    else if (index == 2)
    {
        if (value.vt == DLMS_DATA_TYPE_STRING)
        {
            m_DataLinkLayerReference = value.ToString();
        }
        else
        {
			CGXDLMSVariant tmp;
			CGXDLMSClient::ChangeType(value.byteArr, DLMS_DATA_TYPE_OCTET_STRING, tmp);
			m_DataLinkLayerReference = tmp.ToString();
        }
    }
    else if (index == 3)
    {
		m_IPAddress = value.ToInteger();
    }
    else if (index == 4)
    {
		m_MulticastIPAddress.clear();
        if (value.vt == DLMS_DATA_TYPE_ARRAY)
        {
			for(vector<CGXDLMSVariant>::iterator it = value.Arr.begin(); it != value.Arr.end(); ++it)
            {
                m_MulticastIPAddress.push_back((*it).ToInteger());
            }
        }            
    }
    else if (index == 5)
    {            
		m_IPOptions.clear();
        if (value.vt == DLMS_DATA_TYPE_ARRAY)
        {
			for(vector<CGXDLMSVariant>::iterator it = value.Arr.begin(); it != value.Arr.end(); ++it)
            {
                CGXDLMSIp4SetupIpOption item;
				item.SetType((IP_OPTION_TYPE) it->Arr[0].ToInteger());
                item.SetLength(it->Arr[1].ToInteger());
				item.SetData(it->Arr[0].byteArr);
                m_IPOptions.push_back(item);
            }
        }            
    }
    else if (index == 6)
    {
        m_SubnetMask = value.ToInteger();
    }
    else if (index == 7)
    {
        m_GatewayIPAddress = value.ToInteger();
    }
    else if (index == 8)
    {
		m_UseDHCP = value.boolVal;
    }
    else if (index == 9)
    {
        m_PrimaryDNSAddress = value.ToInteger();
    }
    else if (index == 10)
    {
        m_SecondaryDNSAddress = value.ToInteger();
    }	
	else
	{
		return ERROR_CODES_INVALID_PARAMETER;
	}
	return ERROR_CODES_OK;
}