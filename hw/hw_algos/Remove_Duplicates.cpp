#include <iostream>
#include <vector>
using namespace std;


void print(std::vector <int> const &a) {
   std::cout << "Output Vector : ";

   for(int i=0; i < a.size(); i++)
   std::cout << a.at(i) << ' ';
}

//given sorted array
int remove_duplicates(vector<int>& nums) {
	vector<int> output; 
//	cout << nums.size() << " <<<< \n";

	output.push_back(nums[0]);
	for(int i = 0; i < nums.size() - 1; i++) {
		if(nums[i] != nums[i+1]){
			output.push_back(nums[i+1]); 
		}
	}
	print(output); 
	output.clear(); 
	nums.clear();
	return 0; 
}


int main() {

	vector<int> tempList2 = {0,0,0,0,1,1,1,1,2,2,6,6,6};
	remove_duplicates(tempList2);
	tempList2.clear(); 

	cout << "\n"; 


	vector<int> tempList = {0,1,2,3,4,5,6};
	remove_duplicates(tempList);
	tempList.clear();
	return 0; 
}