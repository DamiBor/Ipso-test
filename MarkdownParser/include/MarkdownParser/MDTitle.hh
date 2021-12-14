#ifndef MD_TITLE
#define MD_TITLE

#include <MarkdownParser/md-tools.hh>

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

class MDTitle : public MDContent
{
   public:
    /**
     * @brief Construct a new MDTitle object with given level.
     * @param level Header level of the title
     */
    MDTitle(HeaderLevel level) : m_level(level) {};
    
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
    HeaderLevel m_level; /*! Header level of the title */
};

#endif
