#ifndef _WEBASSIST_H
#define _WEBASSIST_H

#include <map>
#include <string>
#include "./tinyxml/headers/tinyxml.h"

#pragma comment(lib, "tinyxml/libs/tinyxmld.lib")

std::map<std::string, std::string> m_mapCodeDesc;
std::map<int, std::string> m_mapCardStatus;

using namespace std;

void CreateResponXML(int nID, const char *szResult, char *RetXML);

int GetCheckState(const std::string &strXML, std::string &strRetCode, std::string &strSec);

int FormatWriteInfo(const char *strWrite, char *strFMTWrite);

int GetQueryMapInfo(char *QueryXML, std::map<std::string,std::string> &mapQuery);

int GetQueryInfo(char *QueryXML, std::string &szCardNO);

int CreateCheckWsdlParams(const char *CardID, const char *pszCardCheckWSDL, char *strParams);

int CreateRegWsdlParams(const char *CardID, char *strParams);

int GetCheckRetDesc(const std::string &strStatus, std::string &strDesc);

int GetCardStatus(int nStatus, std::string &strStatus);

bool IsMedicalID(const std::string &strID);

#endif
