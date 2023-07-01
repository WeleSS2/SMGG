#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QObject>

#include "../src/settings/settingsoperations.h"

using namespace testing;

// Define a fixture class for the test suite
class SettingsTest : public ::testing::Test {
protected:
    Settings settings;
};

// Test case for SaveValue function
TEST_F(SettingsTest, SaveValueTest) {
    // Call the SaveValue function with test values
    EXPECT_TRUE(settings.SaveValue("key1", 10));
    EXPECT_TRUE(settings.SaveValue("key2", "test"));
}

// Test case for LoadValue function
TEST_F(SettingsTest, LoadValueTest) {
    // Save some values using SaveValue function
    settings.SaveValue("key1", 10);
    settings.SaveValue("key2", "test");

    // Call the LoadValue function to retrieve the saved values
    const int* intValue = settings.LoadValue<int>("key1");
    EXPECT_NE(intValue, nullptr);
    EXPECT_EQ(*intValue, 10);

    const QString* stringValue = settings.LoadValue<QString>("key2");
    EXPECT_NE(stringValue, nullptr);
    EXPECT_EQ(*stringValue, "test");
}
