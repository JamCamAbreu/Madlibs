
// This function will search for all .txt files 
// in the current directory, and then put them 
// in a vector of strings, that can be used by
// our program.

// This function will be used by main.cpp



#include "searchFiles.hpp"

// --------------------------------------------------

//The vector will be returned, and using a forloop, 
// the object will copy the vector into an object that 
// will be accessed by the menu. 
int retrieveFilenames(std::string dir, std::vector<std::string> &fileNames) {


  //not sure what DIR is, but hopefully it works..
  DIR *dp;
  struct dirent *dirp;
  if ((dp = opendir(dir.c_str())) == NULL) {
    std::cout << "Error opening " << dir << std::endl;
    return 0;
  }

  // store for checking and parsing
  std::string tempString;

  // flag for finding .txt
  int foundTXT;

  while ((dirp = readdir(dp)) != NULL) {

    // store it temporarily so we can parse it:
    tempString = dirp->d_name;
    
    foundTXT = tempString.find(".txt");

    if (foundTXT != -1) { // string was found
    fileNames.push_back(tempString);
    }


  }
  closedir(dp);
  return 0;

  // all documents successfully processed at this point. 

} // end retrieveFilesnames function -----------------



