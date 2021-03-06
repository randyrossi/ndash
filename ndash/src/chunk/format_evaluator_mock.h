/*
 * Copyright 2017 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NDASH_CHUNK_FORMAT_EVALUATOR_MOCK_H_
#define NDASH_CHUNK_FORMAT_EVALUATOR_MOCK_H_

#include <deque>
#include <memory>
#include <vector>

#include "base/time/time.h"
#include "chunk/format_evaluator.h"
#include "gmock/gmock.h"
#include "playback_rate.h"
#include "util/format.h"

namespace ndash {
namespace chunk {

class MediaChunk;

class MockFormatEvaluator : public FormatEvaluatorInterface {
 public:
  MockFormatEvaluator();
  ~MockFormatEvaluator() override;

  MOCK_METHOD0(Enable, void());
  MOCK_METHOD0(Disable, void());
  MOCK_CONST_METHOD5(Evaluate,
                     void(const std::deque<std::unique_ptr<MediaChunk>>& queue,
                          base::TimeDelta playback_position,
                          const std::vector<util::Format>& formats,
                          FormatEvaluation* evaluation,
                          const PlaybackRate& playback_rate));
};

}  // namespace chunk
}  // namespace ndash

#endif  // NDASH_CHUNK_FORMAT_EVALUATOR_MOCK_H_
