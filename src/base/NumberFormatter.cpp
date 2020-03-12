/* ES40 emulator.
 * Copyright (C) 2007-2008 by the ES40 Emulator Project
 *
 * WWW    : http://www.es40.org
 * E-mail : camiel@es40.org
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 * 
 * Although this is not required, the author would appreciate being notified of, 
 * and receiving any modifications you may make to the source code that might serve
 * the general public.
 *
 * Parts of this file based upon the Poco C++ Libraries, which is Copyright (C) 
 * 2004-2006, Applied Informatics Software Engineering GmbH. and Contributors.
 */

/**
 * $Id: NumberFormatter.cpp,v 1.1 2008/05/31 15:47:24 iamcamiel Exp $
 *
 * X-1.1        Camiel Vanderhoeven                             31-MAY-2008
 *      Initial version for ES40 emulator.
 **/

//
// NumberFormatter.cpp
//
// $Id: NumberFormatter.cpp,v 1.1 2008/05/31 15:47:24 iamcamiel Exp $
//
// Library: Foundation
// Package: Core
// Module:  NumberFormatter
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
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


#include "NumberFormatter.h"
#include <cstdio>
#include <cctype>


#if defined(_MSC_VER)
	#define I64_FMT "I64"
#elif defined(__APPLE__) 
	#define I64_FMT "q"
#else
	#define I64_FMT "ll"
#endif


std::string CNumberFormatter::format(int value)
{
	char buffer[64];
	std::sprintf(buffer, "%d", value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*d", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format0(int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*d", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(int value)
{
	char buffer[64];
	std::sprintf(buffer, "%X", value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*X", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(unsigned value)
{
	char buffer[64];
	std::sprintf(buffer, "%u", value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(unsigned value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*u", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format0(unsigned int value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*u", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(unsigned value)
{
	char buffer[64];
	std::sprintf(buffer, "%X", value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(unsigned value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*X", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(long value)
{
	char buffer[64];
	std::sprintf(buffer, "%ld", value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*ld", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format0(long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*ld", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(long value)
{
	char buffer[64];
	std::sprintf(buffer, "%lX", value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*lX", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(unsigned long value)
{
	char buffer[64];
	std::sprintf(buffer, "%lu", value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*lu", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format0(unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*lu", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(unsigned long value)
{
	char buffer[64];
	std::sprintf(buffer, "%lX", value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(unsigned long value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*lX", width, value);
	return std::string(buffer);
}


#if defined(POCO_HAVE_INT64) && !defined(POCO_LONG_IS_64_BIT)


std::string CNumberFormatter::format(Int64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"d", value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*"I64_FMT"d", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format0(Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"d", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(Int64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"X", value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(Int64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"X", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(UInt64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"u", value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%*"I64_FMT"u", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format0(UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"u", width, value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(UInt64 value)
{
	char buffer[64];
	std::sprintf(buffer, "%"I64_FMT"X", value);
	return std::string(buffer);
}


std::string CNumberFormatter::formatHex(UInt64 value, int width)
{
	poco_assert (width > 0 && width < 64);

	char buffer[64];
	std::sprintf(buffer, "%0*"I64_FMT"X", width, value);
	return std::string(buffer);
}


#endif // defined(POCO_HAVE_INT64) && !defined(POCO_LONG_IS_64_BIT)


std::string CNumberFormatter::format(float value)
{
	char buffer[64];
	std::sprintf(buffer, "%.*g", 10, (double) value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(double value)
{
	char buffer[64];
	std::sprintf(buffer, "%.*g", 20, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(double value, int precision)
{
	poco_assert (precision >= 0 && precision < 32);

	char buffer[64];
	std::sprintf(buffer, "%.*f", precision, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(double value, int width, int precision)
{
	poco_assert (width > 0 && width < 64 && precision >= 0 && precision < width);

	char buffer[64];
	std::sprintf(buffer, "%*.*f", width, precision, value);
	return std::string(buffer);
}


std::string CNumberFormatter::format(const void* ptr)
{
	char buffer[24];
#if defined(POCO_PTR_IS_64_BIT)
	std::sprintf(buffer, "%016" I64_FMT "X", (UIntPtr) ptr);
#else
	std::sprintf(buffer, "%08lX", (UIntPtr) ptr);
#endif
	return std::string(buffer);
}

