# Bomberman World — Boom Eternal

**Student:** Vincent Jung
## How to play

- **Controls:**
  - movement:  WASD,
  - place bomb: space bar,
  - restart / start: R,
  - quit: Q, Esc
- **Objective and rules:**
	- Kill 10 enemies to win.
	- If you die, you lose. If you die and kill 10 enemies, you still lose.
    - You have 5 health.
    - The player has 3 bombs and can use them to kill enemies and destroy walls.
    - After a bomb detonates the player can place it again.
    - Walls can drop bomb reach upgrades that modify the length of the bomb explosion.
    - After the player recieves damage, the player is invulnerable for a short duration. 

- **Configurations / demo setup:**
	- F1: toggle debug hud

## Features and validation

| Feature                          | Check                                                                                                                                                                                                                                 | observed result                                                                                                                                                                                                                                         | expected behaviour                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       |
| -------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 1. Player damage and death       | testes: Player gets damaged when moving into an enemy. <br>Player gets damaged when enemy moves into the player. Player gets damaged when the player is getting hit by a bomb explosion.                                              | Bomb explosion and enemy moving into the player, removed 1 health. player moving into an enemy, depleted all the players health.                                                                                                                        | Every instance of damage should just do 1 damage, the moving into a enemy did more which did not match expectations. This happens because, the player can get damaged every frame, and because we move the character every frame, if we run on 60fps, in 1 seconds the player gets 60 damage from moving into a enemy. The base behavior is correct, there is only 1 instance of damage per frame, but just on its own this is not intended for the player to die when moving into an enemy. The extension Temporary invulnerability fixes this problem. |
| 2. Round states and objective    | I added a debug output for the current game state and tested each outcome, mostly after also implementing the restart.                                                                                                                | The debug output shoed the right state.                                                                                                                                                                                                                 | The feature matched my expectations, I decided to add a starting state as well to show the objective in the beginning.                                                                                                                                                                                                                                                                                                                                                                                                                                   |
| 3. Safe restart                  | Played multiple rounds, tested restarting with an active bomb, an exploding bomb, having damage, placed all bombs.                                                                                                                    | At first the level reset as well, but recreating the random generator and recreating the map worked. Otherwise I observed that the game reset and recreated the same level as before.                                                                   | Besides the level changing in the beginning, the rest was as expected.<br>Every addition has to add their cleanup code to the restart function.                                                                                                                                                                                                                                                                                                                                                                                                          |
| 4. Solid bombs with owner escape | First I just made them solid, and tested that. After that worked I added the escape, and tested with the player moving off and trying to move back into it, as well as placing it in the way of enemies.                              | Just making the bomb solid made the player stuck, placing the bomb in the same tile as an enemy made the enemy also stuck. with the owner escape the owner was able to move in the same space, until they moved off. they were not able to enter again. | The observation matched my expectation. Only that the enemy can get stuck if you place a bomb underneath them feels bad, a further addition could be that every entity can leave bombs they stand on, owner or not.                                                                                                                                                                                                                                                                                                                                      |
| 5. Blast-range pickup            | I added a debug element that shows the current bomb reach for testing. For the early tests I generated a lot of upgrades, and reduced the base bomb reach. I tested placing bombs in open space with different upgrades and at walls. | The debug increased as expected, as well as the explosion effect changed as well. Walls still blocked the explosion, only one wall got destroyed.                                                                                                       | The observation matched my expectation.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| 6. Multiple bombs per owner      | Placed multiple bombs, tried to place more then allowed, tried to place in walls and on top of each other.                                                                                                                            | Placing multiple worked, there were the right amount of bombs, never more than allowed. But bombs were able to be placed in walls and on top of each other, which needed to be fixed.                                                                   | Just the placing of multiple was as expected, the placement in walls was not but was fixed with a collision test before placing.                                                                                                                                                                                                                                                                                                                                                                                                                         |
| 7. Chain reactions               | I placed multiple bombs in a row, in range and out of range.<br>I also tested picking up a range upgrade in between placing behaved.                                                                                                  | When the bombs where in range they triggered each other, when they were not they did not. Range upgrades only applied to new bombs.                                                                                                                     | The observation matched my expectation.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
| 8. Temporary invulnerability     | I tested all instances of damage again, moving into an enemy, getting hit by a bomb, getting hit by multiple bombs at the same time.                                                                                                  | I observed that each instance now just damaged one, and if there were multiple sources, just the first one hit, so moving into an enemy did just 1 damage, and getting hit be multiple bombs also just did 1 damage.                                    | The observation matched my expectation.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |

**Known issues:**
- Enemies get stuck on player bombs if they were placed in the same space.
- The win condition can be really hard, if you play an a big map.

## Sources and assistance

This project builds on the shared Kotte foundations.
- raylib cheatsheet: https://www.raylib.com/cheatsheet/cheatsheet.html
- “None beyond the course material”

## Architectural investigation — VG only

Delete this section for a G submission. For VG, pose a focused engineering question about one decision in your implementation, investigate it, and draw a conclusion from evidence. Documenting the explanation already required for G is not enough. Aim for half a page to one page, excluding small tables, diagrams, or code excerpts. You can use the same decision in your presentation too.

### Decision

[State the question you are investigating and the implementation decision it concerns. Describe your current approach and a plausible alternative. Identify the relevant code. You do not need to implement the alternative.]

### Method

[How did you investigate the decision? Give enough detail to reproduce the key observation: setup, input, configuration/seed, and the test, trace, debugger inspection, or other method used.]

### Evidence

[What did you actually observe in your game? Include the relevant result or a small excerpt, table, or link to supporting material.]

### Interpretation

[Explain why it happened using the relevant code or architecture. Analyse at least one edge case, failure, defect, limitation, or trade-off illustrated by the investigation. Discuss relevant consequences for correctness, maintainability, performance, and/or scalability; you do not need to cover all four.]

### Conclusion

[When is your approach appropriate, what limits it, and when might an alternative become preferable? Base the conclusion on your evidence. Confirming that the current approach is suitable is a valid result.]

<!-- Submission: commit and push this README with your source to GitHub or the internal Gitea server. Submit the final commit link and a runnable Release ZIP from that version in Studium. Ensure the teacher can access the repository throughout assessment. -->
