#pragma once

#include <MarkdownParser/MDRawText.hh>
#include <MarkdownParser/MDTitle.hh>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MDParserContainerUnitTest : public ::testing::Test
{
protected:
    /**
     * @brief Default constructor used by GoogleTest to construct a MDParserContainerUnitTest instance for each test case. 
     */
    MDParserContainerUnitTest() {}

    /**
     * @brief Destroys MDParserContainerUnitTest objects.
     */
    virtual ~MDParserContainerUnitTest() {}

    /**
     * @brief SetUp is executed each time a test case is run
     */
    virtual void SetUp() {}

    /**
     * @brief TearDown is executed each time a test case is finished, whatever the result.
     */
    virtual void TearDown() {}
};

/**
 * @brief Test for MDRawText container
 * @details What is tested : 
 * - MDRawText toString return the text given at creation
 * - MDRawText toHTML return the text given at creation
 */
TEST_F(MDParserContainerUnitTest, mdRawTextTest)
{
    // call readFromDirectory with test data directory
    std::string testRawText("Test raw text");
    MDRawText theText(testRawText);

    // Check data content after read
    EXPECT_EQ(testRawText, theText.toString());
    EXPECT_EQ(testRawText, theText.toHTML());
}

/**
 * @brief Test for MDTitle container
 * @details What is tested : 
 * - MDTitle toString return the text given at creation with markdown format
 * - MDTitle toHTML return the text given at creation with html format
 * TODO : test all header level values
 */
TEST_F(MDParserContainerUnitTest, mDTitleTest)
{
    // call readFromDirectory with test data directory
    std::shared_ptr<MDRawText> theText = std::make_shared<MDRawText>("Test title");
    MDTitle theTitle(H1);
    theTitle.addItem(theText);

    // Check data content after read
    std::string expectedMDText("#Test title");
    std::string expectedHTMLText("<h1>Test title</h1>");

    EXPECT_EQ(expectedMDText, theTitle.toString());
    EXPECT_EQ(expectedHTMLText, theTitle.toHTML());
}