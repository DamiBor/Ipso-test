#include <MarkdownParser/MDItalic.hh>

std::string MDItalic::toString() const
{
    return "*" + MDContent::toString() + "*";
}

std::string MDItalic::toHTML() const
{
    return "<i>" + MDContent::toString() + "</i>";
}
