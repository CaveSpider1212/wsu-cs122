/*
* Programmer: Aabhwan Adhikary
* Class: CptS 122, Spring 2025; Lab Section 9
* Assignment: PA 5
* Created: 3/3/2025
* Description: This file contains the function definitions for the Data class.
*/

#include "Data.hpp"




/*
* Function name: Data::Data()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: This is a constructor for the Data class, called when a Data object is created with the parameters customerNum, servTime,
*				and totTime. It sets the customerNumber, serviceTime, and totalTime fields of the class to the parameters, respectively.
* Input parameters: int customerNum, an integer representing the number of the customer; int servTime, an integer representing the
*					service time of the customer; int totTime, an integer representing the total time the customer needs to wait in line
* Returns: none
*/
Data::Data(int customerNum, int servTime, int totTime)
{
	this->customerNumber = customerNum;
	this->serviceTime = servTime;
	this->totalTime = totTime;
}




/*
* Function name: Data::getCustomerNumber()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: Getter function for customerNumber
* Input parameters: none
* Returns: int customerNumber
*/
int Data::getCustomerNumber()
{
	return customerNumber;
}




/*
* Function name: Data::getServiceTime()
* Programmer: Aabhwan Adhikary
* Created: 3/4/2025
* Description: Getter function for serviceTime
* Input parameters: none
* Returns: int serviceTime
*/
int Data::getServiceTime()
{
	return serviceTime;
}




/*
* Function name: Data::getTotalTime()
* Programmer: Aabhwan Adhikary
* Created: 3/8/2025
* Description: Getter function for totalTime
* Input parameters: none
* Returns: int totalTime
*/
int Data::getTotalTime()
{
	return totalTime;
}




/*
* Function name: Data::setServiceTime()
* Programmer: Aabhwan Adhikary
* Created: 3/8/2025
* Description: Setter function for serviceTime
* Input parameters: int newTime, the new serviceTime value
* Returns: none
*/
void Data::setServiceTime(int newTime)
{
	serviceTime = newTime;
}




/*
* Function name: operator <<
* Programmer: Aabhwan Adhikary
* Created: 3/5/2025
* Description: Overloads the string extraction operator when used with a Data object, printing out the values of the Data object
* Input parameters: ostream &lhs, a reference to the output stream; Data *rhs, a pointer to a Data object whose values will be
*					printed to the screen
* Returns: ostream &lhs, the output stream
*/
ostream& operator<<(ostream& lhs, Data* rhs)
{
	lhs << "Customer number: " << (*rhs).getCustomerNumber() << "; Service time: " << (*rhs).getServiceTime() << "; Total time in line: " << (*rhs).getTotalTime();
	return lhs;
}
