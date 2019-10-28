// Copyright 2017 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <gtest/gtest.h>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <chrono>

#include "realsense/rs_factory.hpp"

TEST(UnitTestFunction, testLibraryFunctions)
{  
  rclcpp::WallRate loop_rate(1);
  
  ASSERT_NO_THROW({
    auto realsense_node = std::make_shared<realsense::RealSenseNodeFactory>();
    rclcpp::spin_some(realsense_node);
    loop_rate.sleep();
    rclcpp::shutdown();
  });
}

TEST(UnitTestFunction, testLibraryIncorrectInputs)
{
  try
  {
    auto realsense_node = std::make_shared<realsense::RealSenseNodeFactory>("ZR300", "0");
  }
  catch (...) 
  {
    SUCCEED();
  }
}

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
