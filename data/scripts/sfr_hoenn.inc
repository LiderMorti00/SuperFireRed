@ Super Fire Red: Hoenn after the events of Emerald.
@ Runs once, when the player first arrives at Slateport from Kanto. Every Emerald story
@ event counts as already done: story vars get their final value, Team Aqua/Magma and
@ the NPCs of the old story scenes are hidden, and the story flags are set.

SFR_EventScript_InitHoennWorld::
	goto_if_set FLAG_SFR_HOENN_WORLD_INIT, SFR_EventScript_InitHoennWorldDone
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 5
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_BIRCH_LAB_STATE, 5
	setvar VAR_ROUTE101_STATE, 3
	setvar VAR_OLDALE_TOWN_STATE, 1
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setvar VAR_ROUTE110_STATE, 1
	setvar VAR_SLATEPORT_CITY_STATE, 2
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	setvar VAR_PETALBURG_CITY_STATE, 5
	setvar VAR_PETALBURG_GYM_STATE, 6
	setvar VAR_RUSTBORO_CITY_STATE, 8
	setvar VAR_ROUTE104_STATE, 2
	setvar VAR_PETALBURG_WOODS_STATE, 1
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setvar VAR_ROUTE118_STATE, 1
	setvar VAR_ROUTE119_STATE, 1
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	setvar VAR_MT_PYRE_STATE, 3
	setvar VAR_JAGGED_PASS_STATE, 2
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	setvar VAR_MOSSDEEP_CITY_STATE, 3
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 3
	setvar VAR_MOSSDEEP_SPACE_CENTER_STAIR_GUARD_STATE, 3
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	setvar VAR_ROUTE121_STATE, 1
	setvar VAR_ROUTE128_STATE, 2
	setvar VAR_METEOR_FALLS_STATE, 1
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_MET_RIVAL_MOM
	setflag FLAG_BIRCH_AIDE_MET
	setflag FLAG_MET_TEAM_AQUA_HARBOR
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_DEFEATED_MAGMA_SPACE_CENTER
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setflag FLAG_RETURNED_DEVON_GOODS
	setflag FLAG_DELIVERED_DEVON_GOODS
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_DEFEATED_GRUNT_SPACE_CENTER_1F
	setflag FLAG_INTERACTED_WITH_STEVEN_SPACE_CENTER
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	setflag FLAG_MET_RIVAL_RUSTBORO
	setflag FLAG_MET_RIVAL_LILYCOVE
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	setflag FLAG_WALLY_SPEECH
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_1_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_1F_GRUNT_2_BLOCKING_ENTRANCE
	setflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	setflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	setflag FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	setflag FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE
	setflag FLAG_HIDE_CHAMPIONS_ROOM_BIRCH
	setflag FLAG_HIDE_CHAMPIONS_ROOM_RIVAL
	setflag FLAG_HIDE_GRANITE_CAVE_STEVEN
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	setflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_ON_BIKE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	setflag FLAG_HIDE_LILYCOVE_CITY_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setflag FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON
	setflag FLAG_HIDE_MAGMA_HIDEOUT_4F_GROUDON_ASLEEP
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	setflag FLAG_HIDE_MAUVILLE_CITY_WALLY
	setflag FLAG_HIDE_MAUVILLE_CITY_WALLYS_UNCLE
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_AQUA
	setflag FLAG_HIDE_METEOR_FALLS_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_MAGMA_NOTE
	setflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_GYM_WALLYS_DAD
	setflag FLAG_HIDE_PETALBURG_WOODS_AQUA_GRUNT
	setflag FLAG_HIDE_PETALBURG_WOODS_DEVON_EMPLOYEE
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	setflag FLAG_HIDE_ROUTE_101_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_HIDE_ROUTE_101_ZIGZAGOON
	setflag FLAG_HIDE_ROUTE_103_BIRCH
	setflag FLAG_HIDE_ROUTE_103_RIVAL
	setflag FLAG_HIDE_ROUTE_104_RIVAL
	setflag FLAG_HIDE_ROUTE_110_BIRCH
	setflag FLAG_HIDE_ROUTE_110_RIVAL
	setflag FLAG_HIDE_ROUTE_110_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_HIDE_ROUTE_116_DEVON_EMPLOYEE
	setflag FLAG_HIDE_ROUTE_118_STEVEN
	setflag FLAG_HIDE_ROUTE_119_RIVAL
	setflag FLAG_HIDE_ROUTE_119_RIVAL_ON_BIKE
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_ROUTE_120_STEVEN
	setflag FLAG_HIDE_ROUTE_121_TEAM_AQUA_GRUNTS
	setflag FLAG_HIDE_ROUTE_128_ARCHIE
	setflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_HIDE_ROUTE_128_STEVEN
	setflag FLAG_HIDE_RUSTBORO_CITY_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_ASLEEP
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA_STILL
	setflag FLAG_HIDE_SKY_PILLAR_WALLACE
	setflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_1
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA_GRUNT_2
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_ARCHIE
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_FAMILIAR_AQUA_GRUNT
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RAYQUAZA
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setflag FLAG_HIDE_UNDERWATER_SEA_FLOOR_CAVERN_STOLEN_SUBMARINE
	setflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	setflag FLAG_HIDE_VICTORY_ROAD_EXIT_WALLY
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	@ the S.S. Tidal sails from the start; Peeko is back home with Mr. Briney
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SS_TIDAL
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_SSTIDAL
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_FERRY_ATTENDANT
	clearflag FLAG_HIDE_LILYCOVE_HARBOR_FERRY_SAILOR
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setvar VAR_BRINEY_LOCATION, 1
	@ Captain Stern works at the harbor again
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	@ Rayquaza sleeps at the top of Sky Pillar
	clearflag FLAG_HIDE_SKY_PILLAR_TOP_RAYQUAZA
	setflag FLAG_SFR_HOENN_WORLD_INIT
