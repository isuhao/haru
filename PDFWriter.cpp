#include "stdafx.h"
#include "PDFWriter.h"
#include "common.h"


CPDFWriter::CPDFWriter()
{
	m_document = HPDF_New(ErrorHandlerHook, m_document);
	if (!m_document) {
		std::cout << "Fail create PDF";

	}
}


CPDFWriter::~CPDFWriter()
{
	HPDF_Free(m_document);
}

void CPDFWriter::HandleError(HPDF_STATUS error_no, HPDF_STATUS detail_no)
{
	std::cout << "ERROR: error_no=" << error_no << ", detail_no=" << detail_no << std::endl;
}

void __stdcall ErrorHandlerHook(HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data)
{
	((CPDFWriter*)user_data)->HandleError(error_no, detail_no);
}
