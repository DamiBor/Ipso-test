#include <MarkdownParser/MDRawText.hh>

std::string MDRawText::toString() const
{
    return m_content;
}

std::string MDRawText::toHTML() const
{
    return m_content;
}
