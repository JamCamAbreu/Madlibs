/********************************************************
 * Author: James Cameron Abreu
 * Date: July 21, 2016
 * Description:
 * *****************************************************/

#include "getAnswers.hpp"

// Request answers
void getAnswers(Madlib currentMadlib) {

  std::cout << std::endl;
  std::cout << "Type in answers to the prompts:";
  std::cout << std::endl << std::endl;

  // for loop takes all of the 
  // madlib's Descriptions and 
  // uses them for prompts. 
  int size = currentMadlib.getDescriptionSize();
                        // times two because each paragraph 
                        // uses two new line characters (elements):
  int realsize = size - (currentMadlib.getParagraphCounter()*2);

  std::string newAnswer; // temporary storage
                         // for cin

  std::string tempString;

  int counter = 0; // used to keep track of actual
                   // prompts and skip empty descriptions.

  for (int i = 0; i < size; i++) {


    tempString = currentMadlib.getDescription(i);

    // ignore if a new line: 
    if (!tempString.empty()) { // not a new line

      counter++; // not a empty description, so increment

      // display the appropriate question:
      std::cout << "[" << counter << " of " << realsize << "] ";
      std::cout << tempString << ": "; 

      // clear previous string data:
      newAnswer.clear();

      // retrieve from user:
      // LATER USE SOMETHING OTHER 
      // THAN CIN? SOMETHING THAT
      // TAKES IN A WHOLE STRING
      std::cin >> newAnswer;




      // add SPACE after words but NOT if it's ------------------
      // punctuation. 

      std::string nextWord; // stores the next element in the 
                            // description vector
      bool isPunctuation;   // used to test for punctuation

      bool spaceFound;      // used to check only the first 
                            // word in the body string
                            // (abort after found)
      
      int max = currentMadlib.getDescriptionSize() - 1;

      // add a new line, unless the next string is punctuation:
      if ( i < max) { // if NOT on the last element of the vector

        // the next word in the body vector. Is it punctuation? 
        // if it is, DON'T put a space. 
        nextWord = currentMadlib.getBody(i + 1);

        //false until proven true:
        isPunctuation = false;

        // check for punctuation: 
        for (int h = 0; h < nextWord.size(); h++) {

          spaceFound = false; // false until proven true

          if (isspace(nextWord.at(h))) {
                spaceFound = true;
                break; // break out of the for loop
              } 
          else if (ispunct(nextWord.at(h))) { // no space, punctuation? 
            isPunctuation = true;
          } 
        }  // end for loop
        

        if (!isPunctuation) {// if NOT punctuation
          newAnswer += " "; // add a space. 
        } 

      } // end if  ----------------------------------------------------



      // temp: DELETE THIS LATER:
      //newAnswer += " "; 

      // store in our vector
      currentMadlib.addAnswer(newAnswer);

      // new line for next prompt
      std::cout << std::endl;

    } // end if

    else {
      currentMadlib.addAnswer("");
    }
    

  }

  // for debugging:
  std::cout << std::endl;
  currentMadlib.printMadlib();


} // end getAnswers function definition

