/********************************************************
 * Author: James Cameron Abreu
 * Date: July 21, 2016
 * Description:
 * *****************************************************/


#ifndef MADLIB_HPP
#define MADLIB_HPP

#include <string> 
#include <vector>
#include <iostream> // used for printing

class Madlib {

  private:
    std::string title;
    std::string author;
    int paragraphCounter;

    std::vector<std::string> body; // holds the printable sentences
    std::vector<std::string> description;
    std::vector<std::string> answers; 
    

  public:

    //set functions
    void setTitle(std::string newTitle);
    void addTitle(std::string newTitle);
    void setAuthor(std::string newAuthor);
    void addAuthor(std::string newAuthor);
    void setParagraphCounter(int i);

    void incrementParagraphCounter();

    // get functions
    std::string getTitle();
    std::string getAuthor();
    int getParagraphCounter();


    // vector to hold the BODY
    void addBody(std::string newBody); // set
    std::string getBody(int i); // get
    int getBodySize();


    // vector to hold the DESCRIPTIONS:
    void addDescription(std::string newDescription); // set
    std::string getDescription(int i); // get
    int getDescriptionSize();


    // vector to hold the ANSWERS:
    void addAnswer(std::string newAnswer); // set
    std::string getAnswer(int i); // get
    int getAnswerSize();


    // print
    void printMadlib();


    // get answers from user and store
    // them in the answers vector
    void getAnswers();


    // default constructor:
    Madlib();

};



#endif
