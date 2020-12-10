#include "District.h"
#include "Party.h"
#include "Person.h"
#include <ostream>
using namespace std;



Person::Person(const String& name, int id, int year, const District& district) :
	_name(name), _id(id), _birth_year(year), _district(district),
	_vote(nullptr), _is_candidate(nullptr)
{
}

Person::Person(const Person& p) :
	_name(p._name), _id(p._id), _birth_year(p._birth_year), _district(p._district),
	_vote(p._vote), _is_candidate(p._is_candidate)
{
}

Person::~Person(){
}

int Person::getDistrictID() const
{
	return _district.get_id();
}

bool Person::setAsCandidate(const Party* p)
{
	_is_candidate = p;
	return true;
}
bool Person::isCandidate() const
{
	return _is_candidate != nullptr;
}

bool Person::isVoted() const
{
	return _vote != nullptr;
}
bool Person::setVote(const Party* p)
{
	if (!isVoted()) {
		_vote = p;
		return true;
	}
	return false;
}

ostream& operator<<(ostream& os, const Person& p) {
    os << "Person Name: " << p.getName() << " | ID: " << p.getID() << " | District: " << p.getDistrictID();
    return os;
}
