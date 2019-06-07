/* Copyright (c) 2019 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BAT_LEDGER_BALANCE_REPORT_INFO_HANDLER_
#define BAT_LEDGER_BALANCE_REPORT_INFO_HANDLER_

#include <string>
#include <vector>

#include "bat/ledger/export.h"
#include "bat/ledger/public/interfaces/ledger.mojom.h"

namespace ledger {

using BalanceReport = mojom::BalanceReport;
using BalanceReportPtr = mojom::BalanceReportPtr;
using BalanceReportList = std::vector<BalanceReportPtr>;

LEDGER_EXPORT enum ReportType {
  GRANT = 0,
  AUTO_CONTRIBUTION = 1,
  DEPOSIT = 2,
  ADS = 3,
  TIP_RECURRING = 4,
  TIP = 5
};

// TODO(jsadler): instances of this need to be converted to mojom instance
LEDGER_EXPORT struct BalanceReportInfo {
  BalanceReportInfo();
  BalanceReportInfo(const BalanceReportInfo&);
  ~BalanceReportInfo();

  const std::string ToJson() const;
  bool loadFromJson(const std::string& json);

  std::string opening_balance_ = "0";
  std::string closing_balance_ = "0";
  std::string deposits_ = "0";
  std::string grants_ = "0";
  std::string earning_from_ads_ = "0";
  std::string auto_contribute_ = "0";
  std::string recurring_donation_ = "0";
  std::string one_time_donation_ = "0";
  std::string total_ = "0";
};

}  // namespace ledger

#endif  // BAT_LEDGER_BALANCE_REPORT_INFO_HANDLER_
