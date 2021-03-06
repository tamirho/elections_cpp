#pragma once
#include <string>
#include <vector>
#include <tuple>

#include "List.h"
#include "PersonPtr.h"
#include "File_Handler.h"

namespace elections {
class District;

class Party
{
	// A class representing a Party in the elections

	using PersonList = mySTL::List<PersonPtr>;
	using DistrictTuple = std::tuple<const District*, PersonList>;
	using CandidatesArray = std::vector<DistrictTuple>;

private:
	int					_id;
	std::string			_name;
    PersonPtr		    _firstCandidate;
	int					_totalCandidates,
						_totalVotes;
	CandidatesArray		_candidates;
	
	void saveCandidatesArray(std::ostream& out) const;

public:
	static int totalParties;

	Party(const std::string& name, PersonPtr candidate);
	Party(const Party& p);
	Party(std::istream& in, std::string& firstCandidateID);
	~Party();

	int getId() const { return _id; }
	const std::string& getName() const { return _name; }
	CandidatesArray& getCandidatesArray() { return _candidates; }
	const CandidatesArray& getCandidatesArray() const { return _candidates; }
	PersonList& getCandidateList(int district_id);
	const PersonList& getCandidateList(int district_id) const;
	PersonPtr getCandidatePtr() { return _firstCandidate; }
	Person& getCandidate() { return *_firstCandidate; }
    const Person& getCandidate() const { return *_firstCandidate; }
    int getTotalCandidates() const { return _totalCandidates; }
    int getTotalVotes() const { return _totalVotes; }

	void setName(const std::string& name);
	void setId(int id);
    void setTotalCandidates(int val);
    void setFirstCandidate(PersonPtr candidate);

	// add value to the total number of candidates the party get in the elections 
	void addTotalCandidates(int val) { _totalCandidates += val; }
	void addTotalVotes(int val) { _totalVotes += val; }

    void load(std::istream& in , std::string& firstCandidateID);
	void save(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& os, const Party& p);
};

}
