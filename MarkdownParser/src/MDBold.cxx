#include <MarkdownParser/MDBold.hh>

std::string MDBold::toString() const
{
    return "**" + MDContent::toString() + "**";
}

std::string MDBold::toHTML() const
{
    return "<b>" + MDContent::toString() + "</b>";
}
