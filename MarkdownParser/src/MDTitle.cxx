#include <MarkdownParser/MDTitle.hh>
#include <map>

std::map<HeaderLevel, std::string> s_mdPrefixMap = { {H1, "#"}, {H2, "##"}, {H3, "###"}, {H4, "####"}, {H5, "#####"}, {H6, "######"}, };
std::map<HeaderLevel, std::string> s_htmlTagMap = { {H1, "h1"}, {H2, "h2"}, {H3, "h3"}, {H4, "h4"}, {H5, "h5"}, {H6, "h6"}, };

std::string MDTitle::toString() const
{
    std::string result = s_mdPrefixMap[m_level] + m_content.toString();
    return result;
}

std::string MDTitle::toHTML() const
{
    std::string result = "<" + s_htmlTagMap[m_level] + ">" + m_content.toString() + "</" + s_htmlTagMap[m_level] + ">";
    return result;
}