SFR_EventScript_InitHoennWorldDone::
	return
@ ---------------------------------------------------------------------------
@ Oak's lab: right after the National Pokedex upgrade, Oak sends the player to Hoenn.
SFR_EventScript_OakAuthorizesHoennTrip::
	msgbox SFR_Text_OakFriendInHoenn, MSGBOX_DEFAULT
	setflag FLAG_SFR_HOENN_TRIP_AUTHORIZED
	return

SFR_Text_OakFriendInHoenn:
	.string "OAK: Oh, {PLAYER}, one more thing.\p"
	.string "Far to the southwest of KANTO lies\n"
	.string "a region called HOENN.\p"
	.string "An old friend of mine, PROF. BIRCH,\n"
	.string "studies POKéMON habitats there.\p"
	.string "He could use the help of a TRAINER\n"
	.string "with a National POKéDEX like yours.\p"
	.string "Your S.S. TICKET is still valid.\n"
	.string "I've arranged everything with the\l"
	.string "port in VERMILION CITY.\p"
	.string "Show your ticket to the sailor by\n"
	.string "the dock and he'll take you aboard\l"
	.string "the S.S. TIDAL to SLATEPORT CITY.\p"
	.string "I'm sure HOENN's POKéMON will\n"
	.string "fascinate you. Off you go!$"

@ ---------------------------------------------------------------------------
@ Vermilion City: sailor of the S.S. Tidal, Kanto -> Slateport
SFR_EventScript_VermilionHoennSailor::
	lock
	faceplayer
	goto_if_unset FLAG_SFR_HOENN_TRIP_AUTHORIZED, SFR_EventScript_VermilionHoennSailorNotYet
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, SFR_EventScript_VermilionHoennSailorNotYet
	msgbox SFR_Text_VermilionSailorBoardToSlateport, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_VermilionHoennSailorDeclined
	msgbox SFR_Text_VermilionSailorAllAboard, MSGBOX_DEFAULT
	closemessage
	call_if_lt VAR_SFR_HOENN_STATE, 1, SFR_EventScript_SetSailingToHoenn
	playse SE_SHIP
	fadescreenspeed FADE_TO_BLACK, 12
	delay 60
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

SFR_EventScript_SetSailingToHoenn::
	setvar VAR_SFR_HOENN_STATE, 1
	return

