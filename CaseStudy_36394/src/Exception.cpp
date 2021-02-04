/*
 * Exception.cpp
 *
 *  Created on: 19-Aug-2020
 *      Author: sunbeam
 */

#include "../include/Exception.h"

namespace kd3 {

Exception::Exception(string massage) {
	this->massage=massage;

}

const string& Exception::getMassage() const
{
	return massage;
}

void Exception::setMassage(const string& massage) {
	this->massage = massage;
}

Exception::~Exception() {
}

} /* namespace kd3 */
