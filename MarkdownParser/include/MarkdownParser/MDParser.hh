#ifndef MD_PARSER
#define MD_PARSER

#include <MarkdownParser/md-tools.hh>
#include <memory>

class MDParser
{
   public:
    /**
     * @brief Parse given text as a markdown formatted text and create MDItems for each element, stored in a returned MDContent.
     * @param text The text to parse, formatted with markdown
     * @return A smart pointer to a MDContent object containing the content of the text as MDItems
     */
    static std::shared_ptr<MDContent> parseMD(const std::string & text);

};

#endif
