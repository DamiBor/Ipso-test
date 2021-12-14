#include <MarkdownParser/MDParagraph.hh>


std::string MDParagraph::toString() const
{
    return MDContent::toString();
}

std::string MDParagraph::toHTML() const
{
    std::string result = "<p>" + MDContent::toHTML() + "</p>";
    return result;
}
