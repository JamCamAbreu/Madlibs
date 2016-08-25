/********************************************************
 * Author: James Cameron Abreu
 * Date: July 21, 2016
 * Description:
 * *****************************************************/

#include "textProcessor.hpp"

// TODO next: instead of being one large text, make a madlib object that
// contains this information. The madlib class will have functions to print the
// data. The madlib class should have a vector of strings, starting from the
// first word in the body to the first set of square brackets.
// There should also be a vector of strings for the square bracket words. Those
// will be used by another object that asks the users the appropriate word. 


Madlib processMadlib(std::string fileName) { // returns a madlib object 

  std::ifstream inputFile; // create an ifstream object
  inputFile.open(fileName.c_str()); // open the file (using a string)

  // for now, just process an example;
  Madlib newMadlib;

  std::string title;
  std::string author;
  std::string body;

  // first process the FULL title: ------------------

  while ( (inputFile >> title) && (title != "[author]") ) {
    if (title == "[title]")  // do not print this tag, skip it.
      inputFile >> title;

    newMadlib.addTitle(title);
    newMadlib.addTitle(" ");
  } // end of title loop




  // next, process the author: --------------------
  while ( (inputFile >> author) && (author != "[body]") ) {
    if (author == "[author]")  // do not print this tag, skip it.
      inputFile >> author;

    newMadlib.addAuthor(author);
    newMadlib.addAuthor(" ");
  } // end of author loop
    

  



  // declare sentence string
  // sentences are all of the words between user input words.
  std::string sentence;
  sentence.clear();

  // this is where we will store the ENTIRE description, no matter how many
  // words it contains:
  std::string description;
  description.clear();


  // finally, process the body text: ------------------
  while (inputFile >> body) { // UNTIL THE END OF THE DOCUMENT:
    
    int L = body.find("["); // to test for [ bracket
    int R = body.find("]"); // to test for ] bracket.
    // note: the reason these are stored as an integer, is because 
    // of how string.find() works. It returns -1 for false, and 
    // if true it returns the position where the string was found. 


    // new paragraph:
    if (body == "[p]") {

      newMadlib.addBody(sentence);
      sentence.clear();

      newMadlib.addDescription(description);
      description.clear();

     newMadlib.addBody("\n");
     newMadlib.addBody("\n");
     // add nothing into the description, in order to keep 
     // the tally the same:
     newMadlib.addDescription("");
     newMadlib.addDescription("");

     // finally increment the paragraph counter so that
     // the user doesn't have to type in descriptions 
     // for the new line characters:
     newMadlib.incrementParagraphCounter();
    }


    

    // come across a descrition in parenthesis-------------------

    else if (L != -1) { // found a LEFT bracket [
        
      // first, store and clear our sentence:
      newMadlib.addBody(sentence);
      sentence.clear(); // clear the sentence for the next sentence. 

      // for now, just leave the brackets in:
      description += body;
      // no " ", skip the white space at first:

      // keep going until we reach the end of the description
      while ( (inputFile >> body) && (R == -1) ) { // while there is no "]"

        R = body.find("]"); 

        // add a space before
        // unless just after a bracket
        if ( (L == -1) && (R == -1) )
          description += " ";

        // keep adding to description
        // until we comes across a 
        // right bracket
        description += body;

        // test again for right bracket
        L = body.find("["); 

      } // end while bracket 

      // store the new description and clear it:
      description += " ";
      newMadlib.addDescription(description);
      description.clear();

      // right now this is taking the last word 
      // right after our description, not the bracket:

      // next word after the description: 
      sentence += body; // add the right bracket
      sentence += " ";


    } // end if (description processing)

     
    else { // word is not [p], or a "["
  
      sentence += body;
      sentence += " ";  // add space at end before storing
                    // in the madlib object
    } // end else, (body sentences)


  // here is where the while loop returns as long as there is more text to
  // process. 

  } // end of body loop ---------------------------------------------------------------------------------


  //one final setence (no square brackets stopped it.)
  newMadlib.addBody(sentence);



  //test
  //newMadlib.printMadlib();
  // explanation: for now, the text processor is run, 
  // but the newMadlib is not stored anywhere. So for now, 
  // we'll just test the printMadlib function inside here. 
  // Later to be removed. 


  return newMadlib;

  inputFile.close(); // close the file.
  std::cout << std::endl << std::endl << "File closed." << std::endl;
}


