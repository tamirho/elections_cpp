#include "District.h"
#include "Party.h"
#include "Person.h"
#include "StringLoader.h"

using namespace std;

namespace elections {


Person::Person(const string& name,const string& id, int year, const District* district) :
_name(name), _birthYear(year), _district(district),
_vote(nullptr), _isCandidate(nullptr)
{
    setId(id);
}

Person::Person(const Person& p) :
_name(p._name), _id(p._id), _birthYear(p._birthYear), _district(p._district),
_vote(p._vote), _isCandidate(p._isCandidate)
{
}

Person::Person(istream& in) :
_district(nullptr), _vote(nullptr), _isCandidate(nullptr)
{
    load(in);
}

Person::Person(istream& in, int& districtID, int& vote, int& candidate) :
_district(nullptr), _vote(nullptr), _isCandidate(nullptr)
{
    load(in);
    in.read(rcastc(&districtID), sizeof(districtID));
    in.read(rcastc(&vote), sizeof(vote));
    in.read(rcastc(&candidate), sizeof(candidate));
	if (!in.good()) throw File_Error("Unable to read from file");
}

Person::~Person() {
}

void Person::setName(const string& name) {
    _name = name;
}

void Person::setId(const string& id) {
    if (id.length() != ID_SIZE) {
        throw invalid_argument("Invalid ID");
    }
    
    for (auto ch : id) {
        if (ch > '9' || ch < '0')
            throw invalid_argument("Invalid ID");
    }    
    _id = id;
}
void Person::setBirthYear(int birthYear) {
    _birthYear = birthYear;
}

void Person::setDistrict(const District* district) {
    _district = district;
}

int Person::getDistrictID() const
{
    int id = _district->getId();
    return id;
}

void Person::setAsCandidate(const Party* p)
{
    if(_isCandidate)
        throw invalid_argument("This person is already candidate of a party");
    
    _isCandidate = p;
}

bool Person::isVoted() const
{
    return _vote != nullptr;
}

void Person::setVote(const Party* p)
{
    if (isVoted()) {
        throw invalid_argument("This person already voted");
    }
    _vote = p;

}

ostream& operator<<(ostream& os, const Person& p) {
    os << "Person Name: " << p.getName() << " | ID: " << p.getID() << " | District: " << p.getDistrictID();
    return os;
}

void Person::load(std::istream& in) {
    string id = StringLoader::load(in);
    setId(id);
    _name = StringLoader::load(in);
    in.read(rcastc(&_birthYear), sizeof(_birthYear));
	if (!in.good()) throw File_Error("Unable to read from file");
}

void Person::save(std::ostream& out) const {
    int district, vote = 0, candidate = 0;
    
    district = _district->getId();
    if (isVoted())
        vote = _vote->getId();
    
    if (_isCandidate)
        candidate = _isCandidate->getId();
    
    StringLoader::save(out, _id);
    StringLoader::save(out, _name);
    out.write(rcastcc(&_birthYear), sizeof(_birthYear));
    out.write(rcastcc(&district), sizeof(district));
    out.write(rcastcc(&vote), sizeof(vote));
    out.write(rcastcc(&candidate), sizeof(candidate));
	if (!out.good()) throw File_Error("Unable to write to file");
}
}
