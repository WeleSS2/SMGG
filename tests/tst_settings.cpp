#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>

#include "../src/settings/settings.h"

using namespace testing;

// Line tests which use one instance of singleton!
class SettingsLineTest : public ::testing::Test {

};

// Test case for SaveValue function
TEST_F(SettingsLineTest, SaveValueTest) {
    // Call the SaveValue function with test values
    EXPECT_TRUE(Settings::getSettings()->SaveValue("key1", 10));
    EXPECT_TRUE(Settings::getSettings()->SaveValue("key2", "test"));
}

// Test case for LoadValue function
TEST_F(SettingsLineTest, LoadValueTest) {
    // Call the LoadValue function to retrieve the saved values
    const int* intValue = Settings::getSettings()->LoadValue<int>("key1");
    EXPECT_NE(intValue, nullptr);
    EXPECT_EQ(*intValue, 10);

    const QString* stringValue = Settings::getSettings()->LoadValue<QString>("key2");
    EXPECT_NE(stringValue, nullptr);
    EXPECT_EQ(*stringValue, "test");
}

/* Test creating a file and saving value into.
 *  Initialization for settings path;
 */
TEST_F(SettingsLineTest, SaveToFileTest) {

    Settings::getSettings()->CheckPath();

    QString path = Settings::getSettings()->defaultPath() + "/test.json";

    int value = Settings::getSettings()->SaveSettingsToFiles(path);

    EXPECT_EQ(value, 0);
}

// Test loading from files
TEST_F(SettingsLineTest, LoadFromFilesTest) {
    QString path = Settings::getSettings()->defaultPath() + "/test.json";

    int value = Settings::getSettings()->LoadSettings(path);

    // Call the LoadValue function to retrieve the saved values
    const int* intValue = Settings::getSettings()->LoadValue<int>("key1");
    EXPECT_NE(intValue, nullptr);
    EXPECT_EQ(*intValue, 10);

    const QString* stringValue = Settings::getSettings()->LoadValue<QString>("key2");
    EXPECT_NE(stringValue, nullptr);
    EXPECT_EQ(*stringValue, "test");

    EXPECT_EQ(value, 0);
}
