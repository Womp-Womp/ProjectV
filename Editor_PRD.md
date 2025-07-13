# PRD: Project Charisma - Grand Strategy Game Creation Suite

---

**Document Version:** 1.0
**Status:** Scoping & Requirement Definition
**Author:** Product Management
**Stakeholders:** Jules (Lead AI Developer), Future Community Creators
**Date:** 2023-10-27

---

## 1. Vision & Introduction

**The Vision:** To empower creators, writers, and developers to build deep, narrative-rich, turn-based grand strategy games in the vein of the *Gihren's Greed* series, without requiring deep programming knowledge.

**Project Charisma** will be a comprehensive, all-in-one creation suite. It will consist of a powerful, intuitive editor and a robust, distributable game engine that interprets the editor's output. Creators will use Charisma to define every aspect of their game world—from the political factions and their iconic leaders to the individual stats of a grunt mobile suit, the tiles of a battlefield, and the complex web of events that drive the story forward. The ultimate goal is to foster a community of creators who can build, share, and play an infinite variety of strategy games.

This project will be developed entirely by **Jules**, our AI Software Engineer. Therefore, this document will be explicit in its technical and functional requirements. Jules has full access to our GitHub repositories for code management and a suite of VMs for compilation and testing across different platforms.

---

## 2. Problem Statement

Creating complex grand strategy games is prohibitively difficult. It requires expertise in multiple domains: engine programming, game logic, UI/UX design, data management, and scripting. Aspiring creators with compelling stories, world-building ideas, or unique gameplay mechanics are locked out by this high technical barrier. Existing game engines are often too generic for the specific needs of a tile-based, stat-heavy strategy game, while modding existing games is often restrictive.

**Project Charisma will solve this by:**
*   **Centralizing Tools:** Providing a single, integrated application for all aspects of game creation.
*   **Abstracting Complexity:** Replacing raw code with intuitive graphical user interfaces (GUIs) for most tasks.
*   **Enabling Customization:** Offering a powerful scripting layer (Lua) for creators who want to implement unique, complex game logic that goes beyond the standard UI capabilities.
*   **Decoupling Creation from Playing:** The editor outputs data files that are read by a standardized, distributable game client, allowing creators to easily share their work.

---

## 3. Target Audience / User Personas

1.  **The "World-Builder" / Modder (Primary):**
    *   **Description:** A fan of the genre (e.g., Gundam, Legend of the Galactic Heroes) who has a deep passion for the lore. They want to create "what-if" scenarios, alternate histories, or total conversions based on their favorite IP or their own original universe.
    *   **Needs:** A powerful lore and faction editor. A simple way to create and modify units. An event system to script key story moments.
    *   **Technical Skill:** Low to Medium. Comfortable with complex UIs but may not be a programmer.

2.  **The "Indie Strategist" (Secondary):**
    *   **Description:** An indie game developer who wants to prototype or fully develop a commercial grand strategy game. They understand game mechanics deeply but want to accelerate development by not having to build an engine from scratch.
    *   **Needs:** Deep control over game mechanics (damage formulas, AI behavior). A robust and well-documented scripting API (Lua). Performance and scalability. The ability to export a standalone commercial game.
    *   **Technical Skill:** High. Proficient in scripting or programming.

3.  **The "Storyteller" (Tertiary):**
    *   **Description:** A writer or visual novelist who sees the grand strategy format as a powerful medium for interactive storytelling. Their focus is on character-driven narratives and branching event chains.
    *   **Needs:** An exceptionally powerful and easy-to-use Event/Trigger/Dialogue editor. A way to manage character portraits, music, and story flags. Gameplay mechanics are secondary to the narrative.
    *   **Technical Skill:** Low.

---

## 4. Product Goals & Success Metrics

