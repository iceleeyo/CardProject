/* soapClient.cpp
   Generated by gSOAP 2.7.17 from CardClientProc.h
   Copyright(C) 2000-2010, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.7.17 2011-09-21 11:45:19 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__CardRegisger(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string *pRegXML, std::string &strRetXML)
{	struct ns__CardRegisger soap_tmp_ns__CardRegisger;
	struct ns__CardRegisgerResponse *soap_tmp_ns__CardRegisgerResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost";
	soap->encodingStyle = "";
	soap_tmp_ns__CardRegisger.pRegXML = pRegXML;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__CardRegisger(soap, &soap_tmp_ns__CardRegisger);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__CardRegisger(soap, &soap_tmp_ns__CardRegisger, "ns:CardRegisger", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__CardRegisger(soap, &soap_tmp_ns__CardRegisger, "ns:CardRegisger", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&strRetXML)
		return soap_closesock(soap);
	soap_default_std__string(soap, &strRetXML);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__CardRegisgerResponse = soap_get_ns__CardRegisgerResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	strRetXML = soap_tmp_ns__CardRegisgerResponse->strRetXML;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__CardCheck(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string *pRegXML, std::string &strRetXML)
{	struct ns__CardCheck soap_tmp_ns__CardCheck;
	struct ns__CardCheckResponse *soap_tmp_ns__CardCheckResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost";
	soap->encodingStyle = "";
	soap_tmp_ns__CardCheck.pRegXML = pRegXML;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__CardCheck(soap, &soap_tmp_ns__CardCheck);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__CardCheck(soap, &soap_tmp_ns__CardCheck, "ns:CardCheck", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__CardCheck(soap, &soap_tmp_ns__CardCheck, "ns:CardCheck", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&strRetXML)
		return soap_closesock(soap);
	soap_default_std__string(soap, &strRetXML);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__CardCheckResponse = soap_get_ns__CardCheckResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	strRetXML = soap_tmp_ns__CardCheckResponse->strRetXML;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__CardCheckForNH(struct soap *soap, const char *soap_endpoint, const char *soap_action, std::string *pRegXML, std::string &strRetXML)
{	struct ns__CardCheckForNH soap_tmp_ns__CardCheckForNH;
	struct ns__CardCheckForNHResponse *soap_tmp_ns__CardCheckForNHResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://localhost";
	soap->encodingStyle = "";
	soap_tmp_ns__CardCheckForNH.pRegXML = pRegXML;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__CardCheckForNH(soap, &soap_tmp_ns__CardCheckForNH);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__CardCheckForNH(soap, &soap_tmp_ns__CardCheckForNH, "ns:CardCheckForNH", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__CardCheckForNH(soap, &soap_tmp_ns__CardCheckForNH, "ns:CardCheckForNH", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!&strRetXML)
		return soap_closesock(soap);
	soap_default_std__string(soap, &strRetXML);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__CardCheckForNHResponse = soap_get_ns__CardCheckForNHResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	strRetXML = soap_tmp_ns__CardCheckForNHResponse->strRetXML;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */