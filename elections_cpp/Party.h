#pragma once
#include "String.h"
#include "CandidatesArray.h"

namespace elections {
class District;

class Party
{
	// A class representing a Party in the elections

private:
	int					_id;
	String				_name;
    PersonPtr		    _firstCandidate;
	int					_totalCandidates,
						_totalVotes;
	CandidatesArray		_candidates;
	
public:
	static int totalParties;

	Party(const String& name, PersonPtr candidate);
	Party(const Party& p);
	Party(std::istream& in, int& firstCandidateID);
	~Party();

	int getId() const { return _id; }
	const String& getName() const { return _name; }
	CandidatesArray& getCandidatesArray() { return _candidates; }
	const CandidatesArray& getCandidatesArray() const { return _candidates; }
	PersonPtr getCandidatePtr() { return _firstCandidate; }
	Person& getCandidate() { return *_firstCandidate; }
    const Person& getCandidate() const { return *_firstCandidate; }
    int getTotalCandidates() const { return _totalCandidates; }
    int getTotalVotes() const { return _totalVotes; }

	bool setName(const String& name);
	bool setId(int id);
    bool setTotalCandidates(int val);
    bool setFirstCandidate(PersonPtr candidate);

	// add value to the total number of candidates the party get in the elections 
	void addTotalCandidates(int val) { _totalCandidates += val; }
	void addTotalVotes(int val) { _totalVotes += val; }

	bool load(std::istream& in , int& firstCandidateID);
	bool save(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& os, const Party& p);
};

}
