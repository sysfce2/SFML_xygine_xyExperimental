/*********************************************************************
Matt Marchant 2016
http://trederia.blogspot.com

DoodleChum - Zlib license.

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
you must not claim that you wrote the original software.
If you use this software in a product, an acknowledgment
in the product documentation would be appreciated but
is not required.

2. Altered source versions must be plainly marked as such,
and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
source distribution.
*********************************************************************/

#include <CatAnimationTask.hpp>

#include <xygine/util/Random.hpp>

namespace
{
    const float minSleep = 110.f;
    const float maxSleep = 240.f;
    const float minSit = 102.f;
    const float maxSit = 190.f;
    const float poop = 6.f;
    const float eat = 45.f;
}

CatAnim::CatAnim(xy::Entity& e, xy::MessageBus& mb, Action action)
    :Task(e, mb),
    m_action(action),
    m_time(10.f)
{

}

//public
void CatAnim::onStart()
{
    switch (m_action)
    {
    default:
    case Action::Eat:
        m_time = eat;
        break;
    case Action::Poop:
        m_time = poop;
        break;
    case Action::Sit:
        m_time = xy::Util::Random::value(minSit, maxSit);
        break;
    case Action::Sleep:
        m_time = xy::Util::Random::value(minSleep, maxSleep);
        //TODO start particle system
        break;
    }
}

void CatAnim::update(float dt)
{
    m_time -= dt;
    if (m_time < 0)
    {
        setCompleted(Message::TaskEvent::CatTask);
        if (m_action == Action::Sleep)
        {
            //TODO stop particles
        }
    }
}