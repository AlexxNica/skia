/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
 
#ifndef SKSL_ASTFIELDSUFFIX
#define SKSL_ASTFIELDSUFFIX

#include "SkSLASTSuffix.h"

namespace SkSL {

/**
 * A dotted identifier of the form ".foo". We refer to these as "fields" at parse time even if it is
 * actually vector swizzle (which looks the same to the parser).
 */
struct ASTFieldSuffix : public ASTSuffix {
    ASTFieldSuffix(Position position, SkString field) 
    : INHERITED(position, ASTSuffix::kField_Kind)
    , fField(std::move(field)) {}

    SkString description() const override {
        return "." + fField;
    }

    SkString fField;

    typedef ASTSuffix INHERITED;
};

} // namespace

#endif
