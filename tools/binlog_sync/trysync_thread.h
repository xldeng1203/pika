// Copyright (c) 2015-present, Qihoo, Inc.  All rights reserved.
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree. An additional grant
// of patent rights can be found in the PATENTS file in the same directory.

#ifndef TRYSYNC_THREAD_H_
#define TRYSYNC_THREAD_H_

#include "pink/include/pink_thread.h"
#include "pink/include/redis_cli.h"

class TrysyncThread : public pink::Thread {
public:
  TrysyncThread() {
    cli_ = pink::NewRedisCli();
    cli_->set_connect_timeout(1500);
	};
  virtual ~TrysyncThread();

private:
  int sockfd_;
  int64_t sid_;
  pink::PinkCli *cli_;

  bool Send();
  bool RecvProc();
  void PrepareRsync();
  bool TryUpdateMasterOffset();

  virtual void* ThreadMain();

};

#endif
