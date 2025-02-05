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

#ifdef HOST_TIZEN
#include <app_common.h>
#include <aul.h>
#include <bundle.h>
#include <bundle_internal.h>
#endif

#include <string>

class AULEventReceiver {
 public:
  static AULEventReceiver* getInstance();

#ifdef HOST_TIZEN
  static int aulEventHandler(aul_type type, bundle* b, void* data);
  bool hasAulArguments(int argc, char* argv[]);
  bool start(int argc, char* argv[]);
#else
  bool start(int argc, char* argv[]) { return false; }
#endif

  void initLoggerOutput();
  bool isEventReceiverRunning();

 private:
  AULEventReceiver() = default;
  bool isEventReceiverRunning_{false};
  static const int kMaxPackageNameSize{512};
  std::string appid_;
};
