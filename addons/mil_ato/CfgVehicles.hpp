class CfgSFX
{
    class AirRaidSiren
    {
        Alarm_BLUFOR[] = {"A3\Sounds_F\sfx\alarm_blufor",1,1,800,1,0,0,0};
        empty[] = {"", 0, 0, 0, 0, 0, 0, 0};
        name = "Air Raid Siren";
        sounds[] = {"Alarm_BLUFOR"};
    };
};
class CfgVehicles
{
    class Logic;
    class Module_F : Logic
    {
        class AttributesBase
        {
            class Edit;
            class Combo;
            class ModuleDescription;
        };
    };
    class ModuleAliveBase : Module_F
    {
        class AttributesBase : AttributesBase
        {
            class ALiVE_ModuleSubTitle;
        };
        class ModuleDescription;
    };
    class ADDON : ModuleAliveBase
    {
        scope = 2;
        displayName = "$STR_ALIVE_ATO";
        function = "ALIVE_fnc_ATOInit";
        author = MODULE_AUTHOR;
        functionPriority = 190;
        isGlobal = 1;
        icon = "x\alive\addons\mil_ato\icon_mil_ATO.paa";
        picture = "x\alive\addons\mil_ato\icon_mil_ATO.paa";
        class Attributes : AttributesBase
        {
                // ---- General --------------------------------------------------------
                class HDR_GENERAL : ALiVE_ModuleSubTitle { property = "ALiVE_mil_ato_HDR_GENERAL"; displayName = "GENERAL"; };
                class debug : Combo
                {
                        property = "ALiVE_mil_ato_debug";
                        displayName = "$STR_ALIVE_ATO_DEBUG";
                        tooltip = "$STR_ALIVE_ATO_DEBUG_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; };
                            class No { name = "No"; value = false; default = 1; };
                        };
                };
                class persistent : Combo
                {
                        property = "ALiVE_mil_ato_persistent";
                        displayName = "$STR_ALIVE_ATO_PERSISTENT";
                        tooltip = "$STR_ALIVE_ATO_PERSISTENT_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class No { name = "No"; value = false; default = 1; };
                            class Yes { name = "Yes"; value = true; };
                        };
                };
                // Shared ALiVE_FactionChoice dropdown - see addons/main/CfgVehicles.hpp.
                class faction
                {
                        property     = "ALiVE_mil_ato_faction";
                        displayName  = "$STR_ALIVE_ATO_FACTION";
                        tooltip      = "$STR_ALIVE_ATO_FACTION_COMMENT";
                        control      = "ALiVE_FactionChoice_Military";
                        typeName     = "STRING";
                        expression   = "_this setVariable ['faction', _value];";
                        defaultValue = """OPF_F""";
                };
                // ---- Air Operations ------------------------------------------------
                class HDR_OPS : ALiVE_ModuleSubTitle { property = "ALiVE_mil_ato_HDR_OPS"; displayName = "AIR OPERATIONS"; };
                // Multi-select picker rather than a free-text array. The old Edit
                // asked the mission maker to hand-type ['CAP','DCA',...]; a typo
                // silently disabled a mission type with no feedback, and the bare
                // acronyms explained nothing. Stored as CSV of the same tokens.
                //
                // OCA is included: it is fully implemented and the AI commander
                // raises it against enemy airfields, but it was missing from the
                // old default, so Editor-placed modules dropped those requests
                // without a word. AS is absent - it has no implementation at all.
                class types
                {
                        property     = "ALiVE_mil_ato_types";
                        displayName  = "$STR_ALIVE_ATO_TYPES";
                        tooltip      = "$STR_ALIVE_ATO_TYPES_COMMENT";
                        control      = "ALiVE_ATOTypeChoiceMulti";
                        typeName     = "STRING";
                        expression   = "_this setVariable ['types', _value];";
                        defaultValue = """CAP,DCA,SEAD,CAS,Strike,Recce,OCA""";
                };
                class airspace : Edit
                {
                        property = "ALiVE_mil_ato_airspace";
                        displayName = "$STR_ALIVE_ATO_AIRSPACE";
                        tooltip = "$STR_ALIVE_ATO_AIRSPACE_COMMENT";
                        defaultValue = """""";
                };
                // What the commander's radar picture is built from. The airspace and
                // air defence scans read the vehicles array, which only ever holds
                // spawned objects - so on a virtualised battlefield most enemy air and
                // most enemy air defence is invisible to it. "All profiles" adds a
                // sweep of enemy vehicle profiles inside the airspace. Left on spawned
                // aircraft only by default because the profile sweep costs time on
                // every scan and changes what the AI commander reacts to.
                class radarCoverage : Combo
                {
                        property = "ALiVE_mil_ato_radarCoverage";
                        displayName = "$STR_ALIVE_ATO_RADAR_COVERAGE";
                        tooltip = "$STR_ALIVE_ATO_RADAR_COVERAGE_COMMENT";
                        defaultValue = """spawned""";
                        class Values
                        {
                            class SPAWNED { name = "$STR_ALIVE_ATO_RADAR_COVERAGE_SPAWNED"; value = "spawned"; default = 1; };
                            class PROFILES { name = "$STR_ALIVE_ATO_RADAR_COVERAGE_PROFILES"; value = "profiles"; };
                        };
                };
                class createHQ : Combo
                {
                        property = "ALiVE_mil_ato_createHQ";
                        displayName = "$STR_ALIVE_ATO_CREATE_HQ";
                        tooltip = "$STR_ALIVE_ATO_CREATE_HQ_COMMENT";
                        defaultValue = """true""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; default = 1; };
                            class No { name = "No"; value = false; };
                        };
                };
                class placeAir : Combo
                {
                        property = "ALiVE_mil_ato_placeAir";
                        displayName = "$STR_ALIVE_ATO_PLACE_AIR";
                        tooltip = "$STR_ALIVE_ATO_PLACE_AIR_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; };
                            class No { name = "No"; value = false; default = 1; };
                        };
                };
                class generateTasks : Combo
                {
                        property = "ALiVE_mil_ato_generateTasks";
                        displayName = "$STR_ALIVE_ATO_GENERATE_TASKS";
                        tooltip = "$STR_ALIVE_ATO_GENERATE_TASKS_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class No { name = "No"; value = false; default = 1; };
                            class Yes { name = "Yes"; value = true; };
                        };
                };
                class generateSEADTasks : Combo
                {
                        property = "ALiVE_mil_ato_generateSEADTasks";
                        displayName = "$STR_ALIVE_ATO_GENERATE_SEADTASKS";
                        tooltip = "$STR_ALIVE_ATO_GENERATE_SEADTASKS_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class No { name = "No"; value = false; default = 1; };
                            class Yes { name = "Yes"; value = true; };
                        };
                };
                // Off by default: DCA needs a Fighter-role airframe, and a faction
                // that catalogues none answers an interception request with a silent
                // denial and no fallback. Only the target's own profile decides -
                // helicopters and ground contacts keep CAS either way.
                class counterAir : Combo
                {
                        property = "ALiVE_mil_ato_counterAir";
                        displayName = "$STR_ALIVE_ATO_COUNTER_AIR";
                        tooltip = "$STR_ALIVE_ATO_COUNTER_AIR_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class No { name = "No"; value = false; default = 1; };
                            class Yes { name = "Yes"; value = true; };
                        };
                };
                // The AI SEAD sortie has been commented out of the source for years
                // with the note that aircraft get owned by AA, so suppression was
                // whatever players chose to do about the setting above. Turning this
                // on flies it again, but only against air defences the commander is
                // confident about, at standoff, and two airframes at a time - and a
                // package that does not come back bars the target and hands it to the
                // ground commander. Off by default: it spends aircraft.
                class enableAISEAD : Combo
                {
                        property = "ALiVE_mil_ato_enableAISEAD";
                        displayName = "$STR_ALIVE_ATO_ENABLE_AI_SEAD";
                        tooltip = "$STR_ALIVE_ATO_ENABLE_AI_SEAD_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class No { name = "No"; value = false; default = 1; };
                            class Yes { name = "Yes"; value = true; };
                        };
                };
                // Air request rate: above Normal, a synced commander's contact
                // response also fans sorties across its known-enemy picture
                // instead of answering the single lead target. Default Normal
                // keeps today's behaviour exactly. Every fanned sortie spawns
                // its target's profile, so this is the virtualization load dial
                // as much as the tempo one (needs OPCOM).
                class airRequestRate : Combo
                {
                        property = "ALiVE_mil_ato_airRequestRate";
                        displayName = "$STR_ALIVE_ATO_AIR_REQUESTRATE";
                        tooltip = "$STR_ALIVE_ATO_AIR_REQUESTRATE_COMMENT";
                        defaultValue = """NORMAL""";
                        class Values
                        {
                            class Normal { name = "Normal (1 target)"; value = "NORMAL"; default = 1; };
                            class High { name = "High (2 targets)"; value = "HIGH"; };
                            class Surge { name = "Surge (3 targets)"; value = "SURGE"; };
                        };
                };
                // Defaults to Yes. Ground forces are reinforced through the Logistics
                // Commander as a matter of course, so air was the only arm that could
                // only ever shrink - every loss permanent, and a commander with nothing
                // left refuses every request for the rest of the mission. A default that
                // steers long campaigns toward that dead end is the wrong one.
                class Resupply : Combo
                {
                        property = "ALiVE_mil_ato_Resupply";
                        displayName = "$STR_ALIVE_ATO_RESUPPLY";
                        tooltip = "$STR_ALIVE_ATO_RESUPPLY_COMMENT";
                        defaultValue = """true""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; default = 1; };
                            class No { name = "No"; value = false; };
                        };
                };
                class broadcastOnRadio : Combo
                {
                        property = "ALiVE_mil_ato_broadcastOnRadio";
                        displayName = "$STR_ALIVE_ATO_BROADCASTONRADIO";
                        tooltip = "$STR_ALIVE_ATO_BROADCASTONRADIO_COMMENT";
                        defaultValue = """true""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; default = 1; };
                            class No { name = "No"; value = false; };
                        };
                };
                // Override for factions that catalogue no drones of their own, which is
                // common regardless of what the mod itself ships. Same shape as the
                // artillery module's custom type field.
                class droneTypes
                {
                        property     = "ALiVE_mil_ato_droneTypes";
                        displayName  = "$STR_ALIVE_ATO_DRONE_TYPES";
                        tooltip      = "$STR_ALIVE_ATO_DRONE_TYPES_COMMENT";
                        control      = "ALiVE_DroneChoiceMulti";
                        typeName     = "STRING";
                        expression   = "_this setVariable ['droneTypes', _value];";
                        defaultValue = """""";
                };
                // Separate from Place Air Assets on purpose: a drone needs no aircrew,
                // so an air component can consist of drones alone, and that should not
                // depend on whether crewed aircraft were wanted too.
                class placeDrones : Combo
                {
                        property = "ALiVE_mil_ato_placeDrones";
                        displayName = "$STR_ALIVE_ATO_PLACE_DRONES";
                        tooltip = "$STR_ALIVE_ATO_PLACE_DRONES_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; };
                            class No { name = "No"; value = false; default = 1; };
                        };
                };
                // Defaults to Yes - the module has flown drones for years and carries
                // dedicated handling for their lack of a crew. The setting exists so a
                // mission maker can say no, which was not previously possible.
                class useUAVs : Combo
                {
                        property = "ALiVE_mil_ato_useUAVs";
                        displayName = "$STR_ALIVE_ATO_USE_UAVS";
                        tooltip = "$STR_ALIVE_ATO_USE_UAVS_COMMENT";
                        defaultValue = """true""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; default = 1; };
                            class No { name = "No"; value = false; };
                        };
                };
                // Off by default: this is the only setting that makes the commander
                // task itself rather than answer a request, so it has to be asked for.
                // Needs Use Drones on and Recce in the mission types to do anything.
                class droneISR : Combo
                {
                        property = "ALiVE_mil_ato_droneISR";
                        displayName = "$STR_ALIVE_ATO_DRONE_ISR";
                        tooltip = "$STR_ALIVE_ATO_DRONE_ISR_COMMENT";
                        defaultValue = """false""";
                        class Values
                        {
                            class Yes { name = "Yes"; value = true; };
                            class No { name = "No"; value = false; default = 1; };
                        };
                };
                // Tempo controls. Both blank by default and blank means "as before",
                // so an untouched mission is byte-identical in behaviour.
                class sortieDuration : Edit
                {
                        property = "ALiVE_mil_ato_sortieDuration";
                        displayName = "$STR_ALIVE_ATO_SORTIE_DURATION";
                        tooltip = "$STR_ALIVE_ATO_SORTIE_DURATION_COMMENT";
                        defaultValue = """""";
                };
                class minAssetsForOffensive : Edit
                {
                        property = "ALiVE_mil_ato_minAssetsForOffensive";
                        displayName = "$STR_ALIVE_ATO_MIN_ASSETS";
                        tooltip = "$STR_ALIVE_ATO_MIN_ASSETS_COMMENT";
                        defaultValue = """""";
                };
                // Aircrew, not runway geometry - this was previously filed under the
                // runway section, where nobody would think to look for it.
                class pilotbuilding : Edit
                {
                        property = "ALiVE_mil_ato_pilotbuilding";
                        displayName = "$STR_ALIVE_ATO_PILOTBUILDING";
                        tooltip = "$STR_ALIVE_ATO_PILOTBUILDING_COMMENT";
                        defaultValue = """""";
                        typeName = "STRING";
                };
                // ---- Objective Objects (#875) ---------------------------------------
                class HDR_OBJECTIVES : ALiVE_ModuleSubTitle { property = "ALiVE_mil_ato_HDR_OBJECTIVES"; displayName = "$STR_ALIVE_OBJECTIVE_HDR"; };
                // Airfield radar arrays are a strong thematic fit for ATO.
                // AA-style triplet: count Edit + behaviour Combo + picker.
                class objectiveObjectsCount : Edit
                {
                        property     = "ALiVE_mil_ato_objectiveObjectsCount";
                        displayName  = "$STR_ALIVE_OBJECTIVE_OBJECTS_COUNT";
                        tooltip      = "$STR_ALIVE_OBJECTIVE_OBJECTS_COUNT_COMMENT";
                        defaultValue = """0""";
                };
                class objectiveObjectsChance : Edit
                {
                        property     = "ALiVE_mil_ato_objectiveObjectsChance";
                        displayName  = "$STR_ALIVE_OBJECTIVE_OBJECTS_CHANCE";
                        tooltip      = "$STR_ALIVE_OBJECTIVE_OBJECTS_CHANCE_COMMENT";
                        defaultValue = """100""";
                };
                class objectiveObjectsBehaviour : Combo
                {
                        property     = "ALiVE_mil_ato_objectiveObjectsBehaviour";
                        displayName  = "$STR_ALIVE_OBJECTIVE_OBJECTS_BEHAVIOUR";
                        tooltip      = "$STR_ALIVE_OBJECTIVE_OBJECTS_BEHAVIOUR_COMMENT";
                        defaultValue = """dispersed""";
                        class Values
                        {
                            class CLUSTERED { name = "$STR_ALIVE_OBJECTIVE_OBJECTS_BEHAVIOUR_CLUSTERED"; value = "clustered"; };
                            class DISPERSED { name = "$STR_ALIVE_OBJECTIVE_OBJECTS_BEHAVIOUR_DISPERSED"; value = "dispersed"; default = 1; };
                            class PERIMETER { name = "$STR_ALIVE_OBJECTIVE_OBJECTS_BEHAVIOUR_PERIMETER"; value = "perimeter"; };
                        };
                };
                class objectiveObjects
                {
                        property     = "ALiVE_mil_ato_objectiveObjects";
                        displayName  = "$STR_ALIVE_OBJECTIVE_OBJECTS";
                        tooltip      = "$STR_ALIVE_OBJECTIVE_OBJECTS_COMMENT";
                        control      = "ALiVE_ObjectiveObjectChoice";
                        typeName     = "STRING";
                        expression   = "_this setVariable ['objectiveObjects', _value];";
                        defaultValue = """""";
                };
                // ---- Advanced airfield overrides -----------------------------------
                // Rarely needed. ALiVE already detects real runways and taxiways by itself
                // (see ALiVE_fnc_getAirfieldGeometry); these exist only for terrains where
                // that detection falls short. They feed composition and parking exclusion -
                // they do NOT decide where aircraft take off and land.
                class HDR_RUNWAY : ALiVE_ModuleSubTitle { property = "ALiVE_mil_ato_HDR_RUNWAY"; displayName = "ADVANCED - AIRFIELD OVERRIDES"; };
                class runwaystartpos : Edit
                {
                        property = "ALiVE_mil_ato_runwaystartpos";
                        displayName = "$STR_ALIVE_ATO_RUNWAYSTARTPOS";
                        tooltip = "$STR_ALIVE_ATO_RUNWAYSTARTPOS_COMMENT";
                        defaultValue = """""";
                };
                class runwayendpos : Edit
                {
                        property = "ALiVE_mil_ato_runwayendpos";
                        displayName = "$STR_ALIVE_ATO_RUNWAYENDPOS";
                        tooltip = "$STR_ALIVE_ATO_RUNWAYENDPOS_COMMENT";
                        defaultValue = """""";
                };
                class runwaywidth : Edit
                {
                        property = "ALiVE_mil_ato_runwaywidth";
                        displayName = "$STR_ALIVE_ATO_RUNWAYWIDTH";
                        tooltip = "$STR_ALIVE_ATO_RUNWAYWIDTH_COMMENT";
                        defaultValue = """""";
                };
                class ModuleDescription : ModuleDescription {};
        };
        class ModuleDescription
        {
            description[] = {"$STR_ALIVE_ATO_COMMENT","","$STR_ALIVE_ATO_USAGE"};
            sync[] = {"ALiVE_mil_OPCOM","ALiVE_sys_factioncompiler"};
            class ALiVE_mil_OPCOM
            {
                description[] = {"$STR_ALIVE_OPCOM_COMMENT","","$STR_ALIVE_OPCOM_USAGE"};
                position = 1; direction = 0; optional = 1; duplicate = 1;
            };
            class ALiVE_sys_factioncompiler
            {
                description[] = {"Custom Faction Compiler module."};
                position = 0; direction = 0; optional = 1; duplicate = 0;
            };
        };
    };
    class StaticMGWeapon;
    class AAA_System_01_base_F : StaticMGWeapon { class textureSources { class Sand { factions[] = {"BLU_F","OPF_F"}; }; }; };
    class B_AAA_System_01_F : AAA_System_01_base_F { class EventHandlers; };
    class O_AAA_System_01_F : B_AAA_System_01_F
    {
        class EventHandlers: EventHandlers { init = "if (local (_this select 0)) then {[(_this select 0), """", false, false] call bis_fnc_initVehicle;};"; };
        crew = "O_UAV_AI"; faction = "OPF_F"; side = 0; typicalCargo[] = {"O_UAV_AI"}; textureList[] = {"Sand",1};
    };
    class SAM_System_01_base_F : StaticMGWeapon { class textureSources { class Sand { factions[] = {"BLU_F","OPF_F"}; }; }; };
    class SAM_System_02_base_F : StaticMGWeapon { class textureSources { class Sand { factions[] = {"BLU_F","OPF_F"}; }; }; };
    class B_SAM_System_01_F : SAM_System_01_base_F { class EventHandlers; };
    class O_SAM_System_01_F : B_SAM_System_01_F
    {
        class EventHandlers: EventHandlers { init = "if (local (_this select 0)) then {[(_this select 0), """", false, false] call bis_fnc_initVehicle;};"; };
        crew = "O_UAV_AI"; faction = "OPF_F"; side = 0; typicalCargo[] = {"O_UAV_AI"}; textureList[] = {"Sand",1};
    };
    class B_SAM_System_02_F : SAM_System_02_base_F { class EventHandlers; };
    class O_SAM_System_02_F : B_SAM_System_02_F
    {
        class EventHandlers: EventHandlers { init = "if (local (_this select 0)) then {[(_this select 0), """", false, false] call bis_fnc_initVehicle;};"; };
        crew = "O_UAV_AI"; faction = "OPF_F"; side = 0; typicalCargo[] = {"O_UAV_AI"}; textureList[] = {"Sand",1};
    };
    class Sound;
    class Sound_AirRaidSiren : Sound { author = "ALiVE Team"; displayName = "Air Raid Siren"; scope = 2; sound = "AirRaidSiren"; };
};
