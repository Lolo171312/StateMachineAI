# StateMachineAI
AI behavior using State Machine

AI Behavior Implemented Using a State Machine. In this project, the AI has a component that manages the logic of its states. From the inspector, new states can be added to the AI. Each state is an UObject class that inherits from a base State class. The transition from one state to another is done through conditions, which are other UObject classes that inherit from a base Condition class.

In this project, the AI has 5 states:

Patrol: Patrols between 3 points placed in the scene.
- Chase: When it sees the player (red vision lines), it chases them.
- Attack: If it is within X distance of the player, it changes its sprite to the attack sprite.
- Investigate: While it sees the player, if the player moves away (red vision lines), it starts chasing by going to the last point - where it saw the player and then searching random points around that last known location.
- Die: When its health is <= 0, it stops performing actions.

The player can move in all directions using W, A, S, D, and can attack the enemy by pressing Space (it deals damage just by pressing it; there's no need to be within X distance).