SFR_EventScript_VermilionHoennSailorNotYet::
	msgbox SFR_Text_VermilionSailorNeedPermission, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_VermilionHoennSailorDeclined::
	msgbox SFR_Text_VermilionSailorComeBackAnytime, MSGBOX_DEFAULT
	release
	end

SFR_Text_VermilionSailorNeedPermission:
	.string "The S.S. TIDAL sails between\n"
	.string "VERMILION and SLATEPORT, in HOENN.\p"
	.string "Only passengers with a special\n"
	.string "permit may board, I'm afraid.$"

SFR_Text_VermilionSailorBoardToSlateport:
	.string "Ah, PROF. OAK told us about you!\p"
	.string "The S.S. TIDAL is bound for\n"
	.string "SLATEPORT CITY in HOENN.\p"
	.string "Would you like to board?$"

SFR_Text_VermilionSailorAllAboard:
	.string "All aboard!$"

SFR_Text_VermilionSailorComeBackAnytime:
	.string "Come back whenever you're ready\n"
	.string "to set sail.$"

@ ---------------------------------------------------------------------------
@ VAR_SFR_HOENN_STATE
@ 0: In Kanto
@ 1: Sailing to Hoenn (arrival scene pending at Slateport Harbor)
@ 2: Met Brendan, Birch's welcome pending
@ 3: Choosing a starter in Birch's lab
@ 4: Got the starter, Brendan waits by the lab door
@ 5: Got the Pokénav and DexNav

@ Slateport Harbor: arrival from Vermilion
SFR_EventScript_SlateportHarborArrival::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	playse SE_PIN
	applymovement LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN, Common_Movement_Delay48
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	applymovement LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN, SFR_Movement_HarborBrendanApproach
	waitmovement 0
	msgbox SFR_Text_HarborBrendanWelcome, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SFR_HOENN_STATE, 2
	setflag FLAG_SFR_HIDE_SLATEPORT_HARBOR_BRENDAN
	clearflag FLAG_SFR_HIDE_BIRCHS_LAB_BRENDAN
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_SLATEPORT_HARBOR_SFR_BRENDAN
	playse SE_M_FLY
	delay 40
	warpsilent MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 11
	waitstate
	releaseall
	end

SFR_Movement_HarborBrendanApproach:
	walk_up
	walk_up
	step_end

@ Slateport Harbor: ferry back to Kanto
SFR_EventScript_SlateportFerryToVermilion::
	msgbox SFR_Text_VermilionItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_Harbor_EventScript_ChooseNewDestination
	call SlateportCity_Harbor_EventScript_BoardFerry
	warp MAP_VERMILION_CITY, 25, 32
	waitstate
	release
	end

@ Birch's lab -------------------------------------------------------------
SFR_EventScript_BirchsLabFaceNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

SFR_EventScript_BirchsLabWelcome::
	lockall
	applymovement LOCALID_PLAYER, SFR_Movement_PlayerWalkToBirch
	waitmovement 0
	msgbox SFR_Text_BirchWelcome, MSGBOX_DEFAULT
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SFR_Text_BirchLabBrendanAfterWelcome, MSGBOX_DEFAULT
	setvar VAR_SFR_HOENN_STATE, 3
	releaseall
	end

SFR_Movement_PlayerWalkToBirch:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SFR_EventScript_BirchsLabBirchChooseStarter::
	msgbox SFR_Text_BirchChooseStarter, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabTreeckoBall::
	setvar VAR_TEMP_2, SPECIES_TREECKO
	goto SFR_EventScript_BirchsLabStarterBall
	end

SFR_EventScript_BirchsLabTorchicBall::
	setvar VAR_TEMP_2, SPECIES_TORCHIC
	goto SFR_EventScript_BirchsLabStarterBall
	end

SFR_EventScript_BirchsLabMudkipBall::
	setvar VAR_TEMP_2, SPECIES_MUDKIP
	goto SFR_EventScript_BirchsLabStarterBall
	end

