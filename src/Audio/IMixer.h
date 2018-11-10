/*
 * Copyright 2012-2018 Falltergeist Developers.
 *
 * This file is part of Falltergeist.
 *
 * Falltergeist is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Falltergeist is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Falltergeist.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <string>

namespace Falltergeist {
    namespace UI {
        class MvePlayer;
    }
    namespace Audio {
        enum class Channel {
            Music,
            Effects,
            Speech
        };
        class IMixer {
        public:
            virtual ~IMixer() = default;
            virtual void playACMMusic(const std::string& filename, bool loop) = 0;
            virtual void playACMSpeech(const std::string& filename) = 0;
            virtual void playACMSound(const std::string& filename) = 0;
            virtual void playMovieMusic(UI::MvePlayer* mve) = 0;
            virtual std::string& lastMusic() = 0;

            /**
             * @param channel
             */
            virtual void stopChannel(Channel channel) = 0;

            /**
             * @param channel
             */
            virtual void pauseChannel(Channel channel) = 0;

            /**
             * @param channel
             */
            virtual void resumeChannel(Channel channel) = 0;

            /**
             * Sets master volume
             * @param volume from 0.0 to 1.0
             */
            virtual void setMasterVolume(double volume) = 0;

            /**
             * Returns master volume
             * @return from 0.0 to 1.0
             */
            virtual double masterVolume() = 0;

            /**
             * Sets channel volume
             * @param channel
             * @param volume from 0.0 to 1.0
             */
            virtual void setChannelVolume(Channel channel, double volume) = 0;

            /**
             * Returns channel volume
             * @param channel
             * @return from 0.0 to 1.0
             */
            virtual double channelVolume(Channel channel) = 0;
        };
    }
}