| Goal ID | Product Goal                                                | Success Metrics (Key Performance Indicators - KPIs)                                                                                                                                                                                                                            |
| :------ | :---------------------------------------------------------- | :----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| G-1     | **Enable Creation:** Users can successfully build a playable game scenario from scratch. | **Quantitative:** <br/> - Time from first-time user launch to successful "Playtest" execution < 2 hours. <br/>- % of new users who create and save at least one custom unit, one map, and one event within the first week > 50%. <br/>- Number of completed and exported "game packages" created per month. |
| G-2     | **Foster a Community:** Users share and play each other's creations. | **Quantitative:** <br/> - Number of projects uploaded to a central community hub/repository per month. <br/> - Number of downloads/plays of user-created content. <br/>- Active users on a dedicated Discord/forum. <br/> **Qualitative:** <br/>- Positive sentiment in community feedback. <br/>- Presence of collaborative projects and "total conversion" mods. |
| G-3     | **Ensure High Quality & Stability:** The editor and the resulting games are robust and performant. | **Quantitative:** <br/> - Crash rate < 0.1% per session. <br/>- Editor maintains >60 FPS during standard operations (e.g., map painting). <br/> - Game engine turn processing time < 5 seconds for a "standard" large-scale map (e.g., 200x200 tiles, 10 factions, 500 units). <br/> **Qualitative:** <br/>- Bug reports related to data corruption are near zero. |
| G-4     | **Empower Advanced Users:** The scripting engine is flexible and powerful enough for complex mechanics. | **Quantitative:** <br/> - Percentage of advanced projects that use the Lua scripting feature > 70%. <br/>- Number of functions and modules in the Lua API. <br/>- Community-created tutorials and documentation for the Lua API. <br/> **Qualitative:** <br/>- Showcase projects demonstrating unique mechanics (e.g., new resource systems, complex diplomatic actions) built entirely with Lua. |

---

## 5. Core Features / Epics

This product is comprised of two main components: The **Charisma Editor (IDE)** and the **Charisma Game Engine (Player)**.

### Epic 1: The Charisma Editor (IDE)

This is the core user-facing creation tool. It must be a single, unified desktop application with multiple, interconnected modules.

*   **F-1.1: Project Management:**
    *   Create, load, and save "Charisma Projects." A project is a self-contained folder housing all game data (maps, units, events, assets, etc.).
    *   A main dashboard that provides an overview of the project, recent files, and validation warnings (e.g., "Faction 'Zeon' has no starting units").
    *   One-click "Playtest" button to launch the Game Engine with the current project data.
    *   One-click "Export Package" to bundle the project into a single distributable file (`.cpx` - Charisma Package) for sharing.

*   **F-1.2: Map / Level Editor:**
    *   **Grid System:** Support for both Square and Hexagonal grids (selectable per map).
    *   **Tile System:**
        *   Create and manage a library of "Tiles."
        *   Tile properties: Name, graphic (sprite), terrain type (e.g., `Space`, `Ground`, `Water`, `Colony Interior`), movement cost per unit type, defense bonus (%), resource yield (e.g., `+50 Money`, `+20 Resources`).
    *   **Map Creation:**
        *   Define map dimensions (width x height).
        *   Paint tools: Brush (single tile paint), Fill (flood fill), Eraser.
        *   Layers: A base terrain layer, a location/node layer on top.
    *   **Location/Node System:**
        *   Place named locations (e.g., "Solomon," "Jaburo," "A Baoa Qu") on the map.
        *   Node properties: Name, Controlling Faction at start, special facilities (e.g., `Shipyard`, `MS Factory`, `Headquarters`), production capacity.
        *   Create links/paths between nodes for strategic movement.

*   **F-1.3: Unit Editor:**
    *   **Unit Database:** A searchable, filterable list of all units in the project.
    *   **Unit Templates & Inheritance:** Ability to create a base template (e.g., "Zaku II Frame") and create variants that inherit and override stats (e.g., "Zaku II J-Type," "Zaku II S-Type").
    *   **Core Stats:**
        *   `ID`, `Name`, `Description`.
        *   `HP` (Hit Points), `EN` (Energy/Fuel).
        *   `Attack`, `Defense`, `Mobility`.
        *   `Movement_Range`, `Movement_Type` (e.g., `Ground`, `Air`, `Space`, `Amphibious`).
        *   `Production_Cost` (Money/Resources), `Production_Time` (Turns).
        *   `Upkeep_Cost`.
        *   Size (`S`, `M`, `L`, `XL`) for stacking limits.
    *   **Weapons:** A unit can have multiple weapons. Weapon properties: `Name`, `Power`, `Range`, `Accuracy`, `EN_Cost`, `Ammo`, `Type` (`Beam`, `Physical`, `Melee`), special properties (`Penetrates_Armor`, `Stun_Effect`).
    *   **Abilities:** Passive or active abilities (e.g., "Newtype," "Phase Shift Armor," "Minovsky Craft"). These will be defined in a separate Ability Editor and linked here.
    *   **Assets:** Fields to link 2D sprite sheets (idle, move, attack), portrait/icon, and sound effects (move, attack, explode).