SFR_EventScript_BirchsLabStarterBall::
	lock
	goto_if_set FLAG_SFR_RECEIVED_HOENN_STARTER, SFR_EventScript_BirchsLabLeaveOthers
	copyvar VAR_0x8004, VAR_TEMP_2
	bufferspeciesname STR_VAR_1, VAR_0x8004
	showmonpic VAR_0x8004, 10, 3
	msgbox SFR_Text_BirchYoullTakeStarter, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_BirchsLabTakeYourTime
	setvar VAR_TEMP_TRANSFERRED_SPECIES, 0
	copyvar VAR_TEMP_TRANSFERRED_SPECIES, VAR_0x8004
	givemon VAR_0x8004, 45, ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, SFR_EventScript_BirchsLabStarterToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, SFR_EventScript_BirchsLabStarterToPC
	hidemonpic
	goto Common_EventScript_NoMoreRoomForPokemon
	end

SFR_EventScript_BirchsLabStarterToParty::
	call SFR_EventScript_BirchsLabReceivedStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_BirchsLabAfterStarter
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto SFR_EventScript_BirchsLabAfterStarter
	end

SFR_EventScript_BirchsLabStarterToPC::
	call SFR_EventScript_BirchsLabReceivedStarter
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SFR_EventScript_BirchsLabStarterTransferred
	call Common_EventScript_NameReceivedBoxMon
SFR_EventScript_BirchsLabStarterTransferred::
	call Common_EventScript_TransferredToPC
	goto SFR_EventScript_BirchsLabAfterStarter
	end

SFR_EventScript_BirchsLabReceivedStarter::
	copyvar VAR_SFR_HOENN_STARTER, VAR_0x8004
	setflag FLAG_SFR_RECEIVED_HOENN_STARTER
	removeobject VAR_LAST_TALKED
	hidemonpic
	playfanfare MUS_OBTAIN_ITEM
	message SFR_Text_ReceivedHoennStarter
	waitmessage
	waitfanfare
	return

SFR_EventScript_BirchsLabAfterStarter::
	setvar VAR_SFR_HOENN_STATE, 4
	applymovement LOCALID_BIRCHS_LAB_BIRCH, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SFR_Text_BirchAfterStarter, MSGBOX_DEFAULT
	closemessage
	msgbox SFR_Text_BirchLabBrendanWaitByDoor, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, SFR_Movement_BrendanToDoor
	waitmovement 0
	setobjectxyperm LOCALID_BIRCHS_LAB_SFR_BRENDAN, 5, 10
	setobjectmovementtype LOCALID_BIRCHS_LAB_SFR_BRENDAN, MOVEMENT_TYPE_FACE_RIGHT
	release
	end

SFR_Movement_BrendanToDoor:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

SFR_EventScript_BirchsLabLeaveOthers::
	msgbox SFR_Text_BirchLeaveOthers, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabTakeYourTime::
	hidemonpic
	msgbox SFR_Text_BirchTakeYourTime, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabBrendan::
	lock
	faceplayer
	goto_if_ge VAR_SFR_HOENN_STATE, 4, SFR_EventScript_BirchsLabBrendanGoAhead
	msgbox SFR_Text_BirchLabBrendanAfterWelcome, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabBrendanGoAhead::
	msgbox SFR_Text_BirchLabBrendanWaitByDoor, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_BirchsLabPokenavTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto SFR_EventScript_BirchsLabPokenav
	end

SFR_EventScript_BirchsLabPokenavTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto SFR_EventScript_BirchsLabPokenav
	end

SFR_EventScript_BirchsLabPokenav::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call_if_eq VAR_0x8008, 1, SFR_EventScript_BirchsLabBrendanStepCloser
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SFR_Text_BrendanGivesPokenav, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SFR_Text_ReceivedPokenav
	waitmessage
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HAS_MATCH_CALL
	setflag FLAG_ADDED_MATCH_CALL_TO_POKENAV
	msgbox SFR_Text_BrendanGivesDexNav, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SFR_Text_ReceivedDexNav
	waitmessage
	waitfanfare
	setflag FLAG_SFR_DEXNAV_GET
	setflag FLAG_SFR_RECEIVED_POKENAV
	msgbox SFR_Text_BrendanSeeYouOnRoute103, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, SFR_EventScript_BirchsLabBrendanLeave0
	call_if_eq VAR_0x8008, 1, SFR_EventScript_BirchsLabBrendanLeave1
	playse SE_EXIT
	removeobject LOCALID_BIRCHS_LAB_SFR_BRENDAN
	setflag FLAG_SFR_HIDE_BIRCHS_LAB_BRENDAN
	setvar VAR_SFR_HOENN_STATE, 5
	releaseall
	end

