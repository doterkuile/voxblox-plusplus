// Copyright (c) 2019, ASL, ETH Zurich, Switzerland
// Licensed under the BSD 3-Clause License (see LICENSE for details)

#include <gflags/gflags.h>
#include <glog/logging.h>
#include <ros/ros.h>

#include "global_segment_map_node/controller.h"

typedef uint16_t Label;

int main(int argc, char** argv) {
//  ros::init("test");
  std::map<Label, int> labelMap;
  int ii = 0;
  int jj = 0;
  for(; ii < 25; ii++){
      std::pair<Label,int> new_pair = std::pair<Label,int>(jj,ii);
      if(labelMap.size() > 10)
      {
          // find key with lowest .second
          auto it = std::min_element(labelMap.begin(), labelMap.end(),
                      [](const auto& l, const auto& r) { return l.second < r.second; });
          labelMap.erase(it);
          // remove this key first
      }
      labelMap.insert(new_pair);
      jj = jj + 3;
  }
  return 0;
}
