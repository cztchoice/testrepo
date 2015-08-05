#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

int main(int argc, char *argv[]){
	map<string, int> temp;
	temp["c"] = 13;
	temp["a"] = 13;
	temp["b"] = 13;
	temp["d"] = 13;
	for(map<string, int>::iterator it = temp.begin(); it != temp.end(); ++it){
		cout<<it->first<<" "<<it->second<<endl;
	}

	unordered_map<string, int> un_map;
	un_map["c"] = 15;
	un_map["a"] = 15;
	un_map["b"] = 15;
	un_map["d"] = 15;
	for(unordered_map<string, int>::iterator it = un_map.begin(); it != un_map.end(); ++it){
		cout<<it->first<<" "<<it->second<<endl;
	}


	
}