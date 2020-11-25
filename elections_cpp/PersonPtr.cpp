////
////  PersonPtr.cpp
////  cpp_elections
////
////  Created by Yuval  Yakovskind  on 25/11/2020.
////  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
////
//
//#include "PersonPtr.h"
//
//PersonPtr::PersonPtr(const String& name, int idnum, int year, int district_num) :
//_p(new Person(name, idnum, year, district_num)), _r(new int(1))
//{
//}
//
//PersonPtr::PersonPtr(const PersonPtr& other) : _p(other._p), _r(other._r)
//{
//    ++*_r;
//}
//
//PersonPtr::PersonPtr(Person* pnt) : _p(pnt), _r(new int(1))
//{
//}
//
//PersonPtr::~PersonPtr()
//{
//    release();
//}
//
//void PersonPtr::release()
//{
//    --*_r;
//
//    if (_r == 0) {
//        delete _r;
//        delete _p;
//    }
//}
//
//PersonPtr& PersonPtr::operator=(PersonPtr& other)
//{
//
//    if (this != &other) {
//        release();
//        
//        _p = other._p;
//        _r = other._r;
//
//        ++*_r;
//    }
//    return *this;
//}
//
