#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool oper(int & result, const int & a, const int & b, const int & operatorNumber) {
	switch(operatorNumber) {
		case 0: //add
			result = a + b;
			break;
		case 1: //multiply
			result = a * b;
			break;
		case 2: //subtract
			result = a - b;
			break;
		case 3: //antisubtract
			result = b - a;
			break;
		case 4: //divide
			if(b != 0 && a % b == 0) result = a/b; else return false;
			break;
		case 5: //anti-divide
			if(a != 0 && b % a == 0) result = b/a; else return false;
			break;
		default: 
			cout<<"oper what??"<<endl;
			return false;
	}
	return true;
};

string opStr(const int & i) {
        switch(i) {
                case 0: //add
                        return "+";
                case 1: //multiply
                        return "*";
                case 2: //subtract
                        return "-";
                case 3: //antisubtract
                        return "anti-";
                case 4: //divide
                        return "/";
                case 5: //anti-divide
                        return "anti/";
        }
	throw string("huh?");
};

bool solve(int * data, const int & target, const int & length, string & toReturn) {
	int temp1; int temp2;
	for(int i = 0; i < length - 1; i++) {
		for(int j = i + 1; j < length; j++) {
			for(int k = 0; k < 6; k++) {
				temp1 = data[i];
				int temp3;
				stringstream toRet;

				if(oper(temp3, data[i], data[j], k)) {
				toRet <<toReturn << data[i] << string(" ") << opStr(k) << string(" ") << data[j] <<" = "<<temp3<<string("\n");

				if(temp3 == target) {
					toRet<<target<<string("\n");
					toReturn = toRet.str();
					return true;
				}
				temp2 = data[j];
				data[i] = temp3;
				data[j] = data[length - 1];
				string toRetStr = toRet.str();
				if(solve(data, target, length - 1, toRetStr)) {
					toReturn = toRetStr;
					return true;
				}
				data[j] = temp2;
				data[i] = temp1;
				}
			}
		}
	}			
	return false;
};

int main() {
	int numbers[6];
	int temp;
	int i = 0;
	cout<<"Enter the target:"<<endl;
	int target;	
	cin>>target;
	cout<<"Enter 6 numbers:"<<endl;
	while(i < 6 && cin>>temp) {
		if(temp == target) {
			cout<<"Target number is an input! Exiting..."<<endl;
			exit(0);
		}
		numbers[i] = temp;
		i++;
	}
	cout<<"Calculating..."<<endl;
	string toReturn;
	if(solve(numbers, target, 6, toReturn)) cout<<"Solution:"<<endl<<toReturn<<endl;
	else cout<<"No solution."<<endl;
};

