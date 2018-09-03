#include "counter.h"

counter_c::counter_c() noexcept : QObject (), m_nValue{0}
{

}

void counter_c::slotInc() noexcept
{
   emit sigCounterChanged(++m_nValue);

    if (m_nValue == 5)
        emit sigGoodbye();
}

