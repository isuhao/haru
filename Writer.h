#pragma once


class CWriter
{
public:
	CWriter();
	virtual ~CWriter();
	virtual void Open() = 0;
	virtual void Error() = 0;

};

