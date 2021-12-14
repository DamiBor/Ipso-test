
#include <MarkdownParser/MDParser.hh>
#include <MarkdownParser/MDRawText.hh>
#include <MarkdownParser/MDTitle.hh>
#include <sstream>

std::shared_ptr<MDContent> MDParser::parseMD(const std::string & text)
{
    std::stringstream theTextStream(text);
    
    std::shared_ptr<MDContent> theContent = std::make_shared<MDContent>();

    std::string readVal;
    while(std::getline(theTextStream, readVal))
    {
        size_t firstNonSpacePos = readVal.find_first_not_of(' ');
        if(readVal[firstNonSpacePos] == '#')
        {
            size_t firstNotHashPos = readVal.find_first_not_of('#', firstNonSpacePos);
            unsigned int headerLevel = firstNotHashPos - firstNonSpacePos;

            size_t firstTitleChar = readVal.find_first_not_of(' ', firstNotHashPos);
            std::string titleContent = readVal.substr(firstTitleChar) + "\n";

            std::shared_ptr<MDTitle> theTitle = std::make_shared<MDTitle>(MDRawText(titleContent), static_cast<HeaderLevel>(headerLevel));
            theContent->addItem(theTitle);
        }
        else
        {
            std::shared_ptr<MDRawText> theItem = std::make_shared<MDRawText>(readVal + "\n");
            theContent->addItem(theItem);
        }
    }

    return theContent;
}