*   **F-1.4: Faction & Lore Editor:**
    *   **Faction Creation:**
        *   Define factions: `Name`, `Abbreviation`, `Flag/Insignia`, `Color`.
        *   Define relationships with other factions: `Neutral`, `Ally`, `War`, `Vassal`.
        *   Starting state: Starting Money/Resources, owned locations, starting units.
        *   AI Profile: Link to an AI behavior script (e.g., `Aggressive`, `Defensive`, `Expansionist`).
    *   **Leader/Character Editor:**
        *   Create characters: `Name`, `Portrait`, `Biography`.
        *   Stats for command roles: `Command`, `Melee`, `Ranged`, `Defense`.
        *   Link characters to factions. They can be commanders of units or faction leaders.
    *   **Technology Tree Editor:**
        *   A visual node-based editor for creating tech trees.
        *   Each node is a "Technology" which can unlock new units, facilities, or global bonuses.
        *   Tech properties: `Name`, `Description`, `Research_Cost`, `Dependencies` (requires other techs).
    *   **Lore Database:**
        *   A simple, wiki-style text editor with hyperlinking capability.
        *   Create pages for `Eras`, `Events`, `Organizations`, `Technology Lore`. Allows the creator to build an in-game encyclopedia accessible to the player.

*   **F-1.5: Event, Trigger, and Scripting Editor (The Core Logic Engine):**
    *   **GUI-based Triggers:** An intuitive interface for creating simple event triggers.
        *   "WHEN (Trigger)..." -> Dropdown list of conditions:
            *   `Turn Number` (`is`, `>`, `<`)
            *   `Faction Captures Location`
            *   `Unit is Destroyed`
            *   `Player Selects Dialogue Option`
        *   "...AND IF (Conditions)..." -> Add more granular checks:
            *   `Faction Resource Level`
            *   `Character_A is in play`
            *   `Technology_X is researched`
        *   "...THEN DO (Actions)" -> List of possible outcomes:
            *   `Show Dialogue Box` (with character portraits and text).
            *   `Give Unit(s)` to a faction.
            *   `Change Faction Relationship`.
            *   `Give Resources`.
            *   `Play Music / Sound Effect`.
            *   `Move Camera to Location`.
            *   `Trigger another Event`.
    *   **Lua Scripting Integration:**
        *   For any `Action`, provide an option to "Run Lua Script."
        *   A built-in text editor with syntax highlighting for Lua.
        *   **CRITICAL:** A comprehensive, well-documented **Charisma Lua API**. Jules must create this API. Example functions:
            ```lua
            -- Game State API
            local turn = Game.GetTurnNumber()
            local zeon = Faction.GetByName("Zeon")
            local amuro = Character.GetByName("Amuro Ray")

            -- Faction Manipulation
            zeon:AddResources("Money", 5000)
            zeon:DeclareWarOn(Faction.GetByName("Federation"))

            -- Unit Manipulation
            local unit = Unit.GetById(amuro.assigned_unit_id)
            if unit then
              unit:SetHP(unit.max_hp) -- Heal unit
              unit:AddExperience(100)
            end

            -- UI API
            UI.ShowDialogue({
              title = "A Fateful Encounter",
              character_left = "Amuro Ray",
              character_right = "Char Aznable",
              text = "I've been waiting for you!",
            })
            UI.PlayMusic("path/to/encounter_theme.ogg")

            -- Event API
            Event.SetFlag("amuro_met_char", true)
            Event.Trigger("the_red_comet_escapes")
            ```

*   **F-1.6: Media Manager (Music, SFX, Graphics):**
    *   A simple asset browser within the editor.
    *   Users can import `PNG` files for sprites/portraits and `OGG`/`MP3` files for audio.
    *   Assign aliases to asset files (e.g., `sfx_beam_rifle` points to `assets/audio/br_01.ogg`). This allows for easy asset swapping.

### Epic 2: The Charisma Game Engine (Player)

This is the standalone executable (`.exe`, etc.) that runs the games created by the editor. It will be packaged with exported projects.

*   **F-2.1: Data Loading:** The engine's primary function is to parse the project data (`.json`, `.xml`, or a custom binary format) created by the editor.
*   **F-2.2: Game Loop:** Implement a classic turn-based game loop: Faction 1 Turn -> Faction 2 Turn -> ... -> Event Phase -> Faction 1 Turn.
*   **F-2.3: Gameplay UI:**
    *   Render the map and units.
    *   Display unit/tile/faction information on hover/click.
    *   UI panels for managing production, research, diplomacy, and the in-game lore encyclopedia.
    *   Handle player input for moving units, attacking, and managing bases.
