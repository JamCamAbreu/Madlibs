/********************************************************
 * Author: James Cameron Abreu
 * Date: July 21, 2016
 * Description:
 * *****************************************************/

#include "Madlib.hpp"



// set functions
void Madlib::setTitle(std::string newTitle) {
  title = newTitle;
}

void Madlib::addTitle(std::string newTitle) {
  title += newTitle;
}

void Madlib::setAuthor(std::string newAuthor) {
  author = newAuthor;
}

void Madlib::addAuthor(std::string newAuthor) {
  author += newAuthor;
}

void Madlib::setParagraphCounter(int i) {
  paragraphCounter = i;
} 

void Madlib::incrementParagraphCounter() {
  paragraphCounter++;
} 


// get functions
std::string Madlib::getTitle() {
  return title;
}

std::string Madlib::getAuthor() {
  return author;
}

int Madlib::getParagraphCounter() {
  return paragraphCounter;
}




//for the vector of strings (sentences)

void Madlib::addBody(std::string newBody) {
  body.push_back(newBody);
}

int Madlib::getBodySize() {
  return body.size();
}

  // MODIFIED for bounds checking!
std::string Madlib::getBody(int i) {
  if (i < getBodySize())
    return body.at(i);
  else
    return body.at(getBodySize());
}





// for the vector of descriptions:

void Madlib::addDescription(std::string newDescription) {
  description.push_back(newDescription);
}

int Madlib::getDescriptionSize() {
  return description.size();
}

  // MODIFIED for bounds checking!
std::string Madlib::getDescription(int i) {
  if (i <= getDescriptionSize())
    return description.at(i);
  else 
    return description.at(getDescriptionSize());
}



//for the vector of answers 

void Madlib::addAnswer(std::string newAnswer) {
 answers.push_back(newAnswer);
}

std::string Madlib::getAnswer(int i) {
  return answers.at(i);
}

int Madlib::getAnswerSize() {
  return answers.size();
}



// print
void Madlib::printMadlib() {
  std::cout << std::endl << std::endl;

  std::cout << "Title: ";
  std::cout << getTitle();
  std::cout << std::endl;

  std::cout << "Author: ";
  std::cout << getAuthor();
  std::cout << std::endl << std::endl;

  // debugging: 
  /* 
  std::cout << "Body elements: " << getBodySize();
  std::cout << std::endl;

  std::cout << "Description elements: " << getDescriptionSize();
  std:: cout << std::endl; 

  std::cout << "Answer elements: " << getAnswerSize();
  std:: cout << std::endl << std:: endl; 
  */
  
  // print all of the sentences (elements) in body vector:
  for (int i = 0; i < getBodySize(); i++) {
    std::cout << getBody(i); // end of for loop


    // bounds checking:
    if (getAnswerSize() > i) { 
      std::cout << getAnswer(i); // end of for loop
    } 

  }


  std::cout << std::endl << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << std::endl << std::endl;
  std::cout << std::endl << std::endl;
} // end print function definition




// Default Constructor--------------------
Madlib::Madlib() {
  setTitle("");
  setAuthor("");
  setParagraphCounter(0);
}

