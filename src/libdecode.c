/*
 * libdecode.c
 *
 *  Created on: 26 févr. 2013
 *      Author: chaf0uin
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libdecode.h"

int iDecHex(char * acIn,char ** pacOut)
{
	char * pcPos=*pacOut;
	int iNum;
	int iRet=0;
	if(sscanf(acIn,"%d",&iNum)==1)
	{
		iRet=sprintf(pcPos,"%2X",iNum);
	}
	*pacOut+=iRet;
	return iRet;
}

int iDecOct(char * acIn,char ** pacOut)
{
	char * pcPos=*pacOut;
	int iNum;
	int iRet=0;
	if(sscanf(acIn,"%d",&iNum)==1)
	{
		iRet=sprintf(pcPos,"%2o",iNum);
	}
	*pacOut+=iRet;
	return iRet;
}

int iNumber2Letter(char * acIn,char ** pacOut)
{
	char * pcPos=*pacOut;
	int iNum;
	int iRet=0;
	if(sscanf(acIn,"%2d",&iNum)==1)
	{
		iRet=sprintf(pcPos,"%c",'a'+iNum);
	}
	*pacOut+=iRet;
	return iRet;
}

int iLetter2Number(char * acIn,char ** pacOut)
{
	char * pcPos=*pacOut;
	char cNum;
	int iRet=0;
	acIn++; //?????
	if((acIn[0]>='a')&&(acIn[0]<='i'))
	{
		if(sscanf(acIn,"%c",&cNum)==1)
		{
			iRet=sprintf(pcPos,"%d",cNum-'a');
		}
	}
	*pacOut+=iRet;
	return iRet;
}


int iGet(char * acIn,char ** pacOut)
{
	char * pcPos=*pacOut;

	char acChar[255];
	int iRet=0;
	//printf("%s\n",acIn);
	if(sscanf(acIn,"%s",acChar)==1)
	{
		iRet=sprintf(pcPos,"%s",acChar);
	}

	*pacOut+=iRet;
	return iRet;
}


int iDecAscii(char * acIn,char ** pacOut)
{

	char * pcPos=*pacOut;

	int iNum;
	int iRet=0;
	if(sscanf(acIn,"%d",&iNum)==1)
	{
		iRet=sprintf(pcPos,"%c",iNum);
	}

	*pacOut+=iRet;
	return iRet;
}

int iHexAscii(char * acIn,char ** pacOut)
{
	char * pcPos=*pacOut;

	int iNum;
	int iRet=0;
	if(sscanf(acIn,"%x",&iNum)==1)
	{
		iRet=sprintf(pcPos,"%c",iNum);
	}

	*pacOut+=iRet;
	return iRet;
}


int iAddPad(char ** pacOut)
{
	char * pcPos=*pacOut;
	int iRet=1;
	*pcPos=PAD;
	*pacOut+=iRet;
	return iRet;
}


int iGetNewPos(char ** ppcPosIn)
{
	char * pcPos=*ppcPosIn;
	int iRet=1;
	pcPos++;
	pcPos = strchr(pcPos, PAD);
	*ppcPosIn=pcPos;
	return iRet;
}

void vReverse(char * acCode,char * acDeCode,int iLen)
{
	int i,iIndex;
	for(i=iLen,iIndex=0;i;i--,iIndex++)
	{
		acDeCode[iIndex]=acCode[i-1];
	}
	acDeCode[iIndex]='\0';
}
void vAlpha2Num(char * acCode,char * acDeCode,int iLen)
{
	int iIndex;
	for(iIndex=0;iIndex<iLen;iIndex++)
	{
		acDeCode[iIndex]=acCode[iIndex];
		if((acCode[iIndex]<='i')&&(acCode[iIndex]>='a'))
		{
			acDeCode[iIndex]='0'+acCode[iIndex]-'a'+1;
		}
	}
	acDeCode[iIndex]='\0';
}
