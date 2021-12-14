#ifndef MD_PARAGRAPH
#define MD_PARAGRAPH

#include <MarkdownParser/md-tools.hh>

class MDParagraph : public MDContent
{
   public:
    /**
     * @brief Construct a new MDParagraph object.
     */
    MDParagraph() {};
    
    /**
     * @brief Return the content of the markdown object, as text with markdown paragraph format
     * @return std::string The content of the item with markdown format
     */
    std::string toString() const;
    
    /**
     * @brief Return content of the markdown object, formatted with HTML syntax for paragraph
     * @return std::string The content of the item in HTML syntax
     */
    std::string toHTML() const;
};

#endif
