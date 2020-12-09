#include "Party.h"

int Party::total_parties = 0;

Party::Party(const String& name, const Person& candidate) :
	_id(++total_parties), _name(name), _first_candidate(candidate)
{
}

Party::Party(const Party& p) :
	_id(p._id), _name(p._name), _first_candidate(p._first_candidate), 
	_total_candidates(p._total_candidates) , _total_votes(p._total_votes),
	_candidates(District::total_districts) 
{
}

Party::~Party() {
	
}

int Party::get_candidate_id() const
{
	return _first_candidate.getID();
}

void Party::add_candidate(PersonPtr p, int district_id) {
	_candidates.get(district_id).addPerson(p);
}


ostream& operator<<(ostream& os, const Party& p) {
	os << "Party ID: " << p._id << " | Name: " << p._name << " | First candidate ID: " << p._first_candidate.getID();
	return os;
}

void Party::add_district_to_candidates_arr()
{
	_candidates.add();
}

void Party::merge(Party** arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int i, j;
	Party** L = new Party*[n1];
	Party** R = new Party*[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    int k = l;
    i = j = 0;

    while (i < n1 && j < n2) {
        if (L[i]->get_total_candidates() >= R[j]->get_total_candidates())
        {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

	delete[] L;
	delete[] R;
}


void Party::mergeSort(Party** arr,int l,int r){
    if(l >= r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


