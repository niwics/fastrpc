/*
 * FastRPC -- Fast RPC library compatible with XML-RPC
 * Copyright (C) 2005-7  Seznam.cz, a.s.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Seznam.cz, a.s.
 * Radlicka 2, Praha 5, 15000, Czech Republic
 * http://www.seznam.cz, mailto:fastrpc@firma.seznam.cz
 *
 * $Id: pythonfeeder.h,v 1.4 2011-02-16 12:04:07 volca Exp $
 *
 * AUTHOR      Vaclav Blazek <blazek@firma.seznam.cz>
 *
 * DESCRIPTION
 * Python FastRPC support. Python data feeder.
 *
 * HISTORY
 *      2006-05-24 (vasek)
 *              Created
 */


#ifndef PYTHONFEEDER_H_
#define PYTHONFEEDER_H_

// Included first to get rid of the _POSIX_C_SOURCE warning
#include <Python.h>

#include <string>
#include <vector>

#include <frpcmarshaller.h>

namespace FRPC { namespace Python {

class  Feeder_t {
public:
    Feeder_t(FRPC::Marshaller_t *marshaller,const std::string &encoding)
            :marshaller(marshaller), encoding(encoding)
    {}

    void feed(PyObject *args);
    void feedValue(PyObject *value);

private:
    Feeder_t();
    FRPC::Marshaller_t *marshaller;
    const std::string encoding;
};

} } // namespace FRPC::Python

#endif // PYTHONFEEDER_H_
