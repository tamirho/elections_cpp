#include "PartyArray.h"
#include <iostream>
using namespace std;


PartyArray::PartyArray(int size) :
	_arr(new Party*[size]), _logSize(size), _pysSize(size){
}

PartyArray::~PartyArray() {
	for (int i = 0; i < _logSize; i++)
	{
		delete _arr[i];
	}
	delete[] _arr;
}
bool PartyArray::resize(int new_size) {
	Party** temp = new Party*[new_size];

	int copy = _logSize <= new_size ? _logSize : new_size;
	for (int i = 0; i < copy; ++i)
		temp[i] = _arr[i];

	for (int j = copy; j < _logSize; j++) {
		delete _arr[j];
	}

	delete[] _arr;
	_arr = temp;
	this->_pysSize = new_size;
	return true;
}

Party& PartyArray::get(int id) {
	check_valid_idx(id - 1);
	return *_arr[id - 1];
}

bool PartyArray::set(int idx, Party* d) {
	if (check_valid_idx(idx)) {
		_arr[idx] = d;
		return true;
	}
	return false;
}

const Party& PartyArray::add(const Party& d) {
	if (_logSize == _pysSize) {
		resize(_logSize * 2 + 1);
	}

	_arr[_logSize] = new Party(d);
	++_logSize;
	return *_arr[_logSize - 1];
}

bool PartyArray::setLength(int new_size) {
	if (new_size > _pysSize) {
		resize(new_size);
	}
	_logSize = new_size;
	return true;
}

Party& PartyArray::operator[](int idx) {
	check_valid_idx(idx);
	return *_arr[idx];
}

const Party& PartyArray::operator[](int idx) const {
	check_valid_idx(idx);
	return *_arr[idx];
}

void PartyArray::print() const {
	for (int i = 0; i < _logSize; i++)
	{
		cout << *_arr[i] << endl;
		cout << _arr[i]->get_candidates_array() << endl;
	}
}

bool PartyArray::addDistrictToParty() {
	for (int i = 0; i < _logSize; i++)
	{
		_arr[i]->addDistrictToCandidatesArr();
	}
	return true;
}

bool PartyArray::checkValidIdx(int idx) const {
	if (idx >= _logSize || idx < 0) {
		exit(1); // index error
	}
	return true;
}



void PartyArray::merge(Party** arr, int l, int m, int r)
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


void PartyArray::mergeSort(Party** arr,int l,int r){
    if(l >= r){
        return;//returns recursively
    }
    int m = (l+r-1)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

