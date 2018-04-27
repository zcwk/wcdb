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

#ifndef LangIndexedColumn_hpp
#define LangIndexedColumn_hpp

#include <WCDB/LangCommon.hpp>

namespace WCDB {

namespace Lang {

class IndexedColumn : public Lang {
public:
    IndexedColumn();
    enum class Switch : int {
        NotSet,
        Column,
        Expr,
    };
    Switch switcher;
    CopyOnWriteLazyLang<Column> column;
    CopyOnWriteLazyLang<Expr> expr;
    CopyOnWriteString collationName;
    Order order;

    CopyOnWriteString SQL() const;
};

} // namespace Lang

} // namespace WCDB

#endif /* LangIndexedColumn_hpp */