SFR_EventScript_BirchsLabBrendanStepCloser::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, Common_Movement_WalkRight
	waitmovement 0
	return

SFR_EventScript_BirchsLabBrendanLeave0::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, SFR_Movement_BrendanLeaveFromLeft
	waitmovement 0
	return

SFR_EventScript_BirchsLabBrendanLeave1::
	applymovement LOCALID_BIRCHS_LAB_SFR_BRENDAN, SFR_Movement_BrendanLeaveFromCenter
	waitmovement 0
	return

SFR_Movement_BrendanLeaveFromLeft:
	walk_down
	step_end

SFR_Movement_BrendanLeaveFromCenter:
	walk_down
	walk_down
	step_end

@ Texts --------------------------------------------------------------------
SFR_Text_VermilionItIs:
	.string "VERMILION CITY in KANTO it is, then!$"

SFR_Text_HarborBrendanWelcome:
	.string "BRENDAN: Hey! You must be {PLAYER}!\n"
	.string "The TRAINER from KANTO, right?\p"
	.string "I'm BRENDAN. My dad is PROF. BIRCH.\p"
	.string "PROF. OAK phoned him and said you\n"
	.string "were coming to see HOENN.\p"
	.string "Dad wants to meet you at his lab in\n"
	.string "LITTLEROOT TOWN. It's a long way from\l"
	.string "here, so I'll fly you there!\p"
	.string "Come on, let's go!$"

SFR_Text_BirchWelcome:
	.string "PROF. BIRCH: Welcome to HOENN,\n"
	.string "{PLAYER}! I'm PROF. BIRCH.\p"
	.string "My old friend PROF. OAK told me\n"
	.string "all about you.\p"
	.string "Beating the KANTO LEAGUE!\n"
	.string "That's really something!\p"
	.string "Here in HOENN, things have finally\n"
	.string "calmed down after some big trouble.\p"
	.string "It's the perfect time to explore!\p"
	.string "To get you started, I'd like you\n"
	.string "to have a POKéMON from HOENN.\p"
	.string "The three POKé BALLS on that table\n"
	.string "hold TREECKO, TORCHIC and MUDKIP.\p"
	.string "They've been raised well, so they're\n"
	.string "quite strong already.\p"
	.string "Go on, choose the one you like!$"

SFR_Text_BirchLabBrendanAfterWelcome:
	.string "BRENDAN: I already have my partner\n"
	.string "from Dad. Pick whichever you like!$"

SFR_Text_BirchChooseStarter:
	.string "PROF. BIRCH: Go on, pick one of the\n"
	.string "POKé BALLS on the table!$"

SFR_Text_BirchYoullTakeStarter:
	.string "PROF. BIRCH: So, you'd like\n"
	.string "the {STR_VAR_1}?$"

SFR_Text_BirchTakeYourTime:
	.string "PROF. BIRCH: Take your time.\n"
	.string "They're all wonderful POKéMON.$"

SFR_Text_ReceivedHoennStarter:
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from PROF. BIRCH!$"

SFR_Text_BirchLeaveOthers:
	.string "PROF. BIRCH: The others are staying\n"
	.string "here with me, I'm afraid.$"

SFR_Text_BirchAfterStarter:
	.string "PROF. BIRCH: That POKéMON is holding\n"
	.string "an EVERSTONE.\p"
	.string "It won't evolve while it holds the\n"
	.string "stone. When you feel your bond is\l"
	.string "strong enough, just take it away.\p"
	.string "HOENN has eight GYMS, and you can\n"
	.string "challenge them in any order you like.\p"
	.string "Beat all eight and you can take on\n"
	.string "the POKéMON LEAGUE!$"

SFR_Text_BirchLabBrendanWaitByDoor:
	.string "BRENDAN: Before you go, I've got\n"
	.string "something for you. Don't run off!$"

SFR_Text_BrendanGivesPokenav:
	.string "BRENDAN: Here! This is a POKéNAV.\n"
	.string "Everyone in HOENN carries one.$"

