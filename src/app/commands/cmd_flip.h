/* Aseprite
 * Copyright (C) 2001-2013  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef APP_COMMANDS_CMD_FLIP_H_INCLUDED
#define APP_COMMANDS_CMD_FLIP_H_INCLUDED
#pragma once

#include "app/commands/command.h"
#include "doc/algorithm/flip_type.h"

namespace app {

  class FlipCommand : public Command {
  public:
    FlipCommand();
    Command* clone() const override { return new FlipCommand(*this); }

    doc::algorithm::FlipType getFlipType() const { return m_flipType; }

  protected:
    void onLoadParams(Params* params);
    bool onEnabled(Context* context);
    void onExecute(Context* context);
    std::string onGetFriendlyName() const;

  private:
    bool m_flipMask;
    doc::algorithm::FlipType m_flipType;
  };

} // namespace app

#endif // APP_COMMANDS_CMD_FLIP_H_INCLUDED
