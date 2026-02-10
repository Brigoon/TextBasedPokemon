# Starting a Battle

```c
#include <lib/customMonsters.h>
#include "battleEngine.h"

Bulbasaur bulbasaur;
Chikorita chikorita;
BattleEngine::StateMachine fsm;
fsm.commenceBattle(&chikorita, &bulbasaur);
```
