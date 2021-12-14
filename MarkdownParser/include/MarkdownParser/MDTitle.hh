#ifndef MD_TITLE
#define MD_TITLE

#include <MarkdownParser/md-tools.hh>
#include <MarkdownParser/MDRawText.hh>

/**
 * @brief Enumeration to define the header level
 */
enum HeaderLevel {
    H1 = 1,
    H2,
    H3,
    H4,
    H5,
    H6
};

class MDTitle : public MDItem
{
   public:
    /**
     * @brief Construct a new MDTitle object with given text content.
     * @param content Content of the object as a MDRawText object
     * @param level Header level of the title
     */
    MDTitle(MDRawText content, HeaderLevel level) : m_content(content), m_level(level) {};
    
    /**
     * @brief Return the content of the markdown object, as text with markdown title format
     * @return std::string The content of the item with markdown format
     */
    std::string toString() const;
    
    /**
     * @brief Return content of the markdown object, formatted with HTML syntax for headers
     * @return std::string The content of the item in HTML syntax
     */
    std::string toHTML() const;

   protected:
    MDRawText m_content; /*! Content of the title */
    HeaderLevel m_level; /*! Header level of the title */
};

#endif
