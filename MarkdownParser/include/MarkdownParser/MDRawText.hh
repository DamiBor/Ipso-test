#ifndef MD_RAWTEXT
#define MD_RAWTEXT

#include <MarkdownParser/md-tools.hh>

class MDRawText : public MDItem
{
   public:
    /**
     * @brief Construct a new MDRawText object with given text content.
     * @param content Content of the object as raw text
     */
    MDRawText(std::string content) : m_content(content) {};
    
    /**
     * @brief Return the content of the markdown object, as raw text
     * @return std::string The content of the item as raw text
     */
    std::string toString() const;
    
    /**
     * @brief Return content of the markdown object, formatted with HTML syntax
     * @return std::string The content of the item in HTML syntax
     */
    std::string toHTML() const;

   protected:
    std::string m_content; /*! Raw text content of the item */
};

#endif
