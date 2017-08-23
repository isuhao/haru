#pragma once
#include "Writer.h"
#include "hpdf.h"
EXTERN_C {
void __stdcall ErrorHandlerHook(HPDF_STATUS error_no, HPDF_STATUS detail_no, void* user_data);
}

class CPDFWriter :
	public CWriter
{
public:
	CPDFWriter();
	virtual ~CPDFWriter();
	void HandleError(HPDF_STATUS error_no, HPDF_STATUS detail_no);

	private:
	HPDF_Doc m_document;
};

