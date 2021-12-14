#include <MarkdownParser/MDRawText.hh>
#include <MarkdownParser/MDParser.hh>

#include <iostream>

void exercise1()
{
    std::shared_ptr<MDRawText> md_raw_text_1(new MDRawText("bienvenue "));
    std::shared_ptr<MDRawText> md_raw_text_2(new MDRawText("chez "));
    std::shared_ptr<MDRawText> md_raw_text_3(new MDRawText("ipso !"));
    std::shared_ptr<MDContent> md_content(new MDContent);
    md_content->addItem(md_raw_text_1);
    md_content->addItem(md_raw_text_2);
    md_content->addItem(md_raw_text_3);
    std::cout << "markdown: " << md_content->toString() << std::endl;
    std::cout << "html: " << md_content->toHTML() << std::endl;
}

void exercise2()
{
    std::cout << "==== EXERCISE 2 ====" << std::endl;
    std::string txt = "# Title\n## Subtitle\nContent";
    std::shared_ptr<MDContent> content = MDParser::parseMD(txt);
    std::cout << content->toString() << std::endl;
    std::cout << content->toHTML() << std::endl;
}

void exercise3()
{
    std::cout << "==== EXERCISE 3 ====" << std::endl;
    std::string txt = "Par1\n#Titre\nPar2-l1\nPar2-l2\n\n\nPar3\n";
    std::shared_ptr<MDContent> content = MDParser::parseMD(txt);
    std::cout << content->toString() << std::endl;
    std::cout << content->toHTML() << std::endl;
}

int main(int argc, char **argv)
{
    exercise1();
    exercise2();
    exercise3();
    return 0;
}