SFR_Text_ReceivedPokenav:
	.string "{PLAYER} received the POKéNAV!$"

SFR_Text_BrendanGivesDexNav:
	.string "BRENDAN: And this is the DEXNAV!\p"
	.string "It shows which POKéMON live in the\n"
	.string "area, even ones hiding in the grass.$"

SFR_Text_ReceivedDexNav:
	.string "{PLAYER} received the DEXNAV!$"

SFR_Text_BrendanSeeYouOnRoute103:
	.string "BRENDAN: I'm heading to ROUTE 103,\n"
	.string "past OLDALE TOWN.\p"
	.string "Come find me there. I want to see\n"
	.string "how strong a KANTO CHAMPION really is!$"

@ Littleroot houses: Brendan's house is the Birch family's, May's house is Norman's.
SFR_EventScript_SetupBrendansHouse1F::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_BRENDAN
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	end

SFR_EventScript_SetupMaysHouse1F::
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setobjectxyperm LOCALID_PLAYERS_HOUSE_1F_MOM, 6, 5
	setobjectmovementtype LOCALID_PLAYERS_HOUSE_1F_MOM, MOVEMENT_TYPE_FACE_UP
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_HOUSE_VIGOROTH_2
	setflag FLAG_HIDE_PLAYERS_HOUSE_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MAY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	end

SFR_EventScript_SetupRivalHouse2F::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_PLAYERS_BEDROOM_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	call SecretBase_EventScript_SetDecorationFlags
	setvar VAR_SECRET_BASE_INITIALIZED, 1
	end

SFR_EventScript_MrsBirch::
	lock
	faceplayer
	goto_if_ge VAR_SFR_HOENN_STATE, 5, SFR_EventScript_MrsBirchLater
	msgbox SFR_Text_MrsBirchFirst, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_MrsBirchLater::
	msgbox SFR_Text_MrsBirchLater, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_MaysMom::
	lock
	faceplayer
	goto_if_set FLAG_SFR_HOENN_GAME_CLEAR, SFR_EventScript_MaysMomAfterLeague
	msgbox SFR_Text_MaysMom, MSGBOX_DEFAULT
	release
	end

SFR_EventScript_MaysMomAfterLeague::
	msgbox SFR_Text_MaysMomAfterLeague, MSGBOX_DEFAULT
	release
	end

SFR_Text_NormansHouseSign:
	.string "NORMAN'S HOUSE$"

SFR_Text_MrsBirchFirst:
	.string "Oh, hello! You must be the TRAINER\n"
	.string "from KANTO my husband mentioned.\p"
	.string "I'm BRENDAN's mother. Please go and\n"
	.string "see the PROFESSOR at his lab!$"

SFR_Text_MrsBirchLater:
	.string "BRENDAN is always out somewhere,\n"
	.string "helping his father with fieldwork.\p"
	.string "He's grown so much. He even says\n"
	.string "he's going to beat the CHAMPION!$"

SFR_Text_MaysMom:
	.string "Hello! I'm MAY's mother.\p"
	.string "My husband NORMAN is the GYM LEADER\n"
	.string "in PETALBURG CITY.\p"
	.string "And MAY… She became the CHAMPION\n"
	.string "of HOENN! I'm so proud of her.\p"
	.string "She's always at the POKéMON LEAGUE\n"
	.string "these days, waiting for challengers.$"

SFR_Text_MaysMomAfterLeague:
	.string "MAY called and told me all about\n"
	.string "your battle!\p"
	.string "She said she's never had so much\n"
	.string "fun losing. Thank you, dear!$"

@ ---------------------------------------------------------------------------
@ Sootopolis Gym: Wallace also hands over HM07 Waterfall (needed for Victory Road)
SFR_EventScript_WallaceGiveWaterfall::
	checkitem ITEM_HM_WATERFALL
	goto_if_eq VAR_RESULT, TRUE, SFR_EventScript_WallaceGiveWaterfallDone
	msgbox SFR_Text_WallaceTakeWaterfall, MSGBOX_DEFAULT
	giveitem ITEM_HM_WATERFALL
	setflag FLAG_RECEIVED_HM_WATERFALL
	msgbox SFR_Text_WallaceExplainWaterfall, MSGBOX_DEFAULT
