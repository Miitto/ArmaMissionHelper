#include "cHelpers.h"

int cHelpers::toInt(wxString str, int dflt)
{
	long value;
	if (!str.ToLong(&value))  return dflt;
	return static_cast<int>(value);
}

