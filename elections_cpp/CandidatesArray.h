#pragma once
#include "PersonList.h"

class CandidatesArray
{
	// A Dynamic Array of PersonList Pointers.
	// Used to store lists of candidates by division into districts (index in the array)

private:
	PersonList** _arr;
	int _log_size;
	int _pys_size;
	
	void resize(int new_size);
	void check_valid_idx(int idx) const;
public:
	CandidatesArray(int size = 0);
	CandidatesArray(const CandidatesArray&) = delete;
	~CandidatesArray();

	// return list of candidates according to the district id received
	// Notice: get(1) return PersonList No.1
	PersonList& get(int district_id); 

	// add empty list to the next empty cell
	void add();

	int get_length() const { return _log_size; }
	void set_length(int new_size);

	// return list of candidates according to the index received
	// Notice: arr[0] = PersonList No.1
	PersonList& operator[](int idx);
	const PersonList& operator[](int idx) const;

	friend std::ostream& operator<<(std::ostream& os, const CandidatesArray& c_arr);
};
