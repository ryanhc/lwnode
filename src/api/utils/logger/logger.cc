/*
 * Copyright (c) 2022-present Samsung Electronics Co., Ltd
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "logger.h"

// Dlog
#ifdef HOST_TIZEN
#include <dlog.h>

void DlogOut::flush(std::stringstream& ss,
                    std::shared_ptr<Output::Config> config) {
  auto c =
      config ? std::static_pointer_cast<DLogConfig>(config) : LogKind::lwnode();
  dlog_print(DLOG_INFO, c->tag.c_str(), "%s", ss.str().c_str());
}

void DlogOut::appendEndOfLine(std::stringstream& ss){
    /* NOTHING */
};

#else
// TEST
void DlogOut::flush(std::stringstream& ss,
                    std::shared_ptr<Output::Config> config) {
  auto c =
      config ? std::static_pointer_cast<DLogConfig>(config) : LogKind::lwnode();
  std::cout << c->tag << " " << ss.str();
}

void DlogOut::appendEndOfLine(std::stringstream& ss) {
  ss << std::endl;
};
#endif

// LogKind
LogKind* LogKind::getInstance() {
  static LogKind kind;
  return &kind;
}

LogKind::LogKind() {
  user_ = std::make_shared<DLogConfig>("USER");
  lwnode_ = std::make_shared<DLogConfig>("LWNODE");
}
