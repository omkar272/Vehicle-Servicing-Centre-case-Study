/*
 * Exception.h
 *
 *  Created on: 19-Aug-2020
 *      Author: sunbeam
 */
#include<iostream>
using namespace std;
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

namespace kd3 {

class Exception {
	string massage;
public:
	Exception(string massage);
	~Exception();
	const string& getMassage() const;
	void setMassage(const string& massage);
};

} /* namespace kd3 */

#endif /* EXCEPTION_H_ */
