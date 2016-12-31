#include <iostream>
#include <string>
#include <sstream> // split string
#include <cstdio> // printf
#include <cstdlib> // atoi
#include <fstream> // save load
#include <iomanip> // setprecision
#include "LinkedList.h"
using namespace std;

int stringtoint(string a) // convert string to integer
{
    int b;
    if(atoi(a.c_str())) // set integer to 0 if string is not numeric
        b = atoi(a.c_str());
    else
        b = 0;
    return b;
}

string to_string(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

class Date
{
	int year;
	int month;
	int day;
public:
	Date(int year, int month, int day) : year(year), month(month), day(day) {}
	int getYear() { return year; }
	void setYear(int year) { this->year = year; }
	int getMonth() { return month; }
	void setMonth(int month) { this->month = month; }
	int getDay() { return day; }
	void setDay(int day) { this->day = day; }
	//friend bool operator>= (Date from, Date to);
	//friend bool operator<= (Date from, Date to);
	//friend ostream& operator<< (ostream &os, Date date);
};

bool operator>= (Date from, Date to)
{
	//cout << from.getDay() << "/" << from.getMonth() << "/" << from.getYear() << " more than " << to.getDay() << "/" << to.getMonth() << "/" << to.getYear() << endl;
	if(from.getYear() >= to.getYear())
		if(from.getMonth() >= to.getMonth())
		{
			if(from.getDay() >= to.getDay())
				return true;
			else if(from.getDay() <= to.getDay() && from.getMonth() > to.getMonth())
				return true;
		}
		else if(from.getMonth() <= to.getMonth() && from.getYear() > to.getYear())
			return true;
	return false;
}

bool operator<= (Date from, Date to)
{
	//cout << from.getDay() << "/" << from.getMonth() << "/" << from.getYear() << " less than equal " << to.getDay() << "/" << to.getMonth() << "/" << to.getYear() << endl;
	if(from.getYear() <= to.getYear())
		if(from.getMonth() <= to.getMonth())
		{
			if(from.getDay() <= to.getDay())
				return true;
			else if(from.getDay() >= to.getDay() && from.getMonth() < to.getMonth())
				return true;
		}
		else if(from.getMonth() >= to.getMonth() && from.getYear() < to.getYear())
			return true;
	return false;
}

ostream& operator<< (ostream &os, Date date)
{
	os << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
}

class Leave
{
	LinkedList<Date*> dateOfLeave;
	string staffName;
	string type;
	string reason;
	string approver;
	string status;
public:
	Leave(LinkedList<Date*> dateOfLeave, string staffName, string type, string reason) : dateOfLeave(dateOfLeave), staffName(staffName), type(type), reason(reason), status("Pending Approval") {}
	Leave(LinkedList<Date*> dateOfLeave, string staffName, string type, string reason, string approver, string status) : dateOfLeave(dateOfLeave), staffName(staffName), type(type), approver(approver), reason(reason), status(status) {}
	LinkedList<Date*> getDate() { return dateOfLeave; }
	void setDate(LinkedList<Date*> dateOfLeave) { this->dateOfLeave = dateOfLeave; }
	string getStaffName() { return staffName; }
	void setStaffName(string staffName) { this->staffName = staffName; }
	string getType() { return type; }
	void setType(string type) { this->type = type; }
	string getReason() { return reason; }
	void setReason(string reason) { this->reason = reason; }
	string getApprover() { return approver; }
	void setApprover(string approver) { this->approver = approver; } 
	string getStatus() { return status; }
	void setStatus(string status) { this->status = status; }

	int getDateLength() { return dateOfLeave.getLength(); }
	int getYear(int k) { return dateOfLeave[k]->getYear(); }
	int getMonth(int k) { return dateOfLeave[k]->getMonth(); }
	int getDay(int k) { return dateOfLeave[k]->getDay(); }

	string printDate()
	{
		string fromDay = to_string(dateOfLeave[1]->getDay());
		string fromMonth = to_string(dateOfLeave[1]->getMonth());
		string fromYear = to_string(dateOfLeave[1]->getYear());
		string toDay = to_string(dateOfLeave[dateOfLeave.getLength()]->getDay());
		string toMonth = to_string(dateOfLeave[dateOfLeave.getLength()]->getMonth());
		string toYear = to_string(dateOfLeave[dateOfLeave.getLength()]->getYear());

		string dateRange = fromDay + "/" + fromMonth + "/" + fromYear + " to " + toDay + "/" + toMonth + "/" + toYear;
		return dateRange;
	}
	void printAccordingDate()
	{
		for(int i=1; i<=dateOfLeave.getLength(); i++)
		{
			cout << dateOfLeave[i]->getDay() << "/" << dateOfLeave[i]->getMonth() << "/" << dateOfLeave[i]->getYear();
		}
	}
	string getOneDate(int j) 
	{
		string d = to_string(dateOfLeave[j]->getDay());
		string m = to_string(dateOfLeave[j]->getMonth());
		string y = to_string(dateOfLeave[j]->getYear());
		string date = d + "/" + m + "/" + y;
		return date;
	}
	string getOneDateMonth(int j) 
	{
		string m = to_string(dateOfLeave[j]->getMonth());
		string y = to_string(dateOfLeave[j]->getYear());
		string date = m + "/" + y;
		return date;
	}
};

class Staff
{
	string name;
	string staffID;
	string position;
	string category;
	string telno;
	string faculty;
	int leaveBalance;
	int maxLeave = 10; // maximum leave
	LinkedList<Leave*> leaveInfoList;
public:
	Staff(string name, string staffID, string position, string category, string telno, string faculty) : name(name), staffID(staffID), position(position), category(category), telno(telno), faculty(faculty), leaveBalance(leaveBalance) { leaveBalance=maxLeave; }
	Staff(string name, string staffID, string position, string category, string telno, string faculty, int leaveBalance) : name(name), staffID(staffID), position(position), category(category), telno(telno), faculty(faculty), leaveBalance(leaveBalance) {}
	string getName() { return name; }
	void setName(string name) { this->name = name; }
	string getStaffID() { return staffID; }
	void setStaffID(string staffID) { this->staffID = staffID; }
	string getPosition() { return position; }
	void setPosition(string position) { this->position = position; }
	string getCategory() { return category; }
	void setCategory(string category) { this->category = category; }
	string getTelno() { return telno; }
	void setTelno(string telno) { this->telno = telno; }
	string getFaculty() { return faculty; }
	void setFaculty(string faculty) { this->faculty = faculty; }
	int getLeaveBalance() { return leaveBalance; }
	void setLeaveBalance(int leaveBalance) { this->leaveBalance = leaveBalance; }

	int getLeaveCount() { return leaveInfoList.getLength(); }
	int getDateLength(int j) { leaveInfoList[j]->getDateLength(); }
	string getStaffName(int j) { return leaveInfoList[j]->getStaffName(); }
	string getType(int j) { return leaveInfoList[j]->getType(); }
	string getReason(int j) { return leaveInfoList[j]->getReason(); }
	string getApprover(int j) { return leaveInfoList[j]->getApprover(); }
	string getStatus(int j) { return leaveInfoList[j]->getStatus(); }
	int getYear(int j, int k) { return leaveInfoList[j]->getYear(k); }
	int getMonth(int j, int k) { return leaveInfoList[j]->getMonth(k); }
	int getDay(int j, int k) { return leaveInfoList[j]->getDay(k); }

	void addLeave(LinkedList<Date*> dateOfLeave, string staffName, string type, string reason)
	{
		this->leaveInfoList.insert(leaveInfoList.getLength()+1, new Leave(dateOfLeave, staffName, type, reason));
	}
	void addAllLeave(string staffName, string type, string reason, string approver, string status, LinkedList<Date*> dateOfLeave)
	{
		this->leaveInfoList.insert(leaveInfoList.getLength()+1, new Leave(dateOfLeave, staffName, type, reason, approver, status));
	}
	void deleteLeave(int dataToUpdate)
	{
		this->leaveInfoList.remove(dataToUpdate);
		if(this->leaveInfoList[dataToUpdate]->getStatus() == "Approved")
			this->leaveBalance = leaveBalance + 1;
	}
	void printAllLeaveInfo(int &leaveCounter)
	{
		for(int i=1; i<=leaveInfoList.getLength(); i++)
		{
			leaveCounter++;
			cout << setw(3) << leaveCounter << setw(20) << leaveInfoList[i]->getStaffName() << setw(30) << leaveInfoList[i]->printDate() << setw(20) << leaveInfoList[i]->getType() << setw(20) << leaveInfoList[i]->getReason() << setw(20) << leaveInfoList[i]->getApprover() << setw(20) << leaveInfoList[i]->getStatus() << endl;
		}
	}
	void updateTheData(int dataToUpdate, string dataStatus, string approver)
	{
		this->leaveInfoList[dataToUpdate]->setStatus(dataStatus);
		this->leaveInfoList[dataToUpdate]->setApprover(approver);
		if(dataStatus == "Approved")
			this->leaveBalance = leaveBalance - 1;
	}
	void printAccordingDate()
	{
		for(int i=1; i<=leaveInfoList.getLength(); i++)
		{
			this->leaveInfoList[i]->printAccordingDate();
		}
	}
	void printSatistic(int &counter)
	{
		for(int i=1; i<=leaveInfoList.getLength(); i++)
		{
			for(int j=1; j<=leaveInfoList[i]->getDateLength(); j++)
			{
				cout << setw(3) << counter << setw(20) << name << setw(30) << leaveInfoList[i]->getOneDate(j) << setw(20) << faculty << setw(20) << leaveInfoList[i]->getType() << setw(20) << leaveInfoList[i]->getReason() << setw(20) << leaveInfoList[i]->getApprover() << setw(20) << leaveInfoList[i]->getStatus() << endl;
				counter++;
			}
		}
	}
	void printSatisticByDay(int &counter, int i, int j)
	{
		cout << setw(3) << counter << setw(20) << name << setw(30) << leaveInfoList[i]->getOneDate(j) << setw(20) << faculty << setw(20) << leaveInfoList[i]->getType() << setw(20) << leaveInfoList[i]->getReason() << setw(20) << leaveInfoList[i]->getApprover() << setw(20) << leaveInfoList[i]->getStatus() << endl;
		counter++;
	}
	void printSatisticByMonth(int &counter, int i, int j)
	{
		cout << setw(3) << counter << setw(20) << name << setw(30) << leaveInfoList[i]->getOneDateMonth(j) << setw(20) << faculty << setw(20) << leaveInfoList[i]->getType() << setw(20) << leaveInfoList[i]->getReason() << setw(20) << leaveInfoList[i]->getApprover() << setw(20) << leaveInfoList[i]->getStatus() << endl;
		counter++;
	}
	int getPendingLeave()
	{
		int counter = 0;
		for(int i=1; i<=leaveInfoList.getLength(); i++)
			if(this->leaveInfoList[i]->getStatus() == "Pending Approval")
				counter++;
		return counter;
	}
};

void loadData(LinkedList<Staff*> &staffList)
{
    string wholeline, wholeline2, name, staffID, position, category, telno, faculty, leaveBalance;
    string staffName, type, reason, approver, status, day, month, year;
    int ileaveBalance;
    LinkedList<Date*> date;
    staffList.clear();

    // load staff list
    ifstream fin;
    fin.open("Staff.txt");
    if(fin.is_open())
    {
        while(getline(fin, wholeline))
        {
            istringstream ss(wholeline);
            if(wholeline.empty())
          		break;
            getline(ss, name, '\t');
            getline(ss, staffID, '\t');
            getline(ss, position, '\t');
            getline(ss, category, '\t');
            getline(ss, telno, '\t');
            getline(ss, faculty, '\t');
            getline(ss, leaveBalance, '\t');

            ileaveBalance = stringtoint(leaveBalance);
            staffList.insert(staffList.getLength()+1 ,new Staff(name, staffID, position, category, telno, faculty, ileaveBalance));
        }
    }
    fin.close();

    // load leave
    fin.open("Leave.txt");
    if(fin.is_open())
    {
    	while(getline(fin, wholeline))
    	{
    		istringstream ss(wholeline);
	    	getline(ss, staffName, '\t');
	    	getline(ss, type, '\t');
	        getline(ss, reason, '\t');
	        getline(ss, approver, '\t');
	        getline(ss, status, '\t');

	        while(getline(fin, wholeline2))
	        {
	        	istringstream ss(wholeline2);
	        	if(wholeline2.empty())
	          		break;
    			getline(ss, day, '\t');
    			getline(ss, month, '\t');
        		getline(ss, year, '\t');

	            date.insert(date.getLength()+1, new Date(stringtoint(year), stringtoint(month), stringtoint(day)));
	        }
	        for(int i=1; i<=staffList.getLength(); i++)
        		if(staffList[i]->getName() == staffName)
        		{
        			staffList[i]->addAllLeave(staffName, type, reason, approver, status, date);
        			date.clear();
        		}
    	}
    }
    fin.close();
}

void saveData(LinkedList<Staff*> &staffList)
{
	/*string name;
	string staffID;
	string position;
	string category;
	string telno;
	string faculty;
	int leaveBalance;
	*/
    ofstream fout;
    fout.open("Staff.txt");
    if(staffList.getLength()>0)
    {
        for (int i=1; i<=staffList.getLength(); i++)
        {
            fout << staffList[i]->getName() << "\t" << staffList[i]->getStaffID() << "\t" << staffList[i]->getPosition() << "\t" << staffList[i]->getCategory() << "\t" << staffList[i]->getTelno() << "\t" << staffList[i]->getFaculty() << "\t" << staffList[i]->getLeaveBalance() << "\n";
        }
    }
    fout.close();

    /*string staffName;
	string type;
	string reason;
	string approver;
	string status;*/

    fout.open("Leave.txt");
    if(staffList.getLength()>0)
    {
        for (int i=1; i<=staffList.getLength(); i++)
        {
        	int leaveCount = staffList[i]->getLeaveCount();
        	if(leaveCount > 0)
        	{
        		for (int j=1; j<=leaveCount; j++)
	            {
	            	fout << staffList[i]->getStaffName(j) << "\t" << staffList[i]->getType(j) << "\t" << staffList[i]->getReason(j) << "\t" << staffList[i]->getApprover(j) << "\t" << staffList[i]->getStatus(j) << "\n";
	            	int dateLength = staffList[i]->getDateLength(j);
	            	for (int k=1; k<=dateLength; k++)
		            {
		            	fout << staffList[i]->getDay(j, k) << "\t" << staffList[i]->getMonth(j, k) << "\t" << staffList[i]->getYear(j, k) << "\n";
		            }
	            }
	            fout << "\n";
        	}
        }
    }
    fout.close();

    cout << "Saved successfully" << endl;
    cout << endl;
	system("pause");
}

void addStaff(LinkedList<Staff*> &staffList)
{
	string name, staffID, position, category, telno, faculty;
	bool checkExistingName = true;

	cout << "Add Staff" << endl
		 << "=========" << endl;

	do{
		checkExistingName = false;
		cout << "Name : ";
		getline(cin, name);
		for(int i=1; i<=staffList.getLength(); i++)
			if(staffList[i]->getName() == name)
				checkExistingName = true;
		if(checkExistingName)
			cout << "Name entered already exists" << endl;
	}while (checkExistingName);
	cout << "Staff ID : ";
	getline(cin, staffID);
	cout << "Position : ";
	getline(cin, position);
	cout << "Category : ";
	getline(cin, category);
	cout << "Telephone no. : ";
	getline(cin, telno);
	cout << "Faculty : ";
	getline(cin, faculty);

	staffList.insert(staffList.getLength()+1 , new Staff(name, staffID, position, category, telno, faculty));

	cout << endl << "Staff added successfully" << endl << endl;

	system("pause");
}

void viewStaffInfo(LinkedList<Staff*> &staffList)
{
	cout << "Staff Info" << endl
		 << "==========" << endl << endl
		 << setw(3) << "No." << setw(20) << "Staff Name" << setw(20) << "Staff ID" << setw(20)  <<  "Position" << setw(30)  << "Category" << setw(20) << "Telephone No." << setw(20) << "Faculty" << setw(20) << "Leave Balance" << endl
		 << setw(3) << "===" << setw(20) << "==========" << setw(20) << "========" << setw(20)  <<  "========" << setw(30)  << "========" << setw(20) << "=============" << setw(20) << "=======" << setw(20) << "=============" << endl;

	for(int i=1; i<=staffList.getLength(); i++)
	{
		cout << setw(3) << i << setw(20) << staffList[i]->getName() << setw(20) << staffList[i]->getStaffID() << setw(20) << staffList[i]->getPosition() << setw(30) << staffList[i]->getCategory() << setw(20) << staffList[i]->getTelno() << setw(20) << staffList[i]->getFaculty() << setw(20) << staffList[i]->getLeaveBalance() << endl;
	}
	if (staffList.getLength()==0)
		cout << "List is empty" << endl;

	cout << endl;
	system("pause");
}

void printSimplifiedStaffInfo(LinkedList<Staff*> &staffList)
{
	cout << endl;
	cout << "Staff Info" << endl
		 << "==========" << endl << endl
		 << setw(3) << "No." << setw(20) << "Staff Name" << setw(20) << "Staff ID" << setw(20) << "Faculty" << setw(20) << "Applied Leave" << setw(20) << "Pending Leave" << endl
		 << setw(3) << "===" << setw(20) << "==========" << setw(20) << "========" << setw(20) << "=======" << setw(20) << "=============" << setw(20) << "=============" << endl;

	for(int i=1; i<=staffList.getLength(); i++)
	{
		cout << setw(3) << i << setw(20) << staffList[i]->getName() << setw(20) << staffList[i]->getStaffID() << setw(20) << staffList[i]->getFaculty() << setw(20) << staffList[i]->getLeaveCount() << setw(20) << staffList[i]->getPendingLeave() << endl;
	}
	if (staffList.getLength()==0)
		cout << "List is empty" << endl;
}

int applyLeave(LinkedList<Staff*> &staffList)
{
	string staffName, type, reason, approver, fromDay, fromMonth, fromYear, toDay, toMonth, toYear;
	LinkedList<Date*> dateOfLeave;

	cout << "Add Leave" << endl
		 << "=========" << endl << endl;

	printSimplifiedStaffInfo(staffList);

	cout << endl;
	cout << "Staff Name : ";
	getline(cin, staffName);

	int searchCounter = 0;
	for(int i=1; i<=staffList.getLength(); i++)
		if(staffList[i]->getName() == staffName)
			searchCounter = i;

	if(searchCounter==0) // error proof
	{
		cout << endl;
		cout << "Staff Name not found" << endl;
		system("pause");
		return 0;
	}

	cout << "Date of Leave(from)" << endl;
	cout << "Day : ";
	getline(cin, fromDay);
	cout << "Month : ";
	getline(cin, fromMonth);
	cout << "Year : ";
	getline(cin, fromYear);
	cout << "Date of Leave(to)" << endl;
	cout << "Day : ";
	getline(cin, toDay);
	cout << "Month : ";
	getline(cin, toMonth);
	cout << "Year : ";
	getline(cin, toYear);

	int d=stringtoint(fromDay);
	int m=stringtoint(fromMonth);
	int y=stringtoint(fromYear);
	Date d1 = Date(d, m, y);
	Date d2 =Date(stringtoint(toYear), stringtoint(toMonth), stringtoint(toDay));

	if(d<1 || d>30 || m<1 || m>12 || y<1 || stringtoint(toDay)==0 || stringtoint(toMonth)==0 || stringtoint(toYear)==0 ||  d1>=d2 )
	{
		cout << endl;
		cout << "Invalid Date input" << endl;
		system("pause");
		return 0;
	}

	int counter = 1;
	while(!(d==stringtoint(toDay)+1 && m==stringtoint(toMonth) && y==stringtoint(toYear)))
	{
		if(d==31)
		{
			d=1;
			m++;
		}
		if(m==13)
		{
			m=1;
			y++;
		}
		dateOfLeave.insert(counter, new Date(y, m, d));
		d++;
		counter++;
		if(counter>1000) // prevent overload
		{
			cout << endl;
			cout << "Invalid Date input" << endl;
			system("pause");
			return 0;
		}
	}
	//for(int i=1; i<=dateOfLeave.getLength(); i++)
	//	cout << dateOfLeave[i]->getDay() << "/" << dateOfLeave[i]->getMonth() << "/" << dateOfLeave[i]->getYear() << endl;

	cout << "Type of Leave : ";
	getline(cin, type);
	cout << "Reason : ";
	getline(cin, reason);

	staffList[searchCounter]->addLeave(dateOfLeave, staffName, type, reason);
	cout << endl << "Leave applied successfully" << endl;

	cout << endl;
	system("pause");
}

void printCertainLeave(LinkedList<Staff*> &staffList, int &searchCounter, int &leaveCounter)
{
	leaveCounter = 0;
	cout << "Leave Info" << endl
		 << "==========" << endl << endl
		 << setw(3) << "No." << setw(20) << "Staff Name" << setw(30) << "Date Of Leave" << setw(20) << "Type" << setw(20) << "Reason" << setw(20) << "Approver" << setw(20) << "Status" << endl
		 << setw(3) << "===" << setw(20) << "==========" << setw(30) << "=============" << setw(20) << "====" << setw(20) << "======" << setw(20) << "========" << setw(20) << "======" << endl;

	staffList[searchCounter]->printAllLeaveInfo(leaveCounter);

	if (leaveCounter==0)
		cout << "List is empty" << endl;
}

void printAllLeave(LinkedList<Staff*> &staffList)
{
	cout << "Leave Info" << endl
		 << "==========" << endl << endl
		 << setw(3) << "No." << setw(20) << "Staff Name" << setw(30) << "Date Of Leave" << setw(20) << "Type" << setw(20) << "Reason" << setw(20) << "Approver" << setw(20) << "Status" << endl
		 << setw(3) << "===" << setw(20) << "==========" << setw(30) << "=============" << setw(20) << "====" << setw(20) << "======" << setw(20) << "========" << setw(20) << "======" << endl;

	int leaveCounter = 0;
	for(int i=1; i<=staffList.getLength(); i++)
		staffList[i]->printAllLeaveInfo(leaveCounter);

	if (leaveCounter==0)
		cout << "List is empty" << endl;
}

void cancelLeave(LinkedList<Staff*> &staffList)
{
	string staffName, dataToUpdate;
	int searchCounter;

	cout << "Cancel Leave" << endl
		 << "============" << endl << endl;

	printSimplifiedStaffInfo(staffList);
	cout << endl;

	cout << "Staff Name : ";
	getline(cin, staffName);

	for(int i=1; i<=staffList.getLength(); i++)
		if(staffList[i]->getName() == staffName)
			searchCounter = i;

	if(searchCounter==0) // error proof
		cout << "Staff Name not found" << endl;
	else
	{
		int leaveCounter;
		cout << endl << endl << endl;
		printCertainLeave(staffList, searchCounter, leaveCounter);
		cout << endl;

		if (leaveCounter>0)
		{
			do{ // error proof
				cout << "Choose a data to delete : ";
				getline(cin, dataToUpdate);
				if(stringtoint(dataToUpdate)<=0 || stringtoint(dataToUpdate)>leaveCounter)
					cout << "Wrong Input, Please try again" << endl;
			}while (stringtoint(dataToUpdate)<=0 || stringtoint(dataToUpdate)>leaveCounter);

			staffList[searchCounter]->deleteLeave(stringtoint(dataToUpdate));
			cout << endl << "Leave updated successfully" << endl;
		}
	}

	cout << endl;
	system("pause");
}

void updateLeave(LinkedList<Staff*> &staffList)
{
	string staffName, dataToUpdate, dataStatus, dataStatusSelect, approver;

	cout << "Update Leave" << endl
		 << "============" << endl;

	printSimplifiedStaffInfo(staffList);
	cout << endl;

	cout << "Staff Name : ";
	getline(cin, staffName);

	int searchCounter = 0;
	for(int i=1; i<=staffList.getLength(); i++)
		if(staffList[i]->getName() == staffName)
			searchCounter = i;

	if(searchCounter==0) // error proof
		cout << "Staff Name not found" << endl;
	else
	{
		int leaveCounter;
		cout << endl << endl << endl;
		printCertainLeave(staffList, searchCounter, leaveCounter);
		cout << endl;

		if (leaveCounter>0)
		{
			do{ // error proof
				cout << "Choose a data to update : ";
				getline(cin, dataToUpdate);
				if(stringtoint(dataToUpdate)<=0 || stringtoint(dataToUpdate)>leaveCounter)
					cout << "Wrong Input, Please try again" << endl;
			}while (stringtoint(dataToUpdate)<=0 || stringtoint(dataToUpdate)>leaveCounter);

			cout << endl;
			cout << "1. Approved" << endl;
			cout << "2. Declined" << endl << endl;
			do{ // error proof
				cout << "Choose a status : ";
				getline(cin, dataStatusSelect);
				if(stringtoint(dataStatusSelect)!=1 && stringtoint(dataStatusSelect)!=2)
					cout << "Wrong Input, Please try again" << endl;
			}while (stringtoint(dataStatusSelect)!=1 && stringtoint(dataStatusSelect)!=2);
			cout << "Approver name : ";
			getline(cin, approver);

			if(stringtoint(dataStatusSelect)==1)
				dataStatus = "Approved";
			else
				dataStatus = "Declined";

			staffList[searchCounter]->updateTheData(stringtoint(dataToUpdate), dataStatus, approver);
			cout << endl << "Leave updated successfully" << endl;
		}
	}

	cout << endl;
	system("pause");
}

void viewLeaveInfo(LinkedList<Staff*> &staffList)
{
	printAllLeave(staffList);

	cout << endl;
	system("pause");
}

void checkSatistic(LinkedList<Staff*> &staffList)
{
	string satisticSelection;
	LinkedList<Date> date, monthlydate;

	cout << "Leave Satistic" << endl
		 << "==============" << endl << endl;

	cout << "1. View satistic by day" << endl;
	cout << "2. View satistic by month" << endl;
	cout << "3. View satistic by faculty" << endl << endl;
	cout << "Select an option : ";
	getline(cin, satisticSelection);
	cout << endl;
	
	// get all date
	for(int i=1; i<=staffList.getLength(); i++)
		for(int j=1; j<=staffList[i]->getLeaveCount(); j++)
			for(int k=1; k<=staffList[i]->getDateLength(j); k++)
			{
				bool samedate = false, samemonth = false;
				for(int l=1; l<=date.getLength(); l++) // avoid duplicate day
				{
					if(staffList[i]->getYear(j,k) == date[l].getYear())
						if(staffList[i]->getMonth(j,k) == date[l].getMonth())
						{
							if(staffList[i]->getDay(j,k) == date[l].getDay())
							{
								samedate = true;
								break;
							}
						}
				}
				if(!samedate)
					date.sortInsert( Date(staffList[i]->getYear(j,k), staffList[i]->getMonth(j,k), staffList[i]->getDay(j,k)) );

				for(int l=1; l<=monthlydate.getLength(); l++) // avoid duplicate month
				{
					if(staffList[i]->getYear(j,k) == monthlydate[l].getYear())
						if(staffList[i]->getMonth(j,k) == monthlydate[l].getMonth())
						{
							samemonth = true;
							break;
						}
				}
				if(!samemonth)
					monthlydate.sortInsert( Date(staffList[i]->getYear(j,k), staffList[i]->getMonth(j,k), staffList[i]->getDay(j,k)) );
			}

	/*cout << endl;
	for(int i=1; i<=date.getLength(); i++)
		cout << date[i].getDay() << "/" << date[i].getMonth() << "/" << date[i].getYear() << endl;*/
	/*cout << endl;
	for(int i=1; i<=monthlydate.getLength(); i++)
		cout << monthlydate[i].getMonth() << "/" << monthlydate[i].getYear() << endl;*/

	cout << setw(3) << "No." << setw(20) << "Staff Name" << setw(30) << "Date Of Leave" << setw(20) << "Faculty" << setw(20) << "Type" << setw(20) << "Reason" << setw(20) << "Approver" << setw(20) << "Status" << endl
		 << setw(3) << "===" << setw(20) << "==========" << setw(30) << "=============" << setw(20) << "=======" << setw(20) << "====" << setw(20) << "======" << setw(20) << "========" << setw(20) << "======" << endl;

	if(satisticSelection == "1")
	{
		int counter=1;
		for(int i=1; i<=date.getLength(); i++)
			for(int j=1; j<=staffList.getLength(); j++)
				for(int k=1; k<=staffList[j]->getLeaveCount(); k++)
					for(int l=1; l<=staffList[j]->getDateLength(k); l++)
						if(staffList[j]->getDay(k,l) == date[i].getDay())
							if(staffList[j]->getMonth(k,l) == date[i].getMonth())
								if(staffList[j]->getYear(k,l) == date[i].getYear())
									staffList[j]->printSatisticByDay(counter, k, l);
	}
	else if (satisticSelection == "2")
	{
		int counter=1;
		for(int i=1; i<=monthlydate.getLength(); i++)
			for(int j=1; j<=staffList.getLength(); j++)
				for(int k=1; k<=staffList[j]->getLeaveCount(); k++)
					for(int l=1; l<=staffList[j]->getDateLength(k); l++)
						if(staffList[j]->getMonth(k,l) == monthlydate[i].getMonth())
							if(staffList[j]->getYear(k,l) == monthlydate[i].getYear())
								staffList[j]->printSatisticByMonth(counter, k, l);
	}
	else if (satisticSelection == "3")
	{
		// get all faculty
		LinkedList<string> faculty;
		for(int i=1; i<=staffList.getLength(); i++)
		{
			int counter=0;
			for(int j=1; j<faculty.getLength(); j++)
			{
				if(faculty[j]==staffList[i]->getFaculty())
					counter++;
			}
			if(counter==0)
				faculty.sortInsert(staffList[i]->getFaculty());
		}

		int counter=1;
		for(int i=1; i<=faculty.getLength(); i++)
			for(int j=1; j<=staffList.getLength(); j++)
				if(faculty[i] == staffList[j]->getFaculty())
					if(staffList[j]->getLeaveCount() > 0)
						staffList[j]->printSatistic(counter);
	}
	else
		cout << "Invalid selection" << endl;

	cout << endl;
	system("pause");
}

int main()
{
	bool end=false, wrongInput=false;
	LinkedList<Staff*> staffList;
	loadData(staffList);

	// Hardcoded
	//staffList.insert(1, new Staff("Jason", "15428", "Student", "Student", "011-10705798", "FCI"));
	// Hardcoded

	while(!end)
	{
		system("cls");
		cout << "Main Menu" << endl
		 	 << "=========" << endl;
		cout << "1. Add staff" << endl;
		cout << "2. View staff info" << endl;
		cout << "3. Apply leave" << endl;
		cout << "4. Cancel leave" << endl;
		cout << "5. Update leave status" << endl;
		cout << "6. Check leave status" << endl;
		cout << "7. Check statistic" << endl;
		cout << "8. Save" << endl;
		if(wrongInput)
		{
			cout << "Wrong input" << endl;
			wrongInput=false;
		}
		else
			cout << endl;
		cout << "=> ";

		string menu_select;
		getline(cin, menu_select);

		cout << endl;

		if (menu_select=="1")
			addStaff(staffList);
		else if (menu_select=="2")
			viewStaffInfo(staffList);
		else if (menu_select=="3")
			applyLeave(staffList);
		else if (menu_select=="3")
			cancelLeave(staffList);
		else if (menu_select=="5")
			updateLeave(staffList);
		else if (menu_select=="6")
			viewLeaveInfo(staffList); 
		else if (menu_select=="7")
			checkSatistic(staffList); 
		else if (menu_select=="8")
			saveData(staffList); 
		else
			wrongInput=true;
	}
}