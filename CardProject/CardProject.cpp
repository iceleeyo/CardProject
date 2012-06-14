// CardProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <vector>
#include "../BHGX_HISReader/BHGX_HISReader.h"
#include "../BHGX_CPUCardLib/BHGX_CPUCardLib.h"
//#include "../BHGX_CardLib/src/BHGX_CardLib.h"
#include "../BHGX_CreateCardData/BHGX_CreateCardData.h"
//#include "ConvertUtil.h"
#include <fstream>
#include <map>
#include <time.h>


#pragma comment(lib, "tinyxml/libs/tinyxmld.lib")

#ifdef _DEBUG
//#pragma comment(lib, "../debug/BHGX_CardLib.lib")
#pragma comment(lib, "../debug/BHGX_CreateCardData.lib")
#pragma comment(lib, "../debug/BHGX_HISReader.lib")
#pragma comment(lib, "../debug/BHGX_CPUCardLib.lib")
#else
//#pragma comment(lib, "../release/BHGX_CPUCardLib.lib")
#pragma comment(lib, "../release/BHGX_CreateCardData.lib")
#pragma comment(lib, "../release/BHGX_CardLib.lib")
#endif

#pragma warning (disable : 4996)
using namespace std;

#define SAFE_DELETE(a)\
	if (a != NULL)\
{\
	delete a;\
	a = NULL;\
}\

static int WriteFile(char *filename, char *xml)
{
	FILE *handle;

	fopen_s(&handle, filename, "w");
	fwrite(xml, strlen(xml), 1, handle);
	fclose(handle);

	return 0;
}

static int ReadFile(char *filename, char **xml)
{
	FILE *handle;
	int size;

	fopen_s(&handle, filename, "r");

	if (NULL == handle)
		return -1;
	fseek(handle, 0, SEEK_END);
	size = ftell(handle) + 1;
	rewind(handle);
	*xml = (char *) malloc(size);
	memset(*xml, 0, size);
	fread(*xml,size,1,handle);
	fclose(handle);

	return size;
}

static void DbgMem(unsigned char *mem, int size)
{
	int i = 0;
	for(i=0; i< size; i++)
		printf("%02x ", mem[i]);
	printf("\n");
}



