


#ifndef SEARCHFILES_HPP
#define SEARCHFILES_HPP

#include <iostream>
#include <sys/types.h>
#include <dirent.h>

#include <string>
#include <vector>

int retrieveFilenames(std::string dir, std::vector<std::string> &fileNames);

#endif
