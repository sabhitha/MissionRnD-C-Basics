/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int isOlder(char *dob1, char *dob2) {
	if (dob1 == dob2)
		return 0;
	//tests
	//to check the format
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-'){
		return -1;
	}
	int len1;
	int len2;
	for (len1 = 0; dob1[len1] != '\0'; len1++);
	for (len2 = 0; dob2[len2] != '\0'; len2++);
	if (len1 != 10 || len2 != 10)
		return -1;
	//test for month
	int mon1 = (dob1[3] - 48) * 10 + (dob1[4] - 48);
	int mon2 = (dob1[3] - 48) * 10 + (dob1[4] - 48);
	if (mon1 > 12 || mon2 > 12){
		return -1;
	}
	//checking for leap year
	int year1 = (dob1[6] - 48) * 1000 + (dob1[7] - 48) * 100 + (dob1[8] - 48) * 10 + (dob1[9] - 48);
	int year2 = (dob2[6] - 48) * 1000 + (dob2[7] - 48) * 100 + (dob2[8] - 48) * 10 + (dob2[9] - 48);
	int mon_arr1[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int mon_arr2[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (year1 % 100 == 0 || year1 % 4 == 0)
		mon_arr1[1] = 29;
	if (year2 % 100 == 0 || year2 % 4 == 0)
		mon_arr2[1] = 29;
	int date1 = (dob1[0] - 48) * 10 + (dob1[1] - 48);
	int date2 = (dob2[0] - 48) * 10 + (dob2[1] - 48);
	if (date1 > mon_arr1[mon1 - 1]){
		return -1;
	}
	if (date2 > mon_arr2[mon2 - 1]){
		return -1;
	}
	if (year1 < year2)
		return 1;
	else if (year2 < year1)
		return 2;
	else{
		if (mon1 < mon2)
			return 1;
		else if (mon2 < mon1)
			return 2;
		else{
			if (date1 < date2)
				return 1;
			else
				return 2;
		}
	}
	return 0;
}