int main(int argc, char* argv[])
{
	char szPrinter[1024];
	memset(szPrinter, 0, 1024);

	cout<<"*************一卡通系统测试*********************"<<endl;
	cout<<"功能测试：\n\t1:公卫制卡数据\n\t2:农合制卡数据\n\t3:ReadInfo\n\t4:WriteInfo"<<endl;
	cout<<"\t5:FormateCard\n\t6:CreateCard\n\t7:ReadHISInfo\n\t8:卡注册\n\t9:PatchCard"<<endl;
	cout<<"\t10:PrintCard\n\t11:CardIsEmpty"<<endl;

	char szSelect[10];
	int  nSeg = 1;
	cout<<"请输入功能测试选项:";
	cin>>szSelect;
	std::string strSelect = szSelect;
	std::vector<std::string> vecPrinter;
	//char szPrinter[1024];
	//memset(szPrinter, 0, 1024);

	while (1)
	{
		if (strSelect == "q" || strSelect == "quit")
			break;

		int nSelect = atoi(szSelect);
		if (nSelect == 1)
		{
			//iCreatePubSysCardData("艾地热斯·莫明.txt", "北航冠新.license");
		}
		else if (nSelect == 2)
		{
			//iCreateCardData("艾地热斯·莫明.txt", "北航冠新.license");
		}
		else 
		{
			char *buf;
			char *readBuf;
			char *CreateXML;
			int nStart, nEnd;
			int index,ret;
			char szURL[256];
			char szCheckWSDL[256];
			memset(szURL, 0, sizeof(szURL));
			memset(szCheckWSDL, 0, sizeof(szCheckWSDL));
			std::string strURL = "http://192.168.1.16/nh_webservice/n_api.asmx?WSDL";
			std::string strCheckWSDL = "http://192.168.1.67:8000/ccss/ws/oneCardWebService";
			ret = iCardInit();
			if (ret != 0)
			{
				cout<<"卡初始化失败:"<<ret<<endl;
				break;
			}

			char szRead[4096*4];
			char szError[64];
			memset(szError, 0, 64);
			memset(szRead, 0, sizeof(szRead));
			switch(nSelect)
			{
			case 3:
				ret = iReadInfo(0x1, szRead);
				if (ret != 0)
				{
					strcpy(szError, err(ret));
					printf("%s\n", szError);
				}
				else
				{
					printf("%s\n", szRead);
				}
				
				break;
			case 4:
				ReadFile("CardSave_1.xml", &buf);
				ret = iWriteInfo(buf);
				printf("写操作:%d\n", ret);
				if (ret != 0)
				{
					strcpy(szError, err(ret));
					printf("%s\n", szError);
				}
				free(buf);
				break;
			case 5:
				nStart = GetTickCount();
				ret = iFormatCard();
				nEnd = GetTickCount();
				printf("iFormatCard: %d    所需时间: %d ", ret, nEnd - nStart);
				if (ret != 0)
				{
					strcpy(szError, err(ret));
					printf("%s\n", szError);
				}
				break;
			case 6:
				ReadFile("CreateCard.xml", &CreateXML);
				printf("*************开始制卡*************\n");
				
				nStart = GetTickCount();
				ret = iCreateCard(CreateXML);

				nEnd = GetTickCount();
				printf("iCreateCard: %d    所需时间: %d\n ", ret, nEnd - nStart);
				if (ret != 0)
				{
					strcpy(szError, err(ret));
					printf("%s\n", szError);
				}
				free(CreateXML);
				break;
			case 7:
//				ret = iReadHISInfo((char*)strCheckWSDL.c_str(), (char*)strURL.c_str(), szRead);
				printf("%s", szRead);
				if (ret != 0)
				{
					strcpy(szError, err(ret));
					printf("%s\n", szError);
				}
				break;
			case 8:
				//cout<<"请输入服务器地址:"<<endl;
				//cin>>szURL;
				//cout<<"请输入WSDL文件地址:"<<endl;
				//cin>>szCheckWSDL;
				//ret = iRegMsgForNH((char*)strURL.c_str(), szRead);
				iCheckMsgForNH((char*)strCheckWSDL.c_str(), (char*)strURL.c_str(), szRead);
				printf("%s", szRead);
				break;
			case 9:
				ReadFile("CreateCard.xml", &CreateXML);
				ReadFile("cardprintData.xml", &buf);
				ReadFile("modify_cardprint_652822.xml", &readBuf);
				printf("*************开始制卡*************\n");

				iGetPrinterList(szPrinter);
				printf("探测的打印机列表%s:\n", szPrinter);
				printf("***********************************\n");

				//for(int i=0; i<4; ++i)
				//{
					nStart = GetTickCount();
					ret = iPatchCard(CreateXML,buf,"Zebra P330i Card Printer USB", readBuf);

					nEnd = GetTickCount();
					printf("PatchCard: %d    所需时间: %d \n", ret, nEnd - nStart);
				//}
				free(buf);
				free(readBuf);
				free(CreateXML);
				break;
			case 10:
				ReadFile("cardprintData.xml", &buf);
				ReadFile("modify_cardprint_652822.xml", &readBuf);
				printf("*************开始打印卡*************\n");
				
				printf("***********************************\n");
				//for(int i=0; i<vecPrinter.size(); ++i)
				//{
					nStart = GetTickCount();
					ret = iPrintCard("", buf, readBuf);
					nEnd = GetTickCount();
					printf("iPrintCard: %d    所需时间: %d \n", ret, nEnd - nStart);
				//}
				free(buf);
				free(readBuf);
				break;
			case 11:
				ret = iCardIsEmpty();
				if (ret != 0)
				{
					strcpy(szError, err(ret));
					printf("%s\n", szError);
				}
				break;
			default:
				cout<<"没有改选项，请重新选择\n"<<endl;
				break;
			}
			iCardClose();
		}

		memset(szSelect, 0 , sizeof(szSelect));
		cout<<"\n请输入功能测试选项:";
		cin>>szSelect;
		strSelect = szSelect;

	}
	system("pause");

	return 0;
}

