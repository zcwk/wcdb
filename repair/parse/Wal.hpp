/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef Wal_hpp
#define Wal_hpp

#include <WCDB/Data.hpp>
#include <WCDB/FileHandle.hpp>
#include <WCDB/Initializeable.hpp>
#include <WCDB/PagerRelated.hpp>
#include <map>

namespace WCDB {

namespace Repair {

class Wal : public PagerRelated, public Initializeable {
#pragma mark - Initialize
public:
    Wal(Pager &pager);

    const std::string &getPath() const;
    static constexpr const int headerSize = 32;

protected:
    FileHandle m_fileHandle;

#pragma mark - Page
public:
    bool containsPage(int pageno) const;
    Data acquirePageData(int pageno);
    Data acquireData(off_t offset, size_t size);

protected:
    std::map<int, int> m_framePages;

#pragma mark - Wal
public:
    void setMaxFrame(int maxFrame);
    int getFrameCount() const;
    bool isBigEndian() const;
    const std::pair<uint32_t, uint32_t> &getSalt() const;
    int getPageSize() const;
    const std::pair<uint32_t, uint32_t> &getChecksum() const;

protected:
    int m_maxFrame;
    int m_frames;
    bool m_isBigEndian;
    std::pair<uint32_t, uint32_t> m_salt;
    std::pair<uint32_t, uint32_t> m_checksum;

#pragma mark - Frame
public:
    int getFrameSize() const;
    Data acquireFrameData(int frameno);

#pragma mark - Initializeable
protected:
    bool doInitialize() override;
};

} //namespace Repair

} //namespace WCDB

#endif /* Wal_hpp */
