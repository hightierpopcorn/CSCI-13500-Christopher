#include <iostream>
#include <vector>


void removeCopies(std::vector<int>& data){

    // The vector is sorted in non-decreasing order.
    // Remove all duplicate values in-place so that
    // each value appears exactly once.
    //
    // Do not create another vector.
    // Modify the vector named "data" directly.
    //
    // Maybe two-pointer method? Hmm?
    // Hint: resize() function

    //if the vector is empty nothing is removed
    if (data.empty()){
        return;
    }
  // write points to where the next unique value should go
  int write=1;

  for (int i = 1; i < data.size(); i++){

        // compare the current value to the previous value
        // if they are different, we found a unique number
        if (data[i] != data[i - 1]){
            // copy the unique value to the write position
            data[write] = data[i];
            write++;
        }

  }
  data.resize(write);
}

void isAnagram(std::string officer_name, std::string spy_name){
if(officer_name.size() != spy_name.size()){
    std::cout << "INTRUDER IMPOSTER" << std::endl;
    return;
}
    // Write code to see if the spy name is an anagram of the officer name 
    // Maybe a vector of size 26? Hmm?
    std::vector<int> letters(26,0);

    /* subtract the letters in the officer's and the spys name
     i was struggling with this and this hurt my brain*/
    for(int i = 0; i < officer_name.size(); i++){
        letters[officer_name[i] -'a']++;
    }

    for(int i = 0; i < spy_name.size(); i++){
        letters[spy_name[i] -'a']--;  
    }
/**
    for(int i = 0;i < officer_name.size(); i++){
        letters[spy_name[i] -'a']++;
    }
*/
    for(int i = 0; i<26; i++){
        if (letters[i] != 0){
            std::cout << "INTRUDER IMPOSTER" << std::endl;
            return;
        }
    }
std::cout << "No imposter detected" << std::endl;

}

int main(){

    /*Use other test cases to make sure you program works*/
    std::vector<int> server = {1,1,2,2,2,3,3,4,5,6,6,6};

    /*Print out the original server vector before function called*/
     for (auto data : server){
        std::cout << data << " "; // 1,1,2,2,2,3,3,4,5,6,6,6
    }

    removeCopies(server);
    
    /*Print out the modification of the server vector after function called*/
    for (auto data : server){
        std::cout << data << " ";
    }

    std::cout << std::endl;

    /****************************TEST ANAGRAM*************************************/

    isAnagram("syeda", "aysed"); // No imposter detected!
    isAnagram("angelo", "annabeth"); // IMPOSTER! IMPOSTER!

    return 0;

}
