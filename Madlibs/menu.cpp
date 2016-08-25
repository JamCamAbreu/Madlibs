/********************************************************
 * Author: James Cameron Abreu
 * Date: July 21, 2016
 * Description:
 * *****************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h> // srand()
#include <time.h> // time()

#include "textProcessor.hpp"
#include "Madlib.hpp"
#include "getAnswers.hpp"
//#include "MadlibDatabase.hpp"

#include "searchFiles.hpp"


int main() {

  std::cout << std::endl << "Welcome to Madlibs, by JamCam";
  std::cout << std::endl << std::endl;

  std::cout << "Processing madlibs in current directory...";
  std::cout << std::endl;


  // create a vector of strings to hold the names of the files. 
  std::vector<std::string> fileNames;

  std::string dir = ".";

  //process madlibs in folder here:
  retrieveFilenames(dir, fileNames);

//-------------------------------------------
  // 1. get a list of all the documents
  // that were processed (using a vector)
  //
  // 2. and get the size of that vector
  //
  // 3. print to the user how many madlibs are 
  // available. 
  //
  // 4. Menu choices: 
  //    1. Choose Madlib from list
  //    2. Pick Random Madlib
  //    3. About
  //    4. Quit

  std::cout << std::endl << std::endl;
  std::cout << "There are " << fileNames.size(); 
  std::cout << " madlibs available in this file." << std::endl << std::endl;

  std::cout << "`~-* MAIN MENU *-~'" << std::endl;
  std::cout << "  1. Choose Madlib from list." << std::endl;
  std::cout << "  2. Pick Random Madlib" << std::endl;
  std::cout << "  3. About" << std::endl;
  std::cout << "  4. Quit" << std::endl << std::endl;

  std::cout << "Please enter a number from the menu above: ";


  int choice;

  std::cin >> choice;
  std::cout << std::endl;


  // menu control: 
  while (choice != 4) { 



    switch (choice) {

      case 1: { // display choices, process choice. 

        int pick;

        std::cout << "Madlibs available: " << std::endl;

        for (int f = 0; f < fileNames.size(); f++)
          std::cout << f << ". " << fileNames.at(f) << std::endl;


        std::cout << std::endl;
        std::cout << "Pick a madlib for the list, or type -1 to go back: ";
        std::cin >> pick;

        if (pick != -1) {
        
          while ((pick < 1) && (pick > fileNames.size())) { 
            std::cout << "Please choose a number between 1 and ";
            std::cout << fileNames.size() << "." << std::endl;
            std::cout << "Or, type -1 to go back: "; 
            std::cin >> pick;

            if (pick == -1)
              break;
          }  // end while
        }  // end if


        // process the correct madlib
        // get answers from the user. 
        Madlib madlib1 = processMadlib(fileNames.at(pick));
        getAnswers(madlib1);

        break; // end of menu option 1 (display choices)

        } // end case 1




      case 2: { // process random choice:

        srand(time(NULL));

        int number = (rand() % fileNames.size());

        std::cout << std::endl << fileNames.at(number); 
        std::cout << " was chosen at random." << std::endl;

        Madlib madlib2 = processMadlib(fileNames.at(number));
        getAnswers(madlib2);

      } // end of case 2





        break;

      case 3: 

        std::cout << std::endl << std::endl;
        std::cout << "----------------About----------------" << std::endl;
        std::cout << "Author: James Cameron Abreu" << std::endl;
        std::cout << "Created: July 21, 2016" << std::endl;
        std::cout << "Description: Madlibs takes all txt files" << std::endl;
        std::cout << "  found in the source directory, and parces" << std::endl;
        std::cout << "  them by into question prompts that can be" << std::endl;
        std::cout << "  used by the program. Examples of the" << std::endl;
        std::cout << "  correct format can be seen by viewing" << std::endl;
        std::cout << "  any of the example .txt files provided in" << std::endl;
        std::cout << "  the source code directory." << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << std::endl << std::endl;

        break;

      case 4:
        break;

      default: 
        // input validation:
        std::cout << std::endl << "Please choose a number from the menu: ";
        std::cin >> choice;
        break;
    } // end switch

    std::cout << "There are " << fileNames.size(); 
    std::cout << " madlibs available in this file." << std::endl << std::endl;

    std::cout << "`~-* MAIN MENU *-~'" << std::endl;
    std::cout << "  1. Choose Madlib from list." << std::endl;
    std::cout << "  2. Pick Random Madlib" << std::endl;
    std::cout << "  3. About" << std::endl;
    std::cout << "  4. Quit" << std::endl << std::endl;

    std::cout << "Please enter a number from the menu above: ";


    std::cin >> choice;

  } // end while loop (choice now equals 4)




  std::cout << std::endl << "Madlibs exited successfully." << std::endl;
  return 0;
}
