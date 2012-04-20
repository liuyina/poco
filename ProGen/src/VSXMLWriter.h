//
// VSXMLWriter.h
//
// $Id: //poco/1.4/ProGen/src/VSXMLWriter.h#1 $
//
// Definition of the VSXMLWriter class.
//
// Copyright (c) 2010, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef VSXMLWriter_INCLUDED
#define VSXMLWriter_INCLUDED


#include "Poco/XML/XML.h"
#include "Poco/SAX/ContentHandler.h"
#include "Poco/SAX/Locator.h"
#include "Poco/SAX/Attributes.h"
#include "Poco/XML/XMLString.h"
#include <vector>
#include <ostream>


class VSXMLWriter: public Poco::XML::ContentHandler
{
public:
	VSXMLWriter(std::ostream& ostr, bool convertBool);
	~VSXMLWriter();
		
	// ContentHandler
	void setDocumentLocator(const Poco::XML::Locator* loc);
	void startDocument();
	void endDocument();
	void startFragment();
	void endFragment();
	void startElement(const Poco::XML::XMLString& namespaceURI, const Poco::XML::XMLString& localName, const Poco::XML::XMLString& qname, const Poco::XML::Attributes& attributes);
	void endElement(const Poco::XML::XMLString& namespaceURI, const Poco::XML::XMLString& localName, const Poco::XML::XMLString& qname);
	void characters(const Poco::XML::XMLChar ch[], int start, int length);
	void ignorableWhitespace(const Poco::XML::XMLChar ch[], int start, int length);
	void processingInstruction(const Poco::XML::XMLString& target, const Poco::XML::XMLString& data);
	void startPrefixMapping(const Poco::XML::XMLString& prefix, const Poco::XML::XMLString& namespaceURI);
	void endPrefixMapping(const Poco::XML::XMLString& prefix);
	void skippedEntity(const Poco::XML::XMLString& name);

protected:
	void indent();

private:
	std::ostream& _ostr;
	bool _convertBool;
	int _indent;
	std::vector<bool> _tagClosed;
};


#endif // VSXMLWriter_INCLUDED