*   **F-2.4: Combat System:**
    *   When a unit attacks another, a combat sequence is initiated.
    *   The PRD allows for two modes (selectable by the creator per project):
        1.  **Simplified:** A simple dice roll based on stats. Result is shown immediately on the map.
        2.  **Cinematic (Gihren's Greed style):** A separate screen appears showing simplified 2D sprite animations of the units fighting. The outcome is determined by a series of stat-based calculations.
*   **F-2.5: AI System:**
    *   The engine must include a baseline AI capable of managing its economy, producing units, moving armies, and attacking targets based on the "AI Profile" set in the Faction Editor.
    *   The AI logic should be extensible via the Lua API, allowing advanced users to write their own AI behavior scripts.
*   **F-2.6: Save/Load System:** The player must be able to save and load their progress in any game created with Charisma.

---

## 6. Non-Functional Requirements (NFRs)

*   **NFR-1: Performance:** The editor must be responsive. Map scrolling/painting and database filtering must be instantaneous. The game engine must handle large maps and high unit counts efficiently (see G-3).
*   **NFR-2: Platform Support:** Both the Editor and the distributable Game Engine must be compiled for Windows, macOS, and Linux.
*   **NFR-3: Usability:** The Editor's UI must be clean, modern, and intuitive. Tooltips should be everywhere. A "getting started" tutorial should be included.
*   **NFR-4: Modularity:** Jules should architect the codebase in a highly modular fashion. The rendering engine, data model, UI toolkit, and scripting engine should be loosely coupled to facilitate future upgrades.
*   **NFR-5: Data Format:** All editor data should be saved in a human-readable format (like JSON or YAML) during development for easy debugging, but the final exported package (`.cpx`) should be a compressed archive for portability.

---

## 7. Technology Stack (Proposal for Jules)

*   **Editor Application Framework:** Qt (using C++) or Electron (using TypeScript). Qt offers native performance and cross-platform widgets. Electron allows for faster UI development using web technologies. **Decision for Jules: Evaluate both, but prioritize the performance and native feel of Qt for tools like the map editor.**
*   **Game Engine Core:** C++. This is non-negotiable for performance in the game client.
*   **Rendering Library:** SFML or SDL2 for 2D graphics. They are mature, cross-platform, and well-suited for this project.
*   **Scripting Engine:** Lua. It's lightweight, fast, and easy to embed. We will use a modern Lua version (like LuaJIT or 5.4) with a C++ binding library like `sol2`.
*   **Build System:** CMake for cross-platform project building.
*   **Version Control:** Git. Jules will make atomic, well-documented commits for each feature implementation to the designated repository.

---

## 8. Out of Scope (For Version 1.0)

*   **Multiplayer:** The initial release will be single-player only.
*   **3D Models:** All graphics will be 2D sprites.
*   **Real-time Strategy:** The gameplay is strictly turn-based.
*   **Voice Acting Support:** While audio files can be played, there will be no dedicated lip-syncing or complex audio timing tools in the dialogue editor.
*   **Procedural Generation:** All maps and scenarios are manually created by the user.

---

## 9. Risks & Mitigation

*   **Risk: Feature Creep.** The potential for adding "just one more thing" is enormous.
    *   **Mitigation:** Stick strictly to this PRD for v1.0. All new ideas will be added to a "Future Work" backlog.
*   **Risk: Overly Complex UI.** The editor could become a maze of buttons and fields.
    *   **Mitigation:** A strong focus on UX from the start. Jules will create wireframes/mockups for approval before implementation. Each module should be self-contained and hide complexity unless needed.
*   **Risk: Brittle Lua API.** A poorly designed API could be hard to use and break easily with game updates.
    *   **Mitigation:** The API must be designed with extensibility in mind. All game state modifications must go through the API, not direct memory manipulation. It must be documented with Doxygen or a similar tool.
*   **Risk: Poor AI.** A weak default AI will make the games uninteresting.
    *   **Mitigation:** Develop the AI against a set of benchmark scenarios. The AI doesn't need to be unbeatable, but it must be competent. Make it a priority to ensure the AI can be fully replaced by user scripts.
