#ifndef UTIL_H_
#define UTIL_H_

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
template <typename T>
ostream& operator<< (ostream& out, const vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    copy (v.begin(), v.end(), ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}

#endif