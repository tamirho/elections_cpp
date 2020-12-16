//
//  DividedDistrict.h
//  cpp_elections
//
//  Created by Yuval  Yakovskind  on 16/12/2020.
//  Copyright © 2020 Tamir Houri 205668627 & Yuval Yakovskind 316550524. All rights reserved.
//

#pragma once
#include "District.h"

namespace elections {

class DividedDistrict : public District {
private:
    PersonList _winnerCandidatesList;
public:
    DividedDistrict(String name, int numberOfCandidates);
    ~DividedDistrict();
    DividedDistrict(const DividedDistrict&);
    
    const PersonList& getWinnerCandidatesList() const { return _winnerCandidatesList; }
    
    virtual const DynamicArray& evalPartition();

};


}