SFR_EventScript_WallaceGiveWaterfallDone::
	return

SFR_Text_WallaceTakeWaterfall:
	.string "WALLACE: And one more thing.\n"
	.string "You'll need this on the way to\l"
	.string "the POKéMON LEAGUE.$"

SFR_Text_WallaceExplainWaterfall:
	.string "WALLACE: That HM contains WATERFALL.\p"
	.string "It lets your POKéMON climb up\n"
	.string "walls of cascading water.$"

@ ---------------------------------------------------------------------------
@ Pokémon League: May, the Champion
SFR_Text_MayChampionIntro:
	.string "MAY: {PLAYER}! I knew you'd make it\n"
	.string "all the way here!\p"
	.string "Dad told me all about your battle\n"
	.string "in PETALBURG.\p"
	.string "When I first set out, I was just a\n"
	.string "girl from LITTLEROOT TOWN.\p"
	.string "Since then I've traveled all over\n"
	.string "HOENN, faced the worst trouble this\l"
	.string "region has ever seen…\p"
	.string "And I became the CHAMPION!\p"
	.string "You beat the KANTO LEAGUE, right?\n"
	.string "Then this is a battle between\l"
	.string "two CHAMPIONS!\p"
	.string "My POKéMON and I won't hold back.\n"
	.string "Here I come!$"

SFR_Text_MayChampionDefeat:
	.string "That was amazing…\n"
	.string "You really are the real deal!$"

SFR_Text_MayChampionPostBattle:
	.string "MAY: …I lost.\p"
	.string "But you know what? I'm not even\n"
	.string "upset. That was the most fun I've\l"
	.string "had in a battle in ages!\p"
	.string "{PLAYER}, you're the new CHAMPION\n"
	.string "of the HOENN LEAGUE!$"

SFR_Text_ChampionsRoomBrendanArrives:
	.string "BRENDAN: {PLAYER}! Did you…\p"
	.string "MAY, you lost?!$"

SFR_Text_ChampionsRoomBrendanYouWon:
	.string "BRENDAN: Wow… You actually beat\n"
	.string "MAY!\p"
	.string "I knew you were strong ever since\n"
	.string "that first battle on ROUTE 103!$"

SFR_Text_ChampionsRoomBirchCongratulations:
	.string "PROF. BIRCH: There you are!\p"
	.string "When BRENDAN ran off, I just had\n"
	.string "to come and see for myself.\p"
	.string "Congratulations, {PLAYER}!\p"
	.string "I can't wait to tell PROF. OAK!\n"
	.string "His friend from KANTO has become\l"
	.string "HOENN's new CHAMPION!$"

SFR_Text_MayComeWithMe:
	.string "MAY: {PLAYER}, please come with me.\n"
	.string "There's a place I want to show you.$"

SFR_Text_ChampionsRoomBrendanGoOn:
	.string "BRENDAN: Go on, {PLAYER}!\n"
	.string "We'll wait for you outside.$"

SFR_Text_HallOfFameMayHonor:
	.string "MAY: This room…\p"
	.string "This is where the POKéMON LEAGUE\n"
	.string "honors its CHAMPIONS and the POKéMON\l"
	.string "that battled alongside them.$"

SFR_Text_HallOfFameMayRecord:
	.string "MAY: Come on, let's record your name\n"
	.string "and the names of your partners!$"

@ ---------------------------------------------------------------------------
@ VAR_RESULT = TRUE if the player has all eight Hoenn badges (FLAG_BADGE09_GET-FLAG_BADGE16_GET)
SFR_EventScript_CheckAllHoennBadges::
	setvar VAR_RESULT, FALSE
	goto_if_unset FLAG_BADGE09_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE10_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE11_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE12_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE13_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE14_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE15_GET, SFR_EventScript_CheckAllHoennBadgesDone
	goto_if_unset FLAG_BADGE16_GET, SFR_EventScript_CheckAllHoennBadgesDone
	setvar VAR_RESULT, TRUE
SFR_EventScript_CheckAllHoennBadgesDone::
	return
