
#include <MarkdownParser/MDParser.hh>
#include <MarkdownParser/MDRawText.hh>
#include <MarkdownParser/MDTitle.hh>
#include <MarkdownParser/MDParagraph.hh>
#include <sstream>

std::shared_ptr<MDContent> MDParser::parseMD(const std::string & text)
{
    std::stringstream theTextStream(text);
    
    std::shared_ptr<MDContent> theContent = std::make_shared<MDContent>();
    std::string readVal;
    bool inParagraph = false;
    std::shared_ptr<MDParagraph> currentParagraph;

    while(std::getline(theTextStream, readVal))
    {
        size_t firstNonSpacePos = readVal.find_first_not_of(' ');

        // Check for empty lines
        if(firstNonSpacePos == std::string::npos)
        {
            // Close current paragraph and ignore line
            if(currentParagraph.use_count() != 0)
            {
                theContent->addItem(currentParagraph);
                currentParagraph.reset();
            }
        }
        // Check for title line
        else if(readVal[firstNonSpacePos] == '#')
        {
            // Title found while in a paragraph : close current paragragh
            if(currentParagraph.use_count() != 0)
            {
                theContent->addItem(currentParagraph);
                currentParagraph.reset();
            }

            // Define title item and add it to the content
            size_t firstNotHashPos = readVal.find_first_not_of('#', firstNonSpacePos);
            unsigned int headerLevel = firstNotHashPos - firstNonSpacePos;
            std::shared_ptr<MDTitle> theTitle = std::make_shared<MDTitle>(static_cast<HeaderLevel>(headerLevel));

            size_t firstTitleChar = readVal.find_first_not_of(' ', firstNotHashPos);
            std::string titleContent = readVal.substr(firstTitleChar);
            std::shared_ptr<MDRawText> theTitleText = std::make_shared<MDRawText>(titleContent);
            theTitle->addItem(theTitleText);

            theContent->addItem(theTitle);
        }
        else
        {
            // If no current paragraph, create one
            if(currentParagraph.use_count() == 0)
            {
                currentParagraph = std::make_shared<MDParagraph>();
            }

            // Define the raw text content and add it to current paragraph
            std::shared_ptr<MDRawText> theItem = std::make_shared<MDRawText>(readVal + "\n");
            currentParagraph->addItem(theItem);
        }
    }

    // End of text : close current paragraph
    if(currentParagraph.use_count() != 0)
    {
        theContent->addItem(currentParagraph);
        currentParagraph.reset();
    }

    return theContent;
}