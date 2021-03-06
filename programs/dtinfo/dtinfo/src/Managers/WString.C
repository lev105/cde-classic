// $XConsortium: WString.C /main/4 1996/08/23 20:43:08 cde-hal $
/*	Copyright (c) 1995,1996 FUJITSU LIMITED		*/
/*	All Rights Reserved				*/

#include "WString.hh"

#include <stdlib.h>
#include <string.h>

static wchar_t defwstring[] = { (wchar_t)'\0' };

WString::WString() : f_wstringrep(NULL)
{
    set_wstring(new WStringRep(defwstring, 0));
}

WString::WString(const wchar_t* wstr, int claimed_length) : f_wstringrep(NULL)
{
    if (wstr)
    {
	int length;

	if (claimed_length >= 0)
	    length = claimed_length;
	else
	    length = wcslen(wstr);

	set_wstring(new WStringRep(wstr, length));
    }
    else
	set_wstring(new WStringRep(defwstring, 0));
}

WString::WString(const char *str, int claimed_length) : f_wstringrep(NULL)
{
    if (str) {
	int length;
	if (claimed_length >= 0)
	    length = claimed_length;
	else
	    length = strlen(str);

	char* charbuf = new char[length + 1];
	memcpy(charbuf, str, length);
	charbuf[length] = '\0';

	wchar_t* wcharbuf = new wchar_t[length + 1];
	
	int wlength;
	if ((wlength = mbstowcs(wcharbuf, str, length + 1)) < 0) {
	    set_wstring(new WStringRep(defwstring, 0));
	}
	else {
	    set_wstring(new WStringRep(wcharbuf, wlength));
	}
	delete[] wcharbuf;
	delete[] charbuf;
    }
    else
	set_wstring(new WStringRep(defwstring, 0));
}

WString::WString(const WString& sample) : f_wstringrep(NULL)
{
    set_wstring(sample.f_wstringrep);
}

void
WString::set_wstring(WStringRep* wstringrep)
{
    wstringrep->incref();
    unset_wstring();
    f_wstringrep = wstringrep;
}

void
WString::unset_wstring()
{
    if (f_wstringrep) {
	f_wstringrep->decref();
	f_wstringrep = NULL;
    }
}

WString::~WString()
{
    unset_wstring();
}

WString&
WString::operator=(const WString& sample)
{
    unset_wstring();
    set_wstring(sample.f_wstringrep);

    return *this;
}

WString::operator wchar_t*() const {
    return f_wstringrep->f_data;
}

int
WString::length() const {
    return f_wstringrep->f_length;
}

char*
WString::get_mbstr()
{
    int   buffer_size = MB_CUR_MAX * f_wstringrep->f_length + 1;
    char* buffer      = new char[buffer_size];

    if (wcstombs(buffer, f_wstringrep->f_data, buffer_size) < 0)
	*buffer = 0;

    return buffer;
}

wchar_t*
WString::get_wstr()
{
    wchar_t* buffer = new wchar_t[f_wstringrep->f_length + 1];
    memcpy(buffer, f_wstringrep->f_data,
			f_wstringrep->f_length * sizeof(wchar_t));
    buffer[f_wstringrep->f_length] = (wchar_t)'\0';

    return buffer;
}
