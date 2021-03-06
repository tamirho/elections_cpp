//
//  PersonPtr.cpp
//  cpp_elections
//
//  Created by Yuval  Yakovskind  on 25/11/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#include "PersonPtr.h"
#include <iostream>

using namespace std;

namespace elections {

PersonPtr::PersonPtr() : _p(nullptr), _r(nullptr) {}

PersonPtr::PersonPtr(const string& name,const std::string& id, int year, const District* district) : PersonPtr()
{
    try {
        _p = new Person(name, id, year, district);
        _r = new int(1);
    }
    catch (...) {
        if (_p) delete _p;
        throw;
    }
}

PersonPtr::PersonPtr(const PersonPtr& other) : _p(other._p), _r(other._r)
{
    ++*_r;
}

PersonPtr::PersonPtr(Person* pnt) : _p(pnt), _r(new int(1))
{
}

PersonPtr::~PersonPtr()
{
    release();
}

void PersonPtr::release()
{
	if (_r) {
		--*_r;
		if (*_r == 0) {
			delete _r;
			delete _p;
		}
	}
}

PersonPtr& PersonPtr::operator=(const PersonPtr& other) {

    if (this != &other) {
        if (_r != nullptr)
            release();

        _p = other._p;
        _r = other._r;

        ++*_r;
    }
    return *this;
}


bool PersonPtr::operator==(PersonPtr pnt) const
{
    return _p == pnt._p;
}

bool PersonPtr::operator!=(PersonPtr pnt) const
{
    return _p != pnt._p;
}


std::ostream& operator<<(std::ostream& os, const PersonPtr& p) {
	os << *p;
	return os;
}

}
