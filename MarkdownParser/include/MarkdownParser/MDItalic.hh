#ifndef MD_ITALIC
#define MD_ITALIC

#include <MarkdownParser/md-tools.hh>

class MDItalic : public MDContent
{
   public:
    /**
     * @brief Construct a new MDItalic object with given text content.
     * @param content Content of the object as raw text
     */
    MDItalic() {};
    
    /**
     * @brief Return the content of the markdown object, with markdown format
     * @return std::string The content of the item with markdown format
     */
    std::string toString() const;
    
    /**
     * @brief Return content of the markdown object, formatted with HTML syntax
     * @return std::string The content of the item in HTML syntax
     */
    std::string toHTML() const;
};

#